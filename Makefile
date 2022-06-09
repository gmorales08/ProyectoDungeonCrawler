TARGET := programa
CXX   := g++
BUILD_DIR := ./bin
SOURCE_DIR := ./src
SRCS   := $(shell find $(SOURCE_DIR) -name '*.cpp')
OBJS   := $(SRCS:%=$(BUILD_DIR)/%.o)


all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CXX) $? -o $@ && ./$(BUILD_DIR)/$(TARGET) 

$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) -c $? -o $@

clean:
	rm -rf $(BUILD_DIR)/$(TARGET) $(BUILD_DIR)/$(SOURCE_DIR)


