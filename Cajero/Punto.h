#pragma once
#include<string> //Para hacer uso de la variable "string"
#include<sstream> //Libreria que permite la interoperación entre buffers de flujo y objetos de cadena
using namespace std;
class Punto
{
	string x;
	int y;
public:
	Punto(string x = 0, int y = 0) : x(x), y(y) {}
	string toString() {
		ostringstream ss;
		ss << " ";
		ss << x;
		ss << ": ";
		ss << y;
		ss << "";
		return (ss.str());
	}
};
