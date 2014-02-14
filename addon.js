var addon = require('./build/Release/addon');

var obj = new addon.MyObject(10);
console.log(obj.plusOne());
console.log(obj.plusOne());
console.log(obj.plusOne());
