#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <iostream>
#include <fstream>
#include "despesa.hpp"
#include <list>
#include <ctime>


class Categoria{
    protected: 
        std::string _nome;
        double _orcamento;
        double _gastoTotal;
        bool _limite;
    public:
        // Construtor:
        Categoria (std::string nome, double orcamento);
        Categoria();
        // Destrutor:
        ~Categoria();

        //Métodos
        std::string get_nome();
        double get_gasto();
        void set_gasto(double valor);  // Aqui é plausível que tenha erros propositais por parte do usuário. Seria interessante um teste aqui.
        void adicona_Gasto(double valor);
        std::string get_nome();
        double get_orcamento();
        void verificaLimite();
        virtual void relatorioDeCategoria();

        /*Arquivo
        void registraDespesa(Despesa despesa);
        void imprimeDespesa();
        */
};

#endif
