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
    if(valor<0){
        throw Excecao_ValorInvalido_Dados();
    }
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
    if(valor<0){
        throw Excecao_ValorInvalido_Dados();
    }    
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
void Dados::adicionaCategoria(std::string categoria, double orcamento){
    if(orcamento<0){
        throw Excecao_ValorInvalido_Dados();
    }    
    std::ofstream arq;
    try{
    arq.open(datcat, std::ios::app);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    if(verificaCategoria(categoria)){
        std::cout<<"Essa categoria já existe"<<std::endl;
    }
    else{
    categoria=replace(categoria,' ','_');
    getTime();
    arq<<tempo->tm_mon<<' '<<tempo->tm_mday<<' '<<std::to_string(orcamento)<<' '<<categoria<<std::endl;
    }
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
    int linha = 1;
    while(arq>>mes>>dia>>valor>>categoria>>descricao){
        descricao=replace(descricao,'_',' ');
        categoria=replace(categoria,'_',' ');
        std::cout<<linha<<" - "<<mes<<"/"<<dia<<" R$"<<valor<<" ("<<categoria<<") "<<descricao<<std::endl;
        linha++;
    }

};
void Dados::imprimeGastosCategoriaTotal(std::string cat){
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
    int linha = 1;
    while(arq>>mes>>dia>>valor>>categoria>>descricao){
        descricao=replace(descricao,'_',' ');
        categoria=replace(categoria,'_',' ');
        if(cat==categoria){
            std::cout<<linha<<" - "<<mes<<"/"<<dia<<" R$"<<valor<<" ("<<categoria<<") "<<descricao<<std::endl;
        }
        linha++;
    }

};
void Dados::imprimeGastosMensal(int inmes){
    if(inmes<0||inmes>12){
        throw Excecao_ValorInvalido_Dados();
    }
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
    int linha = 1;
    inmes--;
    while(arq>>mes>>dia>>valor>>categoria>>descricao){
        descricao=replace(descricao,'_',' ');
        categoria=replace(categoria,'_',' ');
        if(inmes==mes){
            std::cout<<linha<<" - "<<mes+1<<"/"<<dia<<" R$"<<valor<<" ("<<categoria<<") "<<descricao<<std::endl;
        }
        linha++;
    }

};
void Dados::imprimeGastosCategoriaMensal(std::string cat, int inmes=0){
    if(inmes<0||inmes>12){
        throw Excecao_ValorInvalido_Dados();
    }
    std::ifstream arq;
    try{
    arq.open(datgastos, std::ios::in);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    if (inmes==0){
        getTime();
        tempo->tm_mon;
    }else{
    inmes--;        
    }
    std::string categoria;
    std::string descricao;
    double valor;
    int mes, dia;
    int linha = 1;

    while(arq>>mes>>dia>>valor>>categoria>>descricao){
        descricao=replace(descricao,'_',' ');
        categoria=replace(categoria,'_',' ');
        if(inmes==mes && cat==categoria){
            std::cout<<linha<<" - "<<mes+1<<"/"<<dia<<" R$"<<valor<<" ("<<categoria<<") "<<descricao<<std::endl;
        }
        linha++;
    }

};
double Dados::somaGastosMes(int inmes=0){
    if(inmes<0||inmes>12){
        throw Excecao_ValorInvalido_Dados();
    }
    std::ifstream arq;
    try{
    arq.open(datgastos, std::ios::in);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    if (inmes==0){
        getTime();
        tempo->tm_mon;
    }else{
        inmes--;
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
double Dados::somaGastosCategoriaMensal(std::string incategoria, int inmes=0){
    if(inmes<0||inmes>12){
        throw Excecao_ValorInvalido_Dados();
    }
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
    if (inmes==0){
        getTime();
        tempo->tm_mon;
    }else{
        inmes--;
    }
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
double Dados::somaEntradasMes(int inmes= 0){
    if(inmes<0||inmes>12){
        throw Excecao_ValorInvalido_Dados();
    }    
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
    if (inmes==0){
        getTime();
        tempo->tm_mon;
    }else{
        inmes--;
    }
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
    int linha = 1;
    while(arq>>mes>>dia>>valor>>descricao){
        std::cout<<linha<<" - "<<mes<<"/"<<dia<<" R$"<<valor<<" "<<descricao<<std::endl;
    }
};
void Dados::imprimeEntradaMensal(int inmes=0){
    if(inmes<0||inmes>12){
        throw Excecao_ValorInvalido_Dados();
    }
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
    int linha = 1;
    if (inmes==0){
        getTime();
        tempo->tm_mon;
    }else{
        inmes--;
    }
    while(arq>>mes>>dia>>valor>>descricao){
        if(inmes==mes){
        std::cout<<linha<<" - "<<mes<<"/"<<dia<<" R$"<<valor<<" "<<descricao<<std::endl;
        }
        linha++;
    }
};
void Dados::deleteGasto(int codigo){
    if(codigo<1){
        throw Excecao_ValorInvalido_Dados();
    }
    std::ofstream arqw;
    std::ifstream arqr;
    try{
    arqr.open(datgastos, std::ios::in | std::ios::out);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    std::vector<std::string> linhas;
    std::string linha;
    ;
    while(getline(arqr, linha)){
        //if(linha!=''){
        linhas.push_back(linha);
       // }
    }
    arqr.close();
    try{
    arqw.open(datgastos, std::ios::out);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    for(long unsigned int i=1;i<=linhas.size();i++){
        if(int(i)!=codigo){
            arqw<<linhas[i-1]<<std::endl;
        }
    }
    arqw.close();
    
};
int Dados::verificaCategoria(std::string nome){
    std::ifstream arq;
    try{
    arq.open(datcat, std::ios::in | std::ios::out);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    int mes,dia,linha=1;
    double orcamento;
    std::string categoria;
    while(arq>>mes>>dia>>orcamento>>categoria){
        categoria=replace(categoria,'_',' ');
        if(nome==categoria){
            return linha;
        }
        linha++;
    }
    return 0;
}
void Dados::deleteCategoria(int codigo){
    if(codigo<1){
        throw Excecao_ValorInvalido_Dados();
    }
    std::ofstream arqw;
    std::ifstream arqr;
    try{
    arqr.open(datcat, std::ios::in | std::ios::out);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    std::vector<std::string> linhas;
    std::string linha;
    ;
    while(getline(arqr, linha)){
        //if(linha!=''){
        linhas.push_back(linha);
       // }
    }
    arqr.close();
    try{
    arqw.open(datcat, std::ios::out);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    for(long unsigned int i=1;i<=linhas.size();i++){
        if(int(i)!=codigo){
            arqw<<linhas[i-1]<<std::endl;
        }
    }
    arqw.close();
}
void Dados::deleteReceita(int codigo){
    if(codigo<1){
        throw Excecao_ValorInvalido_Dados();
    }
    std::ofstream arqw;
    std::ifstream arqr;
    try{
    arqr.open(datreceita, std::ios::in | std::ios::out);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    std::vector<std::string> linhas;
    std::string linha;
    ;
    while(getline(arqr, linha)){
        //if(linha!=''){
        linhas.push_back(linha);
       // }
    }
    arqr.close();
    try{
    arqw.open(datreceita, std::ios::out);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    for(long unsigned int i=1;i<=linhas.size();i++){
        if(int(i)!=codigo){
            arqw<<linhas[i-1]<<std::endl;
        }
    }
    arqw.close();
}
void Dados::imprimeCategorias(){
    std::ifstream arq;
    try{
    arq.open(datcat, std::ios::in);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    std::string categoria;
    double orcamento;
    int mes, dia;
    while(arq>>mes>>dia>>orcamento>>categoria){
        categoria=replace(categoria,'_',' ');
        std::cout<<categoria<<" "<<orcamento<<std::endl;
    }
}
void Dados::vectorCategoria(std::vector<Categoria>& v){
    std::ifstream arq;
    try{
    arq.open(this->datcat, std::ios::in);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    std::string categoria;
    double orcamento;
    int mes, dia;
    while(arq>>mes>>dia>>orcamento>>categoria){
        categoria=replace(categoria,'_',' ');
        v.push_back(Categoria(categoria,orcamento));
    }
};
void Dados::editaGasto(int inlinha, int inmes=0, int india=0, double invalor, std::string incategoria, std::string indescricao){
    if(inlinha<1||inmes<0||inmes>12||india<0||india>31||invalor<0){
        throw Excecao_ValorInvalido_Dados();
    }
    std::ofstream arqw;
    std::ifstream arqr;
    try{
    arqr.open(datgastos, std::ios::in | std::ios::out);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    std::vector<std::string> linhas;
    std::string linha;
    
    while(getline(arqr, linha)){
        linhas.push_back(linha);
    }
    arqr.close();
    try{
    arqw.open(datgastos, std::ios::out);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    if (inmes==0){
        getTime();
        tempo->tm_mon;
    }else{
        inmes--;
    }
    if (india==0){
        getTime();
        tempo->tm_mon;
    }else{
        india--;
    }
    for(long unsigned int i=1;i<=linhas.size();i++){
        if(i==inlinha){
            indescricao=replace(indescricao,' ','_');
            incategoria=replace(incategoria,' ','_');
            arqw<<inmes<<' '<<india<<' '<<std::to_string(invalor)<<' '<<incategoria<<' '<<indescricao<<std::endl;
        }else{
            arqw<<linhas[i-1]<<std::endl;
        }
    }
    arqw.close();
};
