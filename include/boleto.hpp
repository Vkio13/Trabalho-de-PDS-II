#ifndef BOLETO_H
#define BOLETO_H
#include "categoria.hpp"

class Boleto : public Categoria {
    private:
        int _vencimento;
        bool _pago;
    
    public:
        //Construtor
        Boleto(std::string nome, int valor, int vencimento);
        //Destrutor
        ~Boleto();
        //Métodos
        void pagaBoleto();
        bool venceu();
        void relatorioDeCategoria() override;
};
#endif
