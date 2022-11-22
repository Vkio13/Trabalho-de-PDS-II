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
        Caixa();
    //Métodos
        double getSaldo();
        double getReceitas();
        double getGastos();
        void setSaldo(double valor); 
        void setReceitas(double valor);// Aqui é plausível que tenha erros propositais por parte do usuário. Seria interessante um teste aqui.
        void setGastos(double valor);// Aqui é plausível que tenha erros propositais por parte do usuário. Seria interessante um teste aqui.
    };
    class Excecao_Caixa : public std::exception {
        const char* what() const noexcept{
            return "O valor inserido não é valido. Por favor, insira um valor positivo";
        }
    };
#endif
