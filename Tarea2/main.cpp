#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Estudiante{

public:
    string nombre;
    double promedio;

    Estudiante(string n, double p){
        nombre = n;
        promedio = p;
    }

    string getNombre(){

        return nombre;
    }

    double getPromedio(){

        return promedio;
    }
    

};


int main() {

    
    
    vector <Estudiante> estudianteVector;
    
    ifstream archivo("estudiantes.txt");
    
    string nombre;
    
    double n1, n2, n3, promedio;
    
    int total=0;
    
    double suma=0;
    
    if (!archivo.is_open()) return 1;
    
    while (archivo >> nombre >> n1 >> n2 >> n3) {
    
        promedio = (n1+n2+n3)/3.0;
        
        Estudiante estudiante(nombre,promedio);

        estudianteVector.push_back(estudiante);

    

    }
    


    double promedioClase;
    int reprobados = 0;
    int aprobados = 0;
    promedioClase = 0;


    for (int i = 0; i < estudianteVector.size(); i++)
    {
        
        cout << "Nombre: " << estudianteVector[i].getNombre() << "" << " Promedio: " << estudianteVector[i].getPromedio() << endl; 

        promedioClase = promedioClase + estudianteVector[i].getPromedio()/estudianteVector.size();

        if(estudianteVector[i].getPromedio() >= 9){
                cout << "Estado: Excelente \n";

                aprobados = aprobados + 1;
        }

        
        if(estudianteVector[i].getPromedio() >= 7 && estudianteVector[i].getPromedio() <= 9){
                cout << "Estado: Bueno \n";

                aprobados = aprobados + 1;
        }

        if(estudianteVector[i].getPromedio() < 7){
                cout << "Estado: Reprobado \n";

                reprobados = reprobados + 1;

        }

    }
        cout << "Reprobados: " << reprobados << endl;    
        cout << "Aprobados: " << aprobados << endl;
        cout << "Promedio clase: " << promedioClase << endl;

    archivo.close();
    
    return 0;

}
