#TODO automate libevdev include: https://github.com/whot/libevdev
CC := g++
VULKAN_SDK_VERSION = 1.0.46.0
VULKAN_SDK_PATH = /home/dale/local/lunarg/VulkanSDK/$(VULKAN_SDK_VERSION)/x86_64
SRCDIR := src
BUILDDIR := build
TARGET := bin/simulator
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
OPTIMIZATIONS := -O2 -flto
CFLAGS :=-std=c++14 -Wall -g -Werror -DLINUX
LIB := -pthread -L./lib -levdev `pkg-config --static --libs glfw3`
INC := -I include -I$(VULKAN_SDK_PATH)/include
DEBUG := -DDEBUG

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $(OPTIMIZATIONS) $^ -o $(TARGET) $(LIB)"; $(CC) $(OPTIMIZATIONS) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(OPTIMIZATIONS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

debug: CFLAGS += $(DEBUG)
debug: all

# Tests
tester:
	$(CC) $(CFLAGS) test/tester.cc $(INC) $(LIB) -o bin/tester

# Spikes
dir:
	$(CC) $(CFLAGS) $(DEBUG) spike/readdir.cc $(INC) $(LIB) -o bin/readdir
regex:
	$(CC) $(CFLAGS) $(DEBUG) spike/regex.cc $(INC) $(LIB) -o bin/regex
controller:
	$(CC) $(CFLAGS) $(DEBUG) spike/input_demo.cc $(INC) $(LIB) -o bin/controller

.PHONY: clean
