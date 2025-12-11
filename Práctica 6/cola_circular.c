#include <stdio.h>
#define MAX 10  

struct ColaCircular {
    int datos[MAX];
    int frente;
    int final;
    int size;
};

int isEmpty(struct ColaCircular c) {
    return c.size == 0;
}

int isFull(struct ColaCircular c) {
    return c.size == MAX;
}

void enqueue(struct ColaCircular *c, int valor) {
    if (isFull(*c)) {
        printf("Cola llena, no se puede encolar.\n");
        return;
    }
    c->datos[c->final] = valor;
    c->final = (c->final + 1) % MAX;
    c->size++;
}

int dequeue(struct ColaCircular *c) {
    if (isEmpty(*c)) {
        printf("Cola vacía, no se puede desencolar.\n");
        return -1;  // Error
    }
    int valor = c->datos[c->frente];
    c->frente = (c->frente + 1) % MAX;
    c->size--;
    return valor;
}

int peek(struct ColaCircular c) {
    if (isEmpty(c)) {
        printf("Cola vacía.\n");
        return -1;
    }
    return c.datos[c.frente];
}

void printQueue(struct ColaCircular c) {
    int i;
    if (isEmpty(c)) {
        printf("Cola vacía.\n");
        return;
    }
    printf("Estado de la cola (frente=%d, final=%d, size=%d): ", c.frente, c.final, c.size);
    for (i = 0; i < c.size; i++) {
        printf("%d ", c.datos[(c.frente + i) % MAX]);
    }
    printf("\n");
}

int main() {
    struct ColaCircular cola;
    cola.frente = 0;
    cola.final = 0;
    cola.size = 0;
    printf("Cola circular inicializada.\n\n");

    // Pruebas
    // Encolar 5, 10, 15
    enqueue(&cola, 5);
    enqueue(&cola, 10);
    enqueue(&cola, 15);
    printQueue(cola);

    // Desencolar uno
    dequeue(&cola);
    printQueue(cola);

    // Encolar 20, 25, 30
    enqueue(&cola, 20);
    enqueue(&cola, 25);
    enqueue(&cola, 30);
    printQueue(cola);

    return 0;


  
}
