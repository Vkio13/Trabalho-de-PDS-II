#include "../include/boleto.hpp"


//Construtor
Boleto::Boleto(std::string nome, double valor, int vencimento){
    if(nome.size()>20){
        throw Excecao_Caracteres_Boleto();
    }
    _nome = nome;
    if(valor<0){
        throw Excecao_Boleto();
    }
    _orcamento = valor;
    _gastoTotal = 0;
    _limite = false;
    _vencimento = vencimento;
    _pago = false;
};

//Destrutor
Boleto::~Boleto(){

}

//Métodos
void Boleto::vencido(){
    _vencimento = 0;
}

bool Boleto::get_pago(){
    return _pago;
}

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

    const char* Excecao_Boleto::what() const noexcept{ 
        return "O valor inserido não é valido. Por favor, insira um valor positivo: ";
    }
