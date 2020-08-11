
.PHONY: all clean

OUT_DIR := $(BUILD_MODE)

targets := \
$(OUT_DIR)/is_str_num_test

OBJS := \
$(OUT_DIR)/main.o \
$(OUT_DIR)/is_str_num.o \
$(OUT_DIR)/is_str_num_test.o

LIBS += \
-lcppunit

ifeq ($(BUILD_MODE),debug)
	CFLAGS += -g
else ifeq ($(BUILD_MODE),release)
	CFLAGS += -O2
else
	echo Build mode $(BUILD_MODE) not supported by this Makefile
endif

all: $(targets)

$(OUT_DIR)/is_str_num_test: $(OUT_DIR) $(OBJS)
	g++  -o $@ $(OBJS) $(LIBS)

$(OUT_DIR):
	mkdir -p $(OUT_DIR)
	
$(OUT_DIR)/%.o:	%.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

$(OUT_DIR)/%.o:	%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	rm -fr $(OUT_DIR)
