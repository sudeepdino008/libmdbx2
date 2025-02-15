# Project root Makefile
.PHONY: all build test clean

all:
	cmake -S . -B build && cmake --build build

cmake:
	cmake -S . -B build

cmake-dbg:
	cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug

build:
	cmake --build build

test:
	cd build && ctest

clean:
	rm -rf build