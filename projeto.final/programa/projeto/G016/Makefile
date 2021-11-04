#make file example

CC=gcc
CFLAGS = -Wall -std=c11 -O3 -g #tirar o -g
TARGET = covid19
all: 
	$(CC) $(CFLAGS) -o $(TARGET) covid.c data_structure.c specs.c write.c read.c covid19.h

clean:
	rm $(TARGET)