#ifndef DADOS_H
#define DADOS_H
#include <string>
#include <time.h>
#include <fstream>
#include <iostream>
  class Dados{
    private:
      std::string dados ="usuario.txt";
    public:
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
  };
#endif
