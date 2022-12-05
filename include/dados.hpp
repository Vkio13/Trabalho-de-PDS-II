#ifndef DADOS_H
#define DADOS_H
/**
 * @file dados.hpp
 * @brief Classe onde ocorre a conexão 
 * entre arquivo e código.
 * @version 1.4
 * @date 2022-12-05
 * @details TAD com função principal de 
 * criar uma interação entre arquivos de 
 * salvamento de dasdos e o código.
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
         * @brief Armazena e lê os dados do código.
         *
         * @details Recebe todos os dados do código
         * e adiciona em arquivos com fim de salvameto
         * e da mesma forma, lê o que já foi armazenado.
         *
         */     
  class Dados{
    private:
    /**
         * @brief Arquivo onde são salvos os gastos.
         **/ 
      std::string datgastos ="arquivos/atual/gastos.txt";
        /**
         * @brief Arquivo onde são salvas as receitas.
         **/ 
      std::string datreceita ="arquivos/atual/receita.txt";
        /**
         * @brief Arquivo onde são salvas as categorias.
         **/ 
      std::string datcat ="arquivos/atual/categoria.txt";
        /**
         * @brief Struct de tempo.
         **/ 
      struct tm *tempo;
    public:
        /**
         * @brief Construtor de Dados.
         **/ 
      Dados();
        /**
         * @brief Função para obter o tempo.
         **/ 
      void getTime();
        /**
         * @brief Função que adiciona um gasto.
         * @param valor Valor de um determinado gasto.
         * @param categoria Nome de uma determinada categoria
         * @param descricao Descrição de uma determinada categoria.
         **/ 
      void adicionaGasto(double valor, std::string categoria, std::string descricao);
        /**
         * @brief Imprime os gastos mensais.
         * @param mes Mes correspondente aos gastos.
         **/ 
      void imprimeGastosMensal(int mes);
        /**
         * @brief Imprime os gastos gerais.
         **/ 
      void imprimeGastosTodos();
        /**
         * @brief Imprime os gastos totais de uma categoria em especifico.
         * @param categoria Nome da categoria solicitada.
         **/ 
      void imprimeGastosCategoriaTotal(std::string categoria);
        /**
         * @brief Imprime os gastos mensais de uma categoria especifica.
         * @param categoria Nome da categoria solicitada.
         * @param mes Mês solicitado.
         **/ 
      void imprimeGastosCategoriaMensal(std::string categoria, int mes);
        /**
         * @brief Soma todos os gastos de um mês especifico.
         * @param mes Mês solicitado.
         * @return retorna a soma dos gastos.
         **/ 
      double somaGastosMes(int mes);
        /**
         * @brief Soma os gastos gerais.
         * @return Soma dos gastos.
         **/ 
      double somaGastosTotal();
        /**
         * @brief Soma os gastos especificos de uma determinada categoria.
         * @param categoria Nome da categoria desejada.
         * @return Soma dos gastos.
         **/ 
      double somaGastosCategoria(std::string categoria);
        /**
         * @brief Soma os gastos mensais de uma determinada categoria.
         * @param categoria Nome da categoria desejada.
         * @param mes Mês desejado.
         * @return Soma dos gastos.
         **/ 
      double somaGastosCategoriaMensal(std::string categoria, int mes);
     /**
         * @brief Deleta um gasto especifico.
         * @param codigo Código do gasto a ser deletado.
         **/ 
      void deleteGasto(int codigo);
     /**
         * @brief Adiciona uma receita.
         * @param valor Valor a ser adicionado.
         * @param descricao Descrição da receita a ser adicionada.
         **/ 
      void adicionaReceita(double valor, std::string descricao);
     /**
         * @brief Soma todas as entradas.
         * @return Soma das entradas.
         **/ 
      double somaEntradas();
     /**
         * @brief Soma as entradas de um mês especifico.
         * @param mes Mês desejado.
         * @return Soma das entradas do mês.
         **/ 
      double somaEntradasMes(int mes);
     /**
         * @brief Imprime o total das entradas.
         **/ 
      void imprimeEntradaTotal();
     /**
         * @brief Imprime o total das entradas de um mês em especifico.
         * @param mes Mês a ser analizado.
         **/ 
      void imprimeEntradaMensal(int mes);
     /**
         * @brief Deleta uma receita especifica.
         * @param codigo Código da receita a ser deletada.
         **/ 
      void deleteReceita(int codigo);
     /**
         * @brief Adiciona uma categoria em especifico.
         * @param categoria Nome desejado para categoria.
         * @param orcamento Orçamento da categoria a ser criada.
         **/ 
      void adicionaCategoria(std::string categoria, double orcamento);
     /**
         * @brief Imprime as Categorias.
         **/ 
      void imprimeCategorias();
     /**
         * @brief Verifica uma categoria.
         * @param nome Nome da categoria a ser verificada.
         * @return Linha da categoria.
         **/ 
      int verificaCategoria(std::string nome);
     /**
         * @brief Deleta uma categoria.
         * @param codigo Código da categoria a ser deletada.
         **/ 
      void deleteCategoria(int codigo);
     /**
         * @brief Carrega um vetor de categorias.
         * @return As categorias.
         **/ 
      void vectorCategoria(std::vector<Categoria>& v);
      /**
         * @brief Edita um gasto específico.
         * @param inlinha Linha a ser editada.
         * @param inmes Mes a ser editado.
         * @param india Dia a ser editado.
         * @param invalor Valor a ser editado.
         * @param incategoria Categoria a ser editada.
         * @param indescricao Descrição a ser editada.
         **/ 
      void editaGasto(int inlinha, int inmes, int india, double invalor, std::string incategoria, std::string indescricao);
  };
     /**
         * @brief Exceção de categoria.
         * @details Ocorre quando o valor digitado é inválido.
         **/ 
class Excecao_ValorInvalido_Dados : public std::exception {
   public : 
   const char* what() const noexcept;
};
#endif
