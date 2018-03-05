CC = gcc

CFLAGS = -g -Wall -Werror -Isrc -std=c99 -O2
LDFLAGS =  
TARGET = bin/loger.a

SRCS=$(wildcard src/**/*.c src/*.c)
OBJS=$(patsubst src/%.c,build/%.o,$(SRCS))

TEST_SRCS=$(wildcard tests/*_tests.c)
TESTS=$(patsubst %.c,%,$(TEST_SRCS))

all: $(TARGET) tests

$(TARGET): $(OBJS)
	ar rcs $(TARGET) $(OBJS)
	ranlib $(TARGET)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS) -o $(OBJS)

$(TESTS): $(TARGET)
tests: CFLAGS += $(TARGET)
tests: $(TESTS)
	sh ./tests/runtests.sh

clean:
	rm -f $(TARGET) $(OBJS) $(TESTS)
	rm -f tests/tests.log
