# Makefile for Final Project

# Compiler settings - Can change to clang++ if preferred
CXX=g++
CXXFLAGS=-std=gnu++11

# Files
SOURCES=fb_trade_driver.cpp football_DList.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=TradeDLL

# Default target
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# To obtain object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

.PHONY: all clean
