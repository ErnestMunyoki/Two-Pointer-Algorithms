#include "ReversingString.hpp"
#include "PalindromeChecker.hpp"
#include "RemoveDuplicate.hpp"
#include "MergeSortedArrays.hpp"
#include <iostream>
#include <vector>

void printVector(const std::vector<int>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]";
}

int main() {
    std::cout << "========================================\n";
    std::cout << "Two-Pointer Algorithms Demo\n";
    std::cout << "========================================\n\n";
    
    // Demo 1: Reverse String
    std::cout << "1. Reverse String Algorithm\n";
    std::cout << "----------------------------\n";
    std::string testStr1 = "hello";
    std::cout << "Original: \"" << testStr1 << "\"\n";
    TwoPointerAlgorithms::reverseString(testStr1);
    std::cout << "Reversed: \"" << testStr1 << "\"\n\n";
    
    std::string testStr2 = "racecar";
    std::cout << "Original: \"" << testStr2 << "\"\n";
    TwoPointerAlgorithms::reverseString(testStr2);
    std::cout << "Reversed: \"" << testStr2 << "\"\n\n";
    
    // Demo 2: Palindrome Checker
    std::cout << "2. Palindrome Checker Algorithm\n";
    std::cout << "--------------------------------\n";
    std::string palindrome1 = "racecar";
    std::cout << "Is \"" << palindrome1 << "\" a palindrome? " 
              << (TwoPointerAlgorithms::isPalindrome(palindrome1) ? "Yes" : "No") << "\n";
    
    std::string palindrome2 = "hello";
    std::cout << "Is \"" << palindrome2 << "\" a palindrome? " 
              << (TwoPointerAlgorithms::isPalindrome(palindrome2) ? "Yes" : "No") << "\n";
    
    std::string palindrome3 = "a";
    std::cout << "Is \"" << palindrome3 << "\" a palindrome? " 
              << (TwoPointerAlgorithms::isPalindrome(palindrome3) ? "Yes" : "No") << "\n\n";
    
    // Demo 3: Remove Duplicates
    std::cout << "3. Remove Duplicates Algorithm\n";
    std::cout << "------------------------------\n";
    std::vector<int> arr1 = {1, 1, 2, 2, 3, 4, 4, 5};
    std::cout << "Original array: ";
    printVector(arr1);
    std::cout << "\n";
    int newLength1 = TwoPointerAlgorithms::removeDuplicates(arr1);
    std::cout << "After removing duplicates (first " << newLength1 << " elements): ";
    printVector(arr1);
    std::cout << "\n\n";
    
    std::vector<int> arr2 = {1, 2, 3, 4, 5};
    std::cout << "Original array (no duplicates): ";
    printVector(arr2);
    std::cout << "\n";
    int newLength2 = TwoPointerAlgorithms::removeDuplicates(arr2);
    std::cout << "After removing duplicates (first " << newLength2 << " elements): ";
    printVector(arr2);
    std::cout << "\n\n";
    
    // Demo 4: Merge Sorted Arrays
    std::cout << "4. Merge Sorted Arrays Algorithm\n";
    std::cout << "---------------------------------\n";
    std::vector<int> merge1 = {1, 3, 5, 7};
    std::vector<int> merge2 = {2, 4, 6, 8};
    std::cout << "Array 1: ";
    printVector(merge1);
    std::cout << "\n";
    std::cout << "Array 2: ";
    printVector(merge2);
    std::cout << "\n";
    std::vector<int> merged = TwoPointerAlgorithms::mergeSortedArrays(merge1, merge2);
    std::cout << "Merged: ";
    printVector(merged);
    std::cout << "\n\n";
    
    std::vector<int> merge3 = {1, 2, 3};
    std::vector<int> merge4 = {4, 5, 6, 7, 8};
    std::cout << "Array 1: ";
    printVector(merge3);
    std::cout << "\n";
    std::cout << "Array 2: ";
    printVector(merge4);
    std::cout << "\n";
    std::vector<int> merged2 = TwoPointerAlgorithms::mergeSortedArrays(merge3, merge4);
    std::cout << "Merged: ";
    printVector(merged2);
    std::cout << "\n\n";
    
    std::cout << "========================================\n";
    std::cout << "Demo completed successfully!\n";
    std::cout << "========================================\n";
    
    return 0;
}
