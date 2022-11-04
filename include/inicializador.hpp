#ifndef INICIALIZADOR_H
#define INICIALIZADOR_H
#include <list>
#include "../include/categoria.hpp"
class Inicializador {
    private:
        std::list<Categoria> _categorias;
        double _entradas,_investimento,_gastos;
    public :
    //Construtor
        Inicializador(std::list<Categoria> categorias, double entradas, double investimento, double gastos);
    //Destrutor
        ~Inicializador();
    //Métodos
        double GetEntradas();
        double GetGastos();
        std::list<Categoria> GetCategorias();
        void carregaEntradas();
        void carregaGastos();
        void carregaCategorias();
};
#endif
