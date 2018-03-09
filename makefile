CC = gcc

CFLAGS = -std=c99 -g -Wall -Isrc -Werror
LDFLAGS =  
TARGET = bin/logger.a

TEST_SRCS=$(wildcard tests/*_tests.c)
TESTS=$(patsubst %.c,%,$(TEST_SRCS))

all: $(TARGET) tests

$(TARGET): build/logger.o
	ar rcs $@ $^
	ranlib $@

build/logger.o: src/logger.c src/logger.h
	$(CC) $(CFLAGS) -c $< -o $@


$(TESTS): $(TARGET)

tests: $(TESTS)
	sh ./tests/runtests.sh

clean:
	rm -f build/* bin/*
	rm -f $(TESTS)

.PHONY: all tests clean