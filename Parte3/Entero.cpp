#include<iostream>
using namespace std;
#include "Valor.h"
#include "Entero.h"

Entero::Entero(){
	numero = 0;
}

Entero::Entero(Entero& otro){
	this->numero = otro.numero;
}

Entero::Entero(int numero){
	this->numero = numero;
}

Entero:: getEntero(){
	return numero;
}


void Entero::operator=(Valor& otro){
	Entero& temporal = dynamic_cast<Entero&>(otro);
	numero = 0;
	if(temporal.numero != 0){
		numero = temporal.numero;
	}
}

ostream& Entero::imprimir(ostream& salida){
	salida << numero;
	return salida;
}