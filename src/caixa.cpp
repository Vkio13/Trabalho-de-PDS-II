#include "../include/caixa.hpp"
Caixa::Caixa(){
};

double Caixa::getSaldo(){
    return _saldo;
};

double Caixa::getReceitas(){
    return _receitas;
};

double Caixa::getGastos(){
    return _gastos;
};

void Caixa::atualizaSaldo(){
    _saldo = _receitas - _gastos;
};

void Caixa::setReceitas(double valor){
    if(valor<0 || valor > 2147483646){
       throw Excecao_Caixa();
    }
    _receitas = valor;
    this->atualizaSaldo();
};

void Caixa::setGastos(double valor){
    if(valor<0 || valor > 2147483646){
        throw Excecao_Caixa();
    }
    _gastos  = valor;
    this->atualizaSaldo();
};

void Caixa::adicionaGasto(double valor){
    if(valor<0){
       throw Excecao_Caixa();
    }
    _gastos  += valor;
    this->atualizaSaldo();
};

void Caixa::adicionaReceita(double valor){
    if(valor<0){
        throw Excecao_Caixa();
    }
    _receitas  += valor;

    this->atualizaSaldo();
};

void Caixa::resumoDeCaixa(){
    std::cout << "Receitas: " << _receitas << std::endl;
    std::cout << "Despesas: " << _gastos << std::endl;
    std::cout << "SALDO: " << _saldo << std::endl;
}

const char* Excecao_Caixa::what() const noexcept{
    return "O valor inserido não é valido. Por favor, insira um outro valor: ";
};