const express = require('express');
const path = require('path');
const { getConstellationById } = require('../services/constellationsService');
const { getAllStars, getStarById } = require('../services/starsService');
const { getAllGalaxies, getGalaxyById } = require('../services/galaxiesService');

const router = express.Router();

router.get('/index', (req, res) => {
  res.sendFile(path.join(__dirname, '../pages/index.html'));
});

router.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, '../pages/index.html'));
});

router.get('/discoveries', (req, res) => {
  res.sendFile(path.join(__dirname, '../pages/discoveries.html'));
});

router.get('/constellations', async (req, res) => {
  try {
    const result = await pool.query('SELECT * FROM constellations');
    const constellations = result.rows;
    res.render('constellations', { constellations });
  } catch (error) {
    console.error('Error fetching constellations:', error);
    res.status(500).send('Internal Server Error');
  }
});

router.get('/constellations/:id', async (req, res) => {
  const constellationId = req.params.id;

  try {
    const constellation = await getConstellationById(constellationId);

    res.render('constellationDetails', { constellation });
  } catch (error) {
    console.error('Error fetching constellation details:', error);
    res.status(500).send('Internal Server Error');
  }
});

router.get('/stars/:id', async (req, res) => {
  const { id } = req.params;
  try {
    const star = await getStarById(id);
    res.render('starDetails', { star });
  } catch (error) {
    console.error('Error fetching star:', error);
    res.status(500).send('Internal Server Error');
  }
});

router.get('/galaxies/:id', async (req, res) => {
  const { id } = req.params;
  try {
    const galaxy = await getGalaxyById(id);
    res.render('galaxyDetails', { galaxy });
  } catch (error) {
    console.error('Error fetching galaxy:', error);
    res.status(500).send('Internal Server Error');
  }
});

router.get('/explore', async (req, res) => {
  try {
    const stars = await getAllStars();
    const galaxies = await getAllGalaxies();
    res.render('explore', { stars, galaxies });
  } catch (error) {
    console.error('Error fetching stars:', error);
    res.status(500).send('Internal Server Error');
  }
});

module.exports = router;
