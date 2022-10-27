# declaration
UNAME = $(shell uname)

ifeq ($(UNAME), Linux)
	# specific for Linux
	CC = cc
	CFLAGS = -Wall -g -std=c++17 -fPIC -I . -I include -L lib
	LDFLAGS = -l stdc++
endif
ifeq ($(UNAME), Darwin)
	# specific for MacOS
endif

TARGET_SRC_LIST = $(wildcard target/*)
TARGET_LIST = $(patsubst target/%,%,$(TARGET_SRC_LIST))
TARGET_OUT_LIST = $(patsubst %,bin/%,$(TARGET_LIST))

LIBRARY_SRC_LIST = $(wildcard src/*)
LIBRARY_LIST = $(patsubst src/%,%,$(LIBRARY_SRC_LIST))
LIBRARY_OUT_LIST = $(patsubst %,lib/lib%.so,$(LIBRARY_LIST))

.PHONY: target directory library clean

# target
target: directory library $(TARGET_OUT_LIST)

bin/%: target/%
	@echo "building target ... $*"
	$(CC) $(CFLAGS) -o $@ $</*.cpp $(LDFLAGS) $(patsubst %,-l %,$(LIBRARY_LIST))

# directory
directory:
	mkdir -p bin lib

# library
library: $(LIBRARY_OUT_LIST)

lib/lib%.so: src/%
	@echo "building library ... $*"
	$(CC) $(CFLAGS) -shared -o $@ $</*.cpp $(LDFLAGS)


# clean
clean:
	rm -rf bin lib
