'use strict';

var modexp = require('../index');


module.exports = {

  testEasy: function(test) {
    var result = modexp('2', '10', '1000');
    test.strictEqual(parseInt(result, 16), 24);
    test.done();
  },

  testExample1: function(test) {
    test.strictEqual(modexp('45396828', '0x08EE7', '0x2D87BA65'), '26bde95f');
    test.strictEqual(modexp('01260685', '0x08EE7', '0x2D87BA65'), '15ae54c6');
    test.strictEqual(modexp('0115', '0x08EE7', '0x2D87BA65'), '2c487025');
    test.strictEqual(modexp('789', '0x08EE7', '0x2D87BA65'), '233fbeb6');
    test.done();
  },

  testExample2: function(test) {
    test.strictEqual(modexp('0816', '0x08EE7', '0x2D87BA65'), '183bcb71');
    test.strictEqual(modexp('5645', '0x08EE7', '0x2D87BA65'), '19dca45f');
    test.done();
  },

  testExample3: function(test) {
    test.strictEqual(modexp('65396823', '0x08EE7', '0x2D87BA65'), '1f0422a3');
    test.strictEqual(modexp('45820283', '0x08EE7', '0x2D87BA65'), '108673fd');
    test.strictEqual(modexp('1216', '0x08EE7', '0x2D87BA65'), '39924d0');
    test.strictEqual(modexp('125', '0x08EE7', '0x2D87BA65'), '233f8aef');
    test.done();
  },

};
