#ifndef DADOS_H
#define DADOS_H
#include <string>
  class Dados{
    private:
      string historico ="usuario.txt";
    public:
      void imprimeGastosMensal(int mes);
      void imprimeGastosTodos();
      double somaGastosMes(int mes);
      double somaGastosTotal();
      double somaGastosCategoria(string categoria);
      double somaGastosCategoriaMensal(string categoria, int mes);
      double somaEntradas();
      double somaEntradas(int mes);
      void imprimeCategoriaTotal(string categoria);
      void imprimeCategoriaMensal(string categoria, int mes);
  };
#endif
