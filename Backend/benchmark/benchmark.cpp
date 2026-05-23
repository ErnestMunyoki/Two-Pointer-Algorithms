#include "ReversingString.hpp"
#include "PalindromeChecker.hpp"
#include "RemoveDuplicate.hpp"
#include "MergeSortedArrays.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <fstream>

using namespace std::chrono;

// Function to generate a random string of given length
std::string generateRandomString(int length) {
    std::string str;
    str.reserve(length);
    for (int i = 0; i < length; i++) {
        str += 'a' + (rand() % 26);
    }
    return str;
}

// Function to generate a sorted array with duplicates
std::vector<int> generateSortedArrayWithDuplicates(int size) {
    std::vector<int> arr;
    arr.reserve(size);
    for (int i = 0; i < size; i++) {
        arr.push_back(i / 10);  // Create duplicates
    }
    return arr;
}

// Function to generate a sorted array
std::vector<int> generateSortedArray(int size) {
    std::vector<int> arr;
    arr.reserve(size);
    for (int i = 0; i < size; i++) {
        arr.push_back(i);
    }
    return arr;
}

void benchmarkReverseString(int size, std::ofstream& outfile) {
    std::string str = generateRandomString(size);
    
    auto start = high_resolution_clock::now();
    TwoPointerAlgorithms::reverseString(str);
    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(stop - start);
    
    std::cout << "Reverse String (n=" << size << "): " << duration.count() << " microseconds\n";
    outfile << "Reverse String," << size << "," << duration.count() << "\n";
}

void benchmarkPalindromeChecker(int size, std::ofstream& outfile) {
    std::string str = generateRandomString(size);
    
    auto start = high_resolution_clock::now();
    TwoPointerAlgorithms::isPalindrome(str);
    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(stop - start);
    
    std::cout << "Palindrome Checker (n=" << size << "): " << duration.count() << " microseconds\n";
    outfile << "Palindrome Checker," << size << "," << duration.count() << "\n";
}

void benchmarkRemoveDuplicates(int size, std::ofstream& outfile) {
    std::vector<int> arr = generateSortedArrayWithDuplicates(size);
    
    auto start = high_resolution_clock::now();
    TwoPointerAlgorithms::removeDuplicates(arr);
    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(stop - start);
    
    std::cout << "Remove Duplicates (n=" << size << "): " << duration.count() << " microseconds\n";
    outfile << "Remove Duplicates," << size << "," << duration.count() << "\n";
}

void benchmarkMergeSortedArrays(int size, std::ofstream& outfile) {
    std::vector<int> arr1 = generateSortedArray(size);
    std::vector<int> arr2 = generateSortedArray(size);
    
    auto start = high_resolution_clock::now();
    TwoPointerAlgorithms::mergeSortedArrays(arr1, arr2);
    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(stop - start);
    
    std::cout << "Merge Sorted Arrays (n=" << size << " each): " << duration.count() << " microseconds\n";
    outfile << "Merge Sorted Arrays," << size << "," << duration.count() << "\n";
}

int main() {
    srand(time(nullptr));
    
    std::cout << "========================================\n";
    std::cout << "Two-Pointer Algorithms Benchmark\n";
    std::cout << "========================================\n\n";
    
    std::ofstream outfile("../report/timing_results.txt");
    if (!outfile.is_open()) {
        std::cerr << "Error: Could not open timing_results.txt for writing\n";
        return 1;
    }
    
    outfile << "Algorithm,Input Size,Time (microseconds)\n";
    
    // Test with three different input sizes
    std::vector<int> sizes = {1000, 10000, 100000};
    
    for (int size : sizes) {
        std::cout << "\n--- Benchmarking with input size: " << size << " ---\n";
        
        benchmarkReverseString(size, outfile);
        benchmarkPalindromeChecker(size, outfile);
        benchmarkRemoveDuplicates(size, outfile);
        benchmarkMergeSortedArrays(size, outfile);
    }
    
    outfile.close();
    
    std::cout << "\n========================================\n";
    std::cout << "Benchmark completed!\n";
    std::cout << "Results saved to ../report/timing_results.txt\n";
    std::cout << "========================================\n";
    
    return 0;
}
