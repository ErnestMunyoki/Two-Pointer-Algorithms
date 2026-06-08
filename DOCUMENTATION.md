# Two-Pointer Algorithms Project Documentation

## Project Overview

The Two-Pointer Algorithms project is a comprehensive C++ library that implements and demonstrates fundamental algorithmic techniques using the two-pointer approach. This project provides efficient solutions to common computational problems by leveraging the power of simultaneous traversal with two pointers, offering optimal time and space complexity for various scenarios.

The two-pointer technique is a powerful algorithmic strategy where two pointers traverse through a data structure (typically arrays, strings, or linked lists) simultaneously. This approach is particularly effective for problems involving sorted data, searching pairs, or comparing elements from different ends of a structure. By moving pointers strategically, we can often achieve O(n) time complexity where nested loops would result in O(n²) complexity.

## Project Structure

The project is organized into a backend C++ library with supporting demonstration and command-line interface applications:

```
Two-Pointer-Algorithms/
├── Backend/
│   ├── include/           # Header files for algorithm implementations
│   │   ├── MergeSortedArrays.hpp
│   │   ├── PalindromeChecker.hpp
│   │   ├── RemoveDuplicate.hpp
│   │   ├── ReversingString.hpp
│   │   └── TwoPointerAlgorithms.hpp
│   ├── src/               # Implementation files
│   │   ├── MergeSortedArrays.cpp
│   │   ├── PalindromeChecker.cpp
│   │   ├── RemoveDuplicates.cpp
│   │   ├── ReverseString.cpp
│   │   ├── TwoPointerAlgorithms.cpp
│   │   ├── cli.cpp        # Command-line interface
│   │   └── demo.cpp       # Demonstration program
│   ├── tests/             # Unit tests
│   ├── benchmark/         # Performance benchmarks
│   └── build/             # Build artifacts
└── Frontend/              # Frontend application
```

## Implemented Algorithms

### 1. String Reversal

**Function:** `reverseString(std::string& str)`

**Description:** Reverses a string in place using the two-pointer technique. One pointer starts at the beginning of the string while the other starts at the end. The pointers move toward each other, swapping characters until they meet in the middle.

**Time Complexity:** O(n) where n is the length of the string
**Space Complexity:** O(1) - in-place modification

**Algorithm Steps:**
1. Initialize left pointer at index 0 and right pointer at the last index
2. While left pointer is less than right pointer:
   - Swap characters at left and right positions
   - Increment left pointer
   - Decrement right pointer
3. Return the modified string

**Example Usage:**
```cpp
std::string str = "hello";
TwoPointerAlgorithms::reverseString(str);
// str is now "olleh"
```

### 2. Palindrome Checker

**Function:** `isPalindrome(const std::string& str)`

**Description:** Determines whether a string reads the same forwards and backwards using two pointers that start from opposite ends and move toward the center, comparing characters at each step.

**Time Complexity:** O(n) where n is the length of the string
**Space Complexity:** O(1)

**Algorithm Steps:**
1. Initialize left pointer at index 0 and right pointer at the last index
2. While left pointer is less than right pointer:
   - If characters at left and right positions differ, return false
   - Increment left pointer
   - Decrement right pointer
3. If all character pairs match, return true

**Example Usage:**
```cpp
bool result = TwoPointerAlgorithms::isPalindrome("racecar");
// result is true

bool result = TwoPointerAlgorithms::isPalindrome("hello");
// result is false
```

### 3. Remove Duplicates from Sorted Array

**Function:** `removeDuplicates(std::vector<int>& arr)`

**Description:** Removes duplicate elements from a sorted array in place, modifying the original array and returning the new length of the array containing only unique elements. Uses a slow pointer to track the position of the last unique element and a fast pointer to scan through the array.

**Time Complexity:** O(n) where n is the length of the array
**Space Complexity:** O(1) - in-place modification

**Algorithm Steps:**
1. If array is empty, return 0
2. Initialize slow pointer at index 0
3. Iterate with fast pointer from index 1 to end:
   - If element at fast pointer differs from element at slow pointer:
     - Increment slow pointer
     - Copy element from fast to slow position
4. Return slow + 1 (new length of unique elements)

**Example Usage:**
```cpp
std::vector<int> arr = {1, 1, 2, 2, 3, 4, 4, 5};
int newLength = TwoPointerAlgorithms::removeDuplicates(arr);
// arr is now {1, 2, 3, 4, 5, ...} with newLength = 5
```

### 4. Merge Two Sorted Arrays

**Function:** `mergeSortedArrays(const std::vector<int>& arr1, const std::vector<int>& arr2)`

**Description:** Merges two sorted arrays into a single sorted array using two pointers, one for each input array. The algorithm compares elements at both pointers and places the smaller element in the result array, then advances the corresponding pointer.

**Time Complexity:** O(n + m) where n and m are the lengths of the input arrays
**Space Complexity:** O(n + m) for the result array

**Algorithm Steps:**
1. Initialize pointer i for arr1 at index 0 and pointer j for arr2 at index 0
2. While both pointers are within their array bounds:
   - Compare arr1[i] and arr2[j]
   - Add the smaller element to result array
   - Advance the pointer of the array from which the element was taken
3. Add any remaining elements from arr1 (if any)
4. Add any remaining elements from arr2 (if any)
5. Return the merged result array

**Example Usage:**
```cpp
std::vector<int> arr1 = {1, 3, 5, 7};
std::vector<int> arr2 = {2, 4, 6, 8};
std::vector<int> merged = TwoPointerAlgorithms::mergeSortedArrays(arr1, arr2);
// merged is {1, 2, 3, 4, 5, 6, 7, 8}
```

## Building the Project

The project uses a Makefile-based build system. To build the project:

```bash
cd Backend
make
```

This will compile the library and create executable files for the demo and CLI applications.

To clean build artifacts:
```bash
make clean
```

## Running the Applications

### Demo Application

The demo application (`demo.cpp`) provides automated demonstrations of all implemented algorithms with predefined test cases:

```bash
./demo
```

The demo will display:
- String reversal examples
- Palindrome checking with various test strings
- Duplicate removal from sorted arrays
- Merging of sorted arrays

### Command-Line Interface

The CLI application (`cli.cpp`) provides an interactive menu-driven interface to test each algorithm with custom input:

```bash
./cli
```

Available options:
1. Reverse a String - Enter any string to see it reversed
2. Check Palindrome - Enter a string to check if it's a palindrome
3. Remove Duplicates from Sorted Array - Enter a comma-separated sorted array
4. Merge Two Sorted Arrays - Enter two comma-separated sorted arrays
5. Exit - Terminate the application

## Technical Details

### Namespace Organization

All algorithms are organized under the `TwoPointerAlgorithms` namespace to prevent naming conflicts and provide clear API boundaries.

### Header Files

Each algorithm has its own header file in the `include/` directory:
- `ReversingString.hpp` - String reversal functionality
- `PalindromeChecker.hpp` - Palindrome checking functionality
- `RemoveDuplicate.hpp` - Duplicate removal functionality
- `MergeSortedArrays.hpp` - Array merging functionality
- `TwoPointerAlgorithms.hpp` - Unified header including all algorithm headers

### Implementation Files

Corresponding implementation files in the `src/` directory contain the actual algorithm logic.

### Error Handling

The CLI application includes basic error handling for invalid input, particularly in the vector parsing function which skips invalid tokens when parsing comma-separated input.

## Performance Characteristics

All algorithms in this library are designed for optimal performance:

- **String Reversal:** Single pass through the string
- **Palindrome Checker:** Single pass through half the string
- **Remove Duplicates:** Single pass through the array
- **Merge Sorted Arrays:** Single pass through both arrays combined

The two-pointer technique consistently provides O(n) time complexity for these problems, making them highly efficient for large datasets.

## Use Cases

These algorithms are fundamental building blocks for many applications:

- **String Reversal:** Text processing, palindrome generation, data transformation
- **Palindrome Checker:** String validation, puzzle solving, data integrity checks
- **Remove Duplicates:** Data cleaning, preprocessing for other algorithms, memory optimization
- **Merge Sorted Arrays:** Database operations, sorting algorithms, data stream processing

## Future Enhancements

Potential areas for expansion:
- Additional two-pointer algorithms (e.g., finding pairs with specific sums, container with most water)
- Support for different data types (templates)
- Enhanced error handling and validation
- Performance optimization and benchmarking tools
- Integration with other algorithm libraries

## Conclusion

The Two-Pointer Algorithms project demonstrates the elegance and efficiency of the two-pointer technique in solving common computational problems. By providing clean, well-organized implementations with both demonstration and interactive interfaces, this project serves as both a practical library and an educational resource for understanding fundamental algorithmic patterns.

The modular design allows for easy integration into larger projects and extension with additional algorithms, making it a valuable tool for developers working with data processing and algorithmic challenges.
