#include "../include/boleto.hpp"


//Construtor
Bolet::Boleto(std::string nome, double gastoTotal, bool limite, int vencimento){
    Categoria(nome);
    _limite = limite;
    _vencimento = vencimento;
    _pago = false;
};
//Destrutor
Boleto::~Boleto(){
    free(&Boleto);
}
//Métodos
void Boleto::relatorioDeCategoria(){
    std::cout << "Boleto: " << Categoria::_nome << std::endl;
    std::cout << "Valor: " << _gastoTotal << std::endl;
    if(_pago){ 
        std::cout << "Boleto pago!" << std::endl;
    }else{
        if(Venceu()){
        std::cout << "ATENCAO! Boleto VENCIDO ainda nao pago!" << std::endl;    
        }else{
            std::cout << "ATENCAO! Boleto nao pago!" << std::endl;
            std::cout << "Vencimento no dia " << _vencimento << std::endl;
        }
    }

void Venceu(){
    //Depende de time
}