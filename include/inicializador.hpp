#ifndef INICIALIZADOR_H
#define INICIALIZADOR_H
#include <vector>
#include "../include/categoria.hpp"
class Inicializador {
    private:
        Dados d;
        std::vector<Categoria> _categorias;
        double _entradas,_gastos;
    public :
    //Construtor
        Inicializador();
    //Destrutor
        ~Inicializador();
    //Métodos
        double GetEntradas();
        double GetGastos();
        std::vector<Categoria> GetCategorias();
        void carregaEntradas();
        void carregaGastos();
        void carregaCategorias();
};
#endif
