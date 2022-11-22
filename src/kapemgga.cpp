#include <list>
#include <vector>
#include <string>
#include <iostream>

#include "../include/kapemgga.hpp"
#include "../include/categoria.hpp"
#include "../include/caixa.hpp"
#include "../include/boleto.hpp"

Kapemgga::Kapemgga(std::vector<Categoria> categorias, Caixa caixa, std::vector<Boleto> boletos){
    std::vector<Categoria> _categorias = categorias;
    Caixa _caixa = caixa;
    std::vector<Boleto> _boletos = boletos;
}

int Kapemgga::LocalizaCategoria(std::string nome){
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

int Kapemgga::LocalizaBoleto(std::string nome){
    int localizacao = 0;
    for(Categoria bol:_boletos){
        if(bol.get_nome()!=nome){
            localizacao = localizacao + 1;
        }
        if(bol.get_nome()==nome){
            return localizacao;
        }
    }
    std::cout<<"Boleto não encontrada"<<std::endl;
    return -1;
}

void Kapemgga::imprimeCategorias_e_Orcamento(){
    for(Categoria cat:_categorias){
        std::cout << "Categoria:" << cat.get_nome() <<" "<< "Orçamento:" << cat.get_orcamento() << "Gastos:" << cat.get_gasto();
    }
}

void Kapemgga::adicionaCategoria(Categoria cate){
    _categorias.push_back(cate);
}

void Kapemgga::removeCategoria(std::string nome){
    _categorias.erase(_categorias.begin() + LocalizaCategoria(nome));
    
}

void Kapemgga::novaReceita(std::string descricao, double valor){
    _caixa.setReceitas(_caixa.getReceitas() + valor);
}

void Kapemgga::novoGasto(std::string nome, double valor){
    _categorias[LocalizaCategoria(nome)].set_gasto(valor);
}

void Kapemgga::pagaBoleto(std::string nome){
    _boletos[LocalizaBoleto(nome)].pagaBoleto();
    _caixa.setSaldo(_caixa.getSaldo() - _boletos[LocalizaBoleto(nome)].get_orcamento());
}
