#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <iostream>
#include <fstream>
#include "despesa.hpp"
#include <list>

class Categoria{
    protected: 
        std::string _nome;
        double _orcamento;
        double _gastoTotal;
        bool _limite;

    public:
        // Construtor:
        Categoria (std::string nome, double orcamento);
        // Destrutor:
        ~Categoria();

        //Métodos
        double get_gasto();
        void set_gasto(double valor);
        void verificaLimite();
        virtual void relatorioDeCategoria();

        //Arquivo
        void registraDespesa(Despesa despesa);
        void imprimeDespesa();
};

#endif