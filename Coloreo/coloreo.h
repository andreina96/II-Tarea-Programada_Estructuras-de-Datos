#ifndef COLOREO_H_INCLUDED
#define COLOREO_H_INCLUDED
#include "Lista de listas.h"

class Coloreo{

    public:

        Coloreo();
        virtual ~Coloreo();
        void Pruebas(int ne);
        void ResolverColoreo();
        void ColorearVertice(int v);

    private:

        CC colores;
        CC adyacentes;
        int mejorSolucion[20];
        int solucionActual[20];
        int mejorNumeroColores;
        int numeroColoresActual;
        int solucionesFactibles;
        int n;

};

#endif // COLOREO_H_INCLUDED
