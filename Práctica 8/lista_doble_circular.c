#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

void insertarFinal(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error al asignar memoria.\n");
        return;
    }
    nuevo->dato = valor;

    if (*inicio == NULL) {
        *inicio = nuevo;
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
    } else {
        nuevo->siguiente = *inicio;
        nuevo->anterior = (*inicio)->anterior;
        (*inicio)->anterior->siguiente = nuevo;
        (*inicio)->anterior = nuevo;
    }
}

void recorrer(struct Nodo *inicio) {
    if (inicio == NULL) {
        printf("Lista vacía.\n");
        return;
    }
    struct Nodo *actual = inicio;
    printf("Recorrido circular: ");
    do {
        printf("%d <-> ", actual->dato);
        actual = actual->siguiente;
    } while (actual != inicio);
    printf("(vuelve a inicio)\n");
}

void eliminarCircular(struct Nodo **inicio, int valor) {
    if (*inicio == NULL) {
        printf("Lista vacía.\n");
        return;
    }

    struct Nodo *actual = *inicio;

    do {
        if (actual->dato == valor) {
            break;
        }
        actual = actual->siguiente;
    } while (actual != *inicio);

    if (actual->dato != valor) {
        printf("Valor no encontrado.\n");
        return;
    }

    if (actual->siguiente == *inicio && actual->anterior == *inicio) {
        free(actual);
        *inicio = NULL;
        return;
    }

    if (actual == *inicio) {
        actual->anterior->siguiente = actual->siguiente;
        actual->siguiente->anterior = actual->anterior;
        *inicio = actual->siguiente;
    } 
    else {
        actual->anterior->siguiente = actual->siguiente;
        actual->siguiente->anterior = actual->anterior;
    }

    free(actual);
}

void liberar(struct Nodo *inicio) {
    if (inicio == NULL) return;

    struct Nodo *actual = inicio;
    struct Nodo *siguiente;
    do {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    } while (actual != inicio);
}

int main() {
    struct Nodo *inicio = NULL;
    int numValores, i, valor;

    // Paso 2: Inserción al final
    printf("¿Cuántos valores desea insertar? ");
    scanf("%d", &numValores);
    for (i = 0; i < numValores; i++) {
        printf("Ingresa el valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarFinal(&inicio, valor);
        recorrer(inicio);
    }

    // Paso 3: Recorrido
    recorrer(inicio);

    // Paso 4: Eliminación
    printf("¿Qué valor desea eliminar? ");
    scanf("%d", &valor);
    eliminarCircular(&inicio, valor);
    recorrer(inicio);

    // Liberación
    liberar(inicio);
    printf("Memoria liberada correctamente.\n");

    return 0;
}
