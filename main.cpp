#include "include/dados.hpp"
#include "include/caixa.hpp"
int main(){
    Dados d;
    d.adicionaGasto(6,"Bebida","Stella-Artois");
    d.adicionaGasto(6,"Bebida","Suco");
    d.adicionaGasto(6,"Bebida","Agua de coco3");
    d.adicionaGasto(6,"Bebida","Refrigerante4");
    d.adicionaGasto(6,"Bebida com alcool","Vodka");
    d.imprimeCategorias();
    d.imprimeGastosTodos();
    d.imprimeGastosCategoriaTotal("Bebida");
    d.deleteGasto(4);
    Caixa nada;
    return 0;
}
