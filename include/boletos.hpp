#ifndef BOLETOS_H
#define BOLETOS_H
/**
 * @file boletos.hpp
 * @brief Classe que junta todos os boletos de boleto.hpp
 * @version 1.0
 * @date 2022-11-21
 * @details A classe boletos consta cada boleto com seu
 * vencimento e outras informações relevantes.
 * 
 * @copyright GNU General Public License 
 * 
 */
#include "../include/categoria.hpp"
#include "../include/boleto.hpp"
/**
 * @brief Armazena todos os boletos e os disponibiliza para o si
 * 
 * @details Armazena todos os boletos e os disponibiliza 
 * para todo o sistema e para o Kapemgga.hpp
 * 
 */
class Boletos : public Categoria{
  private:
  /**
     * @brief boletos vencidos?
     */
  bool vencidos; //não entendi porque aqui seria um bool. Tipo, "vencidos" não era pra contar todos os boletos vencidos ou eu so muito animal mesmo? (ASSIN: Kaique)
  /* é só para indicar se tá vencido ou não. Tipo, a data passou, então vencido passa a ser true.*/
  //então tinha que ser uma variável no singular, não?//além disso não tinha que ser um vetor?
  public:
  /**
         * @brief Constrói o objeto Boletos.
         * 
         * @param _vencidos contém todos os
         * boletos vencidos que foram recebidos
         * 
         */
    Boletos(bool _vencidos);
  /**
         * @brief Destrói o objeto Boletos.
         * 
         */
    ~Boletos();
  /**
         * @brief Método Get() onde são selecionados os boletos vencidos
         * 
         * @details A preencher
         * 
         * @return retorna os boletos vencidos
         */
  Boleto getVencidos();
  /**
         * @brief Método Get() onde se é testado se um determinado boleto venceu
         * 
         * @details A preencher
         * 
         * @return retorna se o boleto venceu ou não
         */
  bool getVenceu();
  /**
         * @brief Apresenta um relatório de uma determinada categoria
         * 
         * @details A preencher
         * 
         */
  void relatorioDeCategoria();
};
#endif

