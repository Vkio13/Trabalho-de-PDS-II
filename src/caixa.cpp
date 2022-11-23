#include "../include/caixa.hpp"
Caixa::Caixa(double receitas=0, double gastos=0, double saldo=0){
        _receitas = receitas;
        _gastos = gastos;
        _saldo=0;
}
Caixa::~Caixa(){

}
double Caixa::getSaldo(){
    return _saldo;
}
double Caixa::getReceitas(){
    return _receitas;
}
double Caixa::getGastos(){
    return _gastos;
}
void Caixa::atualizaSaldo(){
    _saldo = _receitas - _gastos;
}
void Caixa::setReceitas(double valor){
    if(valor<0){
        throw Excecao_Caixa();
    }else{
    _receitas = valor;
    }
    this->atualizaSaldo();
}
void Caixa::setGastos(double valor){
    if(valor<0){
        throw Excecao_Caixa();
    }else{
    _gastos  = valor;
    }
    this->atualizaSaldo();
}
void Caixa::adicionaGasto(double valor){
    if(valor<0){
        throw Excecao_Caixa();
    }else{
    _gastos  += valor;
    }
    this->atualizaSaldo();
};
void Caixa::adicionaReceita(double valor){
    if(valor<0){
        throw Excecao_Caixa();
    }else{
    _receitas  += valor;
    }
    this->atualizaSaldo();
};

