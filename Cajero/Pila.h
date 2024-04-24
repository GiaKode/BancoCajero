#pragma once
#include"Nodo.h"

template<class T>
class Pila {
private:
	Nodo<T>* tope;
public:
	Pila() { tope = NULL; };
	void push(T v) { //Para agregar valor al nodo
		if (estaVacia()) {// por si esta vacia
			tope = new Nodo<T>(v);// agrega un valor a la cima del nodo
		}
		else {
			tope = new Nodo<T>(v, tope);//agrega un nuevo nodo con un nuevo valor
		}
	}
	T pop() {
		if (estaVacia()) {// estaVacia()==true
			return NULL; //Error, pila vacia
		}
		else {
			T elemento = (T)(tope->dato);
			tope = (Nodo<T>*)tope->siguiente;
			return elemento;
		}
	}
	bool estaVacia() {
		return (tope == NULL);
	}
};