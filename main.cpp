#include "include/dados.hpp"
int main(){
    Dados d;
    d.adicionaGasto(6,"Bebida","Agua");
    d.adicionaGasto(6,"Bebida","Suco");
    d.adicionaGasto(6,"Bebida","Agua de coco3");
    d.adicionaGasto(6,"Bebida","Refrigerante4");
    d.adicionaGasto(6,"Bebida com alcool","Vodka");
    d.imprimeGastosTodos();
    d.imprimeCategoriaTotal("Bebida");
    d.deleteGasto(4);

    return 0;
}
