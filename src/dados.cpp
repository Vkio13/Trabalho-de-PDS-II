#include "../include/dados.hpp"
void Dados::getTime(){
    time_t t;
    time (&t);
    tempo=localtime(&t);
};
std::string replace(std::string n, char c, char s){
    for(long unsigned int i=0; i<n.size(); i++){
        if(n[i]==c){
            n[i]=s;
        }
    }
    return n;
};
Dados::Dados(){
    Dados::getTime();
}
void Dados::adicionaGasto(double valor, std::string categoria, std::string descricao){
    std::ofstream arq;
    try{
    arq.open(datgastos, std::ios::app);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    descricao=replace(descricao,' ','_');
    categoria=replace(categoria,' ','_');
    getTime();
    arq<<tempo->tm_mon<<' '<<tempo->tm_mday<<' '<<std::to_string(valor)<<' '<<categoria<<' '<<descricao<<std::endl;
};
void Dados::adicionaReceita(double valor, std::string descricao){
    std::ofstream arq;
    try{
    arq.open(datreceita, std::ios::out | std::ios::app);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    descricao=replace(descricao,' ','_');
    getTime();
    arq<<tempo->tm_mon<<' '<<tempo->tm_mday<<' '<<std::to_string(valor)<<' '<<descricao<<std::endl;
};
void Dados::adicionaCategoria(std::string categoria, double ocamento){
    std::ofstream arq;
    try{
    arq.open(datcategoria, std::ios::app);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    categoria=replace(categoria,' ','_');
    getTime();
    arq<<tempo->tm_mon<<' '<<tempo->tm_mday<<' '<<std::to_string(ocamento)<<' '<<categoria<<std::endl;
};
void Dados::imprimeGastosTodos(){
    std::ifstream arq;
    try{
    arq.open(datgastos, std::ios::in);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    std::string categoria;
    std::string descricao;
    double valor;
    int mes, dia;
    while(arq>>mes>>dia>>valor>>categoria>>descricao){
        descricao=replace(descricao,'_',' ');
        categoria=replace(categoria,'_',' ');
        std::cout<<mes<<"/"<<dia<<" R$"<<valor<<" ("<<categoria<<") "<<descricao<<std::endl;
    }

};
void Dados::imprimeCategoriaTotal(std::string cat){
    std::ifstream arq;
    try{
    arq.open(datgastos, std::ios::in);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    std::string categoria;
    std::string descricao;
    double valor;
    int mes, dia;
    while(arq>>mes>>dia>>valor>>categoria>>descricao){
        descricao=replace(descricao,'_',' ');
        categoria=replace(categoria,'_',' ');
        if(cat==categoria){
            std::cout<<mes<<"/"<<dia<<" R$"<<valor<<" ("<<categoria<<") "<<descricao<<std::endl;
        }
    }

};
void Dados::imprimeGastosMensal(int inmes){
    std::ifstream arq;
    try{
    arq.open(datgastos, std::ios::in);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    std::string categoria;
    std::string descricao;
    double valor;
    int mes, dia;
    while(arq>>mes>>dia>>valor>>categoria>>descricao){
        descricao=replace(descricao,'_',' ');
        categoria=replace(categoria,'_',' ');
        if(inmes==mes){
            std::cout<<mes<<"/"<<dia<<" R$"<<valor<<" ("<<categoria<<") "<<descricao<<std::endl;
        }
    }

};
void Dados::imprimeCategoriaMensal(std::string cat, int inmes){
std::ifstream arq;
    try{
    arq.open(datgastos, std::ios::in);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    std::string categoria;
    std::string descricao;
    double valor;
    int mes, dia;
    while(arq>>mes>>dia>>valor>>categoria>>descricao){
        descricao=replace(descricao,'_',' ');
        categoria=replace(categoria,'_',' ');
        if(inmes==mes && cat==categoria){
            std::cout<<mes<<"/"<<dia<<" R$"<<valor<<" ("<<categoria<<") "<<descricao<<std::endl;
        }
    }

};
double Dados::somaGastosMes(int inmes){
    std::ifstream arq;
    try{
    arq.open(datgastos, std::ios::in);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    std::string categoria;
    std::string descricao;
    double valor;
    int mes, dia;
    double soma=0;
    while(arq>>mes>>dia>>valor>>categoria>>descricao){
        if(mes==inmes){
        soma+=valor;
        }
    }
    return soma;
};
double Dados::somaGastosTotal(){
    std::ifstream arq;
    try{
    arq.open(datgastos, std::ios::in);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    std::string categoria;
    std::string descricao;
    double valor;
    int mes, dia;
    double soma=0;
    while(arq>>mes>>dia>>valor>>categoria>>descricao){
        soma+=valor;
    }
    return soma;
};
double Dados::somaGastosCategoria(std::string incategoria){
    std::ifstream arq;
    try{
    arq.open(datgastos, std::ios::in);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    std::string categoria;
    std::string descricao;
    double valor;
    int mes, dia;
    double soma=0;
    while(arq>>mes>>dia>>valor>>categoria>>descricao){
        if(categoria==incategoria){
        soma+=valor;
        }
    }
    return soma;
};
double Dados::somaGastosCategoriaMensal(std::string incategoria, int inmes){
    std::ifstream arq;
    try{
    arq.open(datgastos, std::ios::in);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    std::string categoria;
    std::string descricao;
    double valor;
    int mes, dia;
    double soma=0;
    while(arq>>mes>>dia>>valor>>categoria>>descricao){
        if(incategoria==incategoria && inmes==mes){
        soma+=valor;
        }
    }
    return soma;
};
double Dados::somaEntradas(){
    std::ifstream arq;
    try{
    arq.open(datreceita, std::ios::in);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    std::string categoria;
    std::string descricao;
    double valor;
    int mes, dia;
    double soma=0;
    while(arq>>mes>>dia>>valor>>descricao){
        soma+=valor;
    }
    return soma;
};
double Dados::somaEntradas(int inmes){
    std::ifstream arq;
    try{
    arq.open(datreceita, std::ios::in);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    std::string categoria;
    std::string descricao;
    double valor;
    int mes, dia;
    double soma=0;
    while(arq>>mes>>dia>>valor>>descricao){
        if(inmes==mes){
        soma+=valor;
        }
    }
    return soma;
};
void Dados::imprimeEntradaTotal(){
    std::ifstream arq;
    try{
    arq.open(datreceita, std::ios::in);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    std::string categoria;
    std::string descricao;
    double valor;
    int mes, dia;
    while(arq>>mes>>dia>>valor>>descricao){
        std::cout<<mes<<"/"<<dia<<" R$"<<valor<<" "<<descricao<<std::endl;
    }
};
void Dados::imprimeEntradaMensal(int inmes){
    std::ifstream arq;
    try{
    arq.open(datreceita, std::ios::in);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    std::string categoria;
    std::string descricao;
    double valor;
    int mes, dia;
    while(arq>>mes>>dia>>valor>>descricao){
        if(inmes==mes){
        std::cout<<mes<<"/"<<dia<<" R$"<<valor<<" "<<descricao<<std::endl;
        }
    }
};
void Dados::deleteGasto(int codigo){
    std::ofstream arqw;
    std::fstream arqr;
    try{
    arqw.open(datgastos, std::ios::out);
    arqr.open(datgastos, std::ios::in | std::ios::out);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    std::string categoria;
    std::string descricao;
    double valor;
    int mes, dia, linha=1;
    while(arqr>>mes>>dia>>valor>>categoria>>descricao){
        arqw.seekp(arqr.tellg());
        //if(linha!=codigo){
            arqw<<mes<<' '<<dia<<' '<<std::to_string(valor)<<' '<<categoria<<' '<<descricao<<std::endl;
        //}
        linha++;
    }
    
};


