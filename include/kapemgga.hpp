#ifndef KAPEMGGA_HPP
#define KAPEMGGA_HPP

#include <vector>
#include <string>
#include <iostream>
#include "categoria.hpp"
#include "caixa.hpp"
#include "boleto.hpp"
#include "inicializador.hpp"


class Kapemgga{
  private:
    std::vector<Categoria>_categorias;
    Caixa _caixa;
    std::vector<Boleto>_boletos;
    Dados d;

  public:
  //Construtor do Kappemgga.
    Kapemgga();

    void inicializar();
  
    int LocalizaCategoria(std::string nome);

    int LocalizaBoleto(std::string nome);

  //Função para imprimir todas as categorias que o usuário tem.
    void imprimeCategorias();
  
  //Função que permite o usuário criar novas categorias.
    void adicionaCategoria(Categoria cate);
  
  //Função que permite o usuário excluir alguma categoria.
    void removeCategoria(std::string nome);
  
  //Função que permite o usuário somar um valor x ao que ele já tem disponível, e especificar a origem do dinheiro.
    void novaReceita(std::string descricao, double valor);
  
  //Função responsável por realizar um gasto dentro de uma categoria especificada.
    void novoGasto(std::string categoria, double valor, std::string descricao);
  
  //Função para pagar determinado boleto, de acordo com seu nome.
    void pagaBoleto(std::string nome);
  
  //Função que genencia boletos pagos e não pagos ao final de um mês.
    void encerraBoletos();

  //Função que lista os boletos ainda não pagos.
    void boletosAPagar();
  
  //Função responsável por dar o comando de fechar o mês.
    void encerraMes();
  
  //Função que permite ao usuário emitir um relatório mensal de gastos e receitas recebidas.
    void relatorioMensal(int mes);
  
  //Função que permite ao usuário emitir um relatório de gastos e receitas recebidas desde que começou a usar o sistema.
    void relatorioGeral();
  
  //Função que permite ao usuário emitir um relatório do dia atual.
    void relatorioAtual();

};

#endif
