// Ejercicio 2.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Classes.h"

int _tmain(int argc, _TCHAR* argv[])
{
  srand(time(NULL));
  CVentana ventana1;
  CVentana ventana2;
  int puerto;
  cout << "Introduce un puerto: ";
  cin >> puerto;
  ventana1.CrearCanal(puerto);
  ventana1.Send();
  ventana1.Receive();
  cout << "Introduce un puerto: ";
  cin >> puerto;
  ventana2.CrearCanal(puerto);
  ventana2.Send();
  ventana2.Receive();
	return 0;
}

