#ifndef DESPESA_H
#define DESPESA_H

#include<string>
#include <iostream>

class Despesa{
    private:
        std::string _descricao;
        double _valor;
        //data
    public:
        Despesa(std::string descricao, double valor);
        std::string getDescricao();
        double getValor();
        //data
        void setDescricao(std::string descricao);
        void setValor(double valor);
};

class ErroDespesa : public std::exception{
    const char* what() const noexcept {
      return "O valor inserido é inválido. Digite apenas valores positivos.";
   }
};

#endif
