#include <iostream> // Para utilizar cout y cin
#include <algorithm> // Para utilizar la función swap
#include <omp.h> // Para utilizar la OpenMP

using namespace std;
/* Quicksort
 * Este algoritmo es una implementación paralela del algoritmo de ordenamiento
 * Quicksort.
 * Recibe como argumentos un arreglo de enteros, un índice izquierdo y un índice
 * derecho, los cuales indican el rango del arreglo a ordenar.
 * * */
void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    // Se inicializan dos variables i y j en los indices
    //izquierdo y derecho del arreglo
    int pivot = arr[(left + right) / 2];
    // Se elige el pivote como el elemento del medio del arreglo
    /* partición del arreglo
     * Se utiliza el valor del pivote para dividir el arreglo en dos
     * subarreglos, uno con valores menores y otro con valores mayores.
     * Los indices i y j indican la posición del primer elemento del subarreglo
     * izquierdo y derecho respectivamente.
     * */
    while (i <= j) {
        while (arr[i] < pivot)
            // Mientras el elemento en la posición i sea menor al
            // pivote, se decrementa j
            i++;
        while (arr[j] > pivot)
            // Mientras el elemento en la posición j sea mayor al pivote, se
            // decrementa j
            j--;
        if (i <= j) {
            // Si i es menor o igual a j, se intercambian los valores en las
            // posiciones i y j
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    };

    /* recursion
     * Se utiliza la directiva "parallel sections" de OpenMP para ejecutar las
     * llamadas recursivas a la funcion quickSort de manera paralela en dos
     * secciones diferentes.
     * Una para el subarreglo izquierdo y otra para el subarreglo derecho.
     * pragma omp es utilizado para paralelizar el código
     * */
    #pragma omp parallel sections 
    // Indica al compilador que se deben ejecutar
    // las siguientes secciones de código en paralelo
    {
        #pragma omp section
        // Esta directiva indica al compilador que la siguiente sección de código debe ser 
        // ejecutada en un hilo diferente
        if (left < j) 
        // Si el indice izquierdo es menor a j, se llama a la funcion quickSort para ordenar 
        // el subarreglo izquierdo
            quickSort(arr, left, j);
        #pragma omp section 
        // esta directiva indica al compilador que la siguiente sección de código debe ser 
        // ejecutada en un hilo diferente
        if (i < right) // Si i es menor al indice derecho, se llama a la función quickSort para 
        //ordenar el subarreglo derecho
            quickSort(arr, i, right);
    }
}

int main() {
    int arr[] = {3, 6, 1, 8, 4, 5, 9, 2, 7}; //Arreglo de prueba
    int n = sizeof(arr) / sizeof(arr[0]); // Tamaño del arreglo

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

