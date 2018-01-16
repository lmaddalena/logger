CC = gcc

CFLAGS = -std=c99 -g -Wall
LDFLAGS =  
TARGET = build/a.out

SRCS=$(wildcard src/**/*.c src/*.c)
OBJS=$(patsubst %.c,%.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(TARGET)

$(TARGET): build $(OBJS)

build:
	@mkdir -p build
	@mkdir -p bin

clean:
	rm -f $(TARGET) $(OBJS)
