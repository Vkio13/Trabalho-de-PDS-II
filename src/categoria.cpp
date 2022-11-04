#include <iostream>
#include "../include/categoria.hpp"

/* ATRIBUTOS:
string _nome;
double _orcamento;
double _gastoTotal;
bool _limite;
*/

    // Construtor:
    Categoria::Categoria (std::string nome, double orcamento, double gastoTotal, bool limite){
        _nome= nome;
        _orcamento = orcamento;
        _gastoTotal = gastoTotal;
        _limite = limite;
    };

double Categoria::get_gasto() {
    return _gastoTotal;
};

void Categoria::set_gasto(double valor){
    this->_gastoTotal = valor;
}

bool Categoria::statusLimite() {
    return this->_limite;
};

void Categoria::alteraCaixa(double valor){
    // CHAMAR FUNÇÃO DE CAIXA ALTERANDO O MESMO
};

void Categoria::relatorioDeCategoria() {
    std::cout << "Categoria: " << this->_nome << std::endl;
    std::cout << "Orcamento: " << this->_orcamento << std::endl;
    std::cout << "Gasto Total: " << this->_gastoTotal << std::endl;
    if(statusLimite()){ 
        std::cout << "Orcamento nao atingido" << std::endl;
    }else{
        std::cout << "ATENCAO! Orcamento atingido" << std::endl;
    }
};
