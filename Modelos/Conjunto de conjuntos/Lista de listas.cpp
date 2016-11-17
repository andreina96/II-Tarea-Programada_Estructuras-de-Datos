#include <iostream>
#include "Lista de listas.h"
using namespace std;

CC::CC(int c){
    primero = new conjunto(c);
}

CC::CC() : primero(0){}

CC::~CC(){
    vaciar();
}

void CC::iniciar(){
    primero = 0;
}

void CC::destruir(){
    vaciar();
}

void CC::vaciar(){
    if(!vacio()){
        conjunto* auxiliar = primero->getSiguiente();
        while(auxiliar != 0){
            conjunto* auxAEliminar = auxiliar;
            auxiliar = auxiliar->getSiguiente();
            delete auxAEliminar;
        }
        auxiliar = primero;
        primero = 0;
        delete auxiliar;
    }
}

bool CC::vacio(){
    if(!(primero == 0))
        return false;
    return true;
}

void CC::agregarConjunto(int c){
    conjunto* aux = new conjunto(c);
    if(primero == 0){
        primero = new conjunto(c);
    }
    else{
        aux->setSiguiente(primero);
        primero = aux;
    }
}

void CC::eliminarConjunto(int c){
    if(primero->getEtiqueta() == c){
        conjunto* aux = primero;
        primero = primero->getSiguiente();
        delete aux;
    }
    else{
        conjunto* aux = primero;
        while(!(aux->getSiguiente()->getEtiqueta() == c)){
            aux = aux->getSiguiente();
        }
        conjunto* auxElim = aux->getSiguiente();
        aux->setSiguiente(aux->getSiguiente()->getSiguiente());
        delete auxElim;
    }
}

bool CC::conjuntoVacio(int c){
    conjunto* aux = existeConjunto(c);
    if(aux->vacio())
        return true;
    return false;
}

bool CC::conjuntoDisjuntos(int c1, CC& cc, int c2){
    conjunto* aux1 = existeConjunto(c1);
    conjunto* aux2 = cc.existeConjunto(c2);
    if(!(aux1 == 0) && !(aux2 == 0)){
        elemento* elem1 = aux1->getPrimero();
        elemento* elem2;
        while(!(elem1 == 0)){
            elem2 = aux2->getPrimero();
            while(!(elem2 == 0)){
                if(elem1->getElemento() == elem2->getElemento()){
                    return false;
                }
                elem2 = elem2->getSiguiente();
            }
            elem1 = elem1->getSiguiente();
        }
    }
    return true;
}

conjunto* CC::existeConjunto(int c){
    conjunto* aux = primero;
    while(!(aux == 0)){
        if(aux->getEtiqueta() == c){
            return aux;
        }
        aux = aux->getSiguiente();
    }
    return aux;
}

void CC::agregarElementoConjunto(int c, int e){
    if(primero->getEtiqueta() == c){
        primero->agregar(e);
    }
    else{
        conjunto* aux = primero;
        while(!(aux->getSiguiente()->getEtiqueta() == c)){
            aux = aux->getSiguiente();
        }
        aux->getSiguiente()->agregar(e);
    }
}

void CC::eliminarElementoConjunto(int c, int e){
    if(primero->getEtiqueta() == c){
        primero->eliminar(e);
    }
    else{
        conjunto* aux = primero;
        while(!(aux->getSiguiente()->getEtiqueta() == c)){
            aux = aux->getSiguiente();
        }
        aux->getSiguiente()->eliminar(e);
    }
}

bool CC::perteneceElementoConjunto(int c, int e){
    bool pertenece = false;
    if(primero->getEtiqueta() == c){
        pertenece = primero->pertenece(e);
    }
    else{
        conjunto* aux = primero;
        while(!(aux->getSiguiente()->getEtiqueta() == c)){
            aux = aux->getSiguiente();
        }
        pertenece = aux->getSiguiente()->pertenece(e);
    }
    return pertenece;
}
