TARGET     := programa
CXX        := g++
BUILD_DIR  := ./bin
SOURCE_DIR := ./src
SRCS       := $(shell find $(SOURCE_DIR) -name '*.cpp')
OBJS       := $(SRCS:%=$(BUILD_DIR)/%.o)


.PHONY: all
all: $(BUILD_DIR)/$(TARGET) 

$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CXX) $? -o $@ && ./$(BUILD_DIR)/$(TARGET) 

$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) -c $? -o $@

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)/$(TARGET) $(BUILD_DIR)/$(SOURCE_DIR)


