const express = require('express');
const path = require('path');

const router = express.Router();

router.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, '../pages/index.html'));
});

router.get('/discoveries', (req, res) => {
  res.sendFile(path.join(__dirname, '../pages/discoveries.html'));
});

router.get('/constellations', (req, res) => {
  res.sendFile(path.join(__dirname, '../pages/constellations.html'));
});

router.get('/explore', (req, res) => {
  res.sendFile(path.join(__dirname, '../pages/explore.html'));
});

module.exports = router;
