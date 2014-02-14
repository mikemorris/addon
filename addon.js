var createObject = require('./build/Release/addon');

var obj = createObject(10);
console.log(obj.plusOne());
console.log(obj.plusOne());
console.log(obj.plusOne());

var obj2 = createObject(20);
console.log(obj2.plusOne());
console.log(obj2.plusOne());
console.log(obj2.plusOne());
