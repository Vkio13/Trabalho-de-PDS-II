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
        Categoria (std::string nome, double orcamento, double gastoTotal);
        // Destrutor:
        ~Categoria();

        //Métodos
        double get_gasto();
        std::string get_nome();
        void set_gasto(double valor);  // Aqui é plausível que tenha erros propositais por parte do usuário. Seria interessante um teste aqui.
        void verificaLimite();
        virtual void relatorioDeCategoria();

        /*Arquivo
        void registraDespesa(Despesa despesa);
        void imprimeDespesa();
        */
};

#endif