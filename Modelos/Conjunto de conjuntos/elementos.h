#ifndef ELEMENTOS_H_INCLUDED
#define ELEMENTOS_H_INCLUDED
#include <iostream>
using namespace std;

class elemento{

private:

    elemento* siguiente;
    int etiqueta;

public:

    elemento() : siguiente(0){}

    elemento(int e) : siguiente(0), etiqueta(e){}

    ~elemento(){}

    void setSiguiente(elemento* elem){
        siguiente = elem;
    }

    elemento* getSiguiente(){
        return siguiente;
    }

    void setElemento(int e){
        etiqueta = e;
    }

    int getElemento(){
        return etiqueta;
    }

};

#endif // ELEMENTOS_H_INCLUDED
