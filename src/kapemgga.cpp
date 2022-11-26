#include "../include/kapemgga.hpp"


Kapemgga::Kapemgga( std::vector<Boleto> boletos){
    Inicializador i;
    _categorias = i.getCategorias();
    _caixa.setGastos(i.getGastos());
    _caixa.setReceitas(i.getEntradas());
    std::vector<Boleto> _boletos = boletos;
}

int Kapemgga::LocalizaCategoria(std::string nome){
    int localizacao = 0;
    for(Categoria cat:_categorias){
        if(cat.get_nome()!=nome){
            localizacao = localizacao + 1;
        }
        if(cat.get_nome()==nome){
            return localizacao;
        }
    }
    std::cout<<"Categoria não encontrada"<<std::endl;
    return -1;
}

int Kapemgga::LocalizaBoleto(std::string nome){
    int localizacao = 0;
    for(Categoria bol:_boletos){
        if(bol.get_nome()!=nome){
            localizacao = localizacao + 1;
        }
        if(bol.get_nome()==nome){
            return localizacao;
        }
    }
    std::cout<<"Boleto não encontrado"<<std::endl;
    return -1;
}

void Kapemgga::imprimeCategorias_e_Orcamento(){
    for(Categoria cat:_categorias){
        std::cout << "Categoria:" << cat.get_nome() <<" "<< "Orçamento:" << cat.get_orcamento() << "Gastos:" << cat.get_gasto();
    }
}

void Kapemgga::adicionaCategoria(Categoria cate){
    _categorias.push_back(cate);
}

void Kapemgga::removeCategoria(std::string nome){
    _categorias.erase(_categorias.begin() + LocalizaCategoria(nome));
    
}

void Kapemgga::novaReceita(std::string descricao, double valor){
    _caixa.setReceitas(_caixa.getReceitas() + valor);
    d.adicionaReceita(valor, descricao);
}

//Essa parte de entrada de dados com nome com espaço irá dar problemas
void Kapemgga::novoGasto(std::string nome, double valor, std::string descricao){
    if(LocalizaCategoria(nome)>=0){
    _categorias[LocalizaCategoria(nome)].set_gasto(valor);
    _caixa.adicionaGasto(valor);
    d.adicionaGasto(valor, nome, descricao);
    }else{
        std::cout<<"Gasto não adicionado, tente corrigir o nome ou adicionar essa categoria"<<std::endl;
    }
}

void Kapemgga::pagaBoleto(std::string nome){
    _boletos[LocalizaBoleto(nome)].pagaBoleto();
    _caixa.adicionaGasto(_boletos[LocalizaBoleto(nome)].get_orcamento());

}

void Kapemgga::boletosAPagar(){
    for(Boleto bol:_boletos){
        if(bol.get_pago()){
        }else{
            bol.relatorioDeCategoria();
        }
    }
}

void Kapemgga::encerraBoletos(){
    for(Boleto bol:_boletos){
        if(bol.get_pago()){
            ;
        }else{
            bol.vencido();
        }
    }
}
