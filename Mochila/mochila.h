#ifndef MOCHILA_H_INCLUDED
#define MOCHILA_H_INCLUDED
#include <iostream>

class Mochila{

    public:

        Mochila();
        virtual ~Mochila();
        void Pruebas(int ne);
        void ResolverMochila();
        void AgregarObjeto(int);

    private:

        int numObjetos;
        int objetosTentativos[10000];
        int objetosDefinitivos[10000] ;
        int valorObjetos[10000] ;
        int pesoObjetos[10000];
        int solucionesFactibles;
        int valorMaximo ;
        int valorActual;
        int pesoActual;
        int pesoMaximo;

};

#endif // MOCHILA_H_INCLUDED
