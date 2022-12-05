#ifndef KAPEMGGA_HPP
#define KAPEMGGA_HPP

/**
 * @file kapemgga.hpp
 * @brief Superclasse principal onde se juntam
 * todos os módulos.
 * @version 1.0
 * @date 2022-11-30
 * @details TAD com função principal de 
 * juntar todo o cógido e funcionar
 * como um todo
 * 
 * @copyright GNU General Public License 
 * 
 */

#include <vector>
#include <string>
#include <iostream>
#include "categoria.hpp"
#include "caixa.hpp"
#include "boleto.hpp"
#include "inicializador.hpp"


/**
         * @brief Classe contendo informações gerais
         * de todo o código
         *
         * @details Obtém informações de todas as partes
         * do código e as torna um só.
         *
         */   
class Kapemgga{
  private:
  
  
  /**
         * @brief Vetor contendo todas as categorias.
         */
    std::vector<Categoria>_categorias;
  
  
  /**
         * @brief Caixa do sistema como um todo.
         */
    Caixa _caixa;
  
  
  /**
         * @brief Vetor de boletos.
         */
    std::vector<Boleto>_boletos;
  
  
  /**
         * @brief Varável do tipo dados para funções gerais.
         */
    Dados d;

  public:
  /**
         * @brief Construtor do Kapemgga
         **/ 
    Kapemgga();
  
  
/**
         * @brief Função para iniciar o código.
         **/ 
    void inicializar();
  
  
  /**
         * @brief Localiza uma determinada categoria.
         * @param nome Nome da categoria a se encontrar.
         * @return Retorna a localização da categoria.
         **/ 
    int LocalizaCategoria(std::string nome);
  
  
/**
         * @brief Localiza um determinado boleto.
         * @param nome Nome do boleto a se encontrar.
         * @return Retorna a localização do boleto.
         **/ 
    int LocalizaBoleto(std::string nome);
  
  
/**
         * @brief Função que imprime todas as categorias que o usuário tem.
         **/ 
    void imprimeCategorias();
  
  
/**
  * @brief Imprime o relatório de uma categoria específica.
  **/ 
    void sobreUmaCategoria(std::string nome);
  
  
  /**
 * @brief Função que permite o usuário criar novas categorias.
  **/ 
    void adicionaCategoria(Categoria cate);
  
  
  /**
  * @brief Função que permite o usuário excluir alguma categoria.
  **/ 
    void removeCategoria(std::string nome);
  
  
  /**
  * @brief Função que permite o usuário somar um valor x ao que ele já tem disponível, e especificar a origem do dinheiro.
  **/ 
    void novaReceita(std::string descricao, double valor);
  
  
  /**
  * @brief Função responsável por realizar um gasto dentro de uma categoria especificada.
  **/ 
    void novoGasto(std::string categoria, double valor, std::string descricao);
  
  
  /**
  * @brief Função para pagar determinado boleto, de acordo com seu nome.
  **/ 
    void pagaBoleto(std::string nome);
  
  
/**
  * @brief Função que imprime um resumo do caixa.
  **/ 
    void resumoDeCaixa();
  
  
  /**
  * @brief Função que imprime o relatório de um boleto específico.
  **/ 
    void sobreUmBoleto(std::string nome);
  
  
/**
  * @brief Função para imprimir todas as categorias que o usuário tem.
  **/ 
    void imprimeBoletos();
  
  
/**
  * @brief Função que adiciona um boleto ao vetor boletos.
  **/ 
    void adicionaBoleto(Boleto novoBol);
  
  
/**
  * @brief Função que lista os boletos ainda não pagos.
  **/ 
    void boletosAPagar();
  
  
  /**
  * @brief Função responsável por dar o comando de fechar o mês.
  **/ 
    void encerraMes();
  
  
  /**
  * @brief Função que permite ao usuário emitir um relatório mensal de gastos e receitas recebidas.
  **/ 
    void relatorioMensal(int mes);
  
  
  /**
  * @brief Função que permite ao usuário emitir um relatório de gastos e receitas recebidas desde que começou a usar o sistema.
  **/ 
    void relatorioGeral();
  
  
  /**
  * @brief Função que permite ao usuário emitir um relatório do dia atual.
  **/ 
    void relatorioAtual();

};
  class Excecao_Kapemgga: public Excecao_Caixa {
    public :
    const char* what() const noexcept{
      return "O número de caracteres da descricao excede o permitido pelo programa. Por favor, digite uma descrição com menos de 100 caracteres";
    }
  };

  class Excecao_Nome_Boleto: public Excecao_Boleto {
    public :
    const char* what() const noexcept{
      return "Já existe um boleto com o nome digitado. Por favor, escolha outro.";
    }
  };

  // class Excecao_Nome_Categoria: public Excecao_Categoria {
  //   public :
  //   const char* what() const noexcept{
  //     return "Já existe uma categoria com o nome digitado. Por favor, escolha outro.";
  //   }
  // };
  
#endif
