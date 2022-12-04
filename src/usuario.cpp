#include "../include/usuario.hpp"

std::string Usuario::replace(std::string n, char c, char s){
    for(long unsigned int i=0; i<n.size(); i++){
        if(n[i]==c){
            n[i]=s;
        }
    }
    return n;
};

//Construtor
Usuario::Usuario(){
    _logado= false;
    _usuario="";
}
void Usuario::criarUsuario(std::string nome, std::string senha){
        std::ofstream arq;
    try{
    arq.open("../arquivos/usuarios.txt", std::ios::app);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    nome=replace(nome,' ','_');
    senha=replace(senha,' ','_');
    arq<<nome<<' '<<senha<<' '<<std::endl;
    std::string comando = "mkdir /../arquivos/" + nome ;
    system(comando.c_str());
};
int Usuario::procuraUsuario(std::string innome){
    std::ifstream arq;
    try{
    arq.open("../arquivos/usuarios.txt", std::ios::in);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    std::string nome;
    std::string senha;
    int linha = 1;
    while(arq>>nome>>senha){
        nome=replace(nome,'_',' ');
        senha=replace(senha,'_',' ');
        if(innome==nome){
            return linha;
        }
        linha++;
    }
    arq.close();
    return -1;

};
void Usuario::entrarUsuario(std::string innome, std::string insenha){
    std::ifstream arq;
    try{
    arq.open("../arquivos/usuarios.txt", std::ios::in);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    std::string nome;
    std::string senha;
    int codigo,linha = 1;
    codigo = Usuario::procuraUsuario(innome);
    while(arq>>nome>>senha){
        nome=replace(nome,'_',' ');
        senha=replace(senha,'_',' ');
        if(linha==codigo){
            if(senha==insenha){
                this->_logado=true;
                this->_usuario=nome;
                break;
            }
        }
        linha++;
    }

};
