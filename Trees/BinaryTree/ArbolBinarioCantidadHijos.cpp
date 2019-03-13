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
  
int contarNodosHojas(Nodo* nodo)  
{  
    if(nodo == NULL)      
        return 0;  
    if(nodo->izquierdo == NULL && nodo->derecho == NULL)  
        return 1;         
    else
        return contarNodosHojas(nodo->izquierdo)+  
            contarNodosHojas(nodo->derecho);  
}  

  

int main() 
{ 
   	Nodo *raiz = new Nodo(1); 
    raiz->izquierdo  = new Nodo(2); 
    raiz->derecho  = new Nodo(3); 
    raiz->izquierdo->izquierdo = new Nodo(4); 
    raiz->izquierdo->derecho = new Nodo(5);  
  
    cout << "La cantidad de nodos hojas es: "
	<<contarNodosHojas(raiz) << endl;  
  
    return 0; 
} 
