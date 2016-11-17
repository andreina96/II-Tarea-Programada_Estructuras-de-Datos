#include <iostream>
#include "Lista de listas.h"
using namespace std;

int main(){

    CC c = CC();
    c.agregarConjunto(3);
    c.agregarConjunto(4);
    c.agregarConjunto(5);
    c.agregarElementoConjunto(4,5);
    c.agregarElementoConjunto(4,6);
    c.eliminarConjunto(4);

    return 0;

}
