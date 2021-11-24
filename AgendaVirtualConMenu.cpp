#include <iostream> // Para utilizar cin y cout
#include <stdlib.h> // Librería para poder usar comandos del sistema y funciones de conversion de datos
#include <fstream>  // Para no tener que usar el prefijo std antes de cin y cout
#include <sys/stat.h> // Para buscar si existe el archivo
#include <unistd.h> // Buscar si existe un archivo

using namespace std;

// Este programa es un ejemplo de manejo de validación de datos y de uso de menus
// Y tambien de manejo de archivos

int main()
{
    // Declaramos constantes para manejo de valores auxiliares

    const string linea_blanco_100 = "                                                                                                    ";
    const string linea_blanco_65 = "                                                                 ";
    const int numero_intentos = 3;

    // Declaramos variables de entrada
    string opcion_str, id, password;
    int opcion, contador_intentos;
    fstream archivo;
    ifstream buscador;
 
    int total_datos = 0;
    bool bandera;

    string nombre, apellido, telefono, correo, estado, ciudad, nombre_cliente, apellido_cliente, nombre_archivo;
    int i, ciclo, mexico;
    char symbolo_int = 168;
    ofstream myfile, directorio;

    // Todo el código se va a repetir hasta que el usuario indique que quiere terminar
    //menu para elegir agregar contacto o consultar datos
    do
    {
        /* code */

        // Vamos a desplegar el menu principal, entonces primero limpiamos la pantalla
        system("cls");
        // Hacemos primera linea del marco
        cout << "          " << char(201);
        for (int i = 1; i <= 100; i++)
        {
            cout << char(205);
        }
        cout << char(187) << endl;
        // Y ahora hacemos 3 lineas hacia abajo
        for (int i = 1; i <= 3; i++)
        {
            cout << "          " << char(186) << linea_blanco_100 << char(186) << endl;
        }
        // Ponemos el letrero principal
        cout << "          " << char(186) << "                                         MENU PRINCIPAL                                             " << char(186) << endl;
        // Y ahora hacemos 3 lineas hacia abajo
        for (int i = 1; i <= 3; i++)
        {
            cout << "          " << char(186) << linea_blanco_100 << char(186) << endl;
        }
        // Ponemos las opciones
        cout << "          " << char(186) << "      01 Agregar Contacto          " << linea_blanco_65 << char(186) << endl;
        cout << "          " << char(186) << "      02 Buscar Contacto           " << linea_blanco_65 << char(186) << endl;
        cout << "          " << char(186) << "      03 Salir del programa        " << linea_blanco_65 << char(186) << endl;
        // Y ahora hacemos 5 lineas hacia abajo
        for (int i = 1; i <= 5; i++)
        {
            cout << "          " << char(186) << linea_blanco_100 << char(186) << endl;
        }
        //Ponemos la linea de abajo
        cout << "          " << char(200);
        for (int i = 1; i <= 100; i++)
        {
            cout << char(205);
        }
        cout << char(188) << endl;

        //Pedimos la opción al usuario, la capturamos como string para no tener problemas si el usurio se equivoca
        cout << "                                  Opcion ";
        cin >> opcion_str;

        // Cambiamos de string a entero
        opcion = atoi(opcion_str.c_str());

        // Y utilizamos un switch para ejecutar las diferentes opciones
        switch (opcion)
        {
        case 1:
        // agregar contacto
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
                    }while (mexico != 1 & mexico != 0);

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

                directorio << nombre + " " + apellido + "\n" + telefono;

                cout << "Se creo el arichivo " << nombre + apellido << ".txt \n";
            }
            directorio.close();
        system("pause");
        break;
        case 2:
        //buscar contacto
        cout << "Buscar Contacto\n";
        cout << symbolo_int << "Cual es el nombre del cliente?\n";
        cin >> nombre_cliente;
        cout << symbolo_int << "Cual es el apellido del cliente?\n";
        cin >> apellido_cliente;

        nombre_archivo = nombre_cliente + apellido_cliente + ".txt";

        archivo.open(nombre_archivo);
        if (archivo.good())
        {
            cout << "El archivo " << nombre_archivo << " si existe\n";
        }
        else
        {
            cout << "El archivo " << nombre_archivo << " no existe\n";
        }
        system("pause");
        break;
        case 3:
            cout << "Vamos a salir" << endl;
            system("pause");
            break;
            
        default:
            cout << "Por favor da una opcion valida (1, 2, 3 o 4)" << endl;
            system("pause");
            break;
        }
    } while (opcion != 3);

    // Y ahora vamos a vaciar la info de los arreglos al archivo
    archivo.open("datos.txt", fstream::out);
    // Se procesan todos los registros del archivo y se guardan en los arreglos
    for (int i = 0; i < total_datos; i++)
    {
        archivo << nombre[i] << endl;
        archivo << apellido[i] << endl;
        archivo << telefono[i] << endl;
        archivo << ciudad[i] << endl;
        archivo << estado[i] << endl;
    }
    // Se cierra el archivo para que se graben los cambios
    archivo.close();

    return 0;
}