#ifndef CAJITA_H_INCLUDED
#define CAJITA_H_INCLUDED

class cajita{

    public:

        cajita() : siguiente(0){}
        cajita(int d) : diagonal(d), siguiente(0){}
        ~cajita(){}

        void setDiagonal(int d){
            diagonal = d;
        }

        int getDiagonal(){
            return diagonal;
        }

        void setSiguiente(cajita* s){
            siguiente = s;
        }

        cajita* getSiguiente(){
            return siguiente;
        }

    private:

        int diagonal;
        cajita* siguiente;

};

#endif // CAJITA_H_INCLUDED
