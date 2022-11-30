#ifndef DESPESA_H
#define DESPESA_H
/**
 * @file despesa.hpp
 * @brief Classe de uma despesa em individual
 * @version 1.0
 * @date 2022-11-30
 * @details TAD com função principal de 
 * conter dados básicos de uma determinada
 * despesa.
 * 
 * @copyright GNU General Public License 
 * 
 */
#include<string>
#include <iostream>
/**
         * @brief Classe contendo informações básicas
         * de uma despesa
         *
         * @details Armazena informações basicas de uma despesa
         *
         */   
class Despesa{
    private:
    /**
         * @brief Descrição da despesa.
         */
        std::string _descricao;
    /**
         * @brief Valor da despesa.
         */
        double _valor;
        //data
    public:
    /**
         * @brief Constrói o objeto Despesa.
         *
         * @param descricao Descrição da despesa.
         *
         * @param valor Valor da despesa.
         * 
         * @param vencimento Data do vencimento do boleto
         *
         */
        Despesa(std::string descricao, double valor);
    /**
         * @brief função obtém a descrição da despesa.
         *
         * @return Retorna a descrição da despesa.
         */
        std::string getDescricao();
    /**
         * @brief Função que obtém o valor da despesa.
         *
         * @return Retorna o valor da despesa.
         */
        double getValor();
        //data
    /**
         * @brief Define a descrição da despesa.
         *
         * @param descricao Descrição a ser definida.
         *
         */ 
        void setDescricao(std::string descricao);
    /**
         * @brief Define o valor da despesa.
         *
         * @param valor Valor a ser definido.
         *
         */ 
        void setValor(double valor);
};

class ErroDespesa : public std::exception{
    const char* what() const noexcept {
      return "O valor inserido é inválido. Digite apenas valores positivos.";
   }
};

#endif
