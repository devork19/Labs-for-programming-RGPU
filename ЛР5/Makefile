CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = main.exe
OBJS = main.o fraction.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c fraction.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	@cmd /c "chcp 65001 > nul && title Дроби && $(TARGET) && pause"