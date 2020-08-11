PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

.PHONY: all clean get_unique_char is_str_num palindrome rm_c_from_str

targets = \
rm_c_from_str \
palindrome \
is_str_num \
get_unique_char

all: $(targets)

get_unique_char:
	$(MAKE) -C $@

is_str_num:
	$(MAKE) -C $@
	
palindrome:
	$(MAKE) -C $@
	
rm_c_from_str:
	$(MAKE) -C $@

%.o:	$(PROJECT_ROOT)%.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

%.o:	$(PROJECT_ROOT)%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	$(for target in $(targets); do $(MAKE) -C $$target clean; done)
