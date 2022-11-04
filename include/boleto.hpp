#ifndef BOLETO_H
#define BOLETO_H
class Boleto {
private:
  int vencimento;
  bool venceu;
  bool pago;
public:

//Construtor

  Boleto(int _vencimento);
//Destrutor

  ~Boleto();
//Métodos

  int getVencimento();
  bool getVenceu();
  void verificaVenceu();
};
#endif
