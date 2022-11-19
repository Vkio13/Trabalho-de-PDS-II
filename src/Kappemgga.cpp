#include <list>
#include <string>
#include <iostream>

#include "kappemga.hpp"
#include "categoria.hpp"
#include "caixa.hpp"

Kapemgga::Kapemgga(std::list<Categoria> categorias, Caixa caixa){
    std::list<Categoria> _categorias = categorias;
    Caixa _caixa = caixa;
}

void Kapemgga::imprimeCategorias(){
    for(Categoria cat:categorias){
        std::cout<<cat;
    }
}
