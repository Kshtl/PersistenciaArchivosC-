#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <vector>
using namespace std;

string validarEntradas(string mensaje);

double validarNota(string mensaje) {
    double nota;

    while (true) {
        cout << mensaje;
        cin >> nota;

        if (cin.fail() || nota < 0 || nota > 10) {
            cin.clear();
            cin.ignore(1000, '\n');
        } else {
            break;
        }
    }

    return nota;
}

double calcularPromedio() {
    int numeroNotas;

    while (true) {
        cout << "Ingresa el numero de notas: ";
        cin >> numeroNotas;

        if (cin.fail() || numeroNotas <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
        } else {
            break;
        }
    }

    vector<double> notas(numeroNotas);
    double promedio = 0;

    for (int i = 0; i < numeroNotas; i++) {
        notas[i] = validarNota("Ingresa la nota: ");
        promedio += notas[i];
    }

    return promedio / numeroNotas;
}

class Alumno {
private:
    string nombre;
    int fNacimiento;
    string carrera;
    double promedio;

public:
    void setNombre(string mensaje) {
        nombre = validarEntradas(mensaje);
    }

    void setFnacimiento(int f) {
        if (f < 1900 || f > 2026) {
            throw invalid_argument("Fecha invalida");
        }
        fNacimiento = f;
    }

    void setCarrera(string mensaje) {
        carrera = validarEntradas(mensaje);
    }

    void setPromedio(double p) {
        promedio = p;
    }

    string getNombre() { return nombre; }
    int getFnacimiento() { return fNacimiento; }
    string getCarrera() { return carrera; }
    double getPromedio() { return promedio; }
};

string validarEntradas(string mensaje) {
    string entrada;

    do {
        cout << mensaje << ": ";
        getline(cin >> ws, entrada);
    } while (entrada.empty());

    return entrada;
}

void imprimirMenu() {
    int opcion;

    do {
        cout << "\n--- MENU PRINCIPAL ---\n";
        cout << "1. Ingresar alumno\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (opcion) {
        case 1: {
            Alumno alumno;
            int fechaNacimiento;

            alumno.setNombre("Ingresa el nombre");
            alumno.setCarrera("Ingresa la carrera");

            while (true) {
                cout << "Ingresa la fecha: ";
                cin >> fechaNacimiento;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }

                try {
                    alumno.setFnacimiento(fechaNacimiento);
                    break;
                } catch (exception &e) {
                    cout << e.what() << endl;
                }
            }

            alumno.setPromedio(calcularPromedio());

            fstream archivo("archivo.txt", ios::app);

            if (archivo.is_open()) {
                archivo << alumno.getCarrera() << ";"
                        << alumno.getNombre() << ";"
                        << alumno.getFnacimiento() << ";"
                        << alumno.getPromedio() << "\n";
                archivo.close();
            }

            break;
        }

        case 0:
            break;

        default:
            cout << "Opcion invalida\n";
        }

    } while (opcion != 0);
}

int main() {
    imprimirMenu();
    return 0;
}