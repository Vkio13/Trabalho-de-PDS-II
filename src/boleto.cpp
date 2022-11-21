#include "../include/boleto.hpp"


//Construtor
Boleto::Boleto(std::string nome, double gastoTotal, bool limite, int vencimento){
    this->_nome_= nome;
    this->_gastototal = gastoTotal;
    this->_limite = limite;
    this->_vencimento = vencimento;
};
//Destrutor
~Boleto(){

}
//Métodos
void relatorioDeCategoria() override {
    std::cout << "Categoria: " << _nome_ << std::endl;
    std::cout << "Orcamento: " << _orcamento_ << std::endl;
    std::cout << "Gasto Total: " << _gastototal << std::endl;
    if(statusLimite()){ 
        std::cout << "Orcamento nao atingido" << std::endl;
    }else{
        std::cout << "ATENCAO! Orcamento atingido" << std::endl;
    }
}
int getVencimento(){
    return _vencimento;
}
bool getPago() const {
    return _pago;
}
void verificaVenceu(){
    //Depende de time
}