#include "ArbolRNP.h"
#include "Valor.h"
#include "Entero.h"
#include "Letra.h"
#include<iostream>
using namespace std;
// DISEÑE E IMPLEMENTE LAS CLASES QUE CONSIDERE NECESARIAS PARA QUE EL CÓDIGO SIGUIENTE
// FUNCIONE CON SU ARBOL POLIMORFICO, NOTE QUE LA LLAVE ES UN int, PERO LOS VALORES
// PUEDEN SER INSTANCIAS DE Entero o Letra. Y VAN REVUELTAS EN EL MISMO ÁRBOL
// #include "Entero "
// #include "Letra "
// #include " Valor"

int main(){

   ArbolRNP arbol;
   Entero uno(1);
   Entero dos(2);
   Entero tres(3);
   Letra a('A');
   Letra b('B');
   Letra c('C');
   
   arbol.insertar(1, &uno);
   arbol.insertar(2, &a);
   arbol.insertar(3, &tres);
   arbol.insertar(4, &b);
   arbol.insertar(5, &dos);
   arbol.insertar(6, &c);
   
   cout << arbol;

   return 0;
}
