#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "Mochila.h"
#include "Mochila.cpp"
#include "Reinas.h"
#include "Reinas.cpp"
#include "Coloreo.h"
#include "Coloreo.cpp"
#include "Asignacion.h"
#include "Asignacion.cpp"
#include "distribucion.h"
#include "distribucion.cpp"
/*#include "vendedor.h"
#include "vendedor.cpp"*/

using namespace std;

class menu{

    public:

        menu(){}
        ~menu(){}

        void resolverAlgoritmos(){

            string d;
            cout << "Que problema desea resolver (coloreo/reinas/mochila/distribucion/asignacion/vendedor)? ";
            cin >> d; cout << endl;

            bool salirse = false;
            while(!salirse){
                if(d == "coloreo"){
                    Coloreo c = Coloreo();
                    c.ResolverColoreo();
                    string s;
                    cout << "Desea salirse ya (si/cualquier otra cosa)? ";
                    cin >> s;
                    if(s == "si")
                        salirse = true;
                }
                else if(d == "reinas"){
                    Reinas r = Reinas();
                    r.ResolverReinas();
                    string s;
                    cout << "Desea salirse ya (si/cualquier otra cosa)? ";
                    cin >> s;
                    if(s == "si")
                        salirse = true;
                }
                else if(d == "mochila"){
                    Mochila m = Mochila();
                    m.ResolverMochila();
                    string s;
                    cout << "Desea salirse ya (si/cualquier otra cosa)? ";
                    cin >> s;
                    if(s == "si")
                        salirse = true;
                }
                else if(d == "distribucion"){
                    Distribucion d = Distribucion();
                    d.ResolverDistribucion();
                    string s;
                    cout << "Desea salirse ya (si/cualquier otra cosa)? ";
                    cin >> s;
                    if(s == "si")
                        salirse = true;
                }
                else if(d == "asignacion"){
                    Asignacion a = Asignacion();
                    a.ResolverAsignacion();
                    string s;
                    cout << "Desea salirse ya (si/cualquier otra cosa)? ";
                    cin >> s;
                    if(s == "si")
                        salirse = true;
                }
                else if(d == "vendedor"){
                    /*Vendedor v;
                    v.ResolverVendedor();*/
                    string s;
                    cout << "Desea salirse ya (si/cualquier otra cosa)? ";
                    cin >> s;
                    if(s == "si")
                        salirse = true;
                }
                else{
                    cout << "Digite una opcion valida!" << endl << endl;
                }
            }
        }

};

#endif // MENU_H_INCLUDED
