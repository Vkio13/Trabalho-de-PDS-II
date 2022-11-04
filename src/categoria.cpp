#include <iostream>
#include "../include/categoria.hpp"

/* ATRIBUTOS:
string _nome_;
double _orcamento_;
double _gastototal;
bool _limite;
*/

    // Construtor:
    Categoria::Categoria (std::string nome, double orcamento, double gastoTotal, bool limite){
        _nome_= nome;
        _orcamento_ = orcamento;
        _gastototal = gastoTotal;
        _limite = limite;
    };

double Categoria::get_gasto() {
    return _gastototal;
};

void Categoria::set_gasto(double valor){
    this->_gastototal = valor;
}

bool Categoria::statusLimite() {
    return this->_limite;
};

void Categoria::alteraCaixa(double valor){
    // CHAMAR FUNÇÃO DE CAIXA ALTERANDO O MESMO
};

void Categoria::relatorioDeCategoria() {
    std::cout << "Categoria: " << this->_nome_ << std::endl;
    std::cout << "Orcamento: " << this->_orcamento_ << std::endl;
    std::cout << "Gasto Total: " << this->_gastototal << std::endl;
    if(statusLimite()){ 
        std::cout << "Orcamento nao atingido" << std::endl;
    }else{
        std::cout << "ATENCAO! Orcamento atingido" << std::endl;
    }
};
