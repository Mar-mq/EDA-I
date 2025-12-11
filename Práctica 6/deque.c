#include <stdio.h>
#define MAX 10  

struct Deque {
    int datos[MAX];
    int front;
    int size;
};

int isEmpty(struct Deque d) {
    return d.size == 0;
}

int isFull(struct Deque d) {
    return d.size == MAX;
}

void insert_front(struct Deque *d, int valor) {
    if (isFull(*d)) {
        printf("Deque lleno, no se puede insertar.\n");
        return;
    }
    d->front = (d->front - 1 + MAX) % MAX;
    d->datos[d->front] = valor;
    d->size++;
}

void insert_rear(struct Deque *d, int valor) {
    if (isFull(*d)) {
        printf("Deque lleno, no se puede insertar.\n");
        return;
    }
    int rear = (d->front + d->size) % MAX;
    d->datos[rear] = valor;
    d->size++;
}

int delete_front(struct Deque *d) {
    if (isEmpty(*d)) {
        printf("Deque vacío, no se puede eliminar.\n");
        return -1;
    }
    int valor = d->datos[d->front];
    d->front = (d->front + 1) % MAX;
    d->size--;
    return valor;
}

int delete_rear(struct Deque *d) {
    if (isEmpty(*d)) {
        printf("Deque vacío, no se puede eliminar.\n");
        return -1;
    }
    int rear = (d->front + d->size - 1) % MAX;
    int valor = d->datos[rear];
    d->size--;
    return valor;
}

int peek_front(struct Deque d) {
    if (isEmpty(d)) {
        return -1;
    }
    return d.datos[d.front];
}

int peek_rear(struct Deque d) {
    if (isEmpty(d)) {
        return -1;
    }
    return d.datos[(d.front + d.size - 1) % MAX];
}

void printDeque(struct Deque d) {
    int i;
    if (isEmpty(d)) {
        printf("Deque vacío.\n");
        return;
    }
    int rear = (d.front + d.size - 1) % MAX;
    printf("Estado del deque (front=%d, rear=%d, size=%d): ", d.front, rear, d.size);
    for (i = 0; i < d.size; i++) {
        printf("%d ", d.datos[(d.front + i) % MAX]);
    }
    printf("\n");
}

int main() {
    struct Deque deque;
    deque.front = 0;
    deque.size = 0;

    insert_front(&deque, 10);
    printDeque(deque);

    insert_rear(&deque, 15);
    insert_rear(&deque, 20);
    printDeque(deque);

    insert_front(&deque, 30);
    printDeque(deque);

    insert_rear(&deque, 40);
    printDeque(deque);

    delete_front(&deque);
    delete_rear(&deque);
    printDeque(deque);

    insert_front(&deque, 50);
    insert_rear(&deque, 60);
    printDeque(deque);

    return 0;
}
