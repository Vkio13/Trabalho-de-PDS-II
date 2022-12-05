#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"
#include "../include/inicializador.hpp"
#include "../include/usuario.hpp"

TEST_CASE("Testando a função"){
    Usuario u;
    u.entrarUsuario("testes","123");
    Inicializador i;
    SUBCASE("Get Entradas"){
        CHECK_EQ(i.getEntradas(),2000);
    }
    SUBCASE("Get Gastos"){
        CHECK_EQ(i.getGastos(),1300);
    }
    u.sair();
}