const errorHandler = (err, req, res, next) => {
  console.error(err);

  const statusCode = res.statusCode === 200 ? 500 : res.statusCode;
  res.status(statusCode);
  res.json({
    message: err.message,
    stack: process.env.NODE_ENV === 'production' ? 'no details' : err.stack,
  });
};

module.exports = errorHandler;
