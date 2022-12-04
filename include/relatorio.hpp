#ifndef RELATORIO_H
#define RELATORIO_H
#include <vector>
#include "dados.hpp"
#include "categoria.hpp"
/**
 * @file relatorio.hpp
 * @brief Classe onde estão armazenados os relatorios
 * @version 1.5
 * @date 2022-11-24
 * @details TAD com função principal de 
 * conter um relatório com todos os dados
 * sendo eles os gastos e outros inseridos
 * em Dados.hpp
 * 
 * @copyright GNU General Public License 
 * 
 */
/**
         * @brief Gera um relatorio de todas as 
         * categorias
         *
         * @details Recebe as categorias e as insere
         * dentro do relatório.
         *
         */      
    class Relatorio{
/**
         * @brief Lista de categorias
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
         * @param categorias Lista do tipo Categoria
         * contendo todas as categorias registradas
         * e seus dados.
         *
         */ 
        Relatorio();
/**
         * @brief Destrutor do objeto Relatorio.
         *
         */ 
        //~Relatorio();
 /**
         * @brief Printa o relatório mensal.
         * 
         */
        void relatorioMensal(int mes);
 /**
         * @brief Printa o relatório geral.
         * 
         */
        void relatorioGeral();
    };
#endif
