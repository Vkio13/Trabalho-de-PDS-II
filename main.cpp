#include "kapemgga.hpp"
#include "dados.hpp"
#include "usuario.hpp"
#include "relatorio.hpp"
void menu(std::vector<std::string> opcoes);
int main(){
    Dados dados;
    Usuario usuario;
    Kapemgga sistema;
    Relatorio relatorio;
    int op;
    //usuario.verifica();
    while(true){
        menu({"Login","Criar Usuário","Entrar","Deletar Usuário","Sair"});
        std::cin>>op;
        std::string busca, nome, senha, descricao, categoria;
        int codigo,mes,dia;
        double valor,orcamento;
        switch (op)
        {
        case 1:
            std::cout<<"Nome: ";
            getchar();
            std::getline(std::cin, nome);
            std::cout<<"Senha: ";
            std::getline(std::cin, senha);
            usuario.criarUsuario(nome, senha);
            break;
        case 2:
            std::cout<<"Nome: ";
            getchar();
            std::getline(std::cin, nome);
            std::cout<<"Senha: ";
            std::getline(std::cin, senha);
            usuario.entrarUsuario(nome, senha);
            break;
        case 3:
            std::cout<<"Nome: ";
            getchar();
            std::getline(std::cin, nome);
            usuario.deletarUsuario(nome); 
            break;
        case 4:
            usuario.~Usuario();
            exit(0);
            break;
        default:
            std::cout<<"Escolha uma opção válida."<<std::endl;
            break;
        }
        while(usuario.getLogado()){
            menu({"Menu KAPEMGGA","Relatórios","Receita","Boletos","Categorias","Gastos","Editar Senha","Trocar Usuário / Sair"});
            std::cin>>op;
            sistema.inicializar();
            switch (op)
            {
            case 1:
                menu({"Relatórios","Resumo do Caixa", "Relatório Total", "Relatório Mensal"});
                std::cin>>op;
                switch(op){
                    case 1:
                        sistema.resumoDeCaixa();
                    break;
                    case 2:
                        relatorio.relatorioGeral();
                    break;
                    case 3:
                    std::cout<<"Escolha o mês: ";
                        std::cin>>mes;
                        try{
                            relatorio.relatorioMensal(0);
                        }
                        catch(Excecao_ValorInvalido_Relatorio &e){
                            std::cout<<e.what()<<std::endl;
                        }
                    break;
                }
            break;
            case 2:
                menu({"Receita","Adicionar Receitas", "Imprime Receitas", "Imprime Receitas Mensal",/*"Excluir Receita",*/ "Voltar"});
                std::cin>>op;
                switch(op){
                    case 1:
                        std::cin.ignore();
                        std::cout << "Digite a descrição da sua receita: " << std::endl;
                        std::getline(std::cin, descricao);
                        std::cout << "Digite o valor: " << std::endl;
                        std::cin >> valor;
                        try{
                        sistema.novaReceita(descricao,valor);
                        }catch(Excecao_Caixa &e){
                            if(descricao.size()>20){
                                do{
                                    std::cout << e.what() << std::endl;
                                    std::cout << "Insira a descrição: " << std::endl;
                                    std::cin.ignore();
                                    std::getline(std::cin, descricao);
                                }while(descricao.size()>20);
                            }
                            if(valor < 0 || valor > 2147483646 ){
                            do{
                                std::cout << e.what() << std::endl;
                                std::cout << "Insira o valor: " << std::endl;
                                if(true){
                                std::cin >> valor;
                                }
                                }while(valor<0 || valor > 2147483646);
                            }
                            sistema.novaReceita(descricao,valor);
                        }
                        break;
                    case 2:
                        dados.imprimeEntradaTotal();
                        break;
                    case 3:
                        std::cout<<"Escolha o mês: ";
                        std::cin>>mes;
                        try{
                        dados.imprimeEntradaMensal(mes);
                        }
                        catch(Excecao_ValorInvalido_Dados &e){
                            std::cout<<e.what()<<std::endl;

                        }
                        break;
                    case 4:
                        std::cout<<"Voltando para o menu principal"<<std::endl;
                    default:
                        std::cout<<"Voltando para o menu principal"<<std::endl;

                }
                break;
            case 3:
                menu({"Boletos","Descrição de um Boleto","Imprimir Boletos","Adicionar Boleto","Pagar Boleto", "Boletos Pendentes"});
                std::cin>>op;
                switch(op){
                    case 1:
                        std::cout << "Digite o nome do boleto a ser pesquisado: " <<std::endl;
                        std::cin>>busca;
                        sistema.sobreUmBoleto(busca);
                    break;

                    case 2:
                        sistema.imprimeBoletos();
                    break;

                    case 3:
                        std::cout << "Digite o nome do Boleto: " << std::endl;
                        std::cin.ignore();
                        std::getline(std::cin, nome);
                        std::cout << "Digite o valor do Boleto: " << std::endl;
                        std::cin >> valor;
                        std::cout << "Digite o dia de vencimento do boleto: " << std::endl;
                        std::cin >> dia;
                        std::cout << "Digite o mês de vencimento do boleto: " << std::endl;
                        std::cin >> mes;
                        try{
                            sistema.adicionaBoleto(Boleto(nome,valor,dia,mes));
                        }catch(Excecao_Boleto &e){
                            if(valor<0 || valor > 2147483646 ){
                                do{
                                    std::cout << e.what() << std::endl;
                                    std::cin >> valor;  
                                }while(valor<0 || valor > 2147483646 );
                            }
                            if(nome.size()>20){
                                do{
                                    std::cout << e.what() << std::endl;
                                    std::cin.ignore();
                                    std::getline(std::cin, nome);  
                                }while(nome.size()>20);
                            }
                            if(dia < 1 || dia > 31 || mes < 1 || mes > 12){
                                do{
                                    std::cout << e.what() << std::endl;
                                    std::cout << "Digite o dia de vencimento do boleto: " << std::endl;
                                    std::cin >> dia;
                                    std::cout << "Digite o mês de vencimento do boleto: " << std::endl;
                                    std::cin >> mes;
                                }while(dia < 1 || dia > 31 || mes < 1 || mes > 12);
                            }
                            if(LocalizaBoleto(nome)!=-1){
                                do{
                                    std::cout << e.what() << std::endl;
                                    std::cin >> nome; 
                                }while(LocalizaBoleto(nome)!=-1); 
                            }
                            sistema.adicionaBoleto(Boleto(nome,valor,dia,mes);
                    }
                    break;

                    case 4:
                        std::cout << "Digite o nome do boleto: "<<std::endl;
                        getchar();
                        std::getline(std::cin, nome);
                        sistema.pagaBoleto(nome);
                    break;

                    case 5:
                    sistema.boletosAPagar();
                    break;
                }
            break;
            case 4:
                menu({"Categoria","Imprimir Categorias","Descrição de uma Categoria","Adicionar Categoria", "Remover Categoria"});
                std::cin>>op;
                switch(op){

                case 1:
                sistema.imprimeCategorias();
                break;

                case 2:
                    getchar();
                    std::getline(std::cin, busca);
                    sistema.sobreUmaCategoria(busca);
                    break;

                case 3:
                    std::cout << "Digite o nome da Categoria: " << std::endl;
                    getchar();
                    std::getline(std::cin, nome);
                    std::cout << "Digite o orçamento da Categoria: " << std::endl;
                    std::cin >> orcamento;
                    try{
                        sistema.adicionaCategoria (Categoria(nome,orcamento));
                    }catch(Excecao_Categoria &e){
                        if(orcamento<0 || orcamento > 2147483646){
                            do{
                                std::cout << e.what() << std::endl;
                                if(orcamento<0){
                                std::cin >> orcamento;
                                }
                            }while(orcamento<0 || orcamento > 2147483646);
                        }
                        if(nome.size()>20){
                            do{
                                std::cout << e.what() << std::endl;
                                std::cin >> nome; 
                            }while(nome.size()>20);
                        }
                        if(LocalizaCategoria(nome)!=-1){
                            do{
                                std::cout << e.what() << std::endl;
                                std::cin >> nome; 
                            }while(LocalizaCategoria(nome)!=-1); 
                        }
                        sistema.adicionaCategoria (Categoria(nome,orcamento));
                    }
                break;
                case 4:
                    std::cout<<"Digite o código da categoria que deseja excluir: ";
                    std::cin>>codigo;
                    try{
                    dados.deleteCategoria(codigo);
                    }catch(Excecao_ValorInvalido_Dados &e){
                        std::cout<<e.what()<<std::endl;
                    }
                break;
                }
            break;
            case 5:
                menu({"Gastos","Imprimir Gastos Totais","Imprimir Gastos Mensais","Adicionar Gastos", "Editar Gasto", "Excluir Gasto","Voltar"});
                std::cin>>op;
                switch(op){
                    case 1:
                        dados.imprimeGastosTodos();
                    break;
                    case 2:
                        std::cout<<"Escolha o mês: ";
                        std::cin>>mes;
                        try{
                        dados.imprimeGastosMensal(mes);
                        }
                        catch(Excecao_ValorInvalido_Dados &e){
                            std::cout<<e.what()<<std::endl;

                        }
                    break; 
                    case 3:
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
                            if(valor<0 || valor > 2147483646){
                            do{
                                std::cout << e.what() << std::endl;
                                if(true){
                                std::cin >> valor;
                            }
                                }while(valor<0 || valor > 2147483646);
                            }
                            if(descricao.size()>100){
                            do{
                                std::cout << e.what() << std::endl;
                                std::cin.ignore();
                                std::getline(std::cin, descricao);
                            }while(descricao.size()>100);
                        }
                    sistema.novoGasto(nome,valor,descricao);
                    }
                    break;
                    case 4:
                        std::cout<<"Código: ";
                        std::cin>>codigo;
                        std::cout<<"Mês: ";
                        std::cin>>mes;
                        std::cout<<"Dia: ";
                        std::cin>>dia;
                        std::cout<<"Valor: ";
                        std::cin>>valor;
                        std::cout<<"Categoria: ";
                        std::cin.ignore();
                        std::getline(std::cin, categoria);  
                        std::cout<<"Descrição: ";
                        std::getline(std::cin, descricao);                                             
                        try{
                            dados.editaGasto(codigo, mes, dia, valor, categoria, descricao);
                        }
                        catch(Excecao_ValorInvalido_Dados &e){
                            std::cout<<e.what()<<std::endl;
                        }
                    break;
                    case 5:
                        std::cout<<"Código: ";
                        std::cin>>codigo;
                        try{
                            dados.deleteGasto(codigo);
                        }
                        catch(Excecao_ValorInvalido_Dados &e){
                            std::cout<<e.what()<<std::endl;
                        }
                    break;                        
                    case 6:
                        std::cout<<"Voltando para o menu principal"<<std::endl;
                    default:
                        std::cout<<"Voltando para o menu principal"<<std::endl;
                }
                break;
            case 6:
                std::cout<<"Senha: ";
                getchar();
                std::getline(std::cin, senha);
                usuario.editarSenha(senha);
                break;
            case 7:
                usuario.sair();
                break;
            default:
                std::cout<<"Escolha uma opção válida"<<std::endl;
                break;
            }
        }
    }
   /* while(std::cin>>op){
        std::cout<<"-------------------- MENU --------------------" << std::endl
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
        <<"12 - Encerrar o programa" << std::endl
        <<"----------------------------------------------"<<std::endl; 
        
        std::string busca;
        std::string nome;
        std::string senha;
        double orcamento;
        double valor;
        std::string descricao;
        Relatorio r;
        Dados d;
        int mes, dia, linha;
        std::string descricao_, categoria_;
        
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
            sistema.imprimeBoletos();
            break;
        case 5:
            std::cin>>busca;
            sistema.sobreUmBoleto(busca);
            break;
        case 6:
            sistema.boletosAPagar();
            break;
        case 7:
        //Só aceita orçamento positivo e nome com menos de 20 caracteres
            std::cin >> nome;
            std::cin >> orcamento;
            try{
                sistema.adicionaCategoria (Categoria(nome,orcamento));
            }catch(Excecao_Categoria &e){
                if(orcamento<0 || orcamento > 2147483646){
                    do{
                        std::cout << e.what() << std::endl;
                        if(orcamento<0){
                        std::cin >> orcamento;
                        }
                        }while(orcamento<0 || orcamento > 2147483646);
                }
                if(nome.size()>20){
                    do{
                        std::cout << e.what() << std::endl;
                        std::cin >> nome; 
                        }while(nome.size()>20);
                }            
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
                if(valor<0 || valor > 2147483646){
                    do{
                        std::cout << e.what() << std::endl;
                        if(true){
                        std::cin >> valor;
                        }
                    }while(valor<0 || valor > 2147483646);
                }
                if(descricao.size()>100){
                    do{
                        std::cout << e.what() << std::endl;
                        std::cin.ignore();
                        std::getline(std::cin, descricao);
                    }while(descricao.size()>100);
                }
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
                if(valor < 0 || valor > 2147483646 ){
                 do{
                    std::cout << e.what() << std::endl;
                    if(true){
                    std::cin >> valor;
                    }
                    }while(valor<0 || valor > 2147483646);
                }
                if(descricao.size()>100){
                    do{
                        std::cout << e.what() << std::endl;
                        std::cin.ignore();
                        std::getline(std::cin, descricao);
                    }while(descricao.size()>100);
                }
            
            sistema.novaReceita(descricao,valor);
            // Aqui ainda tem um erro - Precisa digitar uma string para dar prosseguimento a função. Não sei o motivo.
            }
            break;
        case 10:
        //O NOME DO BOLETO NÃO SERIA MELHOR COLOCAR COMO STRING?
        //ACHO QUE SERIA INTERESSANTE COLOCAR STRING NO NOME E LIMITAR O NUMERO DE CARACTERES PARA 20 OU ALGO DO GENERO
            std::cout << "Digite o nome do Boleto: " << std::endl;
            std::cin.ignore();
            std::getline(std::cin, nome);
            std::cout << "Digite o valor do Boleto: " << std::endl;
            std::cin >> valor;
            std::cout << "Digite o dia de vencimento do boleto: " << std::endl;
            std::cin >> dia;
            std::cout << "Digite o mês de vencimento do boleto: " << std::endl;
            std::cin >> mes;
            try{
                sistema.adicionaBoleto(Boleto(nome,valor,dia,mes));
            }catch(Excecao_Boleto &e){
                if(valor<0 || valor > 2147483646 ){
                    do{
                        std::cout << e.what() << std::endl;
                        std::cin >> valor;  
                    }while(valor<0 || valor > 2147483646 );
                }
                if(nome.size()>20){
                    do{
                        std::cout << e.what() << std::endl;
                        std::cin.ignore();
                        std::getline(std::cin, nome);  
                    }while(nome.size()>20);
                }
                if(dia < 1 || dia > 31 || mes < 1 || mes > 12){
                    do{
                        std::cout << e.what() << std::endl;
                        std::cout << "Digite o dia de vencimento do boleto: " << std::endl;
                        std::cin >> dia;
                        std::cout << "Digite o mês de vencimento do boleto: " << std::endl;
                        std::cin >> mes;
                    }while(dia < 1 || dia > 31 || mes < 1 || mes > 12);
                }
                sistema.adicionaBoleto(Boleto(nome,valor,dia,mes));
            }
            //AQUI O BOLETO PODE TER PROBLEMA COM A DATA QUE O USUARIO COLOCAR, SERÁ NECESSÁRIO VERIFICAR ESSES NUMEROS
            //OUTRO ERRO QUE PODE TER NO VALOR É O ERRO DE OVERFLOW
            break;
        case 11:
            
            d.imprimeGastosTodos();
            break;
        case 12:

            exit(0);

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
            usuario.criarUsuario("gustavo", "12345");
            std::cout<<usuario.procuraUsuario("gustavo");
            break;
        case 22:
            r.relatorioGeral();
            break;
        case 23:
            std::cin>>mes;
            r.relatorioMensal(mes);
            break;
        case 24:
            std::cout<<"Nome: ";
            std::cin>>nome;
            std::cout<<"Senha: ";
            std::cin>>senha;
            usuario.criarUsuario(nome, senha);
            break;
        case 25:
            std::cout<<"Nome: ";
            std::cin>>nome;
            std::cout<<"Senha: ";
            std::cin>>senha;
            usuario.entrarUsuario(nome, senha);
            break;
        case 26:
            std::cout<<"Senha: ";
            std::cin>>senha;
            usuario.editarSenha(senha);
            break;
        case 27:
            usuario.sair();
            break;
        default:
            break;
        }
    }*/
}












void menu(std::vector<std::string> opcoes){
    std::cout<<"==============================| "<<opcoes[0]<<" |=============================="<<std::endl;
    for(int i=1; i<opcoes.size(); i++){
        std::cout<<i<<" - "<<opcoes[i]<<std::endl;
    }
    for(int i=0; i<64+opcoes[0].size(); i++){
        std::cout<<"=";
    }
    std::cout<<std::endl;
};
