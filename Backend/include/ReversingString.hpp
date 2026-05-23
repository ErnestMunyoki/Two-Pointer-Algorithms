#ifndef REVERSING_STRING_HPP
#define REVERSING_STRING_HPP

#include <string>

namespace TwoPointerAlgorithms {

/**
 * @brief Reverses a string in place using the two-pointer technique.
 * 
 * This function uses two pointers: one starting at the beginning of the string
 * and one at the end. The pointers move towards each other, swapping characters
 * until they meet in the middle.
 * 
 * @param str The string to be reversed (modified in place)
 * @return std::string& Reference to the reversed string for chaining
 */
std::string& reverseString(std::string& str);

} // namespace TwoPointerAlgorithms

#endif // REVERSING_STRING_HPP
