#ifndef CAIXA_H
#define CAIXA_H

#include <iostream>

    class Caixa{
        double saldo;
        double receitas;
        double gastos;
    public :
        double getSaldo();
        double getReceitas();
        double getGastos();
        void setSaldo(double valor);
        void setReceitas(double valor);
        void setGastos(double valor);
    };
#endif
