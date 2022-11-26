#include "include/kapemgga.hpp"
int main(){
    Kapemgga sistema;
    sistema.inicializar();
    int op;
    while(std::cin>>op){
        std::cout<<"---------- MENU ----------" << std::endl
        <<"Digite o número correspondete à função desejada:" << std::endl
        <<"1 - Listar categorias existentes" << std::endl
        <<"2 - Exibir descrição de uma categoria" << std::endl
        <<"3 - Status de caixa" << std::endl
        <<"4 - Boletos a pagar" << std::endl
        <<"5 - Adicionar Categoria"<<std::endl
        <<"6 - Adicionar Gasto"<<std::endl
        <<"7 - Adicionar Receita"<<std::endl
        <<"8 - Adicionar Boleto"<<std::endl
        <<"9 - Relatórios"<<std::endl
        <<"--------------------"<<std::endl; 
        switch (op)
        {
        case 1:
            sistema.imprimeCategorias();
            break;
        case 2:
            
            break;
        default:
            break;
        }
    }
}
