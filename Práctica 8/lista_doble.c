#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

void insertarInicio(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error al asignar memoria.\n");
        return;
    }
    nuevo->dato = valor;
    nuevo->siguiente = *inicio;
    nuevo->anterior = NULL;
    if (*inicio != NULL) {
        (*inicio)->anterior = nuevo;
    }
    *inicio = nuevo;
}

void insertarFinal(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error al asignar memoria.\n");
        return;
    }
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;

    if (*inicio == NULL) {
        *inicio = nuevo;
        return;
    }

    struct Nodo *actual = *inicio;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }
    actual->siguiente = nuevo;
    nuevo->anterior = actual;
}

void recorrerAdelante(struct Nodo *inicio) {
    struct Nodo *actual = inicio;
    printf("Recorrido adelante: ");
    while (actual != NULL) {
        printf("%d <-> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

void recorrerAtras(struct Nodo *inicio) {
    if (inicio == NULL) {
        printf("Lista vacía.\n");
        return;
    }
    struct Nodo *actual = inicio;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }
    printf("Recorrido atrás: ");
    while (actual != NULL) {
        printf("%d <-> ", actual->dato);
        actual = actual->anterior;
    }
    printf("NULL\n");
}

void eliminar(struct Nodo **inicio, int valor) {
    if (*inicio == NULL) {
        printf("Lista vacía.\n");
        return;
    }

    struct Nodo *actual = *inicio;

    while (actual != NULL && actual->dato != valor) {
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        printf("Valor no encontrado.\n");
        return;
    }

    if (actual->anterior == NULL) {
        *inicio = actual->siguiente;
        if (*inicio != NULL) {
            (*inicio)->anterior = NULL;
        }
    } 
    else if (actual->siguiente == NULL) {
        actual->anterior->siguiente = NULL;
    } 
    else {
        actual->anterior->siguiente = actual->siguiente;
        actual->siguiente->anterior = actual->anterior;
    }

    free(actual);
}

void liberar(struct Nodo *inicio) {
    struct Nodo *actual = inicio;
    struct Nodo *siguiente;
    while (actual != NULL) {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
}

int main() {
    struct Nodo *inicio = NULL;
    int numValores, i, valor;

    // Paso: Inserción al inicio
    printf("¿Cuántos valores desea insertar al inicio? ");
    scanf("%d", &numValores);
    for (i = 0; i < numValores; i++) {
        printf("Ingresa el valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarInicio(&inicio, valor);
    }
    recorrerAdelante(inicio);

    printf("¿Cuántos valores desea insertar al final? ");
    scanf("%d", &numValores);
    for (i = 0; i < numValores; i++) {
        printf("Ingresa el valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarFinal(&inicio, valor);
    }
    recorrerAdelante(inicio);

    // Paso 3: Recorridos
    recorrerAdelante(inicio);
    recorrerAtras(inicio);

    // Paso 4: Eliminación
    printf("¿Qué valor desea eliminar? ");
    scanf("%d", &valor);
    eliminar(&inicio, valor);
    recorrerAdelante(inicio);

    // Paso 5: Liberación
    liberar(inicio);
    printf("Memoria liberada correctamente.\n");

    return 0;
}
