PROGRAM     := pdg
PROGRAM_EXE := pdg.exe
BUILD_DIR   := bin
INCLUDE_DIR := include 
SOURCE_DIR  := src
OBJ_DIR     := obj

SRCS        := $(shell find $(SOURCE_DIR) -type f -name *.cpp)
SUBDIRS     := $(shell find $(SOURCE_DIR) -type d)
OBJS        := $(patsubst $(SOURCE_DIR)%,$(OBJ_DIR)%, \
		          $(patsubst %.cpp,%.o,$(SRCS)))
OBJSUBDIRS  := $(patsubst $(SOURCE_DIR)%,$(OBJ_DIR)%,$(SUBDIRS))

CC          := g++
CCFLAGS     := -Wall
MINGW       := x86_64-w64-mingw32-g++-posix
MINGWFLAGS  := -static #-static-libgcc -static-libstdc++


all : elf run_elf

elf : $(PROGRAM)

run_elf :
	./$(BUILD_DIR)/$(PROGRAM)

exe : $(PROGRAM_EXE)

clean :
	rm -rf $(OBJ_DIR)

info : 
	@echo 'BUILD_DIR:    ' $(BUILD_DIR)
	@echo 'INCLUDE_DIR:  ' $(INCLUDE_DIR)
	@echo 'SOURCE_DIR:   ' $(SOURCE_DIR)
	@echo '  SUBDIRS:    ' $(SUBDIRS)
	@echo 'OBJ_DIR:      ' $(OBJ_DIR)
	@echo '  OBJSUBDIRS: ' $(OBJSUBDIRS)
	@echo 
	@echo 'SRCS:         ' $(SRCS)
	@echo
	@echo 'OBJS:         ' $(OBJS)


$(PROGRAM) : $(OBJSUBDIRS) $(OBJS) 
	$(CC) $(CCFLAGS) $(OBJS) -o $(BUILD_DIR)/$(PROGRAM)

$(PROGRAM_EXE) : $(SRCS) 
	$(MINGW) $(MINGWFLAGS) $(SRCS) -o $(BUILD_DIR)/win64/$(PROGRAM_EXE)

$(OBJSUBDIRS) : 
	mkdir -p $(OBJSUBDIRS)

$(OBJ_DIR)/%.o : $(SOURCE_DIR)/%.cpp
	$(CC) $(CCFLAGS) -c $^ -o $@


.PHONY: clean all
