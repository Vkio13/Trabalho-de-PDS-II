#include "include/kapemgga.hpp"
#include "include/dados.hpp"
#include "include/usuario.hpp"
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
        <<"12 - Encerrar o Programa" << std::endl
        <<"--------------------------"<<std::endl; 
        
        std::string busca;
        std::string nome;
        double orcamento;
        double valor;
        std::string descricao;
        int vencimento;

        Dados d;
        int mes, dia, linha;
        std::string descricao_, categoria_;
        Usuario u;
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
            std::cin >> busca;
            sistema.sobreUmBoleto(busca);
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
        /*ACHO QUE SERIA INTERESSANTE COLOCAR STRING NO NOME E LIMITAR O NUMERO DE CARACTERES PARA 20 OU ALGO DO GENERO*/
            std::cin >> nome;
            std::cin >> orcamento;
            try{
                sistema.adicionaCategoria (Categoria(nome,orcamento));
            }catch(Excecao_Categoria &e){
                 do{
                    std::cout << e.what() << std::endl;
                    if(true){
                    std::cin >> orcamento;
                    }
                    }while(orcamento<0);
            sistema.adicionaCategoria (Categoria(nome,orcamento));
            }
            break;
        case 8:
            std::cout << "Digite o nome da Categoria: " << std::endl;
            std::cin >> nome;
            std::cout << "Digite o valor: " << std::endl;
            std::cin >> valor;
            std::cout << "Digite a descrição: " << std::endl;
            std::cin.ignore();
            std::getline(std::cin, descricao);
            try{
            sistema.novoGasto(nome,valor,descricao);
            }catch(Excecao_Caixa &e){
                 do{
                    std::cout << e.what() << std::endl;
                    if(true){
                    std::cin >> valor;
                    }
                    }while(valor<0);
            //      do{
            //         std::cout << e.what() << std::endl;
            //         std::cin.ignore();
            //         std::getline(std::cin, nome);  
            //         }while(nome.size()>20);
            // }
            sistema.novoGasto(nome,valor,descricao);
            //Vamos limitar o tamanho de caracteres da descricao, nao consegui implementar isso agr
            // Aqui ainda tem um erro - Precisa digitar uma string para dar prosseguimento a função. Não sei o motivo.
            }
            break;
        case 9:
            std::cin.ignore();
            std::cout << "Digite a descrição da sua receita: " << std::endl;
            std::getline(std::cin, descricao);
            std::cout << "Digite o valor: " << std::endl;
            std::cin >> valor;
            try{
            sistema.novaReceita(descricao,valor);;
            }catch(Excecao_Caixa &e){
                 do{
                    std::cout << e.what() << std::endl;
                    if(true){
                    std::cin >> valor;
                    }
                    }while(valor<0);
                //  do{
                //     std::cout << e.what() << std::endl;
                //     std::cin.ignore();
                //     std::getline(std::cin, nome);  
                //     }while(nome.size()>20);
            // }
            sistema.novaReceita(descricao,valor);
            // Aqui ainda tem um erro - Precisa digitar uma string para dar prosseguimento a função. Não sei o motivo.
            }
            break;
        case 10:
        /*O NOME DO BOLETO NÃO SERIA MELHOR COLOCAR COMO STRING?*/
        /*ACHO QUE SERIA INTERESSANTE COLOCAR STRING NO NOME E LIMITAR O NUMERO DE CARACTERES PARA 20 OU ALGO DO GENERO*/
            std::cout << "Digite o nome do Boleto: " << std::endl;
            std::cin.ignore();
            std::getline(std::cin, nome);
            std::cout << "Digite o valor do Boleto: " << std::endl;
            std::cin >> valor;
            std::cout << "Digite a data de Vencimento: " << std::endl;
            std::cin >> vencimento;
            try{
            sistema.adicionaBoleto(Boleto(nome,valor,vencimento));
            }catch(Excecao_Boleto &e){
            if(valor<0){
                do{
                std::cout << e.what() << std::endl;
                std::cin >> valor;  
                }while(valor<0);
            }
            if(nome.size()>20){
            do{
                std::cout << e.what() << std::endl;
                std::cin.ignore();
                std::getline(std::cin, nome);  
                }while(nome.size()>20);
            }
            sistema.adicionaBoleto(Boleto(nome,valor,vencimento));
            }
            /*AQUI O BOLETO PODE TER PROBLEMA COM A DATA QUE O USUARIO COLOCAR, SERÁ NECESSÁRIO VERIFICAR ESSES NUMEROS
            OUTRO ERRO QUE PODE TER NO VALOR É O ERRO DE OVERFLOW*/
            break;
        case 11:
            
            d.imprimeGastosTodos();
            break;
        case 12: 
            return 0;
        case 20:
            std::cout<<"Linha: ";
            std::cin>>linha;
            std::cout<<"Mes: ";
            std::cin>>mes;
            std::cout<<"Dia: ";
            std::cin>>dia;
            std::cout<<"Valor: ";
            std::cin>>valor;
            getchar();
            std::cout<<"Categoria: ";
            getline(std::cin, categoria_);
            std::cout<<"Descrição: ";
            getline(std::cin, descricao_);
            d.editaGasto(linha, mes, dia, valor, categoria_, descricao_);
            break;
        case 21:
            u.criarUsuario("gustavo", "12345");
        default:
            break;
        }
    }
}
