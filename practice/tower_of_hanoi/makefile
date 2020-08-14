
.PHONY: all clean

OUT_DIR := $(BUILD_MODE)

targets := \
$(OUT_DIR)/tower_of_hanoi_test

OBJS := \
$(OUT_DIR)/tower_of_hanoi_test.o \
$(OUT_DIR)/tower_of_hanoi.o \
$(OUT_DIR)/main.o

LIBS += \
-lcppunit

CFLAGS += --std=c++17

ifeq ($(BUILD_MODE),debug)
	CFLAGS += -g
else ifeq ($(BUILD_MODE),release)
	CFLAGS += -O2
else
	echo Build mode $(BUILD_MODE) not supported by this Makefile
endif

all: $(targets)

$(OUT_DIR)/tower_of_hanoi_test: $(OUT_DIR) $(OBJS)
	g++  -o $@ $(OBJS) $(LIBS)

$(OUT_DIR):
	mkdir -p $(OUT_DIR)
	
$(OUT_DIR)/%.o:	%.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

$(OUT_DIR)/%.o:	%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	rm -fr $(OUT_DIR)
