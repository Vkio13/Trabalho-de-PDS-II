CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := main.out
CFLAGS := -g -Wall -O3 -std=c++11 -I include/

all: main
despesa:
	$(CC) $(CFLAGS) -c src/despesa.cpp -o build/despesa.o
categoria:
	$(CC) $(CFLAGS) -c src/categoria.cpp -o build/categoria.o
main: despesa categoria
	$(CC) $(CFLAGS) build/despesa.o build/categoria.o main.cpp -o $(TARGET)

clean:
	$(RM) -r $(BUILDDIR)/* $(TARGET)
