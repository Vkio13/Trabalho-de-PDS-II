#include "../include/boleto.hpp"

        Boleto::Boleto(int vencimento);{
                _vencimento =vencimento;
        }

        int Boleto::getVencimento(){
          return _vencimento;
        }
        bool Boleto::getVenceu(){
          return _venceu;
        }
