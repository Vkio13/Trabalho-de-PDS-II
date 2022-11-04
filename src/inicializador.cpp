#include "../include/inicializador.hpp"


//Construtor
Inicializador::Inicializador(std::list<Categoria> categorias, double entradas, double investimento, double gastos){
        _categorias=categorias;
        _entradas=entradas;
        _investimento=investimento;
        _gastos=gastos;
}
//Métodos
        double Inicializador::GetEntradas(){
            return _entradas;
        }
        double Inicializador::GetGastos(){
            return _gastos;
        }
        std::list<Categoria> Inicializador::GetCategorias(){
            return _categorias;
        }
        void Inicializador::carregaEntradas(){
            //PREENCHER
        }
        void Inicializador::carregaGastos(){
            //PREENCHER
        }
        void Inicializador::carregaCategorias(){
            //PREENCHER
        }
