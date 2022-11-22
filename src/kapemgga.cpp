#include <list>
#include <vector>
#include <string>
#include <iostream>

#include "kapemgga.hpp"
#include "categoria.hpp"
#include "caixa.hpp"

Kapemgga::Kapemgga(std::vector<Categoria> categorias, Caixa caixa){
    std::vector<Categoria> _categorias = categorias;
    Caixa _caixa = caixa;
}

int Kapemgga::Localiza(std::string nome){
    int localizacao = 0;
    for(Categoria cat:_categorias){
        if(cat.get_nome()!=nome){
            localizacao = localizacao + 1;
        }
        if(cat.get_nome()==nome){
            return localizacao;
        }
    }
    std::cout<<"Categoria não encontrada"<<std::endl;
    return -1;
}

void Kapemgga::imprimeCategorias_e_Orcamento(){
    for(Categoria cat:_categorias){
        std::cout << "Categoria:" << cat.get_nome() <<" "<< "Orçamento:" << cat.getOrcamento() << "Gastos:" << cat.get_gasto();
    }
}

void Kapemgga::adicionaCategoria(Categoria cate){
    _categorias.push_back(cate);
}

void Kapemgga::removeCategoria(std::string nome){
    _categorias.erase(_categorias.begin() + Localiza(nome));
    
}

void Kapemgga::novaReceita(std::string descricao, double valor){
    _caixa.setReceitas(_caixa.getReceitas() + valor);
}

void Kapemgga::novoGasto(std::string nome, double valor){
    _categorias[Localiza(nome)].adiciona_Gasto(valor);
}
