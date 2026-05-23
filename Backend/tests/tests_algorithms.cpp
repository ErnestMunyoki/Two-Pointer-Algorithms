#include "ReversingString.hpp"
#include "PalindromeChecker.hpp"
#include "RemoveDuplicate.hpp"
#include "MergeSortedArrays.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

// Test counters
int testsPassed = 0;
int testsFailed = 0;

void testReverseString() {
    std::cout << "\n=== Testing Reverse String ===\n";
    
    // Normal cases
    {
        std::string str = "hello";
        TwoPointerAlgorithms::reverseString(str);
        assert(str == "olleh");
        testsPassed++;
        std::cout << "✓ Normal case: 'hello' -> 'olleh'\n";
    }
    
    {
        std::string str = "world";
        TwoPointerAlgorithms::reverseString(str);
        assert(str == "dlrow");
        testsPassed++;
        std::cout << "✓ Normal case: 'world' -> 'dlrow'\n";
    }
    
    // Edge cases
    {
        std::string str = "";
        TwoPointerAlgorithms::reverseString(str);
        assert(str == "");
        testsPassed++;
        std::cout << "✓ Edge case: empty string\n";
    }
    
    {
        std::string str = "a";
        TwoPointerAlgorithms::reverseString(str);
        assert(str == "a");
        testsPassed++;
        std::cout << "✓ Edge case: single character\n";
    }
    
    {
        std::string str = "ab";
        TwoPointerAlgorithms::reverseString(str);
        assert(str == "ba");
        testsPassed++;
        std::cout << "✓ Edge case: two characters\n";
    }
    
    // Stress test - very long string
    {
        std::string str(10000, 'x');
        for (int i = 0; i < 10000; i++) {
            str[i] = 'a' + (i % 26);
        }
        std::string original = str;
        TwoPointerAlgorithms::reverseString(str);
        std::reverse(original.begin(), original.end());
        assert(str == original);
        testsPassed++;
        std::cout << "✓ Stress test: 10,000 character string\n";
    }
}

void testPalindromeChecker() {
    std::cout << "\n=== Testing Palindrome Checker ===\n";
    
    // Normal cases
    {
        assert(TwoPointerAlgorithms::isPalindrome("racecar") == true);
        testsPassed++;
        std::cout << "✓ Normal case: 'racecar' is palindrome\n";
    }
    
    {
        assert(TwoPointerAlgorithms::isPalindrome("hello") == false);
        testsPassed++;
        std::cout << "✓ Normal case: 'hello' is not palindrome\n";
    }
    
    {
        assert(TwoPointerAlgorithms::isPalindrome("madam") == true);
        testsPassed++;
        std::cout << "✓ Normal case: 'madam' is palindrome\n";
    }
    
    // Edge cases
    {
        assert(TwoPointerAlgorithms::isPalindrome("") == true);
        testsPassed++;
        std::cout << "✓ Edge case: empty string is palindrome\n";
    }
    
    {
        assert(TwoPointerAlgorithms::isPalindrome("a") == true);
        testsPassed++;
        std::cout << "✓ Edge case: single character is palindrome\n";
    }
    
    {
        assert(TwoPointerAlgorithms::isPalindrome("ab") == false);
        testsPassed++;
        std::cout << "✓ Edge case: two different characters\n";
    }
    
    {
        assert(TwoPointerAlgorithms::isPalindrome("aa") == true);
        testsPassed++;
        std::cout << "✓ Edge case: two same characters\n";
    }
    
    // Stress test - very long palindrome
    {
        std::string str(10000, 'a');
        assert(TwoPointerAlgorithms::isPalindrome(str) == true);
        testsPassed++;
        std::cout << "✓ Stress test: 10,000 character palindrome\n";
    }
    
    // Stress test - very long non-palindrome
    {
        std::string str(10000, 'a');
        str[5000] = 'b';
        assert(TwoPointerAlgorithms::isPalindrome(str) == false);
        testsPassed++;
        std::cout << "✓ Stress test: 10,000 character non-palindrome\n";
    }
}

void testRemoveDuplicates() {
    std::cout << "\n=== Testing Remove Duplicates ===\n";
    
    // Normal cases
    {
        std::vector<int> arr = {1, 1, 2, 2, 3, 4, 4, 5};
        int newLength = TwoPointerAlgorithms::removeDuplicates(arr);
        assert(newLength == 5);
        assert(arr[0] == 1 && arr[1] == 2 && arr[2] == 3 && arr[3] == 4 && arr[4] == 5);
        testsPassed++;
        std::cout << "✓ Normal case: {1,1,2,2,3,4,4,5} -> length 5\n";
    }
    
    {
        std::vector<int> arr = {1, 2, 3, 4, 5};
        int newLength = TwoPointerAlgorithms::removeDuplicates(arr);
        assert(newLength == 5);
        testsPassed++;
        std::cout << "✓ Normal case: no duplicates\n";
    }
    
    {
        std::vector<int> arr = {1, 1, 1, 1, 1};
        int newLength = TwoPointerAlgorithms::removeDuplicates(arr);
        assert(newLength == 1);
        assert(arr[0] == 1);
        testsPassed++;
        std::cout << "✓ Normal case: all duplicates\n";
    }
    
    // Edge cases
    {
        std::vector<int> arr = {};
        int newLength = TwoPointerAlgorithms::removeDuplicates(arr);
        assert(newLength == 0);
        testsPassed++;
        std::cout << "✓ Edge case: empty array\n";
    }
    
    {
        std::vector<int> arr = {5};
        int newLength = TwoPointerAlgorithms::removeDuplicates(arr);
        assert(newLength == 1);
        assert(arr[0] == 5);
        testsPassed++;
        std::cout << "✓ Edge case: single element\n";
    }
    
    {
        std::vector<int> arr = {1, 2};
        int newLength = TwoPointerAlgorithms::removeDuplicates(arr);
        assert(newLength == 2);
        testsPassed++;
        std::cout << "✓ Edge case: two different elements\n";
    }
    
    // Stress test - very large array
    {
        std::vector<int> arr(10000);
        for (int i = 0; i < 10000; i++) {
            arr[i] = i / 10;  // Create duplicates
        }
        int newLength = TwoPointerAlgorithms::removeDuplicates(arr);
        assert(newLength == 1000);  // 10000/10 = 1000 unique values
        testsPassed++;
        std::cout << "✓ Stress test: 10,000 element array with duplicates\n";
    }
}

void testMergeSortedArrays() {
    std::cout << "\n=== Testing Merge Sorted Arrays ===\n";
    
    // Normal cases
    {
        std::vector<int> arr1 = {1, 3, 5, 7};
        std::vector<int> arr2 = {2, 4, 6, 8};
        std::vector<int> result = TwoPointerAlgorithms::mergeSortedArrays(arr1, arr2);
        std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8};
        assert(result == expected);
        testsPassed++;
        std::cout << "✓ Normal case: merge {1,3,5,7} and {2,4,6,8}\n";
    }
    
    {
        std::vector<int> arr1 = {1, 2, 3};
        std::vector<int> arr2 = {4, 5, 6};
        std::vector<int> result = TwoPointerAlgorithms::mergeSortedArrays(arr1, arr2);
        std::vector<int> expected = {1, 2, 3, 4, 5, 6};
        assert(result == expected);
        testsPassed++;
        std::cout << "✓ Normal case: non-overlapping ranges\n";
    }
    
    {
        std::vector<int> arr1 = {1, 1, 2};
        std::vector<int> arr2 = {1, 2, 2};
        std::vector<int> result = TwoPointerAlgorithms::mergeSortedArrays(arr1, arr2);
        std::vector<int> expected = {1, 1, 1, 2, 2, 2};
        assert(result == expected);
        testsPassed++;
        std::cout << "✓ Normal case: arrays with duplicates\n";
    }
    
    // Edge cases
    {
        std::vector<int> arr1 = {};
        std::vector<int> arr2 = {};
        std::vector<int> result = TwoPointerAlgorithms::mergeSortedArrays(arr1, arr2);
        assert(result.empty());
        testsPassed++;
        std::cout << "✓ Edge case: both arrays empty\n";
    }
    
    {
        std::vector<int> arr1 = {1, 2, 3};
        std::vector<int> arr2 = {};
        std::vector<int> result = TwoPointerAlgorithms::mergeSortedArrays(arr1, arr2);
        assert(result == arr1);
        testsPassed++;
        std::cout << "✓ Edge case: one array empty\n";
    }
    
    {
        std::vector<int> arr1 = {};
        std::vector<int> arr2 = {4, 5, 6};
        std::vector<int> result = TwoPointerAlgorithms::mergeSortedArrays(arr1, arr2);
        assert(result == arr2);
        testsPassed++;
        std::cout << "✓ Edge case: other array empty\n";
    }
    
    {
        std::vector<int> arr1 = {5};
        std::vector<int> arr2 = {3};
        std::vector<int> result = TwoPointerAlgorithms::mergeSortedArrays(arr1, arr2);
        std::vector<int> expected = {3, 5};
        assert(result == expected);
        testsPassed++;
        std::cout << "✓ Edge case: single element arrays\n";
    }
    
    // Stress test - very large arrays
    {
        std::vector<int> arr1(5000);
        std::vector<int> arr2(5000);
        for (int i = 0; i < 5000; i++) {
            arr1[i] = i * 2;
            arr2[i] = i * 2 + 1;
        }
        std::vector<int> result = TwoPointerAlgorithms::mergeSortedArrays(arr1, arr2);
        assert(result.size() == 10000);
        for (int i = 0; i < 10000; i++) {
            assert(result[i] == i);
        }
        testsPassed++;
        std::cout << "✓ Stress test: merge two 5,000 element arrays\n";
    }
}

int main() {
    std::cout << "========================================\n";
    std::cout << "Two-Pointer Algorithms Unit Tests\n";
    std::cout << "========================================\n";
    
    testReverseString();
    testPalindromeChecker();
    testRemoveDuplicates();
    testMergeSortedArrays();
    
    std::cout << "\n========================================\n";
    std::cout << "Test Results:\n";
    std::cout << "Passed: " << testsPassed << "\n";
    std::cout << "Failed: " << testsFailed << "\n";
    std::cout << "========================================\n";
    
    if (testsFailed > 0) {
        std::cout << "FAILED: Some tests did not pass.\n";
        return 1;
    } else {
        std::cout << "SUCCESS: All tests passed!\n";
        return 0;
    }
}
