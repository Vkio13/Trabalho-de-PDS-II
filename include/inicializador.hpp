#ifndef INICIALIZADOR_H
#define INICIALIZADOR_H
/**
 * @file inicializador.hpp
 * @brief Inicializador do programa
 * @version 1.3
 * @date 2022-11-30
 * @details TAD com função principal de 
 * conter a data de vencimento de um 
 * determinado boleto
 * 
 * @copyright GNU General Public License 
 * 
 */
#include <vector>
#include "../include/categoria.hpp"
#include "../include/dados.hpp"
/**
         * @brief Classe contendo o inicializador de 
         * informações e do código.
         *
         * @details Obtém e processa os dados
         * armazenados localmente.
         *
         */  
class Inicializador {
    private:
        Dados d;
        std::vector<Categoria> _categorias;
        double _entradas=0, _gastos=0;
    public :
    /**
         * @brief Constrói a classe Inicializador.
         */
        Inicializador();
    // ~Inicializador();
    //Métodos
    /**
         * @brief Obtém as entradas.
         *
         * @return Retorna as entradas.
         */
        double getEntradas();
    /**
         * @brief Obtém os gastos.
         *
         * @return Retorna o valor dos gastos.
         */
        double getGastos();
    /**
         * @brief Obtém as categorias
         *
         * @return Retorna um vetor com as categorias.
         */
        std::vector<Categoria> getCategorias();
    /**
         * @brief Carrega as entradas.
         */
        void carregaEntradas();
    /**
         * @brief Carrega os gastos.
         */
        void carregaGastos();
    /**
         * @brief Carrega as categorias.
         */
        void carregaCategorias();
};
#endif
