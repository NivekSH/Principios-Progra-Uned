#include <iostream> //Librerias
#include <cctype>  // librerias poder diferenciar mayusculas


using namespace std; //No tener que usar std:: en todo el codigo

// Declaracion Metodos
int calculadorEdadPerro (int edad);
string etapadevida (int edad);
bool comprobacion_edad (int edad);
bool comprobacion_peso (int peso);
bool comprobacion_datos (string nombredeldueno);

//  Programa
int main()
{
    // Variables
    int menu = 0;
    int opciones;
    string nombredeldueno = "";
    string nombredelamascota = "";
    int pesodelamascota;
    string raza = "";
    int edad;
    int edadenanoshumanos;
    string etapadevidadelamascota = "";
    string respuesta;

    // Menu principal
    while (opciones != 4)
    {
        cout << "********************************** \n";
        cout << "   Menu \n";
        cout << "1. Ingresar datos del perro \n";
        cout << "2. Calculo de edad humana \n";
        cout << "3. Resultados \n";
        cout << "4. Salir del Programa \n";
        cout << "**********************************\n";
        cin >> opciones;

        // Navegacion atravez del menu
        switch (opciones)
        {
        //Primera opcion
        case 1:
        {
            cout << "**********************************\n";
            cout << "Igrese el nombre del duenno \n";
            cin >> nombredeldueno;
            cout << "Ingrese el nombre de la mascota \n";
            cin >> nombredelamascota;
            cout << "Ingrese la raza \n";
            cin >> raza;
            //Esto llama a la funcion para la verificacion del dato de peso, para que este dentro del rango, se lo contrario se repite
            do
            {
                cout << "Ingrese el peso de la mascota \n";
                cin >> pesodelamascota;
            }
            while (!comprobacion_peso(pesodelamascota));
            do
            {
                cout << "Ingrese edad de la mascota \n";
                cin >> edad;
            }
            while (!comprobacion_edad(edad));

            cout << "Datos ingresados satisfactoriamente \n";
            cout << "*********************************** \n";
            break;
        }

        //Segunda opcion
        case 2:
        {
            cout << "**********************************\n";
            cout << "Calculo de edad humana \n";
            bool respuesta_correcta = true;

            while (respuesta_correcta)
            {
                cout << "Desea realizar el calculo de la edad del perro en annos humanos? S/N \n";
                cin >> respuesta;
                for (char &c : respuesta)
                {
                    c = toupper(c);
                }
                if (respuesta =="S")
                {
                    cout << "La edad del perro en annos humanos es : " << calculadorEdadPerro (edad) << "\n";
                    respuesta_correcta = true;
                }
                else if (respuesta == "N")
                {
                    cout << "No se realizará el cálculo de edad.\n";
                    respuesta_correcta = false;
                    break;
                }

                else
                {
                    cout << "Opcion invalida, vuelva a intentarlo" << "\n";

                }
                break;

            }




            bool respuesta_salida = false;

            while (!respuesta_salida)
            {
                cout << "Desea regresar al menu principal? S/N \n";
                cin >> respuesta;
                for (char &c : respuesta)
                {
                    c = toupper(c);
                }
                if (respuesta == "S")
                {
                    respuesta_salida = true;
                    break;
                }
                else if (respuesta == "N")
                {
                    respuesta_salida = false;
                }
                else
                {
                    cout << "Opcion invalida, vuelva a intentarlo\n";
                }
            }
        }
        break;

        //Tercera opcion
        case 3:
        {
            if (comprobacion_datos(nombredeldueno))
            {


                cout << "**************Resultados***************" << "\n";
                cout << "Nombre del duenno : " << nombredeldueno << "\n";
                cout << "Nombre de la mascota : " << nombredelamascota << "\n";
                cout << "Peso de la mascota : " << pesodelamascota << "\n";
                cout << "Raza : " << raza << "\n";
                cout << "Edad : " << edad << "\n";
                cout << "Edad en annos humanos : " << calculadorEdadPerro (edad) << "\n";
                cout << "Etapa de vida de la mascota : " << etapadevida (edad) <<  "\n";
                cout <<"***************************************" "\n";


                bool respuesta_valida = false;

                while (!respuesta_valida)
                {

                    cout<< "Desea regresar al menu principal? S/N \n";
                    cin >> respuesta;

                    for (char &c : respuesta)
                    {
                        c = toupper(c);
                    }
                    if (respuesta == "S")
                    {
                        respuesta_valida = true;
                        break;
                    }
                    else if (respuesta == "N")
                    {
                        respuesta_valida = false;
                    }
                    else
                    {
                        cout << "Opcion invalida, vuelva a intentarlo" << "\n";
                    }
                }
            }
            break;
        }
        //Cuarta opcion y salida del programa.
        case 4:
        {
            "**********************************\n";
            cout << "Saliendo del programa\n";
            break;

        }

        //Evitar opciones fuera del menu. (1,2,3,4)
        default:
            cout << "Opcion invalida, vuelva a intentarlo \n";
            ;


        }
    }
}
//Metodo para calcular la edad del perro
int calculadorEdadPerro (int edad)
{
    if (edad < 1 )
    {

        return 0;
    }
    else if (edad == 1)
    {

        return 15;
    }
    else if (edad == 2)
    {

        return 15+6;
    }
    else
    {
        return 21 + (edad - 2)*4;

    }
}

//Metodo para saber en que etapa de la vida se encuentra.
string etapadevida (int edad)
{
    if (edad < 1)
    {
        return  "Etapa de cachorro";
    }
    else if (edad == 1 || edad == 2)
    {
        return  "Etapa de adolescente";
    }
    else if (edad == 3 || edad <= 7)
    {
        return  "Etapa de adulto";
    }
    else if (edad >= 8 )
    {
        return  "Etapa Senior";
    }

}

//Metodo para comprobar que la edad no este fuera del rango
bool comprobacion_edad (int edad)
{
    if (edad <= 30)
    {
        return true;
    }
    else if (edad > 30 )
    {
        cout << "Valor de edad fuera de rango \n";
        return false;

    }

}

//metodo para comprobar que el peso no este fuera del rango.
bool comprobacion_peso (int peso)
{
    if (peso <=100)
    {
        return true;
    }
    else if (peso > 100)
    {
        cout << "Valor de peso fuera de rango \n";
        return false;
    }
}

// Comprobar que se ingrese primero la informacion antes de poder desplegar los resultados.
bool comprobacion_datos (string nombredeldueno)
{
    if (nombredeldueno == "")
    {
        cout << "De ingresar primero la informacion \n";
        return false;
    }
    else
    {
        return true;
    }
}

 // Referencias
 // w3schools.com (1999) https://www.w3schools.com/cpp/cpp_operators_logical.asp
 // Quora (28 de febrero) How can I convert input to uppercase in C++? https://www.quora.com/How-can-I-convert-input-to-uppercase-in-C

