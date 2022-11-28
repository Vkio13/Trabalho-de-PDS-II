#ifndef DADOS_H
#define DADOS_H
/**
 * @file dados.hpp
 * @brief Classe onde ocorre a conexão 
 * entre arquivo e código
 * @version 1.0
 * @date 2022-11-24
 * @details TAD com função principal de 
 * criar uma interação entre arquivos de 
 * salvamento de dasdos e o código
 * 
 * @copyright GNU General Public License 
 * 
 */
#include <string>
#include <time.h>
#include <fstream>
#include <iostream>
#include <vector>
#include "../include/categoria.hpp"
/**
         * @brief Armazena e lê os dados do código
         *
         * @details Recebe todos os dados do código
         * e adiciona em arquivos com fim de salvameto
         * e da mesma forma, lê o que já foi armazenado
         *
         */     
  class Dados{
    private:
    /**
         * @brief Arquivo onde são salvos os gastos
         **/ 
      std::string datgastos ="arquivos/gastos.txt";
        /**
         * @brief Arquivo onde são salvas as receitas
         **/ 
      std::string datreceita ="arquivos/receita.txt";
        /**
         * @brief Arquivo onde são salvas as categorias
         **/ 
      std::string datcat ="arquivos/categoria.txt";
        /**
         * @brief Struct de tempo
         **/ 
      struct tm *tempo;
    public:
        /**
         * @brief Construtor de Dados
         **/ 
      Dados();
        /**
         * @brief Função para obter o tempo
         **/ 
      void getTime();
        /**
         * @brief Função que adiciona um gasto
         * @param valor Valor de um determinado gasto
         * @param categoria Nome de uma determinada categoria
         * @param descricao Descrição de uma determinada categoria
         **/ 
      void adicionaGasto(double valor, std::string categoria, std::string descricao);
        /**
         * @brief Imprime os gastos mensais
         * @param mes Mes correspondente aos gastos
         **/ 
      void imprimeGastosMensal(int mes);
        /**
         * @brief Imprime os gastos gerais
         **/ 
      void imprimeGastosTodos();
        /**
         * @brief Imprime os gastos totais de uma categoria em especifico
         * @param categoria Nome da categoria solicitada
         **/ 
      void imprimeGastosCategoriaTotal(std::string categoria);
        /**
         * @brief Imprime os gastos mensais de uma categoria especifica
         * @param categoria Nome da categoria solicitada
         * @param mes Mês solicitado
         **/ 
      void imprimeGastosCategoriaMensal(std::string categoria, int mes);
        /**
         * @brief Soma todos os gastos de um mês especifico
         * @param mes Mês solicitado
         * @return retorna a soma dos gastos
         **/ 
      double somaGastosMes(int mes);
        /**
         * @brief Soma os gastos gerais
         **/ 
      double somaGastosTotal();
        /**
         * @brief Soma os gastos especificos de uma determinada categoria
         * @param categoria Nome da categoria desejada
         * @return retorna a soma dos gastos
         **/ 
      double somaGastosCategoria(std::string categoria);
        /**
         * @brief Soma os gastos mensais de uma determinada categoria
         * @param categoria Nome da categoria desejada
         * @param mes Mês desejado
         * @return retorna a soma dos gastos
         **/ 
      double somaGastosCategoriaMensal(std::string categoria, int mes);
     /**
         * @brief Deleta um gasto especifico
         * @param codigo Código do gasto a ser deletado
         **/ 
      void deleteGasto(int codigo);

      //Receita
     /**
         * @brief Adiciona uma receita
         * @param valor Valor a ser adicionado 
         * @param descricao Descrição da receita a ser adicionada
         **/ 
      void adicionaReceita(double valor, std::string descricao);
     /**
         * @brief Soma todas as entradas
         * @return retorna a soma das entradas
         **/ 
      double somaEntradas();
     /**
         * @brief Soma as entradas de um mês especifico
         * @param mes Mês desejado
         * @return retorna a soma das entradas do mês
         **/ 
      double somaEntradasMes(int mes);
     /**
         * @brief Imprime o total das entradas
         **/ 
      void imprimeEntradaTotal();
     /**
         * @brief Imprime o total das entradas de um mês em especifico
         **/ 
      void imprimeEntradaMensal(int mes);
     /**
         * @brief Deleta uma receita especifica
         * @param codigo Codigo da receita a ser deletada
         **/ 
      void deleteReceita(int codigo);

      //Categoria
     /**
         * @brief Adiciona uma ccategoria em especifico
         * @param categoria Nome desejado para categoria
         * @param orcamento Orçamento da categoria a ser criada
         **/ 
      void adicionaCategoria(std::string categoria, double orcamento);
     /**
         * @brief Imprime as Categorias
         **/ 
      void imprimeCategorias();
     /**
         * @brief Verifica uma categoria
         * @param nome Nome da categoria a ser verificada
         **/ 
      int verificaCategoria(std::string nome);
     /**
         * @brief Deleta uma categoria
         * @param codigo Código da categoria a ser deletada
         **/ 
      void deleteCategoria(int codigo);
     /**
         * @brief Carrega vetor de categorias
         * @return Retorna as categorias
         **/ 
      void vectorCategoria(std::vector<Categoria>& v);
      /**
         * @brief Carrega vetor de categorias
         * @return Retorna as categorias
         **/ 
      void editaGasto(int inlinha, int inmes, int india, double invalor, std::string incategoria, std::string indescricao);
  };
#endif
