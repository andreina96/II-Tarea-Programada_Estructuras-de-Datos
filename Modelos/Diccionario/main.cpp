#include "lista.h"

int main(){

    lista l;

    l.agregar(8);
    l.agregar(9);
    l.agregar(19);
    l.recorrer();
    cout << l.pertenece(90) << endl;
    cout << l.pertenece(120) << endl;
    cout << l.pertenece(8) << endl;
    cout << l.pertenece(9) << endl;
    cout << l.pertenece(19) << endl;
    l.eliminar(19);
    l.recorrer();

    return 0;

}
