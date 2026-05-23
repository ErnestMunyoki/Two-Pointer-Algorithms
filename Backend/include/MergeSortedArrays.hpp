#ifndef MERGE_SORTED_ARRAYS_HPP
#define MERGE_SORTED_ARRAYS_HPP

#include <vector>

namespace TwoPointerAlgorithms {

/**
 * @brief Merges two sorted arrays into one sorted array using the two-pointer technique.
 * 
 * This function uses two pointers, one for each input array, to traverse both arrays
 * simultaneously. It compares elements at both pointers and places the smaller one
 * in the result array, then advances the corresponding pointer.
 * 
 * @param arr1 First sorted array
 * @param arr2 Second sorted array
 * @return std::vector<int> Merged sorted array
 */
std::vector<int> mergeSortedArrays(const std::vector<int>& arr1, const std::vector<int>& arr2);

} // namespace TwoPointerAlgorithms

#endif // MERGE_SORTED_ARRAYS_HPP
