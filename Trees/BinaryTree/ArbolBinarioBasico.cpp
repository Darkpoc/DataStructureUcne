#include <bits/stdc++.h>

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
  
/* nuevoNodo() Crea un puntero del nuevo nodo y lo devuelve */
struct Nodo* nuevoNodo(int dato) 
{ 
   
 Nodo* nodo = new Nodo(dato); 
  return(nodo); 
} 
  
  
int main() 
{ 
  /*crea la raiz del arbol*/
  Nodo *raiz = nuevoNodo(1);   
  /* Despues de esta instruccion el arbol quedaria de la siguiente manera... 
  	Solo con el 1 y los hijos nulos. 
  
        1 
      /   \ 
     NULL  NULL   
  */
    
  
  raiz->izquierdo = nuevoNodo(2); 
  raiz->derecho = nuevoNodo(3); 
  /* 2 y 3 se ocnvierten en el hijo izquierdo y derecho de 1 
           1 
         /   \ 
        2      3 
     /    \    /  \ 
    NULL NULL NULL NULL 
  */
  
  
  raiz->izquierdo->izquierdo  = nuevoNodo(4); 
  /* 4 se convierte en el hijo izquierdo de 2 
           1 
       /       \ 
      2          3 
    /   \       /  \ 
   4    NULL  NULL  NULL 
  /  \ 
NULL NULL 
*/
  printf("El arbol se ha creado correctamente");
  getchar(); 
  return 0; 
}
