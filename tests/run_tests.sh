#!/bin/sh

# Compile
make

# Run tests
./build/test_mwave.o
./build/test_wrand.o