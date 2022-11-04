#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <iostream>
#include <string>

class Categoria{
    
    std::string _nome;
    double _orcamento;
    double _gastoTotal;
    bool _limite;

public:
// Construtor:
    Categoria (std::string nome, double orcamento,double gastoTotal, double limite):
    _nome(nome), _orcamento(orcamento), _gastoTotal(gastoTotal), _limite(limite) {};

//Métodos
    void set_gasto(double valor);
    double get_gasto();
    bool statusLimite();
    void alteraCaixa(double valor);
    void relatorioDeCategoria();
    };

#endif