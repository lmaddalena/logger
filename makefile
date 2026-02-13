CC = gcc

CFLAGS = -std=c99 -g -Wall -Isrc -Werror
LDFLAGS =  
TARGET = bin/liblogger.a

TEST_SRCS=$(wildcard tests/*_tests.c)
TESTS=$(patsubst %.c,%,$(TEST_SRCS))

all: $(TARGET) tests

$(TARGET): build/logger.o
	@mkdir -p bin
	ar rcs $@ $^
	ranlib $@

build/logger.o: src/logger.c src/logger.h
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@


$(TESTS): $(TARGET)

tests: $(TESTS)
	sh ./tests/runtests.sh

clean:
	rm -f build/* bin/*
	rm -f $(TESTS)

.PHONY: all tests clean