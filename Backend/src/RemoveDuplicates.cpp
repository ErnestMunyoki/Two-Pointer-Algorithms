#include "RemoveDuplicate.hpp"

namespace TwoPointerAlgorithms {

int removeDuplicates(std::vector<int>& arr) {
    if (arr.empty()) {
        return 0;
    }
    
    int slow = 0;
    
    for (int fast = 1; fast < static_cast<int>(arr.size()); fast++) {
        if (arr[fast] != arr[slow]) {
            slow++;
            arr[slow] = arr[fast];
        }
    }
    
    return slow + 1;
}

}
