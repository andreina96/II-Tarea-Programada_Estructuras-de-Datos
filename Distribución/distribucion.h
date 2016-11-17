#ifndef DISTRIBUCION_H_INCLUDED
#define DISTRIBUCION_H_INCLUDED

class Distribucion{

    public:

        Distribucion();
        virtual ~Distribucion();
        void ResolverDistribucion();
        void DarUnidadesGreedy();
        void DarUnidadesLocal(int i);
        void DarUnidadesRYA(int i);
        void DarUnidadesPura(int i);

    private:
        int minimizacion;
        int itemesTotales;
        int itemesRestantes;
        int itemes;
        int unidades;
        int unidadesDisponibles;
        int maximo;
        int minimo;
        int solucionesFactibles;
        int tablero[20][20];
        int valorActual;
        int mejorValor;
        int solucionActual[20];
        int mejorSolucion[20];

};

#endif // DISTRIBUCION_H_INCLUDED
