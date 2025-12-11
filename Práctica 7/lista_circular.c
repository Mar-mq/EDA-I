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

    if (*cabeza == NULL) {
        *cabeza = nuevo;
        nuevo->siguiente = nuevo;
    } else {
        struct Nodo *ultimo = *cabeza;
        while (ultimo->siguiente != *cabeza) {
            ultimo = ultimo->siguiente;
        }
        nuevo->siguiente = *cabeza;
        ultimo->siguiente = nuevo;
        *cabeza = nuevo;
    }
}

void recorrer(struct Nodo *cabeza) {
    if (cabeza == NULL) {
        printf("Lista vacía.\n");
        return;
    }
    struct Nodo *actual = cabeza;
    do {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    } while (actual != cabeza);
    printf("(vuelve a cabeza)\n");
}

void eliminarCircular(struct Nodo **cabeza, int valor) {
    if (*cabeza == NULL) {
        printf("Lista vacía.\n");
        return;
    }

    struct Nodo *actual = *cabeza;
    struct Nodo *anterior = NULL;

    do {
        if (actual->dato == valor) {
            break;
        }
        anterior = actual;
        actual = actual->siguiente;
    } while (actual != *cabeza);

    if (actual->dato != valor) {
        printf("Valor no encontrado.\n");
        return;
    }

    if (actual->siguiente == *cabeza && anterior == NULL) {
        free(actual);
        *cabeza = NULL;
        return;
    }

    if (actual == *cabeza) {
        struct Nodo *ultimo = *cabeza;
        while (ultimo->siguiente != *cabeza) {
            ultimo = ultimo->siguiente;
        }
        ultimo->siguiente = actual->siguiente;
        *cabeza = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }
    free(actual);
}

void liberar(struct Nodo *cabeza) {
    if (cabeza == NULL) return;

    struct Nodo *actual = cabeza;
    struct Nodo *siguiente;
    do {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    } while (actual != cabeza);
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
    eliminarCircular(&cabeza, valor);
    printf("Lista después de eliminación: ");
    recorrer(cabeza);

    liberar(cabeza);
    printf("Memoria liberada correctamente.\n");

    return 0;
}
