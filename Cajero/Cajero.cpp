//Librerias:
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <windows.h>
#include <list>
#include <ctime>
//Encabezados:
#include"Lista.h"
#include"Pila.h"
#include"Punto.h"
#include"File.h"
#include"ArbolBB.h"
#include"ArbolBB2.h"
#include"HashTable.h"

using namespace std;

//Estructuras:
struct clientes
{
	double edad;
	string nombre;
	double sueldo;
};
struct tarjetas
{
	int usuario;
	int pin;
	tarjetas(int buscarpin) : pin(buscarpin) {}
	tarjetas() {}
	struct clientes user;
};

//Llamadas de clases T (templates):
std::ifstream readFile;
std::ofstream writeFile;
void imprimirBB(int);
ArbolBB<int>* arbol = new ArbolBB<int>(imprimirBB);
ArbolBB2<int>* arbol2 = new ArbolBB2<int>(imprimirBB);
Lista<int>* lst = new Lista<int>();
HashTable<Persona> ht(10);

//vectores:
int numeros[20];
struct tarjetas visa[1001];

//Datos externos:
int pinuser1;
int newpinuser;
int v1;
int anio, mes, dia;
int montoRETIRO;
double retiro, saldoPersonal, agregar2, anterior, ret2, ag2;

//Datos con valores asignados:
int cantidadCuentas = 1000;
int cantidadMinCuentas = 2;
int contador = 0;

//PROTOTIPOS
void titulo(string);
void cargar(); //Cargar cuentas puestas en el codigo
bool buscar(int, bool);
void menu(); //Menu principal
void consultar(); //Consultar cuanto saldo tengo disponible

//!!!:
void crearcuenta();
void Retirosino();
void menuretiroX2();
void verificarX2(double);
void retirarX2();
void retirar();// escoger cuanta es la cantidad que deseo retirar
void verificar(double);
void menuretiro();//Al momento de retirar aparece este menu como siguiente
void agregar(); //escoge el monto que desea agregar 
void agregarsaldo(double);//Agrega el saldo seleccionado y lo guarda en mi cuenta creada
void menuagregar();//Al momento de obtener el saldo aparece un menu como siguiente
void imprimir();//Imprimir los movimientos que hice (agregar saldo o retiro)
void error();//Si coloco un numero erroneo en el Menu principal me sale este error
void error2();//Si coloco un numero erroneo en Retiro me sale este error
void error3();//Si coloco un numero erroneo en Ingresar Saldo me sale este error
void CodigoDeVerificacion();
void cambiarContrasenia();
void generadorfileM();
void generateInFileManual(int);
void login();
void loginInicio();
void loginAdmin();
void MovRetirosABdigitacion();
void MovMAgregarABdigitacion();
void loginsearchpin();
void imprimirCUENTASCREADAS();
int factorialSUMA(int);
void restriccion(int);

//!!! con clases:
string _randomStringCode(int);
Persona _generatePersona();
codigo _generatecode();
string _randomStringCodeMinis(int);


//Banco:

int main()
{

	loginInicio();



}

void login() {
	//cargar();
	system("cls");
	auto apoyo1 = []() {cout << "***************************************************" << endl; };
	auto Bienvenida = []() {cout << "               LOGIN EN EL BANCO BBVA      " << endl; };
	auto apoyo2 = []() {cout << "***************************************************" << endl; };

	int usuario, contra;
	
	system("cls");
	//cargar();
	system("color 0a");
	apoyo1();
	cout << "\n";
	Bienvenida();
	cout << "\n";
	apoyo2();
	//titulo("BIENVENIDO A SU CAJERO DE CONFIANZA JGA");
	cout << "\n";
	cout << "\nINGRESA TU USUARIO  :  ";
	cin >> usuario;
	cout << "\n \n";

	//verificar usuario | Inicio de sesion de la cuenta:
	
		if (buscar(usuario, true))
		{
			cout << "INGRESA TU PIN DE 4 DIGITOS  :  ";
			cin >> contra;
			//verificar pin 
			if (buscar(contra, false))
			{
				//VERIFICA SI COINCIDE LOS DATOS ENCONTRADOS
				if ((visa[v1].usuario == usuario) && (visa[v1].pin == contra))
				{
					menu();
				}
				else
				{
					
					system("cls");
					
					titulo("BIENVENIDO AL CAJERO AUTOMATICO");
					cout << "\n \n EL USUARIO Y EL PIN NO COINCIDEN INTENTA DE NUEVO  \n \n";

					system("pause");
					//string opcioncuenta;
					login();


				}

			}
			else
			{
				cout << "\n \n EL PIN ES INVALIDO  \n \n";

			}
		}
		else
		{
			cout << "\n \n USUARIO  INCORRECTO  \n \n";
			system("pause");
			login();

		}

	
	

	
	
	
}

void loginInicio() {
	//srand(time(0));
	//cargar();
	system("color 0a");
	cargar();
	string op;
	

	system("cls");
	titulo("MENU PRINCIPAL DEL BANCO BBVA ");
	

	while (true)
	{
		cout << "[1]  Login \n";
		cout << "[2]  Crear nueva cuenta   \n";
		cout << "[3]  Login (Solo admins)  \n";
		cout << "[4]  Olvidaste tu pin?      \n";
		cout << "\n \n ";
		cout << "Digite una opcion -> "; cin >> op;

		if (op == "1")
		{
			login();
			break;
		}
		else if (op == "2")
		{
			crearcuenta();
			break;
		}
		else if (op == "3")
		{
			loginAdmin();
			break;
		}
		else if (op == "4")
		{
			loginsearchpin();
			break;
		}
		else
		{
			cout << "\n \n NUMERO  INCORRECTO  \n \n";
			system("pause");
			loginInicio();
		}

	}
}

void loginAdmin() {
	system("cls");
	auto apoyo1 = []() {cout << "***************************************************" << endl; };
	auto Bienvenida = []() {cout << "               LOGIN (ADMIN)      " << endl; };
	auto apoyo2 = []() {cout << "***************************************************" << endl; };
	apoyo1();
	cout << "\n";
	Bienvenida();
	cout << "\n";
	apoyo2();

	int usuario, contra;
	cout << "\n";
	cout << "\nINGRESA TU USUARIO DE ADMIN :  ";
	cin >> usuario;
	cout << "\n \n";

	//verificar usuario | Inicio de sesion de la cuenta:

	if (buscar(usuario, true))
	{
		cout << "INGRESA TU PIN DE 4 DIGITOS  :  ";
		cin >> contra;
		//verificar pin 
		if (buscar(contra, false))
		{
			//VERIFICA SI COINCIDE LOS DATOS ENCONTRADOS
			if ((visa[1].usuario == usuario) && (visa[1].pin == contra))
			{
				generadorfileM();
				//system("cls");
				imprimirCUENTASCREADAS();
				Sleep(10000);
				//loginInicio();
			}
			else
			{

				system("cls");
				titulo("BIENVENIDO AL CAJERO AUTOMATICO");
				cout << "\n \n EL USUARIO Y EL PIN NO ESTAN REGRISTRADOS EN LA LISTA BLANCA  \n \n";
				system("pause");
				string opcioncuenta;
				loginInicio();
			}
		}
		else
		{
			cout << "\n \n EL PIN ES INVALIDO  \n \n";

		}
	}
	else
	{
		cout << "\n \n USUARIO  INCORRECTO  \n \n";
		system("pause");
		loginInicio();
	}
}

void loginsearchpin() {
	system("cls");
	auto apoyo1 = []() {cout << "***************************************************" << endl; };
	auto Bienvenida = []() {cout << "               BUSCADOR DE PIN      " << endl; };
	auto apoyo2 = []() {cout << "***************************************************" << endl; };
	apoyo1();
	cout << "\n";
	Bienvenida();
	cout << "\n";
	apoyo2();

	srand(time(0));
	//Persona p = _generatePersona();
	codigo c = _generatecode();
	int op;
	string op2;
	string  key = c.code;
	cout << "\n";
	cout << "Ingrese su usuario : ";
	cin >> op;
	cargar();
	if (buscar(op, true)) {
		if ((visa[v1].usuario == op))
		{
			cout << "\n";
			//p.nombre;
			cout << "Key generada -> ";
			cout << key;
			cout << "\n";
			cout << "\n";
			cout << "Ingrese key: ";
			cin >> op2;
			cout << "\n";
			if (op2 == key)
			{
				HashTable<tarjetas> ht(1);
				ht.insert(key, tarjetas(visa[v1].pin));
				ht.display([](tarjetas v) -> void { std::cout << v.pin; });
				cout << "Se le retornara a la pantalla principal despues de los 10 segundos ";
				Sleep(10000);
				loginInicio();
			}
			else {
				cout << "Key incorrecta" << endl;
				loginInicio();
			}
		}
		else
		{

			system("cls");
			titulo("BIENVENIDO AL CAJERO AUTOMATICO");
			cout << "\n \n EL USUARIO NO SE ENCUENTRA REGRISTRADO EN ESTE BANCO  \n \n";
			system("pause");
			string opcioncuenta;
			loginInicio();
		}
	}

}

void menu()
{
	//cargar();
	string op;

	system("cls");
	titulo("MENU DE OPCIONES DEL CAJERO AUTOMATICO ");


	while (true)
	{
		cout << "[1]  CONSULTAR SALDO \n";
		cout << "[2]  RETIRAR SALDO   \n";
		cout << "[3]  INGRESAR SALDO  \n";
		cout << "[4]  IMPRIMIR (voucher)      \n";
		cout << "[5]  SALIR \n";
		cout << "[6]  CAMBIAR PIN\n";
		cout << "[7]  MOVIMIENTOS CON LOS RETIROS\n";
		cout << "[8]  MOVIMIENTOS CON LAS AGREGACIONES\n";
		cout << "\n \n \n";
		cout << "Elegir una Opcion  :   ";
		cin >> op;

		if (op == "1")
		{
			consultar();
			break;
		}
		else if (op == "2")
		{
			Retirosino();
			break;
		}
		else if (op == "3")
		{
			agregar();
			break;
		}
		else if (op == "4")
		{
			imprimir();
			break;
		}
		else if (op == "5")
		{
			//generadorfileM();
			//system("cls");
			
			exit(0);

			break;
		}
		else if (op == "6")
		{
			CodigoDeVerificacion();
			break;
		}
		else if (op == "7")
		{
			if (retiro == 0)
			{
				system("cls");
				cout << "\n";
				cout << "No tienes historial aun..." << endl;
				Sleep(2000);
				menu();
			}
			else {

				MovRetirosABdigitacion();
			}

			break;
		}
		else if (op == "8") {

			if (agregar2 == 0)
			{
				system("cls");
				cout << "No tienes historial aun..." << endl;
				Sleep(2000);
				menu();
			}
			else {
				MovMAgregarABdigitacion();
			}
			break;
		}
		else
		{
			error();
			break;
		}


	}

}

//Recursividad:

int factorialSUMA(int nro) {
	if (nro == 0) return 0;
	if (nro == 1) return 1;
	else return nro + factorialSUMA(nro - 1);
}

void restriccion(int nro) {
	
	if (factorialSUMA(nro) > 153)
	{
		system("pause");
		main();
	}
	else {
		cout << "Usted es muy menor, se niega la creacion de cuentas a menores de 17 años " << endl;
		cout << "El banco se cerrara en unos segundos" << endl;
		Sleep(1000);
		exit(0);
	}
	

}


//Retiros:

void retirarX2()
{
	retiro = 0; //¿para que sirve este retiro y porque lo igual a 0?

	int op2;
	system("cls");
	auto apoyo1 = []() {cout << "***************************************************" << endl; };
	auto Bienvenida = []() {cout << "               OPCIONES DE RETIROS GRANDES      " << endl; };
	auto apoyo2 = []() {cout << "***************************************************" << endl; };
	apoyo1();
	cout << "\n";
	Bienvenida();
	cout << "\n";
	apoyo2();


	while (true)
	{
		cout << "Saldo disponible en la cuenta: " << visa[v1].user.sueldo << " Soles" << endl;
		//opciones mostradas 
		cout << "\n0 ->  Salir del Retiro \n \n";


		cout << "\n \n \n";

		cout << "Cuanto es la cantidad que desea retirar?  :  ";
		cin >> op2;
		arbol->insertar(op2);

		if (op2 != NULL)
		{
			retiro = op2;
			verificarX2(retiro);
			break;
			menu();
			break;

		}
		else
		{
			menu();
			break;

		}



		//Cantidad que se desea retirar




	}

}

void retirar()
{
	retiro = 0; //¿para que sirve este retiro y porque lo igual a 0?

	string op2;
	system("cls");
	auto apoyo1 = []() {cout << "***************************************************" << endl; };
	auto Bienvenida = []() {cout << "               OPCIONES DE RETIRO      " << endl; };
	auto apoyo2 = []() {cout << "***************************************************" << endl; };
	apoyo1();
	cout << "\n";
	Bienvenida();
	cout << "\n";
	apoyo2();

	while (true)
	{
		cout << "Saldo disponible en la cuenta: " << visa[v1].user.sueldo << " Soles" << endl;
		//opciones mostradas 
		cout << "\n1 ->  10 Soles \n \n";
		cout << "2 ->  20 Soles \n \n";
		cout << "3 ->  50 Soles \n \n";
		cout << "4 ->  100 Soles \n \n";
		cout << "5 ->  200 Soles \n \n";
		cout << "6 ->  Salir \n \n";


		cout << "\n \n \n";
		cout << "Elegir Opcion de Retiro  :  ";
		cin >> op2;

		//Cantidad que se desea retirar
		if (op2 == "1")
		{

			retiro = 10;
			arbol->insertar(retiro);
			verificar(retiro);
			break;
		}
		else if (op2 == "2")
		{
			retiro = 20;
			arbol->insertar(retiro);
			verificar(retiro);
			break;
		}
		else if (op2 == "3")
		{
			retiro = 50;
			arbol->insertar(retiro);
			verificar(retiro);
			break;
		}
		else if (op2 == "4")
		{
			retiro = 100;
			arbol->insertar(retiro);
			verificar(retiro);
			break;
		}
		else if (op2 == "5")
		{
			retiro = 200;
			arbol->insertar(retiro);
			verificar(retiro);
			break;
		}
		else if (op2 == "6")
		{
			menu();
			break;
		}
		else
		{
			error2();
			break;

		}
	}

}

void verificar(double MontoRetiradoSeleccionado)
{
	saldoPersonal = visa[v1].user.sueldo;
	anterior = saldoPersonal;

	if (saldoPersonal >= MontoRetiradoSeleccionado)
	{
		auto SaldoRetirado = [=]() { return saldoPersonal - MontoRetiradoSeleccionado; };
		saldoPersonal = SaldoRetirado();
		visa[v1].user.sueldo = saldoPersonal;
		ret2 = MontoRetiradoSeleccionado;
		system("cls");
		titulo("RETIRO DE SALDO ");
		cout << "SU SALDO DE " << MontoRetiradoSeleccionado << " SOLES FUE RETIRADO CON EXITO \n \n";
		cout << "SU NUEVO SALDO ES " << saldoPersonal << " SOLES\n \n \n";
		system("pause");
		menuretiro();

	}
	else
	{
		system("cls");
		titulo("OPCIONES DE RETIRO ");
		cout << "SALDO INSUFICIENTE PARA EL RETIRO  \n \n \n";
		system("pause");
		retirar();

	}

}

void verificarX2(double MontoRetiradoSeleccionado)
{
	saldoPersonal = visa[v1].user.sueldo;
	anterior = saldoPersonal;

	if (saldoPersonal >= MontoRetiradoSeleccionado)
	{
		auto SaldoRetirado = [=]() { return saldoPersonal - MontoRetiradoSeleccionado; };
		saldoPersonal = SaldoRetirado();
		visa[v1].user.sueldo = saldoPersonal;
		ret2 = MontoRetiradoSeleccionado;
		system("cls");
		titulo("RETIRO DE SALDO ");
		cout << "SU SALDO DE " << MontoRetiradoSeleccionado << " SOLES FUE RETIRADO CON EXITO \n \n";
		cout << "SU NUEVO SALDO ES " << saldoPersonal << " SOLES\n \n \n";
		system("pause");
		menuretiroX2();

	}
	else
	{
		system("cls");
		titulo("OPCIONES DE RETIRO ");
		cout << "SALDO INSUFICIENTE PARA EL RETIRO  \n \n \n";
		system("pause");
		retirarX2();

	}

}

void menuretiro()
{
	string op3;

	system("cls");
	auto apoyo1 = []() {cout << "***************************************************" << endl; };
	auto Bienvenida = []() {cout << "               OPCIONES DE RETIRO      " << endl; };
	auto apoyo2 = []() {cout << "***************************************************" << endl; };
	apoyo1();
	cout << "\n";
	Bienvenida();
	cout << "\n";
	apoyo2();
	cout << "1. REALIZAR OTRO RETIRO   \n \n \n";
	cout << "2. IR AL MENU   \n \n \n";
	cout << "Elegir una Opcion  :   ";
	cin >> op3;

	cout << "Saldo disponible en la cuenta: " << saldoPersonal << endl;

	if (op3 == "1")
	{
		retirar();
		contador++;
	}
	else if (op3 == "2")
	{
		menu();
	}
	else
	{
		menuretiro();
	}


}

void menuretiroX2()
{
	string op3;

	system("cls");
	auto apoyo1 = []() {cout << "***************************************************" << endl; };
	auto Bienvenida = []() {cout << "               OPCIONES DE RETIRO      " << endl; };
	auto apoyo2 = []() {cout << "***************************************************" << endl; };
	apoyo1();
	cout << "\n";
	Bienvenida();
	cout << "\n";
	apoyo2();
	cout << "1. REALIZAR OTRO RETIRO GRANDE   \n \n \n";
	cout << "2. IR AL MENU   \n \n \n";
	cout << "Elegir una Opcion  :   ";
	cin >> op3;

	cout << "Saldo disponible en la cuenta: " << saldoPersonal << endl;

	if (op3 == "1")
	{
		retirarX2();
		contador++;
	}
	else if (op3 == "2")
	{
		menu();
	}
	else
	{
		menuretiro();
	}


}

void Retirosino() {
	system("cls");
	auto apoyo1 = []() {cout << "***************************************************" << endl; };
	auto Bienvenida = []() {cout << "              RETIROS      " << endl; };
	auto apoyo2 = []() {cout << "***************************************************" << endl; };
	apoyo1();
	cout << "\n";
	Bienvenida();
	cout << "\n";
	apoyo2();
	string opSINO;
	while (true) {
		cout << "\n1. Retiros grandes" << endl;
		cout << "\n2. Retiro de un solo monto" << endl;
		cout << "\n3. Salir" << endl;
		cout << "\nElegir una Opcion  :   ";
		cin >> opSINO;

		if (opSINO == "1")
		{
			retirarX2();
			break;
		}
		else if (opSINO == "2")
		{
			retirar();
			break;
		}
		else if (opSINO == "3")
		{
			menu();
			break;
		}
	}

}

void MovRetirosABdigitacion() {
	system("cls");
	auto apoyo1 = []() {cout << "***************************************************" << endl; };
	auto Bienvenida = []() {cout << "               HISTORIAL DE RETIROS     " << endl; };
	auto apoyo2 = []() {cout << "***************************************************" << endl; };
	apoyo1();
	cout << "\n";
	Bienvenida();
	cout << "\n";
	apoyo2();
	for (int i = 1; i < contador; i++)
	{
		arbol->insertar(retiro);
		retiro = numeros[i];
	}
	cout << "Ordenar los movimientos de los retiros (EnOrden): ";
	arbol->enOrden();
	cout << " <- Soles\n";
	cout << "Preordenar los movimientos de los retiros (PreOrden): ";
	arbol->preOrden();
	cout << " <- Soles\n";
	cout << "Postordenar los movimientos de los retiros (PostOrden): ";
	arbol->postOrden();
	cout << " <- Soles\n";
	cout << "El retiros mas alto (Maximo): " << arbol->Maximo();
	cout << "\n";
	cout << "El retiro minimo (Minimo): " << arbol->Minimo();
	cout << "\n";
	system("pause");
	menu();

}

void MovRetirosABescrito() {
	auto apoyo1 = []() {cout << "***************************************************" << endl; };
	auto Bienvenida = []() {cout << "               HISTORIAL DE RETIROS      " << endl; };
	auto apoyo2 = []() {cout << "***************************************************" << endl; };
	apoyo1();
	cout << "\n";
	Bienvenida();
	cout << "\n";
	apoyo2();
	for (int i = 1; i < contador; i++)
	{
		arbol->insertar(numeros[i]);
		//retiro = numeros[i];
	}
	cout << "Ordenar los movimientos de los retiros (EnOrden): ";
	arbol->enOrden();
	cout << " <- Soles";
	cout << "\n";
	cout << "\n";
	cout << "Preordenar los movimientos de los retiros (PreOrden): ";
	arbol->preOrden();
	cout << " <- Soles";
	cout << "\n";
	cout << "\n";
	cout << "Postordenar los movimientos de los retiros (PostOrden): ";
	arbol->postOrden();
	cout << " <- Soles";
	cout << "\n";

	cout << "El retiro mas alto (Maximo): " << arbol->Maximo() << endl;
	cout << "\n";
	cout << "El retiro minimo (Minimo): " << arbol->Minimo() << endl;
	cout << "\n";
	system("pause");
	menu();

}

void Almacenamientoderetiros() {

	int i, j, mayor;
	for (int i = 1; i < contador; i++)
	{
		retiro = numeros[i];

	}


}

//Agregacion:

void agregar()
{
	agregar2 = 0;//porque agregar2 lo iguala a 0?

	string op4;

	system("cls");
	auto apoyo1 = []() {cout << "***************************************************" << endl; };
	auto Bienvenida = []() {cout << "               OPCIONES DE AGREGAR SALDO      " << endl; };
	auto apoyo2 = []() {cout << "***************************************************" << endl; };
	apoyo1();
	cout << "\n";
	Bienvenida();
	cout << "\n";
	apoyo2();

	while (true)
	{
		cout << "Saldo disponible en la cuenta: " << visa[v1].user.sueldo << " Soles" << endl;

		cout << "\n1 ->  10 Soles \n \n";
		cout << "2 ->  20 Soles \n \n";
		cout << "3 ->  50 Soles \n \n";
		cout << "4 ->  100 Soles \n \n";
		cout << "5 ->  200 Soles \n \n";
		cout << "6 ->  Salir \n \n";


		cout << "\n \n \n";
		cout << "Elegir Opcio de Retiro  :  ";
		cin >> op4;

		if (op4 == "1")
		{
			agregar2 = 10;
			arbol2->insertar(agregar2);
			agregarsaldo(agregar2);
			break;
		}
		else if (op4 == "2")
		{
			agregar2 = 20;
			arbol2->insertar(agregar2);
			agregarsaldo(agregar2);
			break;
		}
		else if (op4 == "3")
		{
			agregar2 = 50;
			arbol2->insertar(agregar2);
			agregarsaldo(agregar2);
			break;
		}
		else if (op4 == "4")
		{
			agregar2 = 100;
			arbol2->insertar(agregar2);
			agregarsaldo(agregar2);
			break;
		}
		else if (op4 == "5")
		{
			agregar2 = 200;
			arbol2->insertar(agregar2);
			agregarsaldo(agregar2);
			break;
		}
		else if (op4 == "6")
		{
			menu();
		}
		else
		{
			error3();
			break;

		}
	}

}

void agregarsaldo(double SaldoAgregadoSeleccionado)
{
	saldoPersonal = visa[v1].user.sueldo;
	auto saldoPlus = [=]() {return saldoPersonal + SaldoAgregadoSeleccionado; };
	saldoPersonal = saldoPlus();
	visa[v1].user.sueldo = saldoPersonal;

	ag2 = SaldoAgregadoSeleccionado;
	system("cls");
	titulo("AGREGADO DE SALDO ");
	cout << "SU SALDO DE " << SaldoAgregadoSeleccionado << " FUE AGREGADO CON EXITO \n \n";
	cout << "SU NUEVO SALDO ES " << saldoPersonal << "\n \n \n";
	system("pause");
	menuagregar();

}

void menuagregar()
{
	string op5;

	system("cls");
	titulo("OPCIONES DE AGREGAR SALDO ");
	cout << "1. REALIZAR OTRO AGREGADO DE SALDO   \n \n \n";
	cout << "2. IR AL MENU   \n \n \n";
	cout << "Elegir una Opcion  :   ";
	cin >> op5;


	if (op5 == "1")
	{
		agregar();
		contador++;
	}
	else if (op5 == "2")
	{
		menu();
	}
	else
	{
		menuagregar();
	}


}

void MovMAgregarABdigitacion() {
	system("cls");
	auto apoyo1 = []() {cout << "***************************************************" << endl; };
	auto Bienvenida = []() {cout << "              HISTORIAL DE INGRESOS      " << endl; };
	auto apoyo2 = []() {cout << "***************************************************" << endl; };
	apoyo1();
	cout << "\n";
	Bienvenida();
	cout << "\n";
	apoyo2();
	for (int i = 1; i < contador; i++)
	{
		arbol2->insertar(agregar2);
		agregar2 = numeros[i];
	}
	cout << "Ordenar los movimientos de los montos de menor a mayor (EnOrden): ";
	cout << ""; arbol2->enOrden();
	cout << " <- Soles\n";
	
	cout << "Preordenar los movimientos de las agregaciones a la cuenta (PreOrden)";
	arbol2->preOrden();
	cout << " <- Soles\n";
	cout << "Postordenar los movimientos de las agregaciones a la cuenta (PostOrden)";
	arbol2->postOrden();
	cout << " <- Soles\n";
	cout << "La agregacion mas alta que tuvo esta cuenta bancaria (Maximo): S/" << arbol2->Maximo() << endl;
	cout << "La agregacio mas minima que tuvo esta cuenta bancaria (Minimo): S/" << arbol2->Minimo() << endl;
	
	system("pause");
	menu();

}

//Impresiones: 

void  PilasColasFecha()
{
	Pila<Punto*>* pila;
	pila = new Pila<Punto*>();
	anio = 2022;
	mes = 11;
	dia = 22;
	pila->push(new Punto("Anio", anio));
	pila->push(new Punto("Mes", mes));
	pila->push(new Punto("Dia", dia));
	Punto* elem; // definir puntero "elem" para usar funcion toString

	do
	{
		elem = pila->pop();
		if (elem != NULL) // estoy llamando a pop para verificar si se tiene algun elemento
			cout << elem->toString();

	} while (elem != NULL);


}

void imprimir()
{


	system("cls");
	titulo("IMPRIMIR TRANSANCION ");

	ofstream imp("cliente.txt");

	Sleep(1000);
	cout << "USUARIO        :   " << visa[v1].usuario << "\n \n";
	Sleep(1000);
	cout << "NOMBRE         :   " << visa[v1].user.nombre << "\n \n";
	Sleep(1000);
	cout << "EDAD           :   " << visa[v1].user.edad << "\n \n";
	Sleep(1000);
	cout << "SALDO RETIRO   :   " << ret2 << "\n \n";
	Sleep(1000);
	cout << "SALDO AGREGADO :   " << ag2 << "\n \n";
	Sleep(1000);
	cout << "SALDO ACTUAL   :   " << visa[v1].user.sueldo << "\n \n";
	Sleep(1000);
	PilasColasFecha();

	imp << "USUARIO        :   " << visa[v1].usuario << "\n \n";
	imp << "NOMBRE         :   " << visa[v1].user.nombre << "\n \n";
	imp << "EDAD           :   " << visa[v1].user.edad << "\n \n";
	imp << "SALDO RETIRO   :   " << ret2 << "\n \n";
	imp << "SALDO AGREGADO :   " << ag2 << "\n \n";
	imp << "SALDO ACTUAL   :   " << visa[v1].user.sueldo << "\n \n";
	imp << "FECHA          :   " << " " << dia << " / " << mes << " / " << anio << "\n \n";


	imp.close();

	cout << "\n \n DATOS IMPRESOS CORRECTAMENTE \n \n \n";
	system("pause");
	menu();



}

void imprimirCUENTASCREADAS()
{


	system("cls");
	titulo("IMPRIMIR CUENTAS ");

	ofstream imp("CUENTAS.txt");

	for (int i = 1; i <= cantidadCuentas; i++) {

		cout << "USUARIO        :   " << visa[i].usuario << "\n \n";
		cout << "PIN            :   " << visa[i].pin << "\n \n";
		cout << "NOMBRE         :   " << visa[i].user.nombre << "\n \n";
		cout << "EDAD           :   " << visa[i].user.edad << "\n \n";
		cout << "SUELDO         :   " << visa[i].user.sueldo << "\n \n";
		cout << "----------------------------------------" << "\n \n";


		imp << "USUARIO        :   " << visa[i].usuario << "\n \n";
		imp << "PIN            :   " << visa[i].pin << "\n \n";
		imp << "NOMBRE         :   " << visa[i].user.nombre << "\n \n";
		imp << "EDAD           :   " << visa[i].user.edad << "\n \n";
		imp << "SALDO          :   " << visa[i].user.sueldo << "\n \n";
		imp << "--------------------------------------------" << "\n \n";

	}
	imp.close();


	cout << "\n \n CUENTAS IMPRESOS CORRECTAMENTE \n \n \n";
	system("pause");
	//main();
	exit(0);




}

void imprimirBB(int e) {
	cout << "| S/ " << e;
}



//Generadores:

void generateInFileManual() {
	std::ofstream arch("AccountsInTheBank.csv");

	for (int n = 1; n <= cantidadCuentas; n++)
	{
		arch << "nombres: " << visa[n].user.nombre << "," "usuario: " << visa[n].usuario << "," "pin: " << visa[n].pin << "," "edad: " << visa[n].user.edad << "," "sueldo: " << visa[n].user.sueldo << "\n";

	}
	arch.close();
}

Persona _generatePersona() {
	int toto = (1000 + rand() % (9999 - 1000 + 1));
	int pin = toto;
	int usuario = toto;
	std::string nombre = _randomStringCode(4);
	int sueldo = (10000 + rand() % (9999 - 1000 + 1));
	int edad = 20 + rand() % (80 - 20 + 1);


	return Persona{ sueldo,nombre,edad,usuario,pin };
}

codigo _generatecode() {

	std::string code = _randomStringCodeMinis(5);



	return codigo{ code };
}

std::string _randomStringCodeMinis(int length) {
	// a -> 97
	// z -> 122
	std::string result;
	for (int i = 0; i < length; ++i) {
		int randomAscii = 97 + rand() % (122 - 97 + 1);
		result.push_back(static_cast<char>(randomAscii));
	}
	return result;
}

std::string _randomStringCode(int length) {
	// A -> 65
	// Z -> 90
	std::string result;
	for (int i = 0; i < length; ++i) {
		int randomAscii = 65 + rand() % (90 - 65 + 1);
		result.push_back(static_cast<char>(randomAscii));
	}
	return result;
}

void  generadorfileM() {

	generateInFileManual();
}

//Cuenta:

void cargar()
{
	//Persona p;

	//pinuser1 = newpinuser;
	//int auxnum = 0;
	visa[1].usuario = 1111;
	visa[1].pin = 1111;
	visa[1].user.nombre = "Giakomo";
	visa[1].user.sueldo = 10000;
	visa[1].user.edad = 18;

	visa[2].usuario = lst->obtenerPos(0);
	visa[2].pin = lst->obtenerPos(1);
	visa[2].user.sueldo = lst->obtenerPos(2);
	visa[2].user.edad = lst->obtenerPos(3);

	//Persona p = _generatePersona();
	for (int i = 3; i <= cantidadCuentas; i++) {

		//arch << "nombres: " << p.nombre << "," "pin: " << p.pin << "," "usuario: " << p.usuario << "," "edad: " << p.edad << "," "sueldo: " << p.sueldo << "\n";
		Persona p = _generatePersona();
		visa[i].usuario = p.usuario;
		visa[i].pin = p.pin;
		visa[i].user.nombre = p.nombre;
		visa[i].user.sueldo = p.sueldo;
		visa[i].user.edad = p.edad;
	}


	//generadorfileR();
}

bool buscar(int bs, bool up)
{


	int i = 0;


	if (up == true)
	{
		for (i = 1; i <= cantidadCuentas; i++)
		{
			if (visa[i].usuario == bs)
			{
				v1 = i;
				return true;
			}





		}
	}
	else
	{
		for (i = 1; i <= cantidadCuentas; i++)
		{
			if (visa[i].pin == bs)
			{

				return true;
			}



		}
	}

}

void CodigoDeVerificacion()
{

	srand(time(NULL));
	system("cls");
	titulo("CAMBIO DE PIN ");
	srand(time(0)); //Realiza el cabio aleatorio
	int op1, op2, op3, op4, op5, op6, aux;
	int code1, code2, code3, code4, code5, code6;
	code1 = rand() % 10;
	code2 = rand() % 10;
	code3 = rand() % 10;
	code4 = rand() % 10;
	code5 = rand() % 10;
	code6 = rand() % 10;
	int barajas[] = { code1,code2 ,code3 ,code4,code5,code6 };
	int N = 6;
	for (int i = N - 1; i > 0; i--)
	{
		int j = (rand() % (i + 1));
		swap(barajas[j], barajas[i]);//
	}
	int x = 0;
	cout << "Codigo generado (encriptado) : ";
	while (x < N) {
		cout << barajas[x] << " - ";
		x++;
	}
	cout << "\n \n";
	cout << "\nSi desea saber el codigo encriptado (Barajeado) introduzca su user : ";
	cin >> aux;
	if (buscar(aux, true)) {

		if (visa[v1].usuario == aux)
		{
			cout << "Codigo ordenado : " << code1 << " - " << code2 << " - " << code3 << " - " << code4 << " - " << code5 << " - " << code6;
			cout << "\n \n";
			cout << "\nDigite su codigo de verificacion para validar si no es un bot" << endl;
			cout << "1 er numero -> "; cin >> op1;
			if (op1 == code1) {
				cout << "2 do numero -> "; cin >> op2;
				if (op2 == code2) {
					cout << "3 er numero -> "; cin >> op3;
					if (op3 == code3) {
						cout << "4 to numero -> "; cin >> op4;
						if (op4 == code4)
						{
							cout << "5 to numero -> "; cin >> op5;
							if (op5 == code5)
							{
								cout << "6 to numero -> "; cin >> op6;
								if (op6 == code6)
								{
									cambiarContrasenia();
								}
							}
							else
							{
								CodigoDeVerificacion();
							}
						}
						else {
							CodigoDeVerificacion();
						}
					}
					else
						CodigoDeVerificacion();
				}
				else
					CodigoDeVerificacion();
			}
			else
				CodigoDeVerificacion();
		}
		else
		{
			cout << "El user que ingreso no es correcto" << endl;
			system("pause");
			menu();
		}


	}
	else
	{
		cout << "El user que ingreso no es correcto" << endl;
		system("pause");
		menu();
	}

}

void cambiarContrasenia() {
	system("cls");
	int op;
	cout << "Digite el nuevo PIN : ";
	cin >> op;
	lst->agregaPos(op, 1);
	menu();
}

void crearcuenta() {
	system("cls");
	auto apoyo1 = []() {cout << "***************************************************" << endl; };
	auto Bienvenida = []() {cout << "               NUEVA CUENTA      " << endl; };
	auto apoyo2 = []() {cout << "***************************************************" << endl; };
	int saldonuevo;
	int auxaumento = 1;
	int opusuario, oppin;
	int contadoraux = 0;
	int edad;
	string nombreusuario;

	apoyo1();
	cout << "\n";
	Bienvenida();
	cout << "\n";
	apoyo2();

	cout << "\nColoque su nuevo ID : ";
	cin >> opusuario;
	lst->agregaPos(opusuario, contadoraux);
	contadoraux++;
	cout << "\nDigite su pin : ";
	cin >> oppin;
	lst->agregaPos(oppin, contadoraux);
	contadoraux++;
	cout << "\nDigite su nombre : ";
	cin >> nombreusuario;
	visa[2].user.nombre = nombreusuario;
	//auxaumento++;
	cout << "\nCuando saldo dispone : ";
	cin >> saldonuevo;
	lst->agregaPos(saldonuevo, contadoraux);
	contadoraux++;
	//---------
	int  resultado;
	cout << "\nEdad : ";
	cin >> edad;
	lst->agregaPos(edad, contadoraux);
	contadoraux++;
	restriccion(edad);

}

void consultar()
{
	system("cls");
	auto apoyo1 = []() {cout << "***************************************************" << endl; };
	auto Bienvenida = []() {cout << "              CONSULTA DE SALDO      " << endl; };
	auto apoyo2 = []() {cout << "***************************************************" << endl; };
	apoyo1();
	cout << "\n";
	Bienvenida();
	cout << "\n";
	apoyo2();

	cout << "-----------------------------------------------------------------------\n \n";
	cout << "  Usuario  :  " << visa[v1].usuario << "\n \n";
	cout << "  Pin      :  " << visa[v1].pin << "\n \n";
	cout << "  Nombre   :  " << visa[v1].user.nombre << "\n \n";
	cout << "  Saldo    :  " << visa[v1].user.sueldo << "\n \n";
	cout << "-----------------------------------------------------------------------\n \n";

	system("pause");
	menu();

}

//Errores anuncios:

void error3()
{
	system("cls");
	titulo("OPCIONES INVALIDAS DEL CAJERO AUTOMATICO ");
	cout << "LA OPCION DE INGRESO DE SALDO NO EXISTE \n \n ";
	system("pause");
	agregar();
}

void error2()
{
	system("cls");
	titulo("OPCIONES INVALIDAS DEL CAJERO AUTOMATICO ");
	cout << "LA OPCION DE RETIRO NO EXISTE \n \n ";
	system("pause");
	retirar();
}

void error()
{
	system("cls");
	titulo("OPCIONES INVALIDAS DEL CAJERO AUTOMATICO ");
	cout << "LA OPCION INGRESADO NO EXISTE \n \n ";
	system("pause");
	menu();
}

//Plus:
void titulo(string title)
{
	int i;
	int val;

	val = title.length();

	val = val + 20;


	for (i = 0; i <= val; i++)
	{
		cout << "*";
	}

	cout << "\n \n";

	for (i = 0; i <= val; i++)
	{
		cout << " ";
		if (i == 4)
		{
			cout << title;
		}

		cout << " ";

	}

	cout << "\n";

	for (i = 0; i <= val; i++)
	{
		cout << "*";
	}

	cout << "\n \n \n";

}