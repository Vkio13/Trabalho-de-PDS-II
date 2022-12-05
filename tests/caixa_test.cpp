#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"
#include "../include/caixa.hpp"
#include "../include/kapemgga.hpp"

TEST_CASE("Testando as exceções"){
    Kapemgga sistema;
    SUBCASE("Valor Negativo - Receita"){
        CHECK_THROWS(sistema.novaReceita("descricao",-10));
    }
    SUBCASE("Valor de Overflow - Receita"){
        CHECK_THROWS(sistema.novaReceita("descricao",2147483648));
    }
    SUBCASE("Valor de Caracter Excedente - Receita"){
        CHECK_THROWS(sistema.novaReceita("TesteComUmValorComMaisDeVinteCaracteres",1));
    }
    SUBCASE("Valor Negativo - Gasto"){
        CHECK_THROWS(sistema.novoGasto("nome",-10,"descricao"));
    }
    SUBCASE("Valor de Overflow - Gasto"){
        CHECK_THROWS(sistema.novoGasto("nome",2147483648,"descricao"));
    }
    SUBCASE("Valor de Caracter Excedente - Gastos"){
        CHECK_THROWS(sistema.novoGasto("TesteComUmValorComMaisDeVinteCaracteres",2147483648,"descricao"));
    }
    SUBCASE("Valor de Caracter Excedente - Descricao - Gastos"){
        CHECK_THROWS(sistema.novoGasto("nome",2147483648,"TesteComUmValorComMaisDeCemCaracteresTesteComUmValorComMaisDeCemCaracteresTesteComUmValorComMaisDeCemCaracteres"));
    }
}
TEST_CASE("Testando as Funções"){
    Caixa teste;
    SUBCASE("Teste do Get Gasto"){
        teste.setGastos(1000.100);
        CHECK_EQ(teste.getGastos(), 1000.100);
    }
    SUBCASE("Teste do Get Receita"){
        teste.SetReceitas(200.20);
        CHECK_EQ(teste.getReceitas(), 200.100);
    }
    SUBCASE("Teste do Get Saldo"){
        teste.atualizaSaldo();
        CHECK_EQ(teste.getSaldo(), 800);
    }

}