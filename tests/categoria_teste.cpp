#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"
#include "../include/categoria.hpp"
#include "../include/kapemgga.hpp"

TEST_CASE("Testando a exceção"){
    Kapemgga sistema;
    SUBCASE("Valor negativo"){
        CHECK_THROWS(sistema.adicionaCategoria(Categoria("nome",-100)));
    }
    SUBCASE("Caracteres Excedente"){
        CHECK_THROWS(sistema.adicionaCategoria(Categoria("TesteComUmValorComMaisDeVinteCaracteres",-100)));
    }
}
TEST_CASE("Testando as Funções"){
    Categoria teste("Mercado",1000);
    SUBCASE("Testando Get Orçamentos"){
        CHECK_EQ(teste.get_orcamento,1000);
    }
    SUBCASE("Testando Get Gastos"){
        teste.set_gasto(1000);
        CHECK_EQ(teste.get_gasto(), 1000);
    }
    SUBCASE("Testando Get Nome"){
        CHECK_EQ(teste.get_nome,"Mercado");
    }
}