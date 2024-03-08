const { Pool } = require('pg');
const pool = new Pool({
  user: 'admin',
  host: 'localhost',
  database: 'astronomy',
  password: 'funkyBunch_03',
  port: 5432,
});

const getAllSpectralClasses = async () => {
  try {
    const result = await pool.query('SELECT * FROM spectral_classes');
    return result.rows;
  } catch (error) {
    console.error('Error fetching spectral classes:', error);
    throw new Error('Error fetching spectral classes');
  }
};

async function getSpectralClassById(id) {
  try {
    const result = await pool.query('SELECT * FROM spectral_classes WHERE id = $1', [id]);

    if (result.rows.length > 0) {
      return result.rows[0];
    } else {
      throw new Error('Spectral class not found');
    }
  } catch (error) {
    throw error;
  }
};

module.exports = {
  getAllSpectralClasses,
  getSpectralClassById,
};
