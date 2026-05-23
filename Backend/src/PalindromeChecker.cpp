#include "PalindromeChecker.hpp"
#include <cctype>

namespace TwoPointerAlgorithms {

bool isPalindrome(const std::string& str) {
    int left = 0;
    int right = static_cast<int>(str.length()) - 1;
    
    while (left < right) {
        // Compare characters at left and right pointers
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    
    return true;
}

} // namespace TwoPointerAlgorithms
