const palindrome = require('../index').palindrome;

test('Palindrome of a', () => {
  const result = palindrome('a');

  expect(result).toBe('a');
});

test('Palindrome of react', () => {
  const result = palindrome('react');

  expect(result).toBe('tcaer');
});

test('Palindrome of releveler', () => {
  const result = palindrome('releveler');

  expect(result).toBe('releveler');
});
