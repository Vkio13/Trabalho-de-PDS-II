#include "include/dados.hpp"
int main(){
    Dados d;
    d.adicionaGasto(6,"Bebida","Agua");
    d.adicionaGasto(6,"Bebida","Suco");
    d.adicionaGasto(6,"Bebida","Agua de coco");
    d.adicionaGasto(6,"Bebida","Refrigerante");
    d.adicionaGasto(6,"Bebida com alcool","Vodka");
    d.imprimeGastosTodos();
    d.imprimeCategoriaTotal("Bebida");
    return 0;
}
