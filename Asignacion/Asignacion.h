#ifndef ASIGNACION_H
#define ASIGNACION_H

class Asignacion
{
    public:
        Asignacion();
        virtual ~Asignacion();
        void ResolverAsignacion();
        void AsignarElementoAlLaborGreedy();
        void AsignarElementoAlLaborExhaustivo(int);   //refiriendose a que se resuelve por busqueda exhaustiva
        void AsignarElementoAlLaborAcotamiento(int);
        void AsignarElementoAlLaborLocal();
        int* sortCotas(int[], int [], int);
    protected:
    private:
        int numAsignaciones;
        int minimizacion;
        bool poda;
        int solucionesFactiblesTotales;
        int solucionesFactiblesObtenidas;
        int mejorValorTentativo;
        int mejorValorDefinitivo;
        bool laborAsignado[100];
        int asignacionesTentativas[100];
        int asignacionesDefinitivas[100];
        int valores[100][100];


};

#endif // ASIGNACION_H
