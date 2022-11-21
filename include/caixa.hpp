#ifndef CAIXA_H
#define CAIXA_H

#include <iostream>

    class Caixa{
        double _saldo;
        double _receitas;
        double _gastos;
    public :
    //Construtor
            Caixa(double saldo, double receitas, double gastos);
    //Métodos
        double getSaldo();
        double getReceitas();
        double getGastos();
        void setSaldo(double valor); 
        void setReceitas(double valor);// Aqui é plausível que tenha erros propositais por parte do usuário. Seria interessante um teste aqui.
        void setGastos(double valor);// Aqui é plausível que tenha erros propositais por parte do usuário. Seria interessante um teste aqui.
    };
#endif
