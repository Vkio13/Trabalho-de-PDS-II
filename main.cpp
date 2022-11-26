#include "include/kapemgga.hpp"
int main(){
    Kapemgga sistema;
    sistema.inicializar();
    int op;
    while(std::cin>>op){
        std::cout<<"--------------------"<<std::endl
        <<"1-Exibir Categorias"<<std::endl
        <<"2-Exibir Gastos"<<std::endl
        <<"3-Exibir Receita"<<std::endl
        <<"4-Exibir Boleto"<<std::endl
        <<"5-Adiciona Categoria"<<std::endl
        <<"6-Adiciona Gastos"<<std::endl
        <<"7-Adiciona Receita"<<std::endl
        <<"8-Adiciona Boletos"<<std::endl
        <<"9-Relatórios"<<std::endl
        <<"--------------------"<<std::endl; 
        switch (op)
        {
        case 1:
            sistema.imprimeCategorias();
            break;
        
        default:
            break;
        }
    }
}
