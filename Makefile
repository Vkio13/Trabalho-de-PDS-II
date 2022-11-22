CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := main.out
CFLAGS := -g -Wall -O3 -std=c++11 -I include/

all: main
dados:
	$(CC) $(CFLAGS) -c src/dados.cpp -o build/dados.o

boleto:
	$(CC) $(CFLAGS) -c src/boleto.cpp -o build/boleto.o

caixa:
	$(CC) $(CFLAGS) -c src/caixa.cpp -o build/caixa.o

categoria:
	$(CC) $(CFLAGS) -c src/categoria.cpp -o build/categoria.o

despesa:
	$(CC) $(CFLAGS) -c src/despesa.cpp -o build/despesa.o

inicializador:
	$(CC) $(CFLAGS) -c src/inicializador.cpp -o build/inicializador.o

kapemgga:
	$(CC) $(CFLAGS) -c src/kapemgga.cpp -o build/kapemgga.o

relatorio: 
	$(CC) $(CFLAGS) -c src/relatorio.cpp -o build/relatorio.o

main: dados 
	$(CC) $(CFLAGS) build/dados.o main.cpp -o $(TARGET)

clean:
	$(RM) -r $(BUILDDIR)/* $(TARGET)
