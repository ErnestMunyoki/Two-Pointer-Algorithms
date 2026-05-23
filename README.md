# Two-Pointer Algorithms Library

A complete implementation of efficient algorithms using the two-pointer technique, featuring both a C++ backend and a modern web frontend.

## Overview

This project provides clean, well-tested implementations of four classic algorithms that utilize the two-pointer technique:

1. **String Reversal** - Reverse a string in place
2. **Palindrome Checker** - Determine if a string is a palindrome
3. **Remove Duplicates** - Remove duplicates from a sorted array
4. **Merge Sorted Arrays** - Merge two sorted arrays into one

## Project Components

### Backend (C++)
- Clean C++11 implementation from scratch
- Comprehensive unit tests (30 tests, all passing)
- Performance benchmark with timing measurements
- Interactive CLI for easy algorithm testing
- Technical report with complexity analysis

### Frontend (Web)
- Modern, responsive web interface
- Interactive algorithm demonstrations
- Beautiful gradient UI with animations
- Real-time feedback and results
- No dependencies required

## Project Structure

```
Two-Pointer-Algorithms/
├── Backend/
│   ├── include/           # Header files
│   │   ├── ReversingString.hpp
│   │   ├── PalindromeChecker.hpp
│   │   ├── RemoveDuplicate.hpp
│   │   ├── MergeSortedArrays.hpp
│   │   └── TwoPointerAlgorithms.hpp  # Unified header
│   ├── src/               # Source files
│   │   ├── ReverseString.cpp
│   │   ├── PalindromeChecker.cpp
│   │   ├── RemoveDuplicates.cpp
│   │   ├── MergeSortedArrays.cpp
│   │   ├── TwoPointerAlgorithms.cpp
│   │   ├── demo.cpp       # Demo application
│   │   └── cli.cpp        # Interactive CLI
│   ├── tests/             # Unit tests
│   │   └── tests_algorithms.cpp
│   ├── benchmark/         # Performance benchmark
│   │   └── benchmark.cpp
│   ├── build/             # Build output directory
│   └── makefile           # Build configuration
├── Frontend/
│   ├── index.html         # Web interface
│   └── README.md          # Frontend documentation
├── report/                # Technical report and timing results
│   ├── report.md
│   └── timing_results.txt
└── README.md
```

## Requirements

- C++11 compatible compiler (g++ recommended)
- Make build system
- Standard C++ library

## Building the Project

Navigate to the Backend directory and use the provided makefile:

```bash
cd Backend
make -f makefile
```

This will compile all source files and create three executables in the `build/` directory:
- `demo` - Command-line demo application
- `tests` - Unit test suite
- `benchmark` - Performance benchmark

## Running the Programs

### Demo Application

Run the demo to see all algorithms in action with example inputs:

```bash
make -f makefile demo
```

Or directly:

```bash
./build/demo
```

### Unit Tests

Run the comprehensive test suite covering normal cases, edge cases, and stress tests:

```bash
make -f makefile test
```

Or directly:

```bash
./build/tests
```

Expected output: All tests should pass with a success message.

### Performance Benchmark

Run the benchmark to measure execution times across different input sizes:

```bash
make -f makefile benchmark
```

Or directly:

```bash
./build/benchmark
```

The results will be saved to `../report/timing_results.txt` in CSV format.

### Interactive CLI

Use the interactive command-line interface for easy algorithm testing:

```bash
make -f makefile cli
```

Or directly:

```bash
./build/cli
```

This provides a menu-driven interface to interactively test all algorithms.

## Running the Frontend

The web frontend is a standalone HTML file that can be opened directly in any browser:

```bash
cd Frontend
# Simply open index.html in your browser
# Or use a local server:
python -m http.server 8000
# Then visit http://localhost:8000
```

The frontend provides:
- Interactive algorithm demonstrations
- Beautiful modern UI with animations
- Real-time feedback and results
- No installation required

## Cleaning Build Artifacts

To remove all build files:

```bash
make -f makefile clean
```

To remove build files and benchmark results:

```bash
make -f makefile distclean
```

## Algorithm Details

### Reverse String
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)
- **Description**: Uses two pointers at opposite ends of the string, swapping characters as they move toward the center.

### Palindrome Checker
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)
- **Description**: Compares characters from both ends moving inward, returning false on first mismatch.

### Remove Duplicates
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)
- **Description**: Uses slow and fast pointers to track unique elements in a sorted array.

### Merge Sorted Arrays
- **Time Complexity**: O(n + m)
- **Space Complexity**: O(n + m)
- **Description**: Uses two pointers to traverse both arrays simultaneously, merging them in sorted order.

## Test Coverage

The test suite includes:

- **Normal Cases**: Typical inputs representing common use cases
- **Edge Cases**: Empty inputs, single elements, two elements, no duplicates, all duplicates
- **Stress Tests**: Large inputs (10,000+ elements) to verify scalability

## Documentation

For detailed complexity analysis, pseudocode, and empirical results, see `report/report.md`.

## License

This project is provided for educational purposes.
