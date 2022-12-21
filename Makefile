TARGET      := pdg
INCLUDE_DIR := ./include
BUILD_DIR   := ./bin
SOURCE_DIR  := ./src
CXX         := g++
CXXFLAGS    := -Wall -I$(INCLUDE_DIR) 
SRCS        := $(shell find $(SOURCE_DIR) -name '*.cpp')
OBJS        := $(SRCS:%=$(BUILD_DIR)/%.o)


all: $(BUILD_DIR)/$(TARGET) 

$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $? -o $@ && ./$(BUILD_DIR)/$(TARGET) 

$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $? -o $@

clean:
	rm -rf $(BUILD_DIR)/$(TARGET) $(BUILD_DIR)/$(SOURCE_DIR)

.PHONY: all clean
