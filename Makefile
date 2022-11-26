CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := main.out
CFLAGS := -g -Wall -O3 -std=c++11 -I include/

all: main
dados:categoria
	$(CC) $(CFLAGS) -c build/categoria.o src/dados.cpp -o build/dados.o

boleto:
	$(CC) $(CFLAGS) -c src/boleto.cpp -o build/boleto.o

caixa:
	$(CC) $(CFLAGS) -c src/caixa.cpp -o build/caixa.o

categoria:
	$(CC) $(CFLAGS) -c src/categoria.cpp -o build/categoria.o

inicializador:dados
	$(CC) $(CFLAGS) -c build/dados.o src/inicializador.cpp -o build/inicializador.o

kapemgga:inicializador caixa boleto 
	$(CC) $(CFLAGS) -c build/caixa.o build/boleto.o build/inicializador.o src/kapemgga.cpp -o build/kapemgga.o

relatorio: ##falta incluir na main
	$(CC) $(CFLAGS) -c src/relatorio.cpp -o build/relatorio.o

main: kapemgga
	$(CC) $(CFLAGS) build/kapemgga.o main.cpp -o $(TARGET)

clean:
	$(RM) -r $(BUILDDIR)/* $(TARGET)
