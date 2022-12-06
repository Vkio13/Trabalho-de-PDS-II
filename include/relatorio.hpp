#ifndef RELATORIO_H
#define RELATORIO_H
#include <vector>
#include "dados.hpp"
#include "categoria.hpp"
/**
 * @file relatorio.hpp
 * @brief Classe onde estão armazenados os relatorios
 * @version 1.6
 * @date 2022-12-05
 * @details TAD com função principal de 
 * conter um relatório com todos os dados
 * sendo eles os gastos e outros inseridos
 * em Dados.hpp
 * 
 * @copyright GNU General Public License 
 * 
 */
/**
         * @brief Gera um relatório de todas as 
         * categorias.
         *
         * @details Recebe as categorias e as insere
         * dentro do relatório.
         *
         */      
    class Relatorio{
/**
         * @brief Lista de categorias.
         *
         * @param categorias Lista do tipo Categoria
         * contendo todas as categorias registradas
         * e seus dados.
         *
         */ 
        std::vector<Categoria> _categorias;
    public : 
/**
         * @brief Constrói o objeto Relatorio.
         *
         */ 
        Relatorio();
        //~Relatorio();
 /**
         * @brief Printa o relatório mensal.
         * @param mes Mês solicitado.
         * 
         */
        void relatorioMensal(int mes);
 /**
         * @brief Printa o relatório geral.
         * 
         */
        void relatorioGeral();
    };
/**
         * @brief Exceção de Relatório.
         * @details Ocorre quando o valor digitado é inválido.
         *
         */ 
class Excecao_ValorInvalido_Relatorio : public std::exception {
   public : 
   const char* what() const noexcept;
};
#endif
