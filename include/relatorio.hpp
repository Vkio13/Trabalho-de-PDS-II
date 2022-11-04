#ifndef RELATORIO_H
#define RELATORIO_H
#include "../include/categoria.hpp"

    class Relatorio{
        std::list<Categoria> _categorias;
    public :
    //Construtor
        Relatorio(std::list<Categoria> categorias);
    //Destrutor
        ~Relatorio();
    //Métodos
        void relatorioMensal();
        void relatorioGeral();
    };
#endif
