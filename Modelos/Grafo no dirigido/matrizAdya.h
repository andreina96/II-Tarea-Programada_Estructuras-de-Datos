#ifndef grafo_H_INCLUDED
#define grafo_H_INCLUDED

const int pesoNulo = -1;
const int verticeNulo = -1;

class grafo{

private:

    int vertices[49];
    int aristas[49][49];
    int ultimo;
    int numVert;

public:

    grafo();
    ~grafo();
    void iniciar();
    void destruir();
    void vaciar();
    bool vacio();
    void agregarVert(int etiqueta);
    void eliminarVert(int vertice);
    void modifEtiqueta(int vertice, int nuevaEtiqueta);
    int etiqueta(int vertice);
    void agregarArista(int vertice1, int vertice2, int peso);
    void eliminarArista(int vertice1, int vertice2);
    void modifPeso(int vertice1, int vertice2, int nuevoPeso);
    int peso(int vertice1, int vertice2);
    bool existeArista(int vertice1, int vertice2);
    int primerVert();
    int sigVert(int vertice);
    int primerVertAdya(int vertice);
    int sigVertAdya(int vertice1, int vertice2);

};

#endif // grafo_H_INCLUDED
