const { Pool } = require('pg');
const pool = new Pool({
  user: 'admin',
  host: 'localhost',
  database: 'astronomy',
  password: 'funkyBunch_03',
  port: 5432,
});

const getAllGalaxies = async () => {
  try {
    const result = await pool.query('SELECT * FROM galaxies');
    return result.rows;
  } catch (error) {
    console.error('Error fetching galaxies:', error);
    throw new Error('Error fetching galaxies');
  }
};

async function getGalaxyById(id) {
  try {
    const result = await pool.query('SELECT * FROM galaxies WHERE id = $1', [id]);

    if (result.rows.length > 0) {
      return result.rows[0];
    } else {
      throw new Error('Galaxy not found');
    }
  } catch (error) {
    throw error;
  }
};

module.exports = {
  getAllGalaxies,
  getGalaxyById,
};
