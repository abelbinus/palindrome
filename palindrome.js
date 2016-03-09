var addon = require('bindings')('palindrome');

console.log(addon.isPalindrome(' aaa')); //true
// console.log(addon.isPalindrome('aba')); //true
// console.log(addon.isPalindrome('abb')); //false
