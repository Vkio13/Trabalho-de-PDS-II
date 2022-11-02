#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>

    class Categoria(){
        string nome;
        double orcamento;
        double gastoTotal;
        bool limite;
    public :
        void setGasto(double valor);
        double getGasto();
        bool statusLimite();
        void alteraCaixa(double valor);
        void relatorioDeCategoria();
    }
#endif
