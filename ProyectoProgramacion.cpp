#include <iostream>
#include <string>
#include <fstream>

using namespace std;
// Este codigo sirve como agendador de citaas
//(28 Oct) Ya tenemos todo lo de pedir datos del usuario, guardar informacion en un archivo de texto, y ciclos con contadores
// falta agregar arreglos

int main() 
{

    string nombre, apellido, telefono, correo, estado, ciudad;
    int i, ciclo, mexico;
    char symbolo_int = 168;
    ofstream myfile, directorio;
    fstream directorio_buscar;

    //menu para elegir agregar contacto o consultar datos
    
    directorio.open("directorio.txt", fstream::app);
    cout << symbolo_int << "Cuantos contactos deseas guardar?";
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

        if (correo.find("@") == std::string::npos)
        {
            do
            {
                cout << "El correo es invalido. \n";
                cout << "correo  = ";
                cin >> correo;
                correo.find("@");
            } while (correo.find("@") == std::string::npos);
        }
        cout << "Eres de Mexico?(1 = si / 0 = no)    =";
        cin >> mexico;

        if (mexico == 0)
        {
            cout << "Solo se aceptan contactos de mexico";
            break;
        }

        if (mexico != 1 & mexico != 0)
        {
            do
            {
                cout << "Solo responda con 1 o 0\n";
                cout << "Eres de Mexico? 1 = si / 0 = no    =";
                cin >> mexico;
            } while (mexico != 1 & mexico != 0);

            if (mexico == 0)
            {
                cout << "Solo se aceptan contactos de mexico";
                break;
            }
        }

        cout << "Estado   = ";
        cin >> estado;

        cout << "Ciudad   = ";
        cin >> ciudad;

        myfile.open(nombre + apellido + ".txt");
        myfile << nombre + "\n" + apellido + "\n" + telefono + "\n" + correo + "\n" + estado + "\n" + ciudad + "\n" + "México" + "\n";
        myfile.close();

        directorio << nombre + " " + apellido + "\n";

        cout<<"Se creo el arichivo "<<nombre+apellido<<".txt";
    }
        directorio.close();
        return 0;
}