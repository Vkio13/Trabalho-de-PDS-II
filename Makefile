CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := main.out
CFLAGS := -g -Wall -O3 -std=c++11 -I include/

all: main
KaPeMGGa:
	$(CC) $(CFLAGS) -c src/KaPeMGGa.cpp -o build/KaPeMGGa.o
main: KaPeMGGa
	$(CC) $(CFLAGS) build/KaPeMGGa.o src/main.cpp -o $(TARGET)

clean:
	$(RM) -r $(BUILDDIR)/* $(TARGET)
