const express = require('express');
const { Pool } = require('pg');

const router = express.Router();
const pool = new Pool({
  user: process.env.DB_USER,
  host: process.env.DB_HOST,
  database: process.env.DB_NAME,
  password: process.env.DB_PASSWORD,
  port: process.env.DB_PORT,
});

// GET /api/stars
router.get('/', async (req, res, next) => {
  try {
    const result = await pool.query('SELECT * FROM stars');
    res.json(result.rows);
  } catch (err) {
    next(err);
  }
});

module.exports = router;
