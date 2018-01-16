CC = gcc

CFLAGS = -std=c99 -g -Wall
LDFLAGS =  
TARGET = build/a.out

SRCS=$(wildcard src/**/*.c src/*.c)
OBJS=$(patsubst %.c,%.o,$(SRCS))

TEST_SRCS=$(wildcard tests/*_tests.c)
TESTS=$(patsubst %.c,%,$(TEST_SRCS))

all: $(TARGET) tests

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(TARGET)

$(TARGET): build $(OBJS)

build:
	@mkdir -p build
	@mkdir -p bin

tests: $(TESTS)
	sh ./tests/runtests.sh

clean:
	rm -f $(TARGET) $(OBJS) $(TESTS)
	rm -f tests/tests.log