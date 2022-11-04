#ifndef BOLETOS_H
#define BOLETOS_H

class Boletos :: public Categoria{
  private:
  bool vencidos; //não entendi porque aqui seria um bool. Tipo, "vencidos" não era pra contar todos os boletos vencidos ou eu so muito animal mesmo? (ASSIN: Kaique)
  /* é só para indicar se tá vencido ou não. Tipo, a data passou, então vencido passa a ser true.*/
  public:
    Boletos(bool vencidos){

    }
  Boletos getVencidos();
  bool getVenceu();
  void relatorioDeCategoria();
};
#endif

