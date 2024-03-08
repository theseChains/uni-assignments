const { Pool } = require('pg');
const pool = new Pool({
  user: 'admin',
  host: 'localhost',
  database: 'astronomy',
  password: 'funkyBunch_03',
  port: 5432,
});

async function getConstellationById(id) {
  try {
    const result = await pool.query('SELECT * FROM constellations WHERE id = $1', [id]);

    if (result.rows.length > 0) {
      return result.rows[0];
    } else {
      throw new Error('Constellation not found');
    }
  } catch (error) {
    throw error;
  }
}

module.exports = {
  getConstellationById,
};
