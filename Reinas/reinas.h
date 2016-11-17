#ifndef REINAS_H_INCLUDED
#define REINAS_H_INCLUDED
#include "lista.h"

class Reinas{

    public:

        Reinas();
        virtual ~Reinas();
        void Pruebas(int ne);
        void ResolverReinas();
        void PonerReina(int r);

    private:

        lista diccionarioColumnas;
        lista diccionarioDiagonalesAsc;
        lista diccionarioDiagonalesDesc;
        int tablero[20][20];
        int mejorSolucion[20];
        int solucionActual[20];
        int mejorGanancia;
        int gananciaActual;
        int solucionesFactibles;
        int n;

};

#endif // REINAS_H_INCLUDED
