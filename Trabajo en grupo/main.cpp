// Integrante:
// Fecha: 03/10/23

// Librerias y namespace
#include <iostream> // Librería para la entrada y salida
#include <iomanip> // Librería para ajustar el formato de salida
using namespace std; // namespace std para evitar escribir "std::" repetidamente

// Creación de constantes
const int N = 3;
const int M = 4;

// Prototipo de las funciones
void ternario(); // Prototipo de la función ternario
void electronica(double corriente[], double resistencia[], int N); // Prototipo de la función electronica
void identidad(int matriz[][30], int N); // Prototipo de la función identidad
void costo_proyectos(double cantidades[][4], double costos[], int N, int M); // Prototipo de la función costo_proyectos

// Inicio del programa principal
int main() {
    // Configuración general para la salida de datos
    cout << fixed << setprecision(1); // Redondear SIEMPRE a un decimal
    
    cout << "LABORATORIO GRUPAL: PROGRAMACIÓN" << endl;

    cout << endl;
    cout << ">>> Punto 1. Operador ternario <<<" << endl;
    cout << "-----------------------------------" << endl;
    cout << endl;
    // Punto 1
    ternario(); // Llamado a la función ternario
    
    cout << endl;
    cout << ">>> Punto 2. Operador electronica <<<" << endl;
    cout << "-----------------------------------" << endl;
    cout << endl;
    double corriente[3] = {1.5, 2.0, 3.0}; // en amperios
    double resistencia[3] = {10.0, 5.0, 15.0}; // en ohmios
    electronica(corriente, resistencia, N); // Llamado a la función electronica
    
    return 0;
} // Fin del programa

// Inicio de la función ternario
void ternario() {
    // Cuando se habla del operador ternario en C++, se hace referencia a la operación
    // que se utiliza para realizar una evaluación condicional y devolver un valor
    // basado en esa condición. Su sintaxis es la siguiente:
    // condición ? valor_si_verdadero : valor_si_falso;

    // Ejemplo:
    int numero = 4;
    string resultado = (numero > 5) ? "Mayor que 5" : "Menor o igual que 5";
    cout << resultado << endl;
    // En este ejemplo, si "numero" es mayor que 5, "resultado" será igual a la cadena "Mayor que 5",
    // de lo contrario, será la cadena "Menor o igual que 5".
} // Fin de la función ternario

// Inicio de la función electronica
void electronica (double corriente[], double resistencia[], int N) {
    int columna = 12;  // Ancho de las columnas
    
    // Imprimir línea superior del cuadro
    cout << setfill('-') << setw(columna * 3 + 2) << "-" << setfill(' ') << endl;
    // Imprimir encabezado con líneas de separación
    cout << "|" << setw(columna) << "Corriente" << "|" << setw(columna) << "Resistencia" << "|" << setw(columna) << "Voltios" << "|" << endl;
    // Imprimir línea de separación entre encabezado y datos
    cout << setfill('-') << setw(columna * 3 + 2) << "-" << setfill(' ') << endl;
    
    // Calcular voltios e imprimir los valores centrados
    for (int i = 0; i < N; i++) {
        double voltios = corriente[i] * resistencia[i];
        cout << "|" << setw(columna) << corriente[i] << "|" << setw(columna) << resistencia[i] << "|" << setw(columna) << voltios << "|" << endl;
    }
    
    // Imprimir línea inferior del cuadro
    cout << setfill('-') << setw(columna * 3 + 2) << "-" << setfill(' ') << endl;
    
} // Fin de la función electronica

