#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"
#include "../include/categoria.hpp"
#include "../include/kapemgga.hpp"

TEST_CASE("Testando a exceção"){
    Kapemgga sistema;
    CHECK_THROWS(sistema.adicionaCategoria(Categoria("nome",-100)));
    CHECK_THROWS(sistema.adicionaCategoria(Categoria("TesteComUmValorComMaisDeVinteCaracteres",-100)));
}