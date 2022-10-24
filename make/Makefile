# declaration
CC = cc
CFLAGS = -Wall -g -std=c++17 -fPIC -I . -I include -L lib
LDFLAGS = -l stdc++
LIBRARY = Loader

# generated
LIBRARY_OUT = lib/lib$(LIBRARY).so

UNAME = $(shell uname)

ifeq ($(UNAME), Linux)
# specific for Linux
endif
ifeq ($(UNAME), Darwin)
# specific for MacOS
endif

TARGET_SRC = $(wildcard *.cpp)
TARGET_OUT = $(patsubst %.cpp,%.out,$(TARGET_SRC))

OBJECT_SRC = $(wildcard src/*.cpp)
OBJECT_OUT = $(patsubst src/%.cpp,obj/%.o,$(OBJECT_SRC))

TEXT_SRC = $(wildcard text/*.txt)
TEXT_OUT = $(patsubst text/%.txt,text/%.txt.h,$(TEXT_SRC))

# target
target: directory text library $(TARGET_OUT)
	@echo "TARGET DONE"	

%.out: %.cpp
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) -l $(LIBRARY)

# directory
directory:
	mkdir -p obj lib
	@echo "DIRECTORY DONE"

# text
text: $(TEXT_OUT)
	@echo "TEXT DONE"

text/%.txt.h: text/%.txt
	cat /dev/null > $@
	echo "#ifndef __$(patsubst text/%.txt,%,$<)__" >> $@
	echo "#define __$(patsubst text/%.txt,%,$<)__" >> $@
	xxd -i $< >> $@
	echo "#endif//__$(patsubst text/%.txt,%,$<)__" >> $@

# library
library: $(LIBRARY_OUT)
	@echo "LIBRARY DONE"

$(LIBRARY_OUT): $(OBJECT_OUT)
	$(CC) $(CFLAGS) -shared -o $(LIBRARY_OUT) $(OBJECT_OUT) $(LDFLAGS)

obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<


# clean
clean:
	rm -f $(TEXT_OUT) $(LIBRARY_OUT) $(TARGET_OUT)

.PHONY: target directory text library clean
