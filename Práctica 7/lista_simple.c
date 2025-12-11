#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

void insertarInicio(struct Nodo **cabeza, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error al asignar memoria.\n");
        return;
    }
    nuevo->dato = valor;
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

void recorrer(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

void eliminar(struct Nodo **cabeza, int valor) {
    struct Nodo *actual = *cabeza;
    struct Nodo *anterior = NULL;

    if (actual != NULL && actual->dato == valor) {
        *cabeza = actual->siguiente;
        free(actual);
        return;
    }

    while (actual != NULL && actual->dato != valor) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        printf("Valor no encontrado.\n");
        return;
    }

    anterior->siguiente = actual->siguiente;
    free(actual);
}

void liberar(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;
    struct Nodo *siguiente;

    while (actual != NULL) {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
}

int main() {
    struct Nodo *cabeza = NULL;
    int numValores, i, valor;

    printf("¿Cuántos valores desea insertar? ");
    scanf("%d", &numValores);
    for (i = 0; i < numValores; i++) {
        printf("Ingresa el valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarInicio(&cabeza, valor);
        printf("Lista después de inserción: ");
        recorrer(cabeza);
    }

    printf("\nRecorrido completo: ");
    recorrer(cabeza);

    printf("¿Qué valor desea eliminar? ");
    scanf("%d", &valor);
    eliminar(&cabeza, valor);
    printf("Lista después de eliminación: ");
    recorrer(cabeza);

    liberar(cabeza);
    printf("Memoria liberada correctamente.\n");

    return 0;
}
