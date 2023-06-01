#!/usr/bin/make -f
ifndef VERBOSE
.SILENT:
endif

CC=gcc
BUILD_DIR=build
SRC_DIR='../mwave/src'

all: $(BUILD_DIR)/test_mwave.o $(BUILD_DIR)/test_wrand.o

$(BUILD_DIR)/test_mwave.o: test_mwave.c | $(BUILD_DIR)
	$(CC) -o $(BUILD_DIR)/test_mwave.o test_mwave.c

$(BUILD_DIR)/test_wrand.o: test_wrand.c | $(BUILD_DIR)
	$(CC) -I$(SRC_DIR)/ -o $(BUILD_DIR)/test_wrand.o test_wrand.c $(SRC_DIR)/wrand.c

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -f $(BUILD_DIR)/test_mwave.o
	rm -f $(BUILD_DIR)/test_wrand.o
	rmdir $(BUILD_DIR)
