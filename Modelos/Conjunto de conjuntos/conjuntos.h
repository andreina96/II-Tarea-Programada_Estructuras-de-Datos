#ifndef CONJUNTOS_H_INCLUDED
#define CONJUNTOS_H_INCLUDED
#include "elementos.h"

class conjunto{

private:

	int etiqueta;
	conjunto* siguiente;
	elemento* primero;

public:

	conjunto(int e);

	conjunto();

    ~conjunto();

    void setEtiqueta(int e);

	int getEtiqueta();

	void setSiguiente(conjunto* s);

	conjunto* getSiguiente();

	void setPrimero(elemento* p);

	elemento* getPrimero();

	void iniciar();

	void destruir();

	void vaciar();

	bool vacio();

	void agregar(int elem);

	void eliminar(int elem);

	bool pertenece(int elem);

};


#endif // CONJUNTOS_H_INCLUDED
