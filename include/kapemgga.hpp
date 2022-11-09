#ifndef KAPEMGGA_HPP
#define KAPEMGGA_HPP
#include <list>
#include <string>

class Kapemgga{
  private:
  list<Categoria>_categorias;
  Caixa _caixa;
  public:
  Kapemgga(list<Categoria> categorias, Caixa caixa);
  ~Kapemgga();
  void imprimeCategorias();
  void adicionaCategoria(string nome, double orcamento);
  void removeCategoria(string nome);
  void novaReceita(string descricao, double valor);
  void imprimeLimites();
  void novoGasto(string categoria, double valor)
  void pagaBoleto(string nome);
  void encerraMes();
  void relatorioMensal(int mes);
  void relatorioGeral();
  void relatorioAtual()


#endif
