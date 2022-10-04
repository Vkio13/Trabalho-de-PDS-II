CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := main.out
CFLAGS := -g -Wall -O3 -std=c++11 -I include/

#all: main

#main:

clean:
	$(RM) -r $(BUILDDIR)/* $(TARGET)
