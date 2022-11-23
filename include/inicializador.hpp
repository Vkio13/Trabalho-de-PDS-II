#ifndef INICIALIZADOR_H
#define INICIALIZADOR_H
#include <vector>
#include "../include/categoria.hpp"
#include "../include/dados.hpp"
class Inicializador {
    private:
        Dados d;
        std::vector<Categoria> _categorias;
        double _entradas=0, _gastos=0;
    public :
    //Construtor
        Inicializador();
    //Destrutor
        ~Inicializador();
    //Métodos
        double getEntradas();
        double getGastos();
        std::vector<Categoria> getCategorias();
        void carregaEntradas();
        void carregaGastos();
        void carregaCategorias();
};
#endif
