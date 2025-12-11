#include <stdio.h>
#include <stdlib.h>  

int main() {
    int n, m, i;
    int *arr1; 
    int *arr2;  

    // Paso 1: Reservar memoria con malloc
    printf("¿Cuántos enteros quieres almacenar? ");
    scanf("%d", &n);
    
    arr1 = (int *)malloc(n * sizeof(int));  
    if (arr1 == NULL) {
        printf("Error al reservar memoria con malloc.\n");
        return 1;
    }
    
    printf("Valores iniciales con malloc (basura):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n\n");

    // Paso 2: Reservar memoria con calloc
    arr2 = (int *)calloc(n, sizeof(int));  
    if (arr2 == NULL) {
        printf("Error al reservar memoria con calloc.\n");
        free(arr1);  
        return 1;
    }
    
    printf("Valores iniciales con calloc (deben ser 0):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n\n");

    // Paso 3: Llenar el arreglo arr2
    printf("Ingresa %d valores para el arreglo:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }
    
    printf("Arreglo llenado:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n\n");

    // Paso 4: Redimensionar con realloc
    printf("Ingresa un nuevo tamaño m: ");
    scanf("%d", &m);
    
    arr2 = (int *)realloc(arr2, m * sizeof(int)); 
    if (arr2 == NULL) {
        printf("Error al redimensionar con realloc.\n");
        free(arr1);
        return 1;
    }
    
    if (m > n) {
        printf("Ingresa %d valores adicionales:\n", m - n);
        for (i = n; i < m; i++) {
            scanf("%d", &arr2[i]);
        }
    }
    
    printf("Arreglo después de realloc (tamaño %d):\n", m);
    for (i = 0; i < m; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n\n");

    // Paso 5: Liberar memoria
    free(arr1);
    free(arr2);
    printf("Memoria liberada correctamente.\n");

    return 0;
}
