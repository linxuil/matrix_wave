#!/usr/bin/make -f
ifndef VERBOSE
.SILENT:
endif

CC=gcc
BUILD_DIR=build

all: $(BUILD_DIR)/test_mwave.o

$(BUILD_DIR)/test_mwave.o: test_mwave.c | $(BUILD_DIR)
	$(CC) -o $(BUILD_DIR)/test_mwave.o test_mwave.c

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -f $(BUILD_DIR)/test_mwave.o
	rmdir $(BUILD_DIR)
