CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := main.out
CFLAGS := -g -Wall -O3 -std=c++11 -I include/

all: main
dados:
	$(CC) $(CFLAGS) -c src/dados.cpp -o build/dados.o

main: dados 
	$(CC) $(CFLAGS) build/dados.o main.cpp -o $(TARGET)

clean:
	$(RM) -r $(BUILDDIR)/* $(TARGET)
