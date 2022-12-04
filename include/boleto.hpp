#ifndef BOLETO_H
#define BOLETO_H
/**
 * @file boleto.hpp
 * @brief Subclasse Boleto 
 * @version 1.3
 * @date 2022-11-30
 * @details TAD com função principal de 
 * conter a data de vencimento de um 
 * determinado boleto
 * 
 * @copyright GNU General Public License 
 * 
 */
#include "categoria.hpp"
/**
         * @brief Classe contendo informações básicas
         * de um boleto
         *
         * @details Armazena informações basicas de um boleto
         *
         */   
class Boleto : public Categoria {
    protected:
    /**
         * @brief Valor do vencimento do boleto.
         */
        int _vDia;
        int _vMes;
    /**
         * @brief bool dizendo se o boleto venceu ou não
         */
        bool _pago;
    
    public:
        /**
         * @brief Constrói o objeto Boleto.
         *
         * @param nome Nome do boleto
         *
         * @param valor Valor do boleto
         * 
         * @param vencimento Data do vencimento do boleto
         *
         */ 
        Boleto(std::string nome, double valor, int dia, int mes);
        /**
         * @brief Destrutor da classe Boleto
         */
        ~Boleto();
          /**
         * @brief ...
         */
        bool get_pago();
        /**
         * @brief efetua o pagamento do boleto
         */
        void pagaBoleto();
        /**
         * @brief função que diz se o boleto venceu
         *
         * @return retorna se venceu ou não
         */
        bool venceu();
        /**
         * @brief apresenta um relatorio da categoria
         */
        void relatorioDeCategoria() override;
};
    class Excecao_Boleto : public std::exception {
        public : 
        const char* what() const noexcept;
    };
    class Excecao_Caracteres_Boleto : public Excecao_Boleto{
        public : 
        const char* what() const noexcept{
             return "O número de caracteres excede o número permitido pelo programa. Por favor, digite novamente o nome.";
        }
    };
    class Excecao_Vencimento_Boleto : public Excecao_Boleto{
        public : 
        const char* what() const noexcept{
             return "A data de vencimento inserida é inválida. Certifique-se que o dia de vencimento está entre 1 e 31 e o mês entre 1 e 12.";
        }
    };
#endif
