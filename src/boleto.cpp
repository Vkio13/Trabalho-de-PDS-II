#include "../include/boleto.hpp"


//Construtor
Boleto::Boleto(std::string nome, int valor, int vencimento){
    _nome = nome;
    _orcamento = valor;
    _vencimento = vencimento;
    _pago = false;
};

//Destrutor
Boleto::~Boleto(){
    //Fazer
}

//Métodos
bool Boleto::venceu(){
    time_t agora;
    struct tm * dataHora;

    time(&agora);
    dataHora = localtime(&agora);

    return (dataHora->tm_mday > _vencimento);
}

void Boleto::pagaBoleto(){
    _gastoTotal = _orcamento;
    _pago = true;
}

void Boleto::relatorioDeCategoria(){
    std::cout << "Boleto: " << Categoria::_nome << std::endl;
    std::cout << "Valor: " << _gastoTotal << std::endl;
    if(_pago){ 
        std::cout << "Boleto pago!" << std::endl;
    }else{
        if(venceu()){
        std::cout << "ATENCAO! Boleto VENCIDO ainda nao pago!" << std::endl;    
        }else{
            std::cout << "ATENCAO! Boleto nao pago!" << std::endl;
            std::cout << "Vencimento no dia " << _vencimento << std::endl;
        }
    }
}