#ifndef BOLETO_H
#define BOLETO_H
class Boleto {
private:
  int _vencimento;
  bool _venceu;
  bool _pago;
public:

//Construtor

  Boleto(int vencimento);
//Destrutor

  ~Boleto();
//Métodos

  int getVencimento();
  bool getVenceu();
  void verificaVenceu();
};
#endif
