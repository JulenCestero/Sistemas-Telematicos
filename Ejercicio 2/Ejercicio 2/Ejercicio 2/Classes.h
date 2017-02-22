#include "stdafx.h"

class CCanal
{
public:
  
  int puerto;
  CCanal::CCanal(int port = 0){puerto = port;}
  int read(){return puerto;};
  void write(char*, int len);
};

class CVentana
{
public:
 
  CCanal port;
  char title[20];
   CVentana::CVentana(){
    strcpy_s(title, "");
  }
   void CrearCanal(int puerto){
    CCanal aux(puerto);
    port = aux;
   };
   void Send(){
     cout << "Intro data: ";
     char aux[20];
     cin >> aux;
   };
  void Receive(){
    cout << rand()%100 << endl;
  };
};

class CFrame : public CVentana
{
public:
  int x, y, dx, dy;
  int color;
};

