const assert = require('assert');

const isPalindrome = require('../palindrome');

const palindromes = ['hannah', 'redivider', 'noon', 'civic', 'radar', 'level', 'rotor', 'kayak', 'reviver', 'racecar', 'redder', 'madam', 'refer'];
const notPalindromes = ['foo', 'bar'];

describe('palindrome', function() {
  describe('positives', function() {
    palindromes.forEach((word) => {
      it(`${word} is a palindrome`, function() {
        assert.ok(isPalindrome(word));
      });
    });
  });

  describe('negatives', function() {
    notPalindromes.forEach((word) => {
      it(`${word} is NOT a palindrome`, function() {
        assert.ok(!isPalindrome(word));
      });
    });
  });
});
