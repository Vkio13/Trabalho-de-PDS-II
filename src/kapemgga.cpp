#include <list>
#include <string>
#include <iostream>

#include "../include/kapemgga.hpp"
#include "../include/categoria.hpp"
#include "../include/caixa.hpp"

Kapemgga::Kapemgga(std::list<Categoria> categorias, Caixa caixa){
    std::list<Categoria> _categorias = categorias;
    Caixa _caixa = caixa;
}

void Kapemgga::imprimeCategorias(){
    for(Categoria cat:_categorias){
        std::cout << cat.get_nome();
    }
}

void Kapemgga::adicionaCategoria(Categoria cate){
    _categorias.push_back(cate);
}

