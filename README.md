
modexp64
========

> Modular exponentiation in NodeJS using 64 bits unsigned numbers. Implemented in C++.


Installation
------------

Install via [npm](https://npmjs.org/package/modexp64):

```shell
npm install modexp64 --save
```


Example usage
-------------

```js
var modexp = require('modexp64');

// 0x3E8 = 1000
// It calcs (2^10) % 1000
var result = modexp('2', '10', '0x3E8');

// Prints 18 (in hexadecimal)
console.log(result);

// Prints 24 (in decimal)
console.log(parseInt(result, 16));
```



API Documentation
-----------------

**modexp(base, exp, mod):** It takes 3 strings. They can be decimal numbers
or hexadecimal ones (prefixed with "0x"). It returns a string with the result
in hexadecimal (with no prefix).
