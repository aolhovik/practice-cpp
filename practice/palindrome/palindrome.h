#ifndef PALINDROME_H_
#define PALINDROME_H_

#include <string>

/**
 * \brief	Checks if a given string is a palindrome; a string is a plaindrome if its reverse is equal to original.
 *
 * \ret	Returns true if a given string is palindrome, false otherwise.
 */
bool
isPalindrome (const std::string &s) noexcept;

std::string
getLongestPalindrome (const std::string &sIn);

#endif // PALINDROME_H_
