#ifndef BOLETO_H
#define BOLETO_H
class Boleto {
private:
  int vencimento;
  bool venceu;
  bool pago;
public:
  Boleto(int vencimento);
  ~Boleto();
  
  int getVencimento();
  bool getVenceu();
  void verificaVenceu();
};
#endif
