#include "distribucion.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>
using namespace std;

Distribucion::Distribucion(){}

Distribucion::~Distribucion(){}

void Distribucion::ResolverDistribucion(){
    unidadesDisponibles= 0;
    itemesTotales = 0;
    srand(time(NULL));
    minimizacion = 1;
    int decision;
    cout << "Digite 1 si desea que el programa minimice, si no maximizara por default" << endl;
    cin >> decision;
    if(decision == 1){
        minimizacion = -1;
    }
    string sitemes;
    cout << "Cuantos itemes tendra el problema? ";
    cin >> sitemes; stringstream(sitemes) >> itemes;

    string sunidades;
    cout << "Cuantas unidades a distribuir tendra el problema? ";
    cin >> sunidades; stringstream(sunidades) >> unidades;

    string smaximo;
    cout << "Cual sera el maximo de unidades a distribuir por item? ";
    cin >> smaximo; stringstream(smaximo) >> maximo;

    string sminimo;
    cout << "Cual sera el minimo de unidades a distribuir por item? ";
    cin >> sminimo; stringstream(sminimo) >> minimo; cout << endl << endl;

    unidadesDisponibles = unidades;
    itemesTotales = itemes;
    solucionesFactibles = 0;
    itemesRestantes= itemesTotales;

    for(int i = 0; i <= itemes; i++){
            solucionActual[i] = -100;
            mejorSolucion[i] = -1;
    }

    bool salirse = false;
    while(!salirse){
        string st;
        cout << "Desea agregar los datos del problema de manera manual o desea que se generen de manera aleatoria (manual/aleatoria)? ";
        cin >> st; cout << endl << endl;

        if(st == "manual"){
            for(int i = 1; i <= itemes; i++){
                for(int j = 1; j <= unidades; j++){
                    string svalor; int valor;
                    cout << "Que valor desea que tenga el item " << i << ", cuando la cantidad de unidades es " << j << "? ";
                    cin >> svalor; stringstream(svalor) >> valor; cout << cin;
                    tablero[i][j] = valor*minimizacion;
                }
            }
            cout << endl;
            salirse = true;
        }
        else if(st == "aleatoria"){
            for(int i = 1; i <= itemes; i++){
                for(int j = minimo; j <= maximo; j++){
                    tablero[i][j] = ((rand() % 6)+1)*minimizacion;
                    if (j > minimo && tablero[i][j] > tablero [i][j-1]){
                        tablero[i][j] =  tablero [i][j-1] - (rand() % 4);
                    }
                }
                cout << endl;
            }
            cout << endl;
            salirse = true;
        }
        else{
            cout << "Digite una opcion valida!" << endl << endl;
        }
        cout << "La matriz de valores resultantes es la siguiente (donde las filas representan tareas y las columnas unidades posibles a asignar, por ejemplo: la posicion (1,2) representa el valor de asignar 2 unidades a la tarea 1" << endl << endl;
        cout <<"              " << "Cantidad de Unidades"<< endl;
        cout <<"                 ";
        for (int j = minimo; j <= maximo  ;j++ ){
            cout << j <<  "  ";
        }
        cout << "" << endl;
        cout <<"                 ";
        for (int j = minimo; j <= maximo  ;j++ ){
            cout << "_" <<  "  ";
        }
        cout << "" << endl << endl;
        for (int i = 1; i <= itemesTotales  ;i++ ){
            cout << "Tarea numero " << i << " : ";
            for (int j = minimo; j <= maximo  ;j++ )  {
                cout << tablero[i][j]*minimizacion <<  "  ";
            }
            cout << "" << endl<<endl<< endl;
        }

        string t;
        int greedy = 0;
        cout << "Con cual tecnica desea resolver el problema (greedy/local/rya/pura)? ";
        cin >> t; cout << endl << endl;
        salirse = false;
        while(!salirse){
            if(t == "greedy"){
                greedy = 1;
                DarUnidadesGreedy();
            }
            else if(t == "local"){
                DarUnidadesLocal(1);
            }
            else if(t == "rya"){
                DarUnidadesRYA(1);
            }
            else if(t == "pura"){
                DarUnidadesPura(1);
            }
            else{
                salirse = true;
                cout << "" << endl << endl;
            }
            salirse = true;
        }

        cout << "Soluciones factibles encontradas: " << solucionesFactibles << endl;
        cout << "La solucion optima es: " << endl << endl;
        for(int i = 1; i <= itemes; i++){
            cout << "Item " << i << " : " << mejorSolucion[i-1+greedy] << " unidades" << endl;
        }
    }
}

void Distribucion::DarUnidadesGreedy(){
    while(unidadesDisponibles > 0){
        int valorMejorTareaConMax  = 0;
        int mejorTareaConMax = 0;
        int maximoPosible = maximo;
        bool posible = false;
        itemesRestantes--;
        while (!posible){
            if(unidadesDisponibles - maximoPosible>=(itemesRestantes)*minimo){
                posible = true;
            }
            else{
                maximoPosible--;
            }
        }

        for (int i = 1; i <= itemesTotales; i++){
            if (tablero[i][maximoPosible] > valorMejorTareaConMax && mejorSolucion[i] == -1){
                valorMejorTareaConMax = tablero[i][maximoPosible];
                mejorTareaConMax= i;
            }
        }
        unidadesDisponibles -=maximoPosible;
        mejorValor += valorMejorTareaConMax;
        mejorSolucion[mejorTareaConMax] = maximoPosible;

    }

}


void Distribucion::DarUnidadesLocal(int i){}

void Distribucion::DarUnidadesRYA(int i){}

void Distribucion::DarUnidadesPura(int i){
    for(int u = minimo; u <= maximo; u++){
        if((unidadesDisponibles - u) <= (itemesTotales-i)*maximo &&  (unidadesDisponibles - u) >=(itemesTotales-i)*minimo){
                unidadesDisponibles -=u;
                valorActual += tablero[i][u];
                solucionActual[i-1] = u;
                if(i == itemesTotales){
                    solucionesFactibles++;
                    if(valorActual > mejorValor){
                        mejorValor = valorActual;
                        for(int j = 0; j < itemes ; j++){
                            mejorSolucion[j] = solucionActual[j];
                        }
                    }
                }
                else{
                    DarUnidadesPura(i+1);
                }
                unidadesDisponibles += u;
                valorActual -= tablero[i][u];

        }
    }
}
