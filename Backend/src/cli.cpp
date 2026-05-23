#include "TwoPointerAlgorithms.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

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

std::vector<int> parseVector(const std::string& input) {
    std::vector<int> result;
    std::stringstream ss(input);
    std::string token;
    
    while (std::getline(ss, token, ',')) {
        try {
            result.push_back(std::stoi(token));
        } catch (...) {
            // Skip invalid tokens
        }
    }
    
    return result;
}

void showMenu() {
    std::cout << "\n========================================\n";
    std::cout << "Two-Pointer Algorithms CLI\n";
    std::cout << "========================================\n";
    std::cout << "1. Reverse a String\n";
    std::cout << "2. Check Palindrome\n";
    std::cout << "3. Remove Duplicates from Sorted Array\n";
    std::cout << "4. Merge Two Sorted Arrays\n";
    std::cout << "5. Exit\n";
    std::cout << "========================================\n";
    std::cout << "Enter your choice (1-5): ";
}

int main() {
    int choice;
    
    while (true) {
        showMenu();
        std::cin >> choice;
        std::cin.ignore(); // Clear newline
        
        if (choice == 5) {
            std::cout << "Goodbye!\n";
            break;
        }
        
        switch (choice) {
            case 1: {
                std::string str;
                std::cout << "Enter string to reverse: ";
                std::getline(std::cin, str);
                std::string original = str;
                TwoPointerAlgorithms::reverseString(str);
                std::cout << "Original: \"" << original << "\"\n";
                std::cout << "Reversed: \"" << str << "\"\n";
                break;
            }
            case 2: {
                std::string str;
                std::cout << "Enter string to check: ";
                std::getline(std::cin, str);
                bool result = TwoPointerAlgorithms::isPalindrome(str);
                std::cout << "\"" << str << "\" is " 
                          << (result ? "a palindrome" : "NOT a palindrome") << "\n";
                break;
            }
            case 3: {
                std::string input;
                std::cout << "Enter sorted array (comma-separated, e.g., 1,1,2,2,3): ";
                std::getline(std::cin, input);
                std::vector<int> arr = parseVector(input);
                std::cout << "Original array: ";
                printVector(arr);
                std::cout << "\n";
                int newLength = TwoPointerAlgorithms::removeDuplicates(arr);
                std::cout << "After removing duplicates (first " << newLength << " elements): ";
                printVector(arr);
                std::cout << "\n";
                break;
            }
            case 4: {
                std::string input1, input2;
                std::cout << "Enter first sorted array (comma-separated): ";
                std::getline(std::cin, input1);
                std::cout << "Enter second sorted array (comma-separated): ";
                std::getline(std::cin, input2);
                std::vector<int> arr1 = parseVector(input1);
                std::vector<int> arr2 = parseVector(input2);
                std::cout << "Array 1: ";
                printVector(arr1);
                std::cout << "\n";
                std::cout << "Array 2: ";
                printVector(arr2);
                std::cout << "\n";
                std::vector<int> merged = TwoPointerAlgorithms::mergeSortedArrays(arr1, arr2);
                std::cout << "Merged: ";
                printVector(merged);
                std::cout << "\n";
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
        
        std::cout << "\nPress Enter to continue...";
        std::cin.ignore();
    }
    
    return 0;
}
