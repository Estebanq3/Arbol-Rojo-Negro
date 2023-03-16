#include "ArbolRN.h"
#include<iostream>
using namespace std;

int main(){
   ArbolRN arbol;
   arbol.insertar(1,1);
   arbol.insertar(2,2);
   arbol.insertar(5,5);
   arbol.insertar(6,6);
   arbol.insertar(3,3);
   arbol.insertar(4,4);
   cout << arbol;

   return 0;
}
