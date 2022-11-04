#include "../include/despesa.hpp"
Despesa::Despesa(std::string descricao, double valor){
    this->_descricao=descricao;
    this->_valor=valor;
    //data
};
std::string Despesa::getDescricao(){
    return this->_descricao;
};
double Despesa::getValor(){
    return this->_valor;
};
//getdata
void Despesa::setDescricao(std::string descricao){
    this->_descricao=descricao;
};
void Despesa::setValor(double valor){
    this->_valor=valor;
};
//setdata