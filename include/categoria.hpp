#ifndef CATEGORIA_H
#define CATEGORIA_H
/**
 * @file categoria.hpp
 * @brief Superclasse principal de uma categoria
 * @version 1.0
 * @date 2022-11-24
 * @details TAD com função principal de 
 * conter valores genéricos para que as
 * demais categorias possa herda-la
 * 
 * @copyright GNU General Public License 
 * 
 */
#include <iostream>
#include <fstream>
#include <list>
#include <ctime>
#include "dados.hpp"

/**
         * @brief Contém informações e valores genéricos
         * para outras classes
         *
         * @details Armazena variáveis em comum com as 
         * categorias
         *
         */      
class Categoria{
    protected: 
    /**
         * @brief Nome da categoria.
         **/ 
        std::string _nome;
        /**
         * @brief orçamento de uma categoria.
         **/ 
        double _orcamento;
        /**
         * @brief Gasto total de uma categoria.
         **/ 
        double _gastoTotal;
        /**
         * @brief Limite de uma categoria
         **/ 
        bool _limite;
    public:
         /**
         * @brief Construtor ca classe Categoria
         *
         * @param nome Nome da categoria
         * @param orcamento Orçamento de uma categoria
         *
         **/ 
        Categoria (std::string nome, double orcamento);
         /**
         * @brief Sobrecarga do construtor da classe Categoria
         **/ 
        Categoria();
        /**
         * @brief Destrutor
         **/ 
        ~Categoria();
        /**
         * @brief Obtém o nome da categoria
         * @return Nome da categoria
         **/ 
        std::string get_nome();
        /**
         * @brief Obtém o gasto de uma categoria
         * @return Valor do gasto
         **/ 
        double get_gasto();
        /**
         * @brief Define o valor de um gasto
         * @param valor Valor a ser definido
         **/ 
        void set_gasto(double valor);  // Aqui é plausível que tenha erros propositais por parte do usuário. Seria interessante um teste aqui.
        /**
         * @brief Adiciona um gasto à categoria
         * @param valor Valor a ser adicionado
         **/ 
        void adiciona_Gasto(double valor);
        /**
         * @brief Obtém o orçamento
         * @return Retorna o valor do orçamento
         **/ 
        double get_orcamento();
        /**
         * @brief Verifica a situação do limite
         **/ 
        void verificaLimite();
        /**
         * @brief Função virtual
         **/ 
        virtual void relatorioDeCategoria();
};

#endif
