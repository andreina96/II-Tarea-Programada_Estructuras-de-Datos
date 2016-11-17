#include "mochila.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <ctime>

using namespace std;

Mochila::Mochila(){}

Mochila::~Mochila(){}

void Mochila::Pruebas(int ne){
    solucionesFactibles = 0;
    valorActual= 0;
    pesoActual = 0;
    valorMaximo = 0;
    for(int i = 0; i < numObjetos; i++){
		objetosTentativos[i] = 0;
		objetosDefinitivos[i] = 0;
	}

    srand (time(NULL));
    int rangoParaPesoIndividual;
    int rangoParaValorIndividual;
    numObjetos = ne;
    pesoMaximo = 100;
    rangoParaPesoIndividual = 10;
    rangoParaValorIndividual = 10;

    for(int i = 0; i < numObjetos  ;i++ ){
        pesoObjetos [i] = rand()% rangoParaPesoIndividual + 1;
        valorObjetos[i] = rand()% rangoParaValorIndividual + 1;
    }

    clock_t startTime = clock();
	AgregarObjeto(0);
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    cout << "El algoritmo con elemento tardo: " << timeInSeconds << " segundos" << endl;
    cout << "Soluciones factibles: " << solucionesFactibles << endl;
	cout << "Ademas este valor se obtuvo al escoger los siguientes objetos:  " << endl << endl;
	for(int i = 0; i < numObjetos; i++ ){
		if(objetosDefinitivos[i] == 1){
            cout << "Objeto numero: " << i +1<< " con un peso de: "  << pesoObjetos[i] <<" y un valor de: " << valorObjetos[i] << " ." << endl;
		}
	}
}

void Mochila::ResolverMochila(){
    valorActual= 0;
    pesoActual = 0;
    valorMaximo = 0;
    for(int i = 0; i < numObjetos; i++){
		objetosTentativos[i] = 0;
		objetosDefinitivos[i] = 0;
	}
    string decision;
    cout << "Desea digitar manualmente cada objeto o desea que se generen de forma aletoaria (manual/aleatorio)? " << endl;
    cin >> decision;
    if(decision == "aleatoria"){
        srand (time(NULL));
        int rangoParaPesoIndividual;
        int rangoParaValorIndividual;
        cout << "Digite la cantidad de objetos de los cuales se va a escoger para llenar la mochila." << endl;
        cin >> numObjetos;
        cout << "Digite el peso maximo que la mochila puede aguantar." << endl;
        cin >> pesoMaximo;
        cout << "Entre que rango de numeros desea que se encuentre el peso individual de cada objeto? " << endl;
        cin >> rangoParaPesoIndividual;
        cout << "Entre que rango de numeros desea que se encuentre el valor inicial de cada objeto? " << endl;
        cin >> rangoParaValorIndividual;

        for(int i = 0; i < numObjetos  ;i++ ){
            pesoObjetos [i] =rand()% rangoParaPesoIndividual + 1;
            valorObjetos[i]= rand()% rangoParaValorIndividual + 1;
        }
    }
    else if(decision == "manual"){
        cout << "Digite la cantidad de objetos de los cuales se va a escoger para llenar la mochila." << endl;
        cin >> numObjetos;
        cout << "Digite el peso maximo que la mochila puede aguantar." << endl;
        cin >> pesoMaximo;
        for(int i = 0; i < numObjetos  ;i++ ){
            cout << "Digite el peso del objeto numero " << i + 1 << " ."<< endl;
            cin >> pesoObjetos [i];
            cout << "Digite el valor del objeto numero " << i + 1<< " ."<< endl;
            cin >> valorObjetos [i];
        }
    }
    for(int i = 0; i < 9;i++){
    timeval tim;
    gettimeofday(&tim, NULL);
    double t1 =tim.tv_sec+(tim.tv_usec/1000000.0);
	AgregarObjeto(0);
    gettimeofday(&tim, NULL);
    double t2=tim.tv_sec+(tim.tv_usec/1000000.0);
	cout << "El valor maximo con el que se logro llenar la bolsa fue de: " << valorMaximo << " y se tardaron: " << t2-t1 <<" segundos en hallar este resultado." << endl;
	cout << "Ademas este valor se obtuvo al escoger los siguientes objetos:  " << endl << endl;
    cout << "Soluciones factibles: " << solucionesFactibles << endl;

	for(int i = 0; i < numObjetos; i++ ){
		if(objetosDefinitivos[i] == 1){
            cout << "Objeto numero: " << i +1<< " con un peso de: "  << pesoObjetos[i] <<" y un valor de: " << valorObjetos[i] << " ." << endl;
		}
	}
    }
}

void Mochila::AgregarObjeto (int n){
    for(int i = n; i < numObjetos; i ++){
        if( pesoActual + pesoObjetos[i]<= pesoMaximo){
            pesoActual += pesoObjetos[i];
            valorActual += valorObjetos[i];
            objetosTentativos[i] = 1;
            if(i == numObjetos- 1){
                solucionesFactibles++;
                if(valorActual > valorMaximo){
                    valorMaximo = valorActual;
                    for(int j = 0; j < numObjetos; j++){
                        objetosDefinitivos[j] = objetosTentativos[j];
                    }
                }
            }
            else{
                AgregarObjeto(i+1);
            }
            pesoActual -= pesoObjetos[i];
            valorActual -= valorObjetos[i];
            objetosTentativos[i] = 0;
        }
    }
}
