#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include <unordered_map>

using namespace std;

string obtenerIP(string ip)
{
  ip = ip.substr(15, 25);
  int busq = ip.find(" ");
  if (busq == 0)
  {
    ip = ip.substr(1, 25);
  }
  busq = ip.find(":");
  ip = ip.substr(0, busq);
  return ip;
}

int main()
{
  string bitacora = "bitacora-5_2.txt";
  unordered_map<string, string> Datos;
  unordered_map<string, int> Repeticiones;

  ifstream logFile(bitacora);

  if (logFile.fail())
  {
    cout << "Archivo inexistente" << endl;
  }
  else
  {
    string dato, ip, anterior, linea;
    int repeticiones = 0;
    bool primeraVez = true;
    while (getline(logFile, dato))
    {
      ip = obtenerIP(dato);
      if (primeraVez == false)
      {
        anterior = Datos[ip];
        repeticiones = Repeticiones[ip];
        repeticiones++;
        linea = anterior + dato + "\n";
        Datos[ip] = linea;
        Repeticiones[ip] = repeticiones;
      }
      else
      {
        primeraVez = false;
        repeticiones++;
        Datos[ip] = dato + "\n";
        Repeticiones[ip] = repeticiones;
      }
    }
    logFile.close();

    cout << "-----------Ingrese la direccion IP (sin puertos)-----------" << endl;
    cin >> ip;

    cout << "-----------Resumen-----------" << endl
         << Datos[ip] << endl;
    cout << "-----------Repeticiones-----------" << endl
         << Repeticiones[ip] << endl;
  }

  
  return 0;
}