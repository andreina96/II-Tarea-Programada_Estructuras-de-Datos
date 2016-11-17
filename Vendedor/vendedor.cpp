#include "vendedor.h"
#include "Lista de listas.cpp"
#include "conjuntos.cpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>
using namespace std;

Vendedor::Vendedor(){}

Vendedor::~Vendedor(){}

void Vendedor::ResolverVendedor(){
    string sn;
    cout << "Cuantos vertices tendra el grafo (tome en cuenta que el maximo es 20)? ";
    cin >> sn; stringstream(sn) >> n; cout << endl << endl;
    srand(time(NULL));
    solucioEncontrada = false;
    verticesVisitados = 0;
    mejorCantidad = 0;
    cantidadActual = 0;
    solucionesFactibles = 0;

    for(int i = 0; i < n; i++){
        mejorSolucion[i] = -100;
        solucionActual[i] = -100;
        adyacentes.agregarConjunto(i);
        for(int j = 0; j < n; j++){
            grafo[i][j] = -1;
        }
    }

    bool salirse = false;
    while(!salirse){
        string sa;
        cout << "Desea agregar las aristas de forma manual o que se generen de forma aleatoria (manual/aleatoria)? ";
        cin >> sa; cout << endl << endl;

        if(sa == "manual"){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    string sr;
                    if (i != j){
                        cout << "Desea agregar una arista entre los vertices " << i << " y " << j << " (si/cualquier otra cosa)?";
                        cin >> sr; cout << endl;
                        if(sr == "si"){
                            string sp; int p;
                            cout << "Que peso tendra la arista entre " << i << " y " << j << " (solo pesos positivos)?";
                            cin >> sp; stringstream(sp) >> p;
                            grafo[i][j] = p;
                            adyacentes.agregarElementoConjunto(i,j);

                        }
                    }
                }
                salirse = true;
            }
        }
        else if(sa == "aleatoria"){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                        grafo[i][j] = rand() % 100+1;
                        adyacentes.agregarElementoConjunto(i,j);

                }
            }
            salirse = true;
        }
        else{
            cout << "Digite una opcion valida!" << endl << endl;
        }
    }

    string t;
    cout << "Con cual tecnica desea resolver el problema (greedy/local/rya/pura)? ";
    cin >> t; cout << endl << endl;
    salirse = false;

    if(t == "greedy"){
        primero = 0;
        VendedorGreedy(primero);
    }
    else if(t == "local"){
        VendedorLocal(0);
    }
    else if(t == "rya"){
        VendedorRYA(0);
    }
    else if(t == "pura"){
        primero = 0;
        VendedorPura(primero);
    }
    else{
        cout << "Digite una opcion valida!" << endl << endl;
    }


    cout << "Soluciones factibles encontradas: " << solucionesFactibles << endl;
    cout << "La soluciown optima es realizar un recorrido de costo "<<mejorCantidad << " siguiendo el siguiente recorrido : " << endl << endl;
    for(int i = 0; i < n; i++){
        cout << "Vertice : " << i+1 << " -> " << mejorSolucion[i]+1 << endl;
    }
}

void Vendedor::VendedorGreedy(int v){
    bool probados[n];
    for (int i = 0; i < n ; i++){
        probados[i] = 0;
    }
    verticesRecorridos.agregar(v);
    if(verticesVisitados == n-1 ){
        cout << verticesVisitados << " vertices visitados" << endl;
        if(Adyacentes(v,primero) || n == 3){
            solucioEncontrada = true;
            solucionActual[v] = primero;
            cantidadActual += grafo[v][primero];
            mejorCantidad = cantidadActual;
                for(int i = 0; i < n; i++){
                    mejorSolucion[i] = solucionActual[i];
                }
        }
    }
    int aristaMasCorta = 99999;
    int verticeMasCercano = -1;

    while (!solucioEncontrada && verticesVisitados < n-1){
        for (int j= 0; j < n; j++){
            if (grafo[v][j] < aristaMasCorta && v != j && !verticesRecorridos.pertenece(j) && probados[verticeMasCercano]==false && Adyacentes(v,j)){
                aristaMasCorta = grafo[v][j];
                verticeMasCercano = j;
            }
        }
        verticesVisitados ++;
        probados[verticeMasCercano] = true;
        cantidadActual += grafo[v][verticeMasCercano];
        solucionActual[v] = verticeMasCercano;
        VendedorGreedy(verticeMasCercano);
        verticesVisitados --;
        cantidadActual -= grafo[v][verticeMasCercano];
    }

}

void Vendedor::VendedorLocal(int v){
}

void Vendedor::VendedorRYA(int v){}

void Vendedor::VendedorPura(int v){
    verticesRecorridos.agregar(v);
    cout << "el metodo se llamo con el vertice: "<< v << endl;
    for(int va = 0; va < n; va++){
        cout << va << " vertice adyacente tentativo" <<endl;
        if(va != v && Adyacentes(v, va) && !(verticesRecorridos.pertenece(va))){
            cout << va << " vertice adyacente escogido" <<endl;
            verticesVisitados ++;
            cout << verticesVisitados << " vertices visitados" << endl;
            cantidadActual += grafo[v][va];
            solucionActual[v] = va;
            if(verticesVisitados == n-1){
                if(Adyacentes(va, primero)){
                    solucionActual[va] = primero;
                    cantidadActual += grafo[va][primero];
                    solucionesFactibles++;
                    if(cantidadActual > mejorCantidad){
                        mejorCantidad = cantidadActual;
                        for(int i = 0; i < n; i++){
                            mejorSolucion[i] = solucionActual[i];
                        }
                    }
                }
            }
            else{
                VendedorPura(va);
            }
            verticesVisitados --;
            cantidadActual -= grafo[v][va];
        }
    }
    verticesRecorridos.eliminar(v);
}

bool Vendedor::Adyacentes(int v1,int v2){
    if(grafo[v1][v2] != -1){
        return true;
    }
    else return false;
}
