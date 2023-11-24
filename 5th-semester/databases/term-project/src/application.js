const express = require('express');
const path = require('path');
const { Pool } = require('pg');
const dotenv = require('dotenv');
const starsRouter = require('./routes/stars');
const pagesRouter = require('./routes/pages');
const errorMiddleware = require('./middleware/error');

dotenv.config();

const app = express();
const port = 3000;

const pool = new Pool({
  user: process.env.DB_USER,
  host: process.env.DB_HOST,
  database: process.env.DB_NAME,
  password: process.env.DB_PASSWORD,
  port: process.env.DB_PORT,
});

app.use(express.json());

// app.use('/assets', express.static('src/assets', { type: 'text/css' }));
app.use('/assets', express.static(path.join(__dirname, 'assets'), { type: 'text/css' }));

app.use('/', pagesRouter);

app.use('/api/stars', starsRouter);

app.use(errorMiddleware);

app.listen(port, () => {
  console.log(`Server listening at http://localhost:${port}`);
});
