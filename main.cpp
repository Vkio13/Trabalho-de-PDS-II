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
        <<"5 - Adicionar Categoria" << std::endl
        <<"6 - Adicionar Gasto" << std::endl
        <<"7 - Adicionar Receita" << std::endl
        <<"8 - Adicionar Boleto" << std::endl
        <<"9 - Relatórios" << std::endl
        <<"--------------------------"<<std::endl; 
        
        std::string busca;

        switch (op)
        {
        case 1:
            sistema.imprimeCategorias();
            break;
        case 2:
            std::cin >> busca;
            sistema.sobreUmaCategoria(busca);
            break;
        case 3:
            sistema.resumoDeCaixa();
            break;
        case 4:
            sistema.boletosAPagar();
            break;
        case 5:
            std::cin>>nome;
            std::cin >>orcamento;
            sistema.adicionaCategoria(Categoria(nome,orcamento));
        case 6:
            std::cin>>nome;
            std::cin>>valor;
            std::cin>>descricao;
            sistema.novoGasto(nome,valor,descricao);
        case 7:
            std::cin>>descricao;
            std::cin>>valor;
            sistema.novaReceita(descricao,valor);
        case 8:
            std::cin>>nome;
            std::cin>>val;
            std::cin>>vencimento;
            sistema.adicionaBoleto(Boleto(nome,val,vencimento));
        case 9:
            break;
        default:
            break;
        }
    }
}
