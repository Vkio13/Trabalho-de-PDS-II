#ifndef INICIALIZADOR_H
#define INICIALIZADOR_H
#include <list>
#include "categoria.hpp"
class Inicializador {
    private:
        list<Categoria> categorias;
        double entradas,investimento,gastos;
    public :
        double GetEntradas();
        double GetGastos();
        list<Categoria> GetCategorias();
        void carregaEntradas();
        void carregaGastos();
        void carregaCategorias();
};
#endif
