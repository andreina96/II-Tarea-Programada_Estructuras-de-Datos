#ifndef Vendedor_H_INCLUDED
#define Vendedor_H_INCLUDED
#include "Lista de listas.h"
#include "lista.h"

class Vendedor{

    public:

        Vendedor();
        virtual ~Vendedor();
        void ResolverVendedor();
        void VendedorGreedy(int i);
        void VendedorLocal(int i);
        void VendedorRYA(int i);
        void VendedorPura(int i);
        bool Adyacentes (int, int);

    private:
        bool solucioEncontrada;
        int primero;
        lista verticesRecorridos;
        CC adyacentes;
        int grafo[20][20];
        int mejorSolucion[20];
        int solucionActual[20];
        int verticesVisitados;
        int mejorCantidad;
        int cantidadActual;
        int solucionesFactibles;
        int n;

};

#endif // HAMILTON_H_INCLUDED
