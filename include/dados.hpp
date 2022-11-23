#ifndef DADOS_H
#define DADOS_H
#include <string>
#include <time.h>
#include <fstream>
#include <iostream>
#include <vector>
#include "../include/categoria.hpp"
  class Dados{
    private:
      std::string datgastos ="arquivos/gastos.txt";
      std::string datreceita ="arquivos/receita.txt";
      std::string datcategoria ="arquivos/categoria.txt";
      struct tm *tempo;
    public:
      Dados();
      void getTime();
      //Gastos
      void adicionaGasto(double valor, std::string categoria, std::string descricao);
      void imprimeGastosMensal(int mes);
      void imprimeGastosTodos();
      void imprimeGastosCategoriaTotal(std::string categoria);
      void imprimeGastosCategoriaMensal(std::string categoria, int mes);
      double somaGastosMes(int mes);
      double somaGastosTotal();
      double somaGastosCategoria(std::string categoria);
      double somaGastosCategoriaMensal(std::string categoria, int mes);
      void deleteGasto(int codigo);

      //Receita
      void adicionaReceita(double valor, std::string descricao);
      double somaEntradas();
      double somaEntradasMes(int mes);
      void imprimeEntradaTotal();
      void imprimeEntradaMensal(int mes);
      void deleteReceita(int codigo);

      //Categoria
      void adicionaCategoria(std::string categoria, double ocamento);
      void imprimeCategorias();
      int verificaCategoria(std::string nome);
      void deleteCategoria(int codigo);
      std::vector<Categoria> vectorCategoria();
  };
#endif
