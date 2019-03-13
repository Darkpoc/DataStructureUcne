#include <bits/stdc++.h> 
using namespace std; 


class Nodo 
{ 
	public:
   		int dato; 
    	struct Nodo *izquierdo; 
    	struct Nodo *derecho; 
    	Nodo(int dato) {
    		this->derecho = this->izquierdo = NULL;
    		this->dato = dato;
		}
}; 


Nodo* nuevoNodo(int dato) 
{ 
   
 Nodo* nodo = new Nodo(dato); 
  return(nodo); 
} 


/*Tomando un arbol binario de busqueda y un numero x, 
lo inserta en un nuevo nodo con el numero dentro y lo coloca
en el luar correcto del arbol.
Retorna un puntero al nuevo nodo raiz.*/
Nodo* insertar(Nodo* nodo, int dato) 
{ 
	/* 1. Si el arbol esta vacio, retornar un nodo sencillo. */
	if (nodo == NULL) 
		return(nuevoNodo(dato)); 
	else
	{ 
		/* 2.En otro caso, recorrer el arbol hacia abajo */
		if (dato <= nodo->dato) 
			nodo->izquierdo = insertar(nodo->izquierdo, dato); 
		else
			nodo->derecho = insertar(nodo->derecho, dato); 
	
		/* Retornar el puntero al nodo*/
		return nodo; 
	} 
} 

/* Toma un arbol binario no vacio, retorna el valor minimo del dato encontrado
dentro del arbol. No se necesita buscar en el arbol completo. */
int valorMinimo(Nodo* nodo) 
{ 
	Nodo* actual = nodo; 

/* recorre hacia abajo hasta encontrar el nodo hoja que este mas a la izquierda*/
while (actual->izquierdo != NULL) 
{ 
	actual = actual->izquierdo; 
} 
return(actual->dato); 
} 


int main() 
{ 
	Nodo* raiz = NULL; 
	raiz = insertar(raiz, 4); 
	insertar(raiz, 2); 
	insertar(raiz, 1); 
	insertar(raiz, 3); 
	insertar(raiz, 6); 
	insertar(raiz, 5); 
	
	cout << "\n El valor minimo del arbol binario de busqueda es: " << valorMinimo(raiz); 
	getchar(); 
	return 0; 
} 

// This code is contributed by Mukul Singh. 

