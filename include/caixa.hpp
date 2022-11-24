#ifndef CAIXA_HPP
#define CAIXA_HPP
#include <iostream>
class Caixa{
    private:
        double _receitas;
        double _gastos;
        double _saldo;
    public:
        Caixa();
        double getSaldo();
        double getReceitas();
        double getGastos();
        void atualizaSaldo(); 
        void setReceitas(double valor);
        void setGastos(double valor);
        void adicionaGasto(double valor);
        void adicionaReceita(double valor);
};

class Excecao_Caixa : public std::exception { // Vai faltar a implementação no main
        const char* what() const noexcept;
};

#endif
