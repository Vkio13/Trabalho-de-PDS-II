#include "include/despesa.hpp"
#include "include/categoria.hpp"

int main(){
    std::string nome = "Bebidas";
    Categoria c("Bebidas", 1000.0, 0, false);
    Despesa d ("Agua", 10);
    Despesa f ("Suco", 20);
    c.registraDespesa(d);
    c.registraDespesa(f);
    c.imprimeDespesa();

    return 0;
}
