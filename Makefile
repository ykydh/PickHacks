# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Executable name
TARGET = lander_game

# Source and object files (DO NOT include .h files)
SRCS = main.cpp Lander.cpp LandScape.cpp Ground.cpp
OBJS = $(SRCS:.cpp=.o)

# Default rule: build the executable
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)
