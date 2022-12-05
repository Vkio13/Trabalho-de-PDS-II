#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"
#include "../include/dados.hpp"
#include "../include/usuario.hpp"

TEST_CASE("Testando a função"){
    Usuario u;
    u.entrarUsuario("testes","123");
    Dados d;    
    SUBCASE("somaGastosMes"){
        CHECK_EQ(d.somaGastosMes(12),1300);
        CHECK_THROWS(d.somaGastosMes(-1));
    }
    SUBCASE("somaGastosTotal"){
        CHECK_EQ(d.somaGastosTotal(),1300);
        CHECK_THROWS(d.somaGastosTotal());
    }
    SUBCASE("somaGastosCategoria"){
        CHECK_EQ(d.somaGastosCategoria("Mercado"),500);
    }
    SUBCASE("somaGastosCategoriaMensal"){
        CHECK_EQ(d.somaGastosCategoriaMensal("Mercado",12),500);
        CHECK_THROWS(d.somaGastosCategoriaMensal("Mercado",-1));
    }
    SUBCASE("somaEntradas"){
        CHECK_EQ(d.somaEntradas(),2000);
    }
    SUBCASE("somaEntradasMes"){
        CHECK_EQ(d.somaEntradasMes(12),2000);
        CHECK_THROWS(d.somaEntradasMes(-1));
    }
    SUBCASE("verificaCategoria"){
        CHECK_EQ(d.verificaCategoria("Mercado"),2);
    }
    u.~Usuario();
}