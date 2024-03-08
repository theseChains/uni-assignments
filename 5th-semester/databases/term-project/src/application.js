const express = require('express');
const ejs = require('ejs');
const path = require('path');
const { Pool } = require('pg');
const starsRouter = require('./routes/stars');
const pagesRouter = require('./routes/pages');
const errorMiddleware = require('./middleware/error');
const { getConstellationById } = require('./services/constellationsService');
const { getAllStars, getStarById } = require('./services/starsService');
const { getAllGalaxies, getGalaxyById } = require('./services/galaxiesService');
const { getAllSpectralClasses, getSpectralClassById } = require('./services/spectralClassesService');

const app = express();
const port = 3000;

const pool = new Pool({
  user: process.env.DB_USER,
  host: process.env.DB_HOST,
  database: process.env.DB_DATABASE,
  password: process.env.DB_PASSWORD,
  port: process.env.DB_PORT,
});

app.use(express.json());

app.use('/assets', express.static(path.join(__dirname, 'assets'), { type: 'text/css' }));
app.set('view engine', 'ejs');

app.get('/constellations/:id', async (req, res) => {
  try {
    const result =
      await pool.query('SELECT *, (SELECT id FROM stars WHERE name = brightest_star) as brightest_star_id FROM constellations WHERE id = $1', [req.params.id]);

    const constellation = result.rows[0];
    res.render('constellationDetails', { constellation });
  } catch (error) {
    console.error('Error fetching constellation details:', error);
    res.status(500).send('Internal Server Error');
  }
});

app.get('/stars/:id', async (req, res) => {
  try {
    const star = await getStarById(req.params.id);
    const constellation = await getConstellationById(star.constellation_id);
    const galaxy = await getGalaxyById(star.galaxy_id);
    const spectral_class = await getSpectralClassById(star.spectral_class_id);
    const constellation_name = constellation.name;
    const galaxy_name = galaxy.name;
    const spectral_class_name = spectral_class.name
    res.render('starDetails', { star, constellation_name, galaxy_name, spectral_class_name });
  } catch (error) {
    console.error('Error fetching star details:', error);
    res.status(500).send('Internal Server Error');
  }
});

app.get('/galaxies/:id', async (req, res) => {
  try {
    const galaxy = await getGalaxyById(req.params.id);
    res.render('galaxyDetails', { galaxy });
  } catch (error) {
    console.error('Error fetching galaxy details:', error);
    res.status(500).send('Internal Server Error');
  }
});

app.get('/constellations', async (req, res) => {
  try {
    const result = await pool.query('SELECT * FROM constellations');
    const constellations = result.rows;
    res.setHeader('Content-Type', 'text/html');
    res.render('constellations', { constellations });
  } catch (error) {
    console.error('Error fetching constellations:', error);
    res.status(500).send('Internal Server Error');
  }
});

app.get('/explore', async (req, res) => {
  try {
    const stars = await getAllStars();
    const galaxies = await getAllGalaxies();
    res.render('explore', { stars, galaxies });
  } catch (error) {
    console.error('Error fetching stars:', error);
    res.status(500).send('Internal Server Error');
  }
});

app.get('/spectral-classes', async (req, res) => {
  try {
    const result = await pool.query('SELECT * FROM spectral_classes');
    const spectralClasses = result.rows;
    res.render('spectralClasses', { spectralClasses });
  } catch (error) {
    console.error('Error fetching stars:', error);
    res.status(500).send('Internal Server Error');
  }
});

app.get('/spectralClasses/:id', async (req, res) => {
  try {
    const id = req.params.id;
    const spectralClass = await getSpectralClassById(id);

    res.render('spectralClassDetails', { spectralClass });
  } catch (error) {
    console.error('Error fetching spectral class details:', error);
    res.status(500).send('Internal Server Error');
  }
});

app.use('/', pagesRouter);
app.use('/api/stars', starsRouter);

app.use(errorMiddleware);

app.listen(port, () => {
  console.log(`Server listening at http://localhost:${port}`);
});
