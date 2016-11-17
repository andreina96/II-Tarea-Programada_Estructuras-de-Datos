#include "conjuntos.h"
#include <iostream>
using namespace std;

conjunto::conjunto() : siguiente(0), primero(0){}

conjunto::conjunto(int e) : etiqueta(e), siguiente(0), primero(0){}

conjunto::~conjunto(){
    vaciar();
}

void conjunto::setEtiqueta(int e){
    etiqueta = e;
}

int conjunto::getEtiqueta(){
    return etiqueta;
}

void conjunto::setSiguiente(conjunto* s){
    siguiente = s;
}

conjunto* conjunto::getSiguiente(){
    return siguiente;
}

void conjunto::setPrimero(elemento* p){
    primero = p;
}

elemento* conjunto::getPrimero(){
    return primero;
}

void conjunto::iniciar(){
    siguiente = 0;
    primero = 0;
}

void conjunto::destruir(){
    vaciar();
}

void conjunto::vaciar(){
    if(!vacio()){
        elemento* auxiliar = primero->getSiguiente();
        while(auxiliar != 0){
            elemento* auxAEliminar = auxiliar;
            auxiliar = auxiliar->getSiguiente();
            delete auxAEliminar;
        }
        auxiliar = primero;
        primero = 0;
        delete auxiliar;
    }
}

bool conjunto::vacio(){
    if(!(primero == 0))
        return false;
    return true;
}

void conjunto::agregar(int elem){
    elemento* e = new elemento(elem);
    if(primero == 0){
        primero = e;
    }
    else{
        e->setSiguiente(primero);
        primero = e;
    }
}

void conjunto::eliminar(int elem){
    if(primero->getElemento() == elem){
        elemento* aux = primero;
        primero = primero->getSiguiente();
        delete aux;
    }
    else{
        elemento* aux = primero;
        while(!(aux->getSiguiente()->getElemento() == elem)){
            aux = aux->getSiguiente();
        }
        elemento* auxElim = aux->getSiguiente();
        aux->setSiguiente(aux->getSiguiente()->getSiguiente());
        delete auxElim;
    }
}

bool conjunto::pertenece(int elem){
    elemento* aux = primero;
    while(!(aux == 0)){
        if(aux->getElemento() == elem){
            return true;
        }
        aux = aux->getSiguiente();
    }
    return false;
}
