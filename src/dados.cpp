#include "../include/dados.hpp"
std::string replace(std::string n, char c, char s){
    for(long unsigned int i=0; i<n.size(); i++){
        if(n[i]==c){
            n[i]=s;
        }
    }
    return n;
};
void Dados::adicionaGasto(double valor, std::string categoria, std::string descricao){
    std::ofstream arq;
    try{
    arq.open(dados, std::ios::app);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    descricao=replace(descricao,' ','_');
    categoria=replace(categoria,' ','_');
    arq<<std::to_string(valor)<<' '<<categoria<<' '<<descricao<<std::endl;
};
void Dados::adicionaReceita(double valor, std::string descricao){
    std::ofstream arq;
    try{
    arq.open(dados, std::ios::app);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    arq<<"R"<<' '<<std::to_string(valor)<<' '<<descricao<<std::endl;
};
void Dados::adicionaCategoria(std::string categoria, double ocamento){
    std::ofstream arq;
    try{
    arq.open(dados, std::ios::app);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    arq<<"C"<<' '<<std::to_string(ocamento)<<' '<<categoria<<std::endl;
};
void Dados::imprimeGastosTodos(){
    std::ifstream arq;
    try{
    arq.open(dados, std::ios::in);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    std::string categoria;
    std::string descricao;
    double valor;
    while(arq>>valor>>categoria>>descricao){
        descricao=replace(descricao,'_',' ');
        categoria=replace(categoria,'_',' ');
        std::cout<<valor<<"-"<<categoria<<"-"<<descricao<<std::endl;
    }

};
void Dados::imprimeCategoriaTotal(std::string cat){
    std::ifstream arq;
    try{
    arq.open(dados, std::ios::in);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    std::string categoria;
    std::string descricao;
    double valor;
    while(arq>>valor>>categoria>>descricao){
        descricao=replace(descricao,'_',' ');
        categoria=replace(categoria,'_',' ');
        if(cat==categoria){
            std::cout<<valor<<"-"<<categoria<<"-"<<descricao<<std::endl;
        }
    }

};
