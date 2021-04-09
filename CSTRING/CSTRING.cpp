//Ejemplo manejo CString
#include <iostream> //para usar cout
#include <cstring> //para las funciones de C
#include <afx.h> //para usar las MFC: CStringA
#pragma warning(disable : 4996) //deshabilita el error por unsafe
using namespace std;
int main()
{
	char cadenaOld[] = "Hola Mundo";
	cout << cadenaOld;
	CStringA micadena("Hola Mundo");
	cout << micadena;
}