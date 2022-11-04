#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <iostream>
#include <string>

class Categoria{
private : 
    std::string _nome;
    double _orcamento;
    double _gastoTotal;
    bool _limite;

public:
// Construtor:
    Categoria (std::string nome, double orcamento,double gastoTotal, bool  limite);
//Destrutor
    ~Categoria();

//Métodos
    void set_gasto(double valor);
    double get_gasto();
    bool statusLimite();
    void alteraCaixa(double valor);
    void relatorioDeCategoria();
    };

#endif