#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"
#include "../include/boleto.hpp"
#include "../include/kapemgga.hpp"

TEST_CASE("Testando as exceções"){
        Kapemgga sistemas;
        CHECK_THROWS(sistemas.adicionaBoleto(Boleto("Teste de Exceçao",100,30,13)));
        CHECK_THROWS(sistemas.adicionaBoleto(Boleto("Teste de Exceçao",100,32,12)));
        CHECK_THROWS(sistemas.adicionaBoleto(Boleto("Teste de Exceçao",-100,30,12)));
        CHECK_THROWS(sistemas.adicionaBoleto(Boleto("UmValorComMaisDeVinteCaracteresParaOTesteDeExcecao",100,30,12)));
}