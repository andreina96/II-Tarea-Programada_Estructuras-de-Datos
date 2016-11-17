#include "matrizAdya.h"

grafo::grafo(){
    ultimo = -1;
    numVert = 0;
}

grafo::~grafo(){
    ultimo = -1;
    numVert = 0;
}

void grafo::iniciar(){
    ultimo = -1;
    numVert = 0;
}

void grafo::destruir(){
    ultimo = -1;
    numVert = 0;
}

void grafo::vaciar(){
    ultimo = -1;
    numVert = 0;
}

bool grafo::vacio(){
    if(ultimo == -1)
        return true;
    return false;
}

void grafo::agregarVert(int etiqueta){
    if(!(ultimo == 48)){
        ultimo++;
        numVert++;
        vertices[ultimo] = etiqueta;
        for(int i = 0; i < 48; i++){
            aristas[ultimo][i] = pesoNulo;
        }
    }
}

void grafo::eliminarVert(int vertice){
    for(int i = vertice; i < ultimo; i++){
        vertices[i] = vertices[i+1];
    }
    for(int i = vertice; i < ultimo; i++){
        for(int j = 0; j < 48; j++){
            aristas[i][j] = aristas[i+1][j];
        }
    }
    ultimo--;
    numVert--;
    for(int i = 0; i <= ultimo; i++){
        for(int j = 0; j < 48; j++){
            aristas[i][j] = aristas[i][j+1];
        }
        aristas[i][48] = -1;
    }
}

void grafo::modifEtiqueta(int vertice, int nuevaEtiqueta){
    vertices[vertice] = nuevaEtiqueta;
}

int grafo::etiqueta(int vertice){
    return vertices[vertice];
}

void grafo::agregarArista(int vertice1, int vertice2, int peso){
    aristas[vertice1][vertice2] = peso;
    aristas[vertice2][vertice1] = peso;
}

void grafo::eliminarArista(int vertice1, int vertice2){
    aristas[vertice1][vertice2] = pesoNulo;
    aristas[vertice2][vertice1] = pesoNulo;
}

void grafo::modifPeso(int vertice1, int vertice2, int nuevoPeso){
    aristas[vertice1][vertice2] = nuevoPeso;
    aristas[vertice2][vertice1] = nuevoPeso;
}

int grafo::peso(int vertice1, int vertice2){
    return aristas[vertice1][vertice2];
}

bool grafo::existeArista(int vertice1, int vertice2){
    if(!(aristas[vertice1][vertice2] == pesoNulo))
        return true;
    return false;
}

int grafo::primerVert(){
    if(!vacio())
        return vertices[0];
    return verticeNulo;
}

int grafo::sigVert(int vertice){
    if(!(vertice == 48))
        return vertices[vertice+1];
    return verticeNulo;
}

int grafo::primerVertAdya(int vertice){
    if(!(aristas[vertice][0] == -1))
        return aristas[vertice][0];
    return verticeNulo;
}

int grafo::sigVertAdya(int vertice1, int vertice2){
    if(!(vertice2 == 48))
        return aristas[vertice1][vertice2+1];
    return verticeNulo;
}
