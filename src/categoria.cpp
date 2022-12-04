#include "../include/categoria.hpp"


// Construtor:
Categoria::Categoria(std::string nome, double orcamento){
    if(nome.size()>20){
        throw Excecao_Categoria_Caracter();
    }
    if(orcamento<0 || orcamento > 2147483646){
        throw Excecao_Categoria();
    }
    _nome = nome;
    _orcamento = orcamento;
    _gastoTotal = 0;
    _limite = false;
}

Categoria::Categoria(){
};

std::string Categoria::get_nome(){
    return _nome;
}

double Categoria::get_gasto() {
    return _gastoTotal;
}

double Categoria::get_orcamento(){
    return _orcamento;
}

//Ajusta o gasto da categoria e verifica o limite
void Categoria::set_gasto(double valor){
    _gastoTotal=valor;
    verificaLimite();
};

void Categoria::adiciona_Gasto(double valor){
    _gastoTotal += valor;
    verificaLimite();
}

//Se o limite foi atingido, faz _limite = true
void Categoria::verificaLimite() {
    if(_gastoTotal >= _orcamento){
        _limite = true;
    }
}

//Exibe na tela um relatorio do conteudo de uma categoria em específico
void Categoria::relatorioDeCategoria() {
    std::cout << "Categoria: " << _nome << std::endl;
    std::cout << "Orcamento: " << _orcamento << std::endl;
    std::cout << "Gasto Total: " << _gastoTotal << std::endl;
    if(this->_limite){ 
        std::cout << "ATENCAO! Orcamento atingido." << std::endl;
    }else{
        std::cout << "Orcamento ainda nao atingido." << std::endl;
    }
}

const char* Excecao_Categoria::what() const noexcept{
    return "O valor do Orçamento tem que ser positivo, maior que zero e menor que 2.147.483.647. Por favor, digite novamente o valor atendendo as especificações citadas: ";
}

/* ARQUIVOS - FORA DE USO
void Categoria::registraDespesa(Despesa despesa){
    std::string nome = this->_nome + ".bin";
    std::ofstream arq;
    arq.open(nome, std::ios::binary | std::ios::app);
    ///arq.seekp(std::ios_base::end);
    arq.write((char*)&despesa, sizeof(Despesa));
    //char pula= '\n';
    //arq.write((char*)&pula, sizeof(char));
    arq.close();
};

void Categoria::imprimeDespesa(){
    Despesa *despesa =new Despesa("0",0);
    std::string nome = this->_nome + ".bin";
    std::ifstream arq;
    arq.open(nome, std::ios::in | std::ios::binary);
    //arq.seekg(std::ios_base::beg);
    //int i=0;
    while(!arq.eof()){
        arq.read((char*)despesa, sizeof(Despesa));
        std::cout<<despesa->getDescricao()<<" : "<<despesa->getValor()<<std::endl;
        
        //i++;
        //arq.seekg(sizeof(Despesa)*i,std::ios_base::beg);
    }
    arq.close();
};
*/
