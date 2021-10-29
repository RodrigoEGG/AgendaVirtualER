#include <iostream>
#include <string>
#include <fstream>

using namespace std;
// Este codigo sirve como agendador de citaas
//(28 Oct) Ya tenemos todo lo de pedir datos del usuario, guardar informacion en un archivo de texto, y ciclos con contadores
// falta agregar arreglos

int main() 
{

    string nombre("");
    string apellido("");
    string telefono;
    string correo("");
    string estado("");
    string ciudad("");
    string pais("");
    int i, ciclo;
    char symbolo_int = 168;
    ofstream myfile;

    cout << symbolo_int <<"Cuantos contactos deseas guardar?";
    cin >> ciclo;
    for (i = 1; i <= ciclo; i++) //i++ s con paso 1
    {
        cout << "\nIngrese los datos del contacto:\n";

        cout << "Nombre(s)   = ";
        cin >> nombre;

        cout << "Apellido = ";
        cin >> apellido;

        cout << "Telefono  = ";
        cin >> telefono;

        if (telefono.size() != 10)
        {
            do
            {
                cout << "El numero de telefono es invalido. \n";
                cout << "Telefono  = ";
                cin >> telefono;
            } while (telefono.size() != 10);
        }
        
        cout << "Correo   = ";
        cin >> correo;

        cout << "Pais     = ";
        cin >> pais;
        
        cout << "Estado   = ";
        cin >> estado;

        cout << "Ciudad   = ";
        cin >> ciudad;

    }
        myfile.open(nombre + apellido + ".txt");
        myfile << nombre + "\n" + apellido + "\n" + telefono + "\n" + correo + "\n" + estado + "\n" + ciudad + "\n" + pais + "\n";
        myfile.close();
        return 0;
}