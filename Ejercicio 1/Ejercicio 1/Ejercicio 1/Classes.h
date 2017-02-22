#include <iostream>
using namespace std;

class Rect
{
public:
  int x1; int x2; int y1; int y2;
  Rect::Rect(int X1 = 0, int X2 = 0, int Y1 = 0, int Y2 = 0){
    x1 = X1; x2 = X2; y1 = Y1; y2 = Y2;
  };
  void prt(){
    cout << "x1: " << x1 << ", x2: " << x2 << ", y1: " << y1 << ", y2: " << y2 << endl;
  };

  void putData(){
    cout << "Introduce data [x1, x2, y1, y2]: ";
    cin >> x1 >> x2 >> y1 >> y2;
  };
};

class Control
{
public:
  Rect r1;
  char titulo[20];
  Control::Control(int X1 = 0, int X2 = 0, int Y1 = 0, int Y2 = 0, char title[20] = ""){
    r1 = Rect(X1, X2, Y1, Y2);
    strcpy_s(titulo, title);
  };
  void prt(){
    r1.prt();
    cout << "Titulo: " << titulo << endl;
  };
  void putData(){
    r1.putData();
    cout << "Introduce a title (20 characters max): ";
    cin >> titulo;
  };
};

class Boton : public Control
{
public:
  bool presionado;
  int color;
  Boton::Boton(int X1 = 0, int X2 = 0, int Y1 = 0, int Y2 = 0, char title[20] = "", bool press = false, int colour = 0){
    r1 = Rect(X1, X2, Y1, Y2);
    strcpy_s(titulo, title);
    presionado = press;
    color = colour;
  };
  void prt(){
    r1.prt();
    cout << "Titulo: " <<  titulo << endl;
    cout << "Color: "  << color << endl;
    cout << "Presionado? " << presionado << endl;
  };
  void putData(){
    r1.putData();
    cout << "Introduce a title (20 characters max): ";
    cin >> titulo;
    cout << "Introduce a color: ";
    cin >> color;
    cout << "Esta presionado el boton? Y/N ";
    while(true){
      char tmp;
      cin >> tmp;
      if (tmp == 'Y' || tmp == 'y' || tmp == '1'){
        presionado = true;
        break;
      }
      else if (tmp == 'N' || tmp == 'n' || tmp == '0'){
        presionado = false;
        break;
      }
      else{
        cout << "ERROR: Character not found. Try again." << endl;
      }
    }
  };
};

class Ventana : public Control
{
public:
  bool marco;
  int colMarco;
  int colFondo;
  Ventana::Ventana(int X1 = 0, int X2 = 0, int Y1 = 0, int Y2 = 0, char title[20] = "", bool marc = false, int colourM = 0, int colourF = 0){
    r1 = Rect(X1, X2, Y1, Y2);
    strcpy_s(titulo, title);
    marco = marc;
    colMarco = colourM;
    colFondo = colourF;
  };
  void prt(){
    r1.prt();
    cout << "Titulo: " <<  titulo << endl;
    cout << "Color marco: "  << colMarco << endl;
    cout << "Color fondo: "  << colFondo << endl;
    cout << "Presionado? " << marco << endl;
  };
  void putData(){
    r1.putData();
    cout << "Introduce a title (20 characters max): ";
    cin >> titulo;
    cout << "Introduce a color for the frame: ";
    cin >> colMarco;
    cout << "Introduce a color for the background: ";
    cin >> colFondo;
    cout << "Esta presionado el marco? Y/N ";
    while(true){
      char tmp;
      cin >> tmp;
      if (tmp == 'Y' || tmp == 'y' || tmp == '1'){
        marco = true;
        break;
      }
      else if (tmp == 'N' || tmp == 'n' || tmp == '0'){
        marco = false;
        break;
      }
      else{
        cout << "ERROR: Character not found. Try again." << endl;
      }
    }
  };
};