#include "coloreo.h"
#include "Lista de listas.cpp"
#include "conjuntos.cpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>
#include <ctime>
using namespace std;

Coloreo::Coloreo(){}

Coloreo::~Coloreo(){}

void Coloreo::Pruebas(int ne){
    n = ne;
    mejorNumeroColores = n;
    numeroColoresActual = 0;
    solucionesFactibles = 0;

    for(int i = 0; i < n; i++){
        mejorSolucion[i] = -100;
        solucionActual[i] = -100;
        adyacentes.agregarConjunto(i);
    }
    int k = 1;
    for(int i = 0; i < n-1; i++){
        srand(time(NULL));
        for(int j = k; j < n; j++){
            if((rand() % 2)){
                adyacentes.agregarElementoConjunto(i,j);
                adyacentes.agregarElementoConjunto(j,i);
            }
        }
        k++;
    }
    clock_t startTime = clock();
    ColorearVertice(0);
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    cout << "El algoritmo con elemento tardo: " << timeInSeconds << " segundos" << endl;
    cout << "Soluciones factibles encontradas: " << solucionesFactibles << endl;
    cout << "La solución optima es: " << endl << endl;
    for(int i = 0; i < n; i++){
        cout << "Vertice " << i+1 << " : color " << mejorSolucion[i]+1 << endl;
    }
}

void Coloreo::ResolverColoreo(){
    string sn;
    cout << "Cuantos vertices tendra el grafo (tome en cuenta que el maximo es 20)? ";
    cin >> sn; stringstream(sn) >> n; cout << endl << endl;

    mejorNumeroColores = n;
    numeroColoresActual = 0;
    solucionesFactibles = 0;

    for(int i = 0; i < n; i++){
        mejorSolucion[i] = -100;
        solucionActual[i] = -100;
        adyacentes.agregarConjunto(i);
    }

    bool salirse = false;
    while(!salirse){
        string sa;
        cout << "Desea agregar las aristas de forma manual o que se generen de forma aleatoria (manual/aleatoria)? ";
        cin >> sa; cout << endl << endl;

        if(sa == "manual"){
            int k = 1;
            for(int i = 0; i < n-1; i++){
                for(int j = k; j < n; j++){
                    string sr;
                    cout << "Desea agregar una arista entre los vertices " << i << " y " << j << " (si/cualquier otra cosa)?";
                    cin >> sr; cout << endl << endl;
                    if(sr == "si"){
                        adyacentes.agregarElementoConjunto(i,j);
                        adyacentes.agregarElementoConjunto(j,i);
                    }
                }
                k++;
            }
            salirse = true;
        }
        else if(sa == "aleatoria"){
            int k = 1;
            for(int i = 0; i < n-1; i++){
                for(int j = k; j < n; j++){
                    srand(time(NULL));
                    if((rand() % 2)){
                        adyacentes.agregarElementoConjunto(i,j);
                        adyacentes.agregarElementoConjunto(j,i);
                    }
                }
                k++;
            }
            salirse = true;
        }
        else{
            cout << "Digite una opcion valida!" << endl << endl;
        }
    }

    ColorearVertice(0);
    cout << "Soluciones factibles encontradas: " << solucionesFactibles << endl;
    cout << "La solución optima es: " << endl << endl;
    for(int i = 0; i < 5; i++){
        cout << "Vertice " << i+1 << " : color " << mejorSolucion[i]+1 << endl;
    }
}

void Coloreo::ColorearVertice(int v){
    for(int c = 0; c < n; c++){
        if(colores.conjuntoDisjuntos(c,adyacentes,v)){
            if(colores.existeConjunto(c)){
                colores.agregarElementoConjunto(c,v);
                solucionActual[v] = c;
            }
            else{
                colores.agregarConjunto(c);
                colores.agregarElementoConjunto(c,v);
                numeroColoresActual++;
                solucionActual[v] = c;
            }
            if(v == (n-1)){
                solucionesFactibles++;
                if(mejorNumeroColores > numeroColoresActual){
                    mejorNumeroColores = numeroColoresActual;
                    for(int i = 0; i < n; i++){
                        mejorSolucion[i] = solucionActual[i];
                    }
                }
            }
            else{
                ColorearVertice(v+1);
            }
            colores.eliminarElementoConjunto(c,v);
            if(colores.conjuntoVacio(c)){
                colores.eliminarConjunto(c);
                numeroColoresActual--;
            }
        }
    }
}
