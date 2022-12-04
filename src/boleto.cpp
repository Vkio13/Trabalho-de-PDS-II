#include "../include/boleto.hpp"


//Construtor
Boleto::Boleto(std::string nome, double valor, int dia, int mes){
    if(nome.size()>20){
        throw Excecao_Caracteres_Boleto();
    }
    _nome = nome;
    if(valor<0 || valor > 2147483646){
        throw Excecao_Boleto();
    }
    _orcamento = valor;
    _gastoTotal = 0;
    _limite = false;
    _vDia = dia;
    _vMes = mes;
    _pago = false;
};

//Destrutor
Boleto::~Boleto(){

}

//Métodos
bool Boleto::get_pago(){
    return _pago;
}

bool Boleto::venceu(){
    time_t agora;
    struct tm * dataHora;

    time(&agora);
    dataHora = localtime(&agora);

    if(dataHora->tm_mon > (_vMes - 1)){
        return true;
    }
    if(dataHora->tm_mon == (_vMes - 1)){
        if(dataHora->tm_mday > _vDia) {
            return true;
        } else { return false; }
    if(dataHora->tm_mon < (_vMes - 1)) {
        return false;
        }
    }
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
            std::cout << "Vencimento no dia " << _vDia << "do mês " << _vMes <<  std::endl;
        }
    }
}

    const char* Excecao_Boleto::what() const noexcept{ 
        return "O valor inserido não é valido. Por favor, insira um valor positivo ou de valor menor que o inserido: ";
    }
