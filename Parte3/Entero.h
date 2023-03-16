#ifndef _ENTERO
#define _ENTERO

#include "Valor.h"
#include<iostream>
using namespace std;

class Entero : public Valor {
  private:
    //valor que va a almacenar el numero
    int numero;

  public:
    //Constructores de Entero
    Entero(); //Por defecto
    Entero(Entero&); //Constructor por copia
    Entero(int); //Constructor con parametro int

    
    int getEntero(); //metodo get para obtener numero


    void operator=(Valor&) override; //operador de asignacion
    ostream& imprimir(ostream&) override; //metodo imprimir
};
#endif