#include "../include/inicializador.hpp"
#include "../include/dados.hpp"


//Construtor
Inicializador::Inicializador(){
        this->carregaEntradas();
        this->carregaGastos();
        this->carregaCategorias();
}
//Métodos
        double Inicializador::GetEntradas(){
            return _entradas;
        }
        double Inicializador::GetGastos(){
            return _gastos;
        }
        std::vector<Categoria> Inicializador::GetCategorias(){
            return _categorias;
        }
        void Inicializador::carregaEntradas(){
            _entradas = d.somaEntradasMes(0);
        }
        void Inicializador::carregaGastos(){
            _gastos = d.somaGastosMes(0);
        }
        void Inicializador::carregaCategorias(){
            //Carrega as categorias do arquivo;
            _categorias=d.vectorCategoria();
            //Carrega os gastor de cada categoria;
            for(int i=0; i<_categorias.size(); i++){
                _categorias[i].set_gasto(d.somaGastosCategoriaMensal(_categorias[i].get_nome(), 0));
                _categorias[i].verificaLimite();
            }
        }
