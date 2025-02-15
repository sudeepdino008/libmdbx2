# Project root Makefile
.PHONY: all build test clean

all:
	cmake -S . -B build && cmake --build build

build:
	cmake --build build

test:
	cd build && ctest

clean:
	rm -rf build