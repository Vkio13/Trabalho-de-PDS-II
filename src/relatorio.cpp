#include "../include/relatorio.hpp"

//Construtor
Relatorio::Relatorio(){

};
//
void Relatorio::relatorioGeral(){
Dados d;
    double entradas;
    double gastos;
    d.vectorCategoria(_categorias);
    for(int i=0; i<_categorias.size(); i++){
        _categorias[i].set_gasto(d.somaGastosCategoria(_categorias[i].get_nome()));
    }
    entradas = d.somaEntradas();
    gastos = d.somaGastosTotal();
    std::cout<<"===================| Relatório Geral (Total) | ================="<<std::endl;
    std::cout<<"Entradas: "<<entradas<<" | Gastos: "<<gastos<<std::endl;
    for(int i=0; i<_categorias.size(); i++){
        std::cout<<_categorias[i].get_nome()<<": "<<_categorias[i].get_gasto()<<std::endl;
    }
    std::cout<<"================================================================"<<std::endl;
};
void Relatorio::relatorioMensal(int mes){
    Dados d;
    double entradas;
    double gastos;
    d.vectorCategoria(_categorias);
    for(int i=0; i<_categorias.size(); i++){
        _categorias[i].set_gasto(d.somaGastosCategoriaMensal(_categorias[i].get_nome(), mes));
        _categorias[i].verificaLimite();
    }
    entradas = d.somaEntradasMes(mes);
    gastos = d.somaGastosMes(mes);
    std::cout<<"===================| Relatório Mensal| ================="<<std::endl;
    std::cout<<"Entradas: "<<entradas<<" | Gastos: "<<gastos<<std::endl;
    for(int i=0; i<_categorias.size(); i++){
        std::cout<<_categorias[i].get_nome()<<": "<<_categorias[i].get_gasto()<<" / "<<_categorias[i].get_orcamento()<<std::endl;
    }
    std::cout<<"========================================================"<<std::endl;
};