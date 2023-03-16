#include "Valor.h"
#include "Letra.h"
#include<iostream>
using namespace std;

Letra::Letra(){
	letra = ' ';
}

Letra::Letra(Letra& otro){
	this->letra = otro.letra;
}

Letra::Letra(char letra){
	this->letra = letra;
}

char Letra::getLetra(){
	return letra;
}

void Letra::operator=(Valor& otro){
	Letra& temporal = dynamic_cast<Letra&>(otro);
	letra = ' ';
	if(temporal.letra != ' '){
		letra = temporal.letra;
	}
}


ostream& Letra::imprimir(ostream& salida){
	salida << letra;
	return salida;
}
