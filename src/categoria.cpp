#include "../include/categoria.hpp"
// Construtor:
Categoria::Categoria(std::string nome, double orcamento, double gastoTotal){
    _nome= nome;
    _orcamento = orcamento;
    _gastoTotal = 0;
    _limite = false;
};

double Categoria::get_gasto() {
    return _gastoTotal;
};

std::string Categoria::get_nome(){
    return _nome;
}

//Ajusta o gasto da categoria e altera o caixa
void Categoria::set_gasto(double valor){
    _gastoTotal = get_gasto() + valor;
    verificaLimite();
    Caixa->setSaldo(Caixa->getSaldo() -valor);
    Caixa->setGastos(Caixa->getGastos() -valor);
}

//Se o limite foi atingido, faz _limite = true
void Categoria::verificaLimite() {
    if(_gastoTotal >= _orcamento){
        _limite = true;
    }
};

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
};

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
