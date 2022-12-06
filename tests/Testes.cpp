#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"
#include "../include/boleto.hpp"
#include "../include/kapemgga.hpp"
#include "../include/inicializador.hpp"
#include "../include/usuario.hpp"
#include "../include/dados.hpp"
#include "../include/categoria.hpp"
#include "../include/caixa.hpp"

/*___________________________TESTES__BOLETOS______________________________*/
TEST_CASE("Testando as exceções"){
        Kapemgga sistemas;
        SUBCASE("Mês não existente"){
                CHECK_THROWS_MESSAGE(sistemas.adicionaBoleto(Boleto("Teste de Exceçao",100,30,13)),"A data de vencimento inserida é inválida. Certifique-se que o dia de vencimento está entre 1 e 31 e o mês entre 1 e 12.");       
        }
        SUBCASE("Dia não existente"){
                CHECK_THROWS(sistemas.adicionaBoleto(Boleto("Teste de Exceçao",100,32,12)));      
        }
        SUBCASE("Valor Negativo"){
                CHECK_THROWS(sistemas.adicionaBoleto(Boleto("Teste de Exceçao",-100,30,12)));  
        }
        SUBCASE("Excedendo o número de Caracteres"){
                CHECK_THROWS(sistemas.adicionaBoleto(Boleto("UmValorComMaisDeVinteCaracteresParaOTesteDeExcecao",100,30,12)));
        }

        Boleto b1("Conta",10,30,12);
        Boleto b2("Bola",200,30,1);
        SUBCASE("Venceu"){
                CHECK_EQ(b1.venceu(),false);
                CHECK_EQ(b2.venceu(),true);
        }
        
        SUBCASE("Pago"){
                b2.pagaBoleto();
                CHECK_EQ(b1.get_pago(),false);
                CHECK_EQ(b2.get_pago(),true);
        }        
}
/*___________________________TESTES DE CAIXA____________________________*/
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
        teste.setGastos(1000);
        CHECK_EQ(teste.getGastos(), 1000);
    }
    SUBCASE("Teste do Get Receita"){
        teste.setReceitas(200);
        CHECK_EQ(teste.getReceitas(), 200);
    }
    SUBCASE("Teste do Get Saldo"){
        teste.setGastos(1000);
        teste.setReceitas(200);
        teste.atualizaSaldo();
        CHECK_EQ(teste.getSaldo(), -800);
    }

}
/*____________________-TESTES DE CATEGORIA ____________________________*/
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
        CHECK_EQ(teste.get_orcamento(),1000);
    }
    SUBCASE("Testando Get Gastos"){
        teste.set_gasto(1000);
        CHECK_EQ(teste.get_gasto(), 1000);
    }
    SUBCASE("Testando Get Nome"){
        CHECK_EQ(teste.get_nome(),"Mercado");
    }
}
/*_______________________TESTES DE DADOS __________________________*/
TEST_CASE("Testando a função"){
    Usuario u;
    u.entrarUsuario("testes","123");
    Dados d;    
    SUBCASE("somaGastosMes"){
        CHECK_EQ(d.somaGastosMes(12),2300);
        CHECK_THROWS(d.somaGastosMes(-1));
    }
    SUBCASE("somaGastosTotal"){
        CHECK_EQ(d.somaGastosTotal(),2300);
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
/*_____________________________TESTES DE INICIALIZADOR_______________________*/
TEST_CASE("Testando a função"){
    Usuario u;
    u.entrarUsuario("testes","123");
    Inicializador i;
    SUBCASE("Get Entradas"){
        CHECK_EQ(i.getEntradas(),2000);
    }
    SUBCASE("Get Gastos"){
        CHECK_EQ(i.getGastos(),2300);
    }
    u.sair();
}