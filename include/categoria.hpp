#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <iostream>
#include <fstream>
#include "despesa.hpp"
#include <list>

class Categoria{
    private : 
        std::string _nome_;
        double _orcamento_;
        double _gastototal;
        bool _limite;

    public:
        // Construtor:
        Categoria (std::string nome, double orcamento,double gastoTotal, bool  limite);
        // ~Categoria();

        //Métodos
        void set_gasto(double valor);
        double get_gasto();
        bool statusLimite();
        void alteraCaixa(double valor);
        void relatorioDeCategoria();

        //Arquivo
        void registraDespesa(Despesa despesa);
        void imprimeDespesa();
};

#endif