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
        <<"4 - Listar boletos existentes" << std::endl
        <<"5 - Exibir descrição de um boleto" << std::endl
        <<"6 - Boletos a pagar" << std::endl
        <<"7 - Adicionar Categoria" << std::endl
        <<"8 - Adicionar Gasto" << std::endl
        <<"9 - Adicionar Receita" << std::endl
        <<"10 - Adicionar Boleto" << std::endl
        <<"11 - Relatórios" << std::endl
        <<"--------------------------"<<std::endl; 
        
        std::string busca;
        std::string nome;
        double orcamento;
        double valor;
        std::string descricao;
        int vencimento;

        switch (op){
        case 1:
            sistema.imprimeCategorias();
            break;
        case 2:
            std::cin >> busca;
            sistema.sobreUmaCategoria(busca);
            break;
        case 3:
            sistema.resumoDeCaixa();
            // std::cin >> busca;
            // sistema.sobreUmBoleto(busca);
            break;
        case 4:
            //sistema.imprimeBoletos();
            break;
        case 5:
            break;
        case 6:
            sistema.boletosAPagar();
            break;
        case 7:
            std::cin >> nome;
            std::cin >> orcamento;
            sistema.adicionaCategoria (Categoria(nome,orcamento));
        case 8:
            std::cin >> nome;
            std::cin >> valor;
            std::cin >> descricao;
            sistema.novoGasto(nome,valor,descricao);
        case 9:
            std::cin >> descricao;
            std::cin >> valor;
            sistema.novaReceita(descricao,valor);
        case 10:
            std::cin >> nome;
            std::cin >> valor;
            std::cin >> vencimento;
            sistema.adicionaBoleto(Boleto(nome,valor,vencimento));
        case 11:
            break;
        default:
            break;
        }
    }
}
