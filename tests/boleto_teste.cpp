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

        Boleto b1("Conta",10,30,12);
        Boleto b2("Bola",200,30,1);
        SUBCASE("Venceu"){
                CHECK_EQ(b1.venceu(),false);
                CHECK_EQ(b2.venceu(),true);
        }
        
        SUBCASE("Pago"){
                b2.pagaBoleto();
                CHECK_EQ(b1.get_pago(),false);
                CHECK_EQ(b2.get_gasto(),true);
        }        
}