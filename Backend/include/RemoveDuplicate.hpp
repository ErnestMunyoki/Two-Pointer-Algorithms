#ifndef REMOVE_DUPLICATE_HPP
#define REMOVE_DUPLICATE_HPP

#include <vector>

namespace TwoPointerAlgorithms {

/**
 * @brief Removes duplicates from a sorted array using the two-pointer technique.
 * 
 * This function uses two pointers: one (slow) to track the position of the last
 * unique element, and one (fast) to scan through the array. When a new unique
 * element is found, it's placed at the slow pointer position.
 * 
 * @param arr The sorted array (modified in place)
 * @return int The new length of the array with duplicates removed
 */
int removeDuplicates(std::vector<int>& arr);

} // namespace TwoPointerAlgorithms

#endif // REMOVE_DUPLICATE_HPP
