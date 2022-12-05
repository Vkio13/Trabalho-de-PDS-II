#ifndef INICIALIZADOR_H
#define INICIALIZADOR_H
/**
 * @file inicializador.hpp
 * @brief Inicializador do programa.
 * @version 1.5
 * @date 2022-12-05
 * @details TAD com função principal de 
 * conter a data de vencimento de um 
 * determinado boleto.
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
        /**
         * @brief Variavél contendo dados gerais pra inicialização do código.
         */
        Dados d;
        /**
         * @brief Vetor contendo as categorias.
         */
        std::vector<Categoria> _categorias;
        /**
         * @brief Variavél contendo o valor das entradas.
         */
        double _entradas=0;
        /**
         * @brief Variavél contendo o valor dos gastos.
         */
        double _gastos=0;
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
         * @return As entradas.
         */
        double getEntradas();
    /**
         * @brief Obtém os gastos.
         *
         * @return Valor dos gastos.
         */
        double getGastos();
    /**
         * @brief Obtém todas as categorias
         *
         * @return Vetor com as categorias.
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
