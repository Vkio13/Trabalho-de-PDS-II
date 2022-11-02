#include <iostream>
#include <string>
#include "categoria.hpp"

/* ATRIBUTOS:
string _nome;
double _orcamento;
double _gastoTotal;
bool _limite;
*/


// Construtor:
Categoria (std::string nome, double orcamento):
_nome(nome), _orcamento(orcamento) {};

double get_gasto() const {
    return _gastoTotal;
};

void set_gasto(double valor){
    this->_gastoTotal = valor;
}

bool statusLimite() const {
    return this->_limite;
};

void alteraCaixa(double valor){
    // CHAMAR FUNÇÃO DE CAIXA ALTERANDO O MESMO
};

void relatorioDeCategoria() const {
    std::cout << "Categoria: " << this->_nome << std::endl;
    std::cout << "Orcamento: " << _orcamento << std::endl;
    std::cout << "Gasto Total: " << _gastoTotal << std::endl;
    if(statusLimite()){ 
        std::cout << "Orcamento nao atingido" << std::endl;
    }else{
        std::cout << "ATENCAO! Orcamento atingido" << std::endl;
    }
};
