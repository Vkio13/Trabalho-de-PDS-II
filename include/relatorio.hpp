#ifndef RELATORIO_H
#define RELATORIO_H
/**
 * @file relatorio.hpp
 * @brief Classe onde estão armazenados os relatorios
 * @version 1.0
 * @date 2022-11-21
 * @details TAD com função principal de 
 * conter um relatório com todos os dados
 * sendo eles os gastos e outros inseridos
 * em Dados.hpp
 * 
 * @copyright GNU General Public License 
 * 
 */
#include "../include/categoria.hpp"

    class Relatorio{
        std::list<Categoria> _categorias;
    public :
/**
         * @brief Constrói o objeto Relatorio.
         * 
         * @details Recebe as categorias e as insere
         * dentro do relatório.
         *
         * @param categorias Lista do tipo Categoria
         * contendo todas as categorias registradas
         * e seus dados.
         *
         */        
        Relatorio(std::list<Categoria> categorias);
/**
         * @brief Destrutor do objeto Relatorio.
         *
         */ 
        ~Relatorio();
 /**
         * @brief Printa o relatório mensal.
         * 
         */
        void relatorioMensal();
 /**
         * @brief Printa o relatório geral.
         * 
         */
        void relatorioGeral();
    };
#endif
