#ifndef PALINDROME_CHECKER_HPP
#define PALINDROME_CHECKER_HPP

#include <string>

namespace TwoPointerAlgorithms {

/**
 * @brief Checks if a string is a palindrome using the two-pointer technique.
 * 
 * This function uses two pointers: one starting at the beginning of the string
 * and one at the end. The pointers move towards each other, comparing characters.
 * If all corresponding characters match, the string is a palindrome.
 * 
 * @param str The string to check
 * @return true if the string is a palindrome, false otherwise
 */
bool isPalindrome(const std::string& str);

} // namespace TwoPointerAlgorithms

#endif // PALINDROME_CHECKER_HPP
