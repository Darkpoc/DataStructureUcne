/* C/C++ program para resolver el problema de las  N Reinas 
usando Backtraking */
#define N 4 
#include<stdio.h> 
#include<stdbool.h> 
  
/* Función para imprimir la solucion */
void imprimirTablero(int tablero[N][N]) 
{ 
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
            printf(" %d ", tablero[i][j]); 
        printf("\n"); 
    } 
} 
  
/* 
	Funcion para verificar si una REINA puede ser posicionada en la 
	ubicacion tablero[fila][columna]. Esta funcion es llamada cuando
	las reinas estan bien posicionadas en columnas del 0 a la 'columna' - 1.
	De esta manera solo necesitamos verificar las reinas atacantes del lado izquierdo.
*/
bool esPosicionSegura(int tablero[N][N], int fila, int columna) 
{ 
    int i, j; 
  
    /* Verifica el lado izquierdo de la fila actual (que no hayan atacantes allí)*/
    for (i = 0; i < columna; i++) // recorremos las columnas
        if (tablero[fila][i]) 
            return false; 
  
    /* Verifica que la diagonal superior del lado izquierdo sea segura (sin reinas atacantes) */
    for (i=fila, j=columna; i>=0 && j>=0; i--, j--) 
        if (tablero[i][j]) 
            return false; 
  
    /* Verifica que la diagonal inferior del lado izquierdo sea segura (sin reinas atacantes) */
    for (i=fila, j=columna; j>=0 && i<N; i++, j--) 
        if (tablero[i][j]) 
            return false; 
  
  	/*En caso de que la reina tenga la posibilidad de sobrevivir en esa posicion (que no hayan atacantes ni en sus lados,
	  ni en sus diagonales entonces decimos que la zona de posicionamiento es segura.)*/
    return true; 
} 
  
/* Por medio de esta función daremos solución al problema */
bool resolverNReinas(int tablero[N][N], int columna) 
{ 
    /* caso base: Si todas las reinas han sido posicionadas correctamente 
	es porque hemos encontrado una solucion y devolvemos true en señal de esto.*/
    if (columna >= N) 
        return true; 
  
    /* Se considera la columna actual como una posible solución y 
	se "intenta" posicionar en todas las FILAS de esa columna. */
    for (int i = 0; i < N; i++) 
    { 
        /* Verifica si la reina puede ser posicionada en 
		el tablero[i][columna].*/
        if ( esPosicionSegura(tablero, i, columna) ) 
        { 
            /* Si esta posicion esta libre de ataques de otras reinas, e 
            entonces la colocamos allí */
            tablero[i][columna] = 1; 
  
            /* Recursivamente damos solución a las demas reinas del tablero,
			y verificamos si todas estan en zonas libres de ataque.
			En caso contrario...  :( */
            if ( resolverNReinas(tablero, columna + 1) ) 
                return true; 
  
            /*En caso contrario, de que no haya solucion con la reina en esa posicion,
			volvemos hacia atrás (Backtraking) y probamos con otra solución atraves del 
			cilo en el que estamos.*/
            tablero[i][columna] = 0; 
        } 
    } 
  
     /* Si la reina no puede ser posicionada en ninguna fila de esta columna entonces
     se retorna false porque no hay solucion. */
    return false; 
} 
  
/* En esta funcion nos auxiliamos de las anteriores,
para dividir el trabajo y mostrar la solucion*/
bool mostrarSolucion() 
{ 
    int tablero[N][N] = { {0, 0, 0, 0}, 
        {0, 0, 0, 0}, 
        {0, 0, 0, 0}, 
        {0, 0, 0, 0} 
    }; 
  
    if ( resolverNReinas(tablero, 0) == false ) 
    { 
      printf("No existe solucion!"); 
      return false; 
    } 
  
    imprimirTablero(tablero); 
    return true; 
} 
  
 
int main() 
{ 
    mostrarSolucion(); 
    return 0; 
} 
