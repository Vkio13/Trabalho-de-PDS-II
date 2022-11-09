#include "../include/categoria.hpp"
// Construtor:
Categoria::Categoria(std::string nome, double orcamento, double gastoTotal, bool limite){
    this->_nome_= nome;
    this->_orcamento_ = orcamento;
    this->_gastototal = gastoTotal;
    this->_limite = limite;
};

double Categoria::get_gasto() {
    return this->_gastototal;
};

void Categoria::set_gasto(double valor){
    this->_gastototal = valor;
}

bool Categoria::statusLimite() {
    return this->_limite;
};

/*void Categoria::alteraCaixa(double valor){
    // CHAMAR FUNÇÃO DE CAIXA ALTERANDO O MESMO
};*/

void Categoria::relatorioDeCategoria() {
    std::cout << "Categoria: " << this->_nome_ << std::endl;
    std::cout << "Orcamento: " << this->_orcamento_ << std::endl;
    std::cout << "Gasto Total: " << this->_gastototal << std::endl;
    if(statusLimite()){ 
        std::cout << "Orcamento nao atingido" << std::endl;
    }else{
        std::cout << "ATENCAO! Orcamento atingido" << std::endl;
    }
};

void Categoria::registraDespesa(Despesa despesa){
    std::string nome = this->_nome_ + ".bin";
    std::ofstream arq;
    arq.open(nome, std::ios::binary | std::ios::app);
    arq.write((char*)&despesa, sizeof(despesa));
    arq.close();
};

void Categoria::imprimeDespesa(){
    Despesa despesa("0",0);
    std::string nome = this->_nome_ + ".bin";
    std::ifstream arq;
    arq.open(nome, std::ios::in | std::ios::binary);
    arq.seekg(0);
    //while(!arq.eof()){
        arq.read((char*)&despesa, sizeof(despesa));
        std::cout<<despesa.getDescricao()<<" : "<<despesa.getValor()<<std::endl;
    //}
    arq.close();
};
