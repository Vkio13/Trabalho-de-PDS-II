#ifndef DADOS_H
#define DADOS_H
#include <string>
  class Dados{
    private:
      std::string historico ="usuario.txt";
    public:
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
