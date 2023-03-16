#ifndef _LETRA
#define _LETRA
#include "Valor.h"
#include<iostream>
using namespace std;

class Letra : public Valor {
	private:
		char letra; //valor donde almaceno el caracter

	public:
		Letra(); //constructor por defecto
		Letra(Letra&); //constructor por copia
		Letra(char); //constructor con parametro char

		char getLetra();


		void operator=(Valor&) override; //operador de asignacion, basado en la tarea3
		ostream& imprimir(ostream&) override; //imprimir de letras
};
#endif