#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <iostream>
#include <string>

class Categoria(){
class Categoria{
    string _nome;
    double _orcamento;
    double _gastoTotal;
    bool _limite;
public:
    void set_gasto(double valor);
    double get_gasto();
    bool statusLimite();
    void alteraCaixa(double valor);
    void relatorioDeCategoria();
    };

#endif