#include "../include/usuario.hpp"
#include <iostream>
#include <fstream>
#include <cstdint>
#include <filesystem>

std::string Usuario::replace(std::string n, char c, char s){
    for(long unsigned int i=0; i<n.size(); i++){
        if(n[i]==c){
            n[i]=s;
        }
    }
    return n;
};
Usuario::Usuario(){
    _logado= false;
    _usuario="";
    _id=0;
}
Usuario::~Usuario(){
    sair();
}
void Usuario::criarUsuario(std::string nome, std::string senha){
        std::ofstream arquser;
    try{
    arquser.open("arquivos/usuarios.txt", std::ios::app);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    if(procuraUsuario(nome)>0){
        std::cout<<"Esse usuário já existe."<<std::endl;
    }else{
        nome=replace(nome,' ','_');
        senha=replace(senha,' ','_');
        arquser<<nome<<' '<<senha<<' '<<std::endl;
        arquser.close();
        std::string comando = "mkdir arquivos/" + nome ;
        system(comando.c_str());
        std::cout<<"Usuário criado com sucesso."<<std::endl;
    } 
    
};
int Usuario::procuraUsuario(std::string innome){
    std::ifstream arquser;
    try{
    arquser.open("arquivos/usuarios.txt", std::ios::in);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    std::string nome;
    std::string senha;
    int linha = 1;
    while(arquser>>nome>>senha){
        nome=replace(nome,'_',' ');
        senha=replace(senha,'_',' ');
        if(!innome.compare(nome)){
            return linha;
        }
        linha++;
    }
    arquser.close();
    return -1;

};
void Usuario::entrarUsuario(std::string innome, std::string insenha){
    std::ifstream arquser;
    try{
    arquser.open("arquivos/usuarios.txt", std::ios::in);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    std::string nome;
    std::string senha;
    int codigo,linha = 1;
    codigo = Usuario::procuraUsuario(innome);
    if(codigo>0){
        while(arquser>>nome>>senha){
            nome=replace(nome,'_',' ');
            senha=replace(senha,'_',' ');
            if(linha==codigo){
                if(senha==insenha){
                    std::ofstream arq;
                    try{
                        arq.open("arquivos/usuarioatual.txt", std::ios::out);
                    }
                    catch(std::exception& e){
                        e.what();
                        exit(1);
                    }
                    this->_logado=true;
                    this->_usuario=nome;
                    this->_id=linha;
                    nome=replace(nome,' ','_');
                    std::string comando= "arquivos/" + nome;
                    arq<<comando<<std::endl;
                    std::cout<<"Você entrou no seu usuário."<<std::endl;
                    break;
                }
            }
            linha++;
        }
        std::cout<<"Sua senha está incorreta."<<std::endl;
    }else{
        std::cout<<"Usuário não encontrado."<<std::endl;
    }
    arquser.close();

};
void Usuario::editarSenha(std::string insenha){
    std::ifstream arqr;
    std::ofstream arqw;
    try{
    arqr.open("arquivos/usuarios.txt", std::ios::in | std::ios::out);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    std::vector<std::string> linhas;
    std::string linha;
    ;
    while(getline(arqr, linha)){
        linhas.push_back(linha);
    }
    arqr.close();
    try{
    arqw.open("arquivos/usuarios.txt", std::ios::out);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    std::string nome=this->_usuario;
    for(long unsigned int i=1;i<=linhas.size();i++){
        if(i==this->_id){
            insenha=replace(insenha,' ','_');
            nome=replace(nome,' ','_');
            arqw<<nome<<' '<<insenha<<std::endl;
        }else{
            arqw<<linhas[i-1]<<std::endl;
        }
    }
    arqw.close();
    std::cout<<"Senha alterada com sucesso"<<std::endl;
};
void Usuario::deletarUsuario(std::string innome){
    std::ofstream arqw;
    std::ifstream arqr;
    try{
    arqr.open("arquivos/usuarios.txt", std::ios::in | std::ios::out);
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

    int codigo = procuraUsuario(innome);
    if(codigo>0){
        std::cout<<"Você tem certeza que deseja deletar seus dados, eles não poderam ser recuperados (S/N)"<<std::endl;
        char op;
        std::cin>>op;
        if(op=='s'|| op=='S'){
            try{
                arqw.open("arquivos/usuarios.txt", std::ios::out);
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
            std::string comando = "rm -r arquivos/" + replace(innome,' ','_') ;
            std::cout<<"Seu usuário foi Excluído"<<std::endl;
            system(comando.c_str());
        }
        else{
             std::cout<<"Seus dados não foram deletados :)"<<std::endl;
        }
    }
    else{
        std::cout<<"Usuário não encontrado"<<std::endl;
    }
};
void Usuario::sair(){
    if(_logado){
        // std::string comando= "mv arquivos/atual arquivos/"+ replace(this->_usuario,' ','_');
        // system(comando.c_str());
        _logado= false;
        _usuario="";
        _id=0;
        remove("arquivos/usuarioatual.txt");
        std::cout<<"Você saiu do seu usuário."<<std::endl;
    }else{
        std::cout<<"Você não está logado."<<std::endl;
    }
}
bool Usuario::getLogado(){
    return _logado;
};
/*void Usuario::verifica(){
    std::string home = getenv("HOME");
    home="/arquivos/gustavo";
    std::experimental::filesystem::path();
    if(std::experimental::filesystem::exists(home)){
        std::cout<<"Deu certo";
    }else{
        std::cout<<"Não deu certo";
    }
}*/
const char* Excecao_Usuario::what() const noexcept{
    return "Usuário não encontrado.";
};