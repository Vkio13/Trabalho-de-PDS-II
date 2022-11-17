#ifndef DADOS_H
#define DADOS_H
#include <string>
#include <time.h>
#include <fstream>
#include <iostream>
  class Dados{
    private:
      std::string datgastos ="arquivos/gastos.txt";
      std::string datreceita ="arquivos/receita.txt";
      std::string datcategoria ="arquivos/categoria.txt";
      struct tm *tempo;
    public:
      Dados();
      void getTime();
      void adicionaGasto(double valor, std::string categoria, std::string descricao);
      void adicionaReceita(double valor, std::string descricao);
      void adicionaCategoria(std::string categoria, double ocamento);
      void imprimeGastosMensal(int mes);
      void imprimeGastosTodos();
      double somaGastosMes(int mes);
      double somaGastosTotal();
      double somaGastosCategoria(std::string categoria);
      double somaGastosCategoriaMensal(std::string categoria, int mes);
      double somaEntradas();
      double somaEntradas(int mes);
      void imprimeCategoriaTotal(std::string categoria);
      void imprimeCategoriaMensal(std::string categoria, int mes);
      void imprimeEntradaTotal();
      void imprimeEntradaMensal(int mes);
      void deleteGasto(int codigo);
  };
#endif
