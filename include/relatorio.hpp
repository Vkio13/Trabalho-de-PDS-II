#ifndef RELATORIO_H
#define RELATORIO_H
#include "categoria.hpp"

    class Relatorio{
        list<Categoria> categorias;
    public :
        void relatorioMensal();
        void relatorioGeral();
    };
#endif
