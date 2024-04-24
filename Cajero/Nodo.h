#pragma once
template<class T>
class Nodo
{
public:
	T dato;
	Nodo<T>* siguiente;

public:
	Nodo(T v, Nodo<T>* sig = NULL) {
		dato = v;
		siguiente = sig;
	}
	~Nodo();
};
