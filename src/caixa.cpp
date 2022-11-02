#include "../include/caixa.hpp"

        Caixa(double _saldo, double _receitas, double _gastos){
            _saldo= saldo;
            _receitas = receitas;
            _gastos= gastos;
        }

        double getSaldo(){
            return _saldo;
        }
        double getReceitas(){
            return _receitas;
        }
        double getGastos(){
            return _gastos;
        }
        void setSaldo(double valor){
            _saldo = valor;
        }
        void setReceitas(double valor){
            _receitas = valor;
        }
        void setGastos(double valor){
            _gastos  = valor;
        }
    
