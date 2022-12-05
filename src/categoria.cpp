#include "../include/categoria.hpp"


// Construtor:
Categoria::Categoria(std::string nome, double orcamento){
    if(_nome.size()>20){
        throw Excecao_Categoria_Caracter();
    }
    if(orcamento<0){
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
