#include "RemoveDuplicate.hpp"

namespace TwoPointerAlgorithms {

int removeDuplicates(std::vector<int>& arr) {
    if (arr.empty()) {
        return 0;
    }
    
    int slow = 0;  // Pointer for the position of last unique element
    
    for (int fast = 1; fast < static_cast<int>(arr.size()); fast++) {
        // If we find a new unique element
        if (arr[fast] != arr[slow]) {
            slow++;
            arr[slow] = arr[fast];
        }
    }
    
    // Return the new length (slow + 1 because slow is 0-indexed)
    return slow + 1;
}

} // namespace TwoPointerAlgorithms
