CC=g++
CFLAGS=-pedantic -Wall -std=c++11
SOURCES= palindrom.cpp

all:
	$(CC) $(CFLAGS) $(SOURCES)
