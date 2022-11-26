#ifndef BOLETO_H
#define BOLETO_H
/**
 * @file boleto.hpp
 * @brief Subclasse Boleto 
 * @version 1.0
 * @date 2022-11-24
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
        int _vencimento;
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
        Boleto(std::string nome, int valor, int vencimento);
        /**
         * @brief Destrutor da classe Boleto
         */
        ~Boleto();
          /**
         * @brief efetua o pagamento do boleto
         */
        void vencido();
        bool get_pago();
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
#endif
