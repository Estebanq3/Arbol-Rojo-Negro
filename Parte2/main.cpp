#include "ArbolRN.h"
#include<iostream>
using namespace std;
#include <string>


int main(){
   ArbolRN < int , string > arbol;
   arbol.insertar(1,"UNO");
   arbol.insertar(2,"DOS");
   arbol.insertar(3,"TRES");
   arbol.insertar(4,"CUATRO");
   arbol.insertar(5,"CINCO");
   arbol.insertar(6,"SEIS");
   arbol.insertar(7,"SIETE");
   cout << arbol;


   return 0;
}
