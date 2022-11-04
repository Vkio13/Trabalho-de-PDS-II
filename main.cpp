#include "include/despesa.hpp"
#include "include/categoria.hpp"

int main(){
    std::string nome = "Bebidas";
    Categoria c("Bebidas", 1000.0, 0, false);
    Despesa d ("Agua", 10);
    c.registraDespesa(d);
    

    return 0;
}
