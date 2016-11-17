#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <iostream>
#include "cajita.h"
using namespace std;

class lista{

    public:

        lista() : primero(0){}

        ~lista(){
            if(!(primero == 0)){
                cajita* aux = primero;
                while(!(aux == 0)){
                    cajita* auxAEliminar = aux;
                    aux = aux->getSiguiente();
                    delete auxAEliminar;
                }
            }
        }

        int etiPrimero(){
            return primero->getDiagonal();
        }

        void agregar(int d){
            if(primero == 0){
                cajita* aux = new cajita(d);
                primero = aux;
            }
            else{
                if(primero->getSiguiente() == 0){
                    cajita* aux = new cajita(d);
                    primero->setSiguiente(aux);
                }
                else{
                    cajita* aux = new cajita(d);
                    aux->setSiguiente(primero->getSiguiente());
                    primero->setSiguiente(aux);
                }
            }
        }

        void eliminar(int d){
            if(primero->getDiagonal() == d){
                cajita* aux = primero;
                primero = primero->getSiguiente();
                delete aux;
            }
            else{
                cajita* aux = primero;
                while(!(aux->getSiguiente()->getDiagonal() == d)){
                    aux = aux->getSiguiente();
                }
                cajita* auxAEliminar = aux->getSiguiente();
                aux->setSiguiente(aux->getSiguiente()->getSiguiente());
                delete auxAEliminar;
            }
        }

        bool pertenece(int d){
            if(!(primero == 0)){
                if(primero->getDiagonal() == d){
                    return true;
                }
                else{
                    cajita* aux = primero;
                    while(!(aux == 0)){
                        if(aux->getDiagonal() == d){
                            return true;
                        }
                        aux = aux->getSiguiente();
                    }
                }
            }
            return false;
        }

        void recorrer(){
            cajita* aux = primero;
            while(!(aux == 0)){
                cout << aux->getDiagonal() << endl;
                aux = aux->getSiguiente();
            }
        }

    private:

        cajita* primero;

};

#endif // LISTA_H_INCLUDED
