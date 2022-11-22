#include "caixa.hpp"

        Caixa::Caixa(double saldo, double receitas, double gastos){
                _saldo =saldo;
                _receitas = receitas;
                _gastos = gastos;
        }
        Caixa::Caixa(){

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
        void Caixa::setSaldo(double valor){
            _saldo = valor;
        }
        void Caixa::setReceitas(double valor){
            _receitas = valor;
        }
        void Caixa::setGastos(double valor){
            _gastos  = valor;
        }
    
