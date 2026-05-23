#include "ReversingString.hpp"
#include <algorithm>

namespace TwoPointerAlgorithms {

std::string& reverseString(std::string& str) {
    int left = 0;
    int right = static_cast<int>(str.length()) - 1;
    
    while (left < right) {
        // Swap characters at left and right pointers
        std::swap(str[left], str[right]);
        left++;
        right--;
    }
    
    return str;
}

} // namespace TwoPointerAlgorithms
