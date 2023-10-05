// Integrante:
// Fecha: 03/10/23

// Librerias y namespace
#include <iostream> // Librería para la entrada y salida
#include <iomanip> // Librería para ajustar el formato de salida
#include <locale> // Librería para puntos decimales
using namespace std; // namespace std para evitar escribir "std::" repetidamente

// Creación de constantes
const int N = 3;
const int M = 4;

// Prototipo de las funciones
void ternario(); // Prototipo de la función ternario
void electronica(double corriente[], double resistencia[], int N); // Prototipo de la función electronica
void identidad(int matriz[][4],int M); // Prototipo de la función identidad
void costo_proyectos(double cantidades[][4], double costos[], int N, int M); // Prototipo de la función costo_proyectos

// Inicio del programa principal
int main() {
    // Configuración general para la salida de datos
    cout << fixed << setprecision(1); // Redondear SIEMPRE a un decimal
    cout.imbue(locale("en_US.UTF-8")); // Apoyo para la impreción de los precios en dolares del punto 4
    
    cout << "LABORATORIO GRUPAL: PROGRAMACIÓN" << endl;

    cout << endl;
    cout << ">>> Punto 1. Operador ternario <<<" << endl;
    cout << "-----------------------------------" << endl;
    ternario(); // Llamado a la función ternario
    
    cout << endl;
    cout << ">>> Punto 2. Arreglo Unidimensional (Vector) <<<" << endl;
    cout << "-----------------------------------" << endl;
    double corriente[3] = {1.5, 2.0, 3.0}; // en amperios
    double resistencia[3] = {10.0, 5.0, 15.0}; // en ohmios
    electronica(corriente, resistencia, N); // Llamado a la función electronica
    
    cout << endl;
    cout << ">>> Punto 3. Arreglos Bidimensionales (matrices cuadradas) <<<" << endl;
    cout << "-----------------------------------" << endl;
    int matriz1[M][M]={{1,0,0,0},
                        {0,1,0,0},
                        {0,0,1,0},
                        {0,0,0,1}};
    identidad(matriz1, M);
    int matriz2[M][M]={{1,0,1,0},
                        {0,1,0,1},
                        {1,0,1,0},
                        {0,1,0,1}};
    identidad(matriz2, M);
    
    cout << endl;
    cout << ">>> Punto 4. Arreglos Bidimensionales (matrices N x M) <<<" << endl;
    cout << "-----------------------------------" << endl;
    double costos[M] = {120, 80, 100, 200};
    double cantidades[M][M] = {{50, 40, 60, 10},
                               {100, 80, 120, 50},
                               {150, 100, 200, 100},
                               {200, 150, 300, 80}};
    costo_proyectos(cantidades, costos, M, M);
    
    cout << endl;
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

// Inicio de la función identidad
void identidad (int matriz[][4],int M) {
    bool esIdentidad = true; // Suponemos que es una matriz identidad inicialmente
    
    for (int i = 0; i < M && esIdentidad; i++) {
        for (int j = 0; j < M && esIdentidad; j++) { // esIdentidad en los bucles para optimizar el programa al detener el bucle si ya se sabe que no es identidad (esIdentidad = false)
            // Utilizamos un operador ternario para verificar los elementos
            esIdentidad = (i == j) ? (matriz[i][j] == 1) : (matriz[i][j] == 0); // Verifica primero si estamos en al diagonal principal, en caso
                                                                                // de que sea verdad (estar en la dia. principal) se verifica si contien 1,
                                                                                // y en caso de que estar en otra posición se verifica si es cero.
                                                                                // Se arrojara un booleano en esIdentidad
        }
    }
    
    // Imprimir el resultado
    cout << ">> " << (esIdentidad ? "La matriz es identidad" : "La matriz no es identidad") << endl;
} // Fin de la función identidad

// Inicio de la función costo_proyecto
void costo_proyectos(double cantidades[][4], double costos[], int N, int M) {
    double costoTotal[N];
    cout << "Costo total de los proyectos:" << endl;
    
    cout << endl;
    for (int i = 0; i < N; i++) {
        costoTotal[i] = 0; // Varibale para el calculo de la suma que se reinicia por proyecto
        for (int j = 0; j < M; j++) {
            costoTotal[i] += cantidades[i][j] * costos[j];
        }
        cout << "Proyecto " << i + 1 << ": $" << showpoint << put_money(costoTotal[i] * 100, true) << " USD" << endl; // showpoint y put_money para los puntos de miles
    }
} // Fin de la función costo_proyecto
