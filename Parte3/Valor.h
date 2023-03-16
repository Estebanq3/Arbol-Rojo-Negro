#ifndef _VALOR
#define _VALOR
#include<iostream>
using namespace std;

class Valor {
	friend ostream& operator<<(ostream &salida, Valor& value){
		return value.imprimir(salida);
	}

	public:
		virtual void operator=(Valor&) = 0;
		virtual ostream& imprimir(ostream&) = 0;
};
#endif