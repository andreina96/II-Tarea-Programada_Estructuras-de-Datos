#ifndef LISTA_DE_LISTAS_H_INCLUDED
#define LISTA_DE_LISTAS_H_INCLUDED
#include "conjuntos.h"

class CC{

private:

    conjunto* primero;

public:

    CC(int c);
    CC();
    ~CC();
    void iniciar();
    void destruir();
    void vaciar();
    bool vacio();
    void agregarConjunto(int c);
    void eliminarConjunto(int c);
    bool conjuntoVacio(int c);
    bool conjuntoDisjuntos(int c1, CC& cc, int c2);
    conjunto* existeConjunto(int c);
    void agregarElementoConjunto(int c, int e);
    void eliminarElementoConjunto(int c, int e);
    bool perteneceElementoConjunto(int c, int e);

};

#endif // LISTA_DE_LISTAS_H_INCLUDED
