#include <stdio.h>
#define MAX 5  


struct Pila {
    int arreglo[MAX];
    int tope;
};

struct Cola {
    int arreglo[MAX];
    int frente;
    int final;
};

void push(struct Pila *p, int valor) {
    if (p->tope == MAX - 1) {
        printf("Pila llena, no se puede insertar.\n");
        return;
    }
    p->tope++;
    p->arreglo[p->tope] = valor;
}

int pop(struct Pila *p) {
    if (p->tope == -1) {
        printf("Pila vacía, no se puede extraer.\n");
        return -1;  
    }
    int valor = p->arreglo[p->tope];
    p->tope--;
    return valor;
}

void mostrarPila(struct Pila p) {
    int i;
    if (p.tope == -1) {
        printf("Pila vacía.\n");
        return;
    }
    printf("Estado de la pila (de abajo a arriba): ");
    for (i = 0; i <= p.tope; i++) {
        printf("%d ", p.arreglo[i]);
    }
    printf("\n");
}

void enqueue(struct Cola *c, int valor) {
    if (c->final == MAX - 1) {
        printf("Cola llena, no se puede insertar.\n");
        return;
    }
    c->final++;
    c->arreglo[c->final] = valor;
}

int dequeue(struct Cola *c) {
    if (c->final < c->frente) {
        printf("Cola vacía, no se puede extraer.\n");
        return -1;  
    }
    int valor = c->arreglo[c->frente];
    c->frente++;
    return valor;
}

void mostrarCola(struct Cola c) {
    int i;
    if (c.final < c.frente) {
        printf("Cola vacía.\n");
        return;
    }
    printf("Estado de la cola (de frente a final): ");
    for (i = c.frente; i <= c.final; i++) {
        printf("%d ", c.arreglo[i]);
    }
    printf("\n");
}

int main() {
    struct Pila pila;
    struct Cola cola;
    int numElementos, i, valor;

    pila.tope = -1;
    printf("Pila inicializada vacía.\n\n");

    printf("¿Cuántos elementos quieres apilar (máximo 5)? ");
    scanf("%d", &numElementos);
     if (numElementos > MAX) {
        printf("No se pueden agregar más de %d elementos. \n", MAX);
        printf("Solo se tomarán en cuenta %d elementos\n", MAX);
    }  
   if (numElementos > MAX) numElementos = MAX;  
    
    for (i = 0; i < numElementos; i++) {
        printf("Ingresa el valor %d: ", i + 1);
        scanf("%d", &valor);
        push(&pila, valor);
        mostrarPila(pila);
    }
    
    printf("\n");

    printf("¿Cuántos elementos quieres desapilar? ");
    scanf("%d", &numElementos);
    for (i = 0; i < numElementos; i++) {
        valor = pop(&pila);
        if (valor != -1) {
            printf("Elemento desapilado: %d\n", valor);
            mostrarPila(pila);
        }
    }
    printf("\n");

    cola.frente = 0;
    cola.final = -1;
    printf("Cola inicializada vacía.\n\n");

    printf("¿Cuántos elementos quieres encolar (máximo 5)? ");
    scanf("%d", &numElementos);
    if (numElementos > MAX) {
        printf("No se pueden agregar más de %d elementos. \n", MAX);
        printf("Solo se tomarán en cuenta %d elementos\n", MAX);
    }  
     if (numElementos > MAX) numElementos = MAX; 
    for (i = 0; i < numElementos; i++) {
        printf("Ingresa el valor %d: ", i + 1);
        scanf("%d", &valor);
        enqueue(&cola, valor);
        mostrarCola(cola);
    }
    
    printf("\n");

    printf("¿Cuántos elementos quieres desencolar? ");
    scanf("%d", &numElementos);
    for (i = 0; i < numElementos; i++) {
        valor = dequeue(&cola);
        if (valor != -1) {
            printf("Elemento desencolado: %d\n", valor);
            mostrarCola(cola);
        }
    }
    printf("\n");

   
    return 0;
}
