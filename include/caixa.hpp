#ifndef CAIXA_H
#define CAIXA_H

#include <iostream>

    class Caixa{
        double _saldo;
        double _receitas;
        double _gastos;
    public :
    //Construtor
        Caixa(double receitas, double gastos, double saldo);
        ~Caixa();
    //Métodos
        double getSaldo();
        double getReceitas();
        double getGastos();
        void atualizaSaldo(); 
        void setReceitas(double valor);// Aqui é plausível que tenha erros propositais por parte do usuário. Seria interessante um teste aqui.
        void setGastos(double valor);// Aqui é plausível que tenha erros propositais por parte do usuário. Seria interessante um teste aqui.
        void adicionaGasto(double valor);
        void adicionaReceita(double valor);
    };
    class Excecao_Caixa : public std::exception { // Vai faltar a implementação no main
        const char* what() const noexcept{
            return "O valor inserido não é valido. Por favor, insira um valor positivo";
        }
    };
#endif
