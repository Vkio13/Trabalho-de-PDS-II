CC := g++
SRCDIR := src
TESTDIR := tests
BUILDDIR := build
TARGET := main.out
CFLAGS := -g -Wall -O3 -std=c++11 -I include/

all: main 
test: usuario categoria dados kapemgga boleto inicializador caixa
	$(CC) $(CFLAGS) $(TESTDIR)/Testes.cpp build/usuario.o build/categoria.o build/dados.o build/kapemgga.o build/boleto.o build/inicializador.o build/caixa.o -o $(TESTDIR)/test.out
usuario:
	$(CC) $(CFLAGS) -c src/usuario.cpp -o build/usuario.o

categoria:
	$(CC) $(CFLAGS) -c src/categoria.cpp -o build/categoria.o

dados:categoria
	$(CC) $(CFLAGS) -c build/categoria.o src/dados.cpp -o build/dados.o

inicializador:dados
	$(CC) $(CFLAGS) -c build/categoria.o build/dados.o src/inicializador.cpp -o build/inicializador.o

boleto:
	$(CC) $(CFLAGS) -c build/categoria.o src/boleto.cpp -o build/boleto.o

caixa:
	$(CC) $(CFLAGS) -c src/caixa.cpp -o build/caixa.o

kapemgga:inicializador caixa boleto 
	$(CC) $(CFLAGS) -c build/dados.o build/categoria.o build/caixa.o build/boleto.o build/inicializador.o src/kapemgga.cpp -o build/kapemgga.o

relatorio: ##falta incluir na main
	$(CC) $(CFLAGS) -c src/relatorio.cpp -o build/relatorio.o

main: kapemgga usuario relatorio
	$(CC) $(CFLAGS)  build/relatorio.o build/usuario.o build/dados.o build/categoria.o build/caixa.o build/boleto.o build/inicializador.o build/kapemgga.o main.cpp -o $(TARGET)

clean:
	$(RM) -r $(BUILDDIR)/* $(TARGET)
