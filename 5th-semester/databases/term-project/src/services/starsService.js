const { Pool } = require('pg');
const pool = new Pool({
  user: 'admin',
  host: 'localhost',
  database: 'astronomy',
  password: 'funkyBunch_03',
  port: 5432,
});

const getAllStars = async () => {
  try {
    const result = await pool.query('SELECT * FROM stars');
    return result.rows;
  } catch (error) {
    console.error('Error fetching stars:', error);
    throw new Error('Error fetching stars');
  }
};

async function getStarById(id) {
  try {
    const result = await pool.query('SELECT * FROM stars WHERE id = $1', [id]);

    if (result.rows.length > 0) {
      return result.rows[0];
    } else {
      throw new Error('Star not found');
    }
  } catch (error) {
    throw error;
  }
};

module.exports = {
  getAllStars,
  getStarById,
};
