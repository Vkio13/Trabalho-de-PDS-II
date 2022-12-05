#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"
#include "../include/caixa.hpp"
#include "../include/kapemgga.hpp"

TEST_CASE("Testando as exceções"){
    Kapemgga sistema;
    CHECK_THROWS(sistema.novaReceita("descricao",-10));
    CHECK_THROWS(sistema.novaReceita("descricao",2147483648));
    CHECK_THROWS(sistema.novaReceita("TesteComUmValorComMaisDeVinteCaracteres",1));
    CHECK_THROWS(sistema.novoGasto("nome",-10,"descricao"));
    CHECK_THROWS(sistema.novoGasto("nome",2147483648,"descricao"));
    CHECK_THROWS(sistema.novoGasto("TesteComUmValorComMaisDeVinteCaracteres",2147483648,"descricao"));
    CHECK_THROWS(sistema.novoGasto("nome",2147483648,"TesteComUmValorComMaisDeCemCaracteresTesteComUmValorComMaisDeCemCaracteresTesteComUmValorComMaisDeCemCaracteres"));
}