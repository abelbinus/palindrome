//TODO: export just a function
var addon = require('bindings')('palindrome');

console.log(addon.isPalindrome('a bz a')); //false
console.log(addon.isPalindrome('a santa at nasa')); //true
console.log(addon.isPalindrome('a but tuba')); //true
console.log(addon.isPalindrome('aaa')); //true
console.log(addon.isPalindrome('aba')); //true
console.log(addon.isPalindrome('abb')); //false
console.log(addon.isPalindrome('abbb')); //false
console.log(addon.isPalindrome('abbba')); //true
console.log(addon.isPalindrome('babbbab')); //true
console.log(addon.isPalindrome('bababab')); //true