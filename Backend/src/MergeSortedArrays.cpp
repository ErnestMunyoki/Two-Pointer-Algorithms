#include "MergeSortedArrays.hpp"

namespace TwoPointerAlgorithms {

std::vector<int> mergeSortedArrays(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    std::vector<int> result;
    result.reserve(arr1.size() + arr2.size());
    
    int i = 0;
    int j = 0;
    
    while (i < static_cast<int>(arr1.size()) && j < static_cast<int>(arr2.size())) {
        if (arr1[i] <= arr2[j]) {
            result.push_back(arr1[i]);
            i++;
        } else {
            result.push_back(arr2[j]);
            j++;
        }
    }
    while (i < static_cast<int>(arr1.size())) {
        result.push_back(arr1[i]);
        i++;
    }
    while (j < static_cast<int>(arr2.size())) {
        result.push_back(arr2[j]);
        j++;
    }
    
    return result;
}

} 
