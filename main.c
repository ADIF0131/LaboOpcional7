// Curso IE-0117
// Estudiante: Anthonny Artavia Alpizar C10735
// Asignacion: Laboratorio Opcional

#include <stdio.h>      
#include <stdlib.h>     
#include <string.h>     

// Se define la estructura Person
typedef struct {
    char name[50];      // Almacena el nombre de las personas
    int age;            // Almacena la edad de las personas
    double height;      // Almacena la altura de las personas
} Person;

// Es la logica de comparación para ordenar las personas por nombre alfabéticamente
int compare_by_name(const void *a, const void *b) {
    Person *personA = (Person *)a;   // Es el puntero de tipo Person que analiza datos
    Person *personB = (Person *)b;   // Es el puntero de tipo Person que analiza datos
    return strcmp(personA->name, personB->name); // Compara los nombres usando strcmp
}

// Es la logica de comparación para ordenar las personas por altura de menor a mayor
int compare_by_height(const void *a, const void *b) {
    Person *personA = (Person *)a;   // Es el puntero de tipo Person que analiza datos
    Person *personB = (Person *)b;   // Es el puntero de tipo Person que analiza datos
    if (personA->height < personB->height) return -1; // Si la altura de A es menor que la de B, retorna -1
    if (personA->height > personB->height) return 1;  // Si la altura de A es mayor que la de B, retorna 1
    return 0;   // Si las alturas son iguales, retorna 0
}

// Es la logica de comparación para ordenar las personas por edad de menor a mayor
int compare_by_age(const void *a, const void *b) {
    Person *personA = (Person *)a;   // Es el puntero de tipo Person que analiza datos
    Person *personB = (Person *)b;   // Es el puntero de tipo Person que analiza datos
    return personA->age - personB->age; // Se retorna la diferencia de edades para ordenar de menor a mayor
}


// Es la función para imprimir la lista de personas
void print_persons(Person persons[], int size) {
    for (int i = 0; i < size; i++) {   // Bucle para recorrer cada persona en el arreglo de lista
        printf("Nombre: %s, Edad: %d, Altura: %.2f cm\n", persons[i].name, persons[i].age, persons[i].height); // Imprime los datos de cada persona
    }
    printf("\n");  
}

int main() {
    // Se crea un arreglo de personas con al menos 5 elementos
    Person persons[] = {
        {"Diana", 38, 164.5},      // Se registra la primera persona
        {"Anthonny", 44, 184.0},   // Se registra la segunda persona
        {"Ian", 14, 170.2},        // Se registra la tercera persona
        {"Damian", 21, 185.4},     // Se registra la cuarta persona
        {"Lexy", 22, 150.4}        // Se registra la quinta persona
    };
    int size = sizeof(persons) / sizeof(persons[0]);  // Se calcula el número de elementos en el arreglo

    // Logica para ordenar por nombre
    qsort(persons, size, sizeof(Person), compare_by_name);   // Ordena el arreglo por nombre
    printf("Ordenado por nombre:\n");  // Se imprime la lista por nombre
    print_persons(persons, size);      // Llama a la función para imprimir la lista de personas
    
    // Logica para ordenar por altura
    qsort(persons, size, sizeof(Person), compare_by_height); // Ordena el arreglo por altura
    printf("Ordenado por altura:\n");  // Se imprime la lista por altura
    print_persons(persons, size);      // Llama a la función para imprimir la lista de personas

    // Logica para ordenar por edad
    qsort(persons, size, sizeof(Person), compare_by_age);    // Ordena el arreglo por edad
    printf("Ordenado por edad:\n");   // Se imprime la lista por edad
    print_persons(persons, size);     // Llama a la función para imprimir la lista de personas


    return 0;   
}
