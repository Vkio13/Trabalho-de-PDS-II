#ifndef CAIXA_H
#define CAIXA_H

#include <iostream>

    class Caixa{
        double saldo;
        double receitas;
        double gastos;
    public :
    //Construtor
            Caixa(double _saldo, double _receitas, double _gastos){
                saldo =_saldo;
                receitas = _receitas;
                gastos = _gastos;
            }
    //Métodos
        double getSaldo();
        double getReceitas();
        double getGastos();
        void setSaldo(double valor);
        void setReceitas(double valor);
        void setGastos(double valor);
    };
#endif
