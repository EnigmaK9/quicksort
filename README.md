QuickSort Paralelo en C++ :rocket:
Este repositorio contiene una implementación paralela del algoritmo de ordenamiento Quicksort en C++ utilizando la biblioteca OpenMP.

Características :sparkles:
Implementación paralela del algoritmo Quicksort
Uso de la biblioteca OpenMP para paralelizar el código
Partición del arreglo utilizando el valor del pivote
Recursión en paralelo para ordenar los subarreglos
Uso :wrench:
Para utilizar este código, se requiere un compilador que soporte OpenMP, como GCC o Clang.

Copy code
g++ -fopenmp -o nombre_ejecutable nombre_archivo.cpp
En el caso de utilizar el compilador de Visual Studio se podria utilizar el siguiente comando

Copy code
cl /EHsc /openmp nombre_archivo.cpp
Contribuciones :thumbsup:
Todas las contribuciones son bienvenidas, ya sea en forma de reporte de errores, mejoras en el código o documentación. Si deseas contribuir, por favor crea una pull request.

Licencia :page_with_curl:
Este proyecto se encuentra bajo la licencia MIT. Para más detalles, revisa el archivo LICENSE.

Créditos :heart:
Este proyecto fue realizado por @enigmak9. ¡Gracias por utilizar este código! :smile: