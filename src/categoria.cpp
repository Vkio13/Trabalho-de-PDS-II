#include <iostream>
#include <string>
#include "../include/categoria.hpp"

/* ATRIBUTOS:
string _nome;
double _orcamento;
double _gastoTotal;
bool _limite;
*/

double get_gasto() {
    return _gastoTotal;
};

void set_gasto(double valor){
    this->_gastoTotal = valor;
}

bool statusLimite() {
    return this->_limite;
};

void alteraCaixa(double valor){
    // CHAMAR FUNÇÃO DE CAIXA ALTERANDO O MESMO
};

void relatorioDeCategoria() {
    std::cout << "Categoria: " << _nome << std::endl;
    std::cout << "Orcamento: " << _orcamento << std::endl;
    std::cout << "Gasto Total: " << _gastoTotal << std::endl;
    if(statusLimite()){ 
        std::cout << "Orcamento nao atingido" << std::endl;
    }else{
        std::cout << "ATENCAO! Orcamento atingido" << std::endl;
    }
};
