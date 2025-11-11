# ===========================
# Makefile for Test Runner
# ===========================

CXX := g++
CXXFLAGS := -g -std=c++17 -Iinclude -Isrc
SRC := src/main.cpp
TARGET := main

# Default target
all: $(TARGET)

# Compile target
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Run default (no argument) or specific test
run: $(TARGET)
ifeq ($(TEST),)
	@echo "▶ Running default test (no TEST index specified)..."
	./$(TARGET)
else
	@echo "▶ Running test case index $(TEST)..."
	./$(TARGET) $(TEST)
endif

# Clean build files
clean:
	rm -f $(TARGET)
	rm -f *.o

.PHONY: all run clean
