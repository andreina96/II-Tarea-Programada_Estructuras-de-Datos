#include "Asignacion.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
using namespace std;

Asignacion::Asignacion()
{
    //ctor
}

Asignacion::~Asignacion()
{
    //dtor
}

void Asignacion::ResolverAsignacion(){
    int decision;
    cout << "Desea digitar manualmente cada objeto o desea que se generen de forma aletoaria? (digite 0 para manual, 1 para aleatorio) " << endl;
    cin >> decision;

    if (decision){
        srand (time(NULL));
        int rangoParaGananciaIndividual;
        minimizacion = 1;
        int decision;
        cout << "Digite 1 si desea que el programa minimice, si no maximizara por default" << endl;
        cin >> decision;
        if(decision == 1){
            minimizacion = -1;
        }
        cout << "Digite la cantidad de asignaciones que desea realizar (tanto elementos como tareas)." << endl;
        cin >> numAsignaciones;
        cout << "Entre que rango de valores desea que se encuentre la ganancia (o la perdida de realizar cada tarea)? " << endl;
        cin >> rangoParaGananciaIndividual;

        for (int i = 0; i < numAsignaciones  ;i++ ){
                for (int j = 0; j < numAsignaciones  ;j++ ){
                    valores[i][j] = (rand()% rangoParaGananciaIndividual + 1)*minimizacion;
                }
        }


    }
    else{

        cout << "Digite la cantidad de asignaciones que desea realizar (tanto elementos como tareas)." << endl;
        cin >> numAsignaciones;
        for (int i = 0; i < numAsignaciones  ;i++ ){
            for (int j = 0; j < numAsignaciones  ;j++ )  {
                cout << "Digite la ganancia de asignar al elemento " << i +1 << " en la tarea " << j +1<< " ."<< endl;
                cin >> valores[i][j];
                valores[i][j] = valores[i][j]*minimizacion;
            }
        }

    }
    cout << "La matriz de valores resultantes es la siguiente (donde las filas representan elementos y las columnas labores, por ejemplo: la posicion (1,2) representa el valor de asignar el elemento 1 a al labor 2" << endl << endl;
    for (int i = 0; i < numAsignaciones  ;i++ ){
        for (int j = 0; j < numAsignaciones  ;j++ )  {
            cout << valores[i][j] <<  "  ";
        }
        cout << "" << endl<<endl;
    }

    for (int i = 0; i < numAsignaciones  ;i++ ){
		asignacionesTentativas[i] = -1;
		asignacionesDefinitivas[i] = -1;
		laborAsignado[i] = 0;
		solucionesFactiblesTotales = solucionesFactiblesTotales*(i+1);
	}
    bool seguir = true;
    while (seguir){
        mejorValorTentativo= 0;
        mejorValorDefinitivo = 0;
        solucionesFactiblesObtenidas = 0;
        solucionesFactiblesTotales = 1;

        poda = false;
        cout << "Que tipo de busqueda desea realizar? (digite 0 para greedy, 1 para B.E.R.A o 2 para exhaustiva, 3 para local) 4 para salir" << endl;
        cin >> decision;
        timeval tim;
        gettimeofday(&tim, NULL);
        double t1 =tim.tv_sec+(tim.tv_usec/1000000.0);
        if (decision == 0){
            AsignarElementoAlLaborGreedy();
        }
        else if(decision == 1){
            AsignarElementoAlLaborAcotamiento(0);
        }
        else if (decision == 2){
            AsignarElementoAlLaborExhaustivo(0);
        }
        else if (decision == 3){
            AsignarElementoAlLaborLocal();
        }
        else{
            seguir = false;
        }
        if (decision < 4){
            gettimeofday(&tim, NULL);
            double t2=tim.tv_sec+(tim.tv_usec/1000000.0);
            cout <<"De un total de " << solucionesFactiblesTotales << " soluciones, se tuvieron que calcular " <<solucionesFactiblesObtenidas << " soluciones factibles encontradas el valor maximo que se obtuvo al hacer las asignaciones es de: " << mejorValorDefinitivo << " y se tardaron: " << t2-t1 <<" segundos en hallar este resultado." << endl;
            cout << "Ademas este valor se obtuvo al hacer las siguientes asignaciones:  " << endl << endl;
            for (int i = 0; i < numAsignaciones; i++ ){
                cout << "El elemento " << i+1 << " se asigno al labor " << asignacionesDefinitivas[i] +1 << endl;
            }
        }
        for (int i = 0; i < numAsignaciones  ;i++ ){
		asignacionesTentativas[i] = -1;
		asignacionesDefinitivas[i] = -1;
		laborAsignado[i] = 0;
		solucionesFactiblesTotales = solucionesFactiblesTotales*(i+1);
        }
    }
}

void Asignacion::AsignarElementoAlLaborGreedy(){
    for (int i = 0; i < numAsignaciones ; i++){
        int valorMejorLabor  = 0;
        int mejorLabor = 0;

        for (int j = 0; j < numAsignaciones; j++){
            if (valores[i][j] > valorMejorLabor && laborAsignado[j] == false){
                valorMejorLabor = valores[i][j];
                mejorLabor= j;
            }
        }
        mejorValorDefinitivo += valorMejorLabor;
        asignacionesDefinitivas[i] = mejorLabor;
        laborAsignado[mejorLabor] = true;
    }

}

void Asignacion::AsignarElementoAlLaborExhaustivo(int labor){
    for (int elemento = 0; elemento < numAsignaciones ; elemento++){
        if (asignacionesTentativas[elemento] == -1){

            asignacionesTentativas[elemento] = labor;
            mejorValorTentativo += valores [elemento][labor];
            if(labor == numAsignaciones-1){
                solucionesFactiblesObtenidas++;
                if(mejorValorTentativo > mejorValorDefinitivo){
                    mejorValorDefinitivo = mejorValorTentativo;
                    for (int i = 0; i < numAsignaciones ; i++){
                        asignacionesDefinitivas[i] =asignacionesTentativas[i];
                    }
                }
            }
            else{
                AsignarElementoAlLaborExhaustivo(labor+1);
            }
            mejorValorTentativo -= valores[elemento][labor];
            asignacionesTentativas[elemento] = -1;
        }
    }
}

void Asignacion::AsignarElementoAlLaborLocal(){
    int numCambios;
    numCambios = numAsignaciones/4;
    int cambios[numCambios];
    for (int i = 0; i < numCambios; i++){
        cambios[i] = (i+2)*2;
    }

    for (int i = 0; i < numAsignaciones ; i++){
        int valorMejorLabor  = 0;
        int mejorLabor = 0;

        for (int j = 0; j < numAsignaciones; j++){
            if (valores[i][j] > valorMejorLabor && laborAsignado[j] == false){
                valorMejorLabor = valores[i][j];
                mejorLabor= j;
            }
        }
        mejorValorDefinitivo += valorMejorLabor;
        asignacionesDefinitivas[i] = mejorLabor;
        laborAsignado[mejorLabor] = true;
    }
    for (int i = 0; i < numCambios; i++ )
    {
        mejorValorTentativo = mejorValorDefinitivo;
        int aleatorio = rand() % numAsignaciones;
        mejorValorTentativo += valores[aleatorio][cambios[i]];
        mejorValorTentativo -= valores[aleatorio][asignacionesDefinitivas[aleatorio]];
        mejorValorTentativo += valores[cambios[i]][aleatorio];
        mejorValorTentativo -= valores[cambios[i]][asignacionesDefinitivas[cambios[i]]];
        if (mejorValorTentativo > mejorValorDefinitivo){
            asignacionesDefinitivas[aleatorio] = cambios[i];
            asignacionesDefinitivas[cambios[i]] = aleatorio;
        }
    }

}

void Asignacion::AsignarElementoAlLaborAcotamiento(int labor){
    int cotas[numAsignaciones];
    int elementosUtilizados = 0;

    int elementos[numAsignaciones];
    int numCotas = 0;

    for (int elemento = 0; elemento < numAsignaciones ; elemento++){
        elementos[elemento] = -1;
        if (asignacionesTentativas[elemento] == -1){
            numCotas++;
            cotas[elemento] = 0;
            cotas[elemento] += mejorValorTentativo;
            for (int j = labor +1; j < numAsignaciones; j++){
                int valorMejorLabor  = 0;
                for (int i = 0; i < numAsignaciones; i++){
                    if (valores[i][j] > valorMejorLabor){
                            valorMejorLabor = valores[i][j];
                    }
                }
                cotas[elemento] +=valorMejorLabor;
            }
            cotas[elemento] += valores[elemento][labor];
            int cotaAuxiliar = cotas[elemento];
            elementos[elementosUtilizados] = elemento;
            cotas[elementosUtilizados] = cotaAuxiliar;
            elementosUtilizados ++ ;
        }
    }


    int *elementosOrdenadosPorCota = sortCotas(cotas, elementos, numCotas);





    for (int i = 0; i < numCotas ; i++){
        int elemento = elementosOrdenadosPorCota[i];
        if (asignacionesTentativas[elemento] == -1 && (!poda || !(cotas[elemento] < mejorValorDefinitivo))){

            asignacionesTentativas[elemento] = labor;
            mejorValorTentativo += valores [elemento][labor];
            if(labor == numAsignaciones-1){
                poda = true;
                solucionesFactiblesObtenidas++;
                if(mejorValorTentativo > mejorValorDefinitivo){
                    mejorValorDefinitivo = mejorValorTentativo;
                    for (int k = 0; k < numAsignaciones ; k++){
                        asignacionesDefinitivas[k] =asignacionesTentativas[k];
                    }
                }
            }
            else{
                AsignarElementoAlLaborAcotamiento(labor+1);
            }
            mejorValorTentativo -= valores[elemento][labor];
            asignacionesTentativas[elemento] = -1;

        }
    }
}


int* Asignacion::sortCotas(int arr[], int arrAux[], int arrSize){
    for (int i = 0; i < arrSize ; i++)
    {
        int x = arr[i];
        int y = arrAux[i];
        int j = i;
        while (j > 0 and arr[j-1] < x ){
            arr[j] = arr[j-1];
            arrAux[j] = arrAux[j-1];
            j = j - 1;
        }
        arr[j] = x;
        arrAux[j] = y;
    }
    cout << arr[0] << " " << arr[1]<< endl;
    if (arrSize == 2 && arr[1] > arr[0]){
        int y = arrAux[1];
        arrAux[1] = arrAux[0];
        arrAux[0] = y;
    }

    return arrAux;
}
