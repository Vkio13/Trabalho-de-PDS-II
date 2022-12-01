#ifndef CAIXA_HPP
#define CAIXA_HPP
/**
 * @file caixa.hpp
 * @brief Classe onde estão armazenados os dados do 
 * caixa financeiro
 * @version 1.5
 * @date 2022-11-24
 * @details TAD com função principal de 
 * conter os valores de caixa e facilitar
 * contas e acesso a dados
 * 
 * @copyright GNU General Public License 
 * 
 */
#include <iostream>
/**
         * @brief Armazena dados de caixa
         *
         * @details Armazena receita, gastos e
         * saldo além de facilitar através dos
         * métodos operações financeiras dentro
         * do sistema
         *
         */   
class Caixa{
    private:
     /**
         * @brief Armazena o valor das receitas
         **/
        double _receitas;
         /**
         * @brief Armazena o valor dos gastos
         **/
        double _gastos;
         /**
         * @brief Armazena o saldo
         **/
        double _saldo;
    public:
    /**
         * @brief Constrói o objeto caixa
         **/
        Caixa();
         /**
         * @brief Obtém o saldo
         *
         * @return retorna o saldo
         **/
        double getSaldo();
    /**
         * @brief Obtém as receitas
         *
         * @return retorna o valor das receitas
         **/
        double getReceitas();
    /**
         * @brief Obtém os gastos
         *
         * @return retorna o valor dos gastos
         **/
        double getGastos();
    /**
         * @brief Atualiza os valores de saldo em caixa
         **/
        void atualizaSaldo(); 
    /**
         * @brief Define um valor para as receitas
         *
         * @param valor Valor a ser definido
         **/
        void setReceitas(double valor);
    /**
         * @brief Define um valor para os gastos
         *
         * @param valor Valor a ser definido
         **/
        void setGastos(double valor);
    /**
         * @brief Adiciona um gasto
         *
         * @param valor Valor a ser adicionado
         **/
        void adicionaGasto(double valor);
    /**
         * @brief Adiciona receita
         *
         * @param valor Valor a ser adicionado
         **/
        void adicionaReceita(double valor);
        /**
         * @brief Apresenta um resumo do caixa
         **/
        void resumoDeCaixa();
};
/**
         * @brief Caso de exceção do caixa.hpp
         *
         * @details Subclasse de exception 
         **/
class Excecao_Caixa : public std::exception {
        public : 
        const char* what() const noexcept;
};

class Excecao_Caracteres_Caixa : public Excecao_Caixa {
        public : 
        const char* what() const noexcept{
            return "O número de caracteres excede o número permitido pelo programa. Por favor, digite novamente o nome.";
        }
};

#endif
