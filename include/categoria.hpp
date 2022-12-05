#ifndef CATEGORIA_H
#define CATEGORIA_H
/**
 * @file categoria.hpp
 * @brief Classe onde estão armazenados os dados do 
 * caixa financeiro
 * @version 1.4
 * @date 2022-11-24
 * @details TAD com função principal de 
 * conter os valores de caixa e facilitar
 * contas e acesso a dados
 * 
 * @copyright GNU General Public License 
 * 
 */
/*
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
#include <ctime>

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
        // ~Categoria();
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
/**
         * @brief Função de exceções de categoria.hpp
         **/ 
class Excecao_Categoria : std::exception{
    public : 
    const char* what() const noexcept;
};
class Excecao_Categoria_Caracter : public Excecao_Categoria {
    public : 
    const char* what() const noexcept{
        return "O nome inserido possui muitos caracteres. Por favor, insira um nome com menos de 20 caracteres.";
    }
};
#endif
