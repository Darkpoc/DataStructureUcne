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
  
/* Toma un arbol binario, imprime sus nodos de acuerdo al recorrido abajo-arriba*/
void imprimirPostorden(Nodo* nodo) 
{ 
    if (nodo == NULL) 
        return; 
  
    // Primero se recorre el subarbol de la izquierda 
    imprimirPostorden(nodo->izquierdo); 
  
    // luego se recorre el arbol de la derecha
    imprimirPostorden(nodo->derecho); 
  
    // Ahora el nodo que esta como base de los anteriores 
    cout << nodo->dato << " "; 
} 
  
/* Obtiene un arbol binario e imprime suss nodos enorden*/
void imprimirEnorden(Nodo* nodo) 
{ 
    if (nodo == NULL) 
        return; 
  
    /* recorre los hijos de la izquierda*/
    imprimirEnorden(nodo->izquierdo); 
  
    /* luego imprime el dato del nodo */
    cout << nodo->dato << " "; 
  
    /* por ultimo imprime el subarbol derecho */
    imprimirEnorden(nodo->derecho); 
} 
  
/* Toma un arbol binario e imprime sus nodos en Preorden*/
void imprimirPreorden(Nodo* nodo) 
{ 
    if (nodo == NULL) 
        return; 
  
    /* Primero imprime el dato que esta en el nodo */
    cout << nodo->dato << " "; 
  
    /* Luego recorre el subarbol izquierdo */
    imprimirPreorden(nodo->izquierdo);  
  
    /* por ultimo recorre el arbol derecho ;) */
    imprimirPreorden(nodo->derecho); 
}  
  

int main() 
{ 
   	Nodo *raiz = new Nodo(1); 
    raiz->izquierdo  = new Nodo(2); 
    raiz->derecho  = new Nodo(3); 
    raiz->izquierdo->izquierdo = new Nodo(4); 
    raiz->izquierdo->derecho = new Nodo(5);  
  
    cout << "\nEl recorrido en Preorden del arbol es: \n"; 
    imprimirPreorden(raiz); 
  
    cout << "\nEl recorrido Enorden del arbol es: \n"; 
    imprimirEnorden(raiz);  
  
    cout << "\nEl recorrido Postorden dle arbol es: \n"; 
    imprimirPostorden(raiz); 
  
    return 0; 
} 
