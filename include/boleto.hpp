#ifndef BOLETO_H
#define BOLETO_H
/**
 * @file boleto.hpp
 * @brief Subclasse Boleto 
 * @version 1.5
 * @date 2022-12-05
 * @details TAD com função principal de 
 * conter a data de vencimento de um 
 * determinado boleto.
 * 
 * @copyright GNU General Public License 
 * 
 */
#include "categoria.hpp"
/**
         * @brief Classe contendo informações básicas de um boleto.
         *
         * @details Armazena informações basicas de um boleto.
         *
         */   
class Boleto : public Categoria {
    protected:
    /**
         * @brief Dia do vencimento de um boleto.
         */
        int _vDia;
        /**
         * @brief Mês do vencimento de um boleto.
         */
        int _vMes;
    /**
         * @brief bool dizendo se o boleto foi pago ou não.
         */
        bool _pago;
    
    public:
        /**
         * @brief Constrói o objeto Boleto.
         *
         * @param nome Nome do boleto.
         * @param valor Valor do boleto.
         * @param dia Dia do vencimento do boleto.
         * @param mes Mês do vencimento do boleto.
         *
         */ 
        Boleto(std::string nome, double valor, int dia, int mes);
        /**
         * @brief Destrutor da classe Boleto.
         */
        ~Boleto();
          /**
         * @brief Diz se o boleto foi pago.
         * @return Verdadeiro se foi pago e falso se não.
         */
        bool get_pago();
        /**
         * @brief Efetua o pagamento de um boleto.
         */
        void pagaBoleto();
        /**
         * @brief Função que diz se o boleto venceu ou não.
         *
         * @return Verdadeiro se venceu e falso se não.
         */
        bool venceu();
        /**
         * @brief Apresenta um relatorio da categoria
         */
        void relatorioDeCategoria() override;
};
/**
         * @brief Classe de exceção de boleto.
         *
         * @details É executado quando o valor não é positivo.
         *
         */   
    class Excecao_Boleto : public std::exception {
        public : 
        const char* what() const noexcept;
    };
/**
         * @brief Classe de exceção de boleto.
         *
         * @details É executado quando o número de caracteres é excedido.
         *
         */
    class Excecao_Caracteres_Boleto : public Excecao_Boleto{
        public : 
        const char* what() const noexcept{
             return "O número de caracteres excede o número permitido pelo programa. Por favor, digite novamente o nome.";
        }
    };
/**
         * @brief Classe de exceção de boleto.
         *
         * @details É executado quando a data de vencimento é inválida.
         *
         */
    class Excecao_Vencimento_Boleto : public Excecao_Boleto{
        public : 
        const char* what() const noexcept{
             return "A data de vencimento inserida é inválida. Certifique-se que o dia de vencimento está entre 1 e 31 e o mês entre 1 e 12.";
        }
    };
#endif
