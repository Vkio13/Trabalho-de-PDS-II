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
    _id=0;
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
            std::cout<<linha<<std::endl;
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
    while(arquser>>nome>>senha){
        nome=replace(nome,'_',' ');
        senha=replace(senha,'_',' ');
        if(linha==codigo){
            if(senha==insenha){
                this->_logado=true;
                this->_usuario=nome;
                this->_id=linha;
                break;
            }
        }
        linha++;
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
    try{
    arqw.open("arquivos/usuarios.txt", std::ios::out);
    }
    catch(std::exception& e){
        e.what();
        exit(1);
    }
    int codigo = procuraUsuario(this->_usuario);
    if(codigo>0){
        std::cout<<"Você tem certeza que deseja deletar seus dados, eles não poderam ser recuperados (S/N)"<<std::endl;
        char op;
        std::cin>>op;
        if(op=='s'|| op=='S'){
            for(long unsigned int i=1;i<=linhas.size();i++){
                if(int(i)!=codigo){
                    arqw<<linhas[i-1]<<std::endl;
                }
            }
            arqw.close();
            std::string comando = "rm -r arquivos/" + _usuario ;
            system("delete");
        }
        else{
             std::cout<<"Seus dados não foram deletados :)"<<std::endl;
        }
    }
    else{
        std::cout<<"Usuário não encontrado"<<std::endl;
    }
};
