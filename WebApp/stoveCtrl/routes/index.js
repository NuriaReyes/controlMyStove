var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', {});
});

router.get('/on_off', function(req, res, next) {
  res.render('index', {});
});

router.get('/timer', function(req, res, next) {
  res.render('index', {});
});

router.get('/regulate', function(req, res, next) {
  res.render('index', {});
});

module.exports = router;
