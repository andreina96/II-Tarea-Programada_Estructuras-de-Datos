#include "reinas.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>
using namespace std;

Reinas::Reinas(){}

Reinas::~Reinas(){}

void Reinas::Pruebas(int ne){
    n = ne;
    mejorGanancia = 0;
    gananciaActual = 0;

    for(int i = 0; i < n; i++){
        mejorSolucion[i] = -100;
        solucionActual[i] = -100;
    }

    for(int i = 0; i < n; i++){
        srand(time(NULL));
        for(int j = 0; j < n; j++){
            tablero[i][j] = (rand() % 100);
        }
    }

    for(int i = 0; i < 9; i++){
        solucionesFactibles = 0;
        clock_t startTime = clock();
        PonerReina(0);
        clock_t endTime = clock();
        clock_t clockTicksTaken = endTime - startTime;
        double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;

        cout << "El algoritmo con elemento tardo: " << timeInSeconds << " segundos" << endl;
        cout << "Soluciones factibles encontradas: " << solucionesFactibles << endl;
        cout << "La solucion optima es: " << endl << endl;
        for(int i = 0; i < n; i++){
            cout << "Reina " << i+1 << " : columna " << mejorSolucion[i]+1 << endl;
        }
    }
}

void Reinas::ResolverReinas(){
    string sn;
    cout << "De cuanto sera el problema (tome en cuenta que el maximo es 20)? ";
    cin >> sn; stringstream(sn) >> n; cout << endl << endl;

    mejorGanancia = 0;
    gananciaActual = 0;
    solucionesFactibles = 0;

    for(int i = 0; i < n; i++){
        mejorSolucion[i] = -100;
        solucionActual[i] = -100;
    }

    bool salirse = false;
    while(!salirse){
        string st;
        cout << "Desea agregar los valores del tablero de forma manual o que se generen de forma aleatoria. Si elije aleatoria, se elijiran numeros del 0 al 100 (manual/aleatoria)? ";
        cin >> st; cout << endl << endl;

        if(st == "manual"){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    string sv; int v;
                    cout << "Cual valor desea poner en la posicion (" << i << "," << j << ")?";
                    cin >> sv; stringstream(sv) >> v; cout << endl << endl;
                    tablero[i][j] = v;
                }
            }
            salirse = true;
        }
        else if(st == "aleatoria"){
            srand(time(NULL));
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    tablero[i][j] = (rand() % 100);
                }
                cout << endl;
            }
            salirse = true;
        }
        else{
            cout << "Digite una opcion valida!" << endl << endl;
        }
    }

    PonerReina(0);
    cout << "Soluciones factibles encontradas: " << solucionesFactibles << endl;
    cout << "La solucion optima es: " << endl << endl;
    for(int i = 0; i < n; i++){
        cout << "Reina " << i+1 << " : columna " << mejorSolucion[i]+1 << endl;
    }
}

void Reinas::PonerReina(int reina){
	for(int columna = 0; columna < n; columna++){
		bool factible = true;
		if(diccionarioColumnas.pertenece(columna)){
            factible = false;
		}
		if(diccionarioDiagonalesAsc.pertenece(reina+columna)){
            factible = false;
		}
		if(diccionarioDiagonalesDesc.pertenece(reina-columna)){
            factible = false;
		}
		if(factible == true){
			solucionActual[reina] = columna;
			gananciaActual += tablero[reina][columna];
			diccionarioColumnas.agregar(columna);
			diccionarioDiagonalesAsc.agregar(reina+columna);
			diccionarioDiagonalesDesc.agregar(reina-columna);
			if(reina == (n-1)){
                solucionesFactibles++;
				if(gananciaActual > mejorGanancia){
					mejorGanancia = gananciaActual;
					for(int i = 0; i < n; i++){
                        mejorSolucion[i] = solucionActual[i];
					}
				}
			}
			else{
				PonerReina(reina+1);
			}
			diccionarioColumnas.eliminar(columna);
			diccionarioDiagonalesAsc.eliminar(reina+columna);
			diccionarioDiagonalesDesc.eliminar(reina-columna);
			gananciaActual -= tablero[reina][columna];
		}
	}
}
