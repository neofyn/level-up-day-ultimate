CC      = gcc
CFLAGS  = -Wall -Wextra -O2
TARGET_LINUX   = level_up_day_linux
TARGET_WINDOWS = level_up_day_windows.exe
CROSS   = x86_64-w64-mingw32-gcc

.PHONY: all linux windows clean

all: linux

linux:
	$(CC) $(CFLAGS) -o $(TARGET_LINUX) main.c

windows:
	$(CROSS) $(CFLAGS) -o $(TARGET_WINDOWS) main.c

clean:
	rm -f $(TARGET_LINUX) $(TARGET_WINDOWS)
