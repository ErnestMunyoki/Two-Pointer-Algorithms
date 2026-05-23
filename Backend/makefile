# Makefile for Two-Pointer Algorithms Library

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
INCLUDE_DIR = include
SRC_DIR = src
TEST_DIR = tests
BENCHMARK_DIR = benchmark
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

# Source files
SRCS = $(SRC_DIR)/ReverseString.cpp \
       $(SRC_DIR)/PalindromeChecker.cpp \
       $(SRC_DIR)/RemoveDuplicates.cpp \
       $(SRC_DIR)/MergeSortedArrays.cpp \
       $(SRC_DIR)/TwoPointerAlgorithms.cpp

# Object files
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Executables
DEMO_EXEC = $(BUILD_DIR)/demo
TEST_EXEC = $(BUILD_DIR)/tests
BENCHMARK_EXEC = $(BUILD_DIR)/benchmark
CLI_EXEC = $(BUILD_DIR)/cli

# Default target
all: directories $(DEMO_EXEC) $(TEST_EXEC) $(BENCHMARK_EXEC) $(CLI_EXEC)

# Create necessary directories
directories:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BUILD_DIR)

# Compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Build demo executable
$(DEMO_EXEC): $(OBJS) $(SRC_DIR)/demo.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) $(OBJS) $(SRC_DIR)/demo.cpp -o $@

# Build test executable
$(TEST_EXEC): $(OBJS) $(TEST_DIR)/tests_algorithms.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) $(OBJS) $(TEST_DIR)/tests_algorithms.cpp -o $@

# Build benchmark executable
$(BENCHMARK_EXEC): $(OBJS) $(BENCHMARK_DIR)/benchmark.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) $(OBJS) $(BENCHMARK_DIR)/benchmark.cpp -o $@

# Build CLI executable
$(CLI_EXEC): $(OBJS) $(SRC_DIR)/cli.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) $(OBJS) $(SRC_DIR)/cli.cpp -o $@

# Run demo
demo: $(DEMO_EXEC)
	./$(DEMO_EXEC)

# Run tests
test: $(TEST_EXEC)
	./$(TEST_EXEC)

# Run benchmark
benchmark: $(BENCHMARK_EXEC)
	./$(BENCHMARK_EXEC)

# Run CLI
cli: $(CLI_EXEC)
	./$(CLI_EXEC)

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

# Clean everything including benchmark results
distclean: clean
	rm -f ../report/timing_results.txt

.PHONY: all directories demo test benchmark cli clean distclean
