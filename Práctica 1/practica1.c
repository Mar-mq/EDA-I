##include<stdio.h>

int main(void) {
int n;
int a[100];
int suma=0;
int resta=0;
float promedio = 0.0;
int máximo, mínimo;
int pos_min, pos_max;
int temp = 0;

printf("Ingresa una cantidad(máximo 100):");
scanf("%d", &n);

if (n <= 0 || n > 100) {
printf("Error. La cantidad debe estar entre 1 y 100.\n");
return 1;
}


printf("Ingrese %d numeros:\n", n);
for(int i=0 ; i<n ; i++) {
printf("Elemento %d:", i);
scanf("%d", &a[i]);
}

printf("\nLos elementos del array son: [");
for (int i=0 ; i<n ; i++) {
printf("%d", a[i]);
if(i < n-1){
printf(", ");
}
else{
printf("]");
}
}

resta=a[0];
máximo=a[0];
mínimo=a[0];
pos_max=0;
pos_min=0;

for (int j=0 ; j<n ; j++) {
suma += a[j];
if(j > 0) {
resta -= a[j];
}
if(a[j] > máximo) {
máximo = a[j];
pos_max = j;
}
if(a[j] < mínimo) {
mínimo = a[j];
pos_min = j;
}
}

promedio = (float)suma/n;

for(int i=0 ; i<n/2 ; i++) {
temp = a[i];
a[i] = a[n-1-i];
a[n-1-i] = temp;
}

printf("\nLos elementos del arreglo invertidos son: [");
for(int i=0 ; i<n ; i++) {
printf("%d", a[i]);
if(i < n-1) {
printf(", ");
}
else{
printf("]");
}
}

printf("\nLa suma de los %d elementos es: %d", n, suma);
printf("\nLa resta de los %d elementos es: %d", n, resta);
printf("\nEl promedio de los %d elementos es: %.2f", n, promedio);
printf("\nEl valor máximo de los %d elementos es: %d, con posición en: %d en el arreglo original", n, máximo,pos_max);
printf("\nEl valor mínimo de los %d elementos es: %d, con posición en: %d en el arreglo original", n, mínimo, pos_min);
printf("\n");
return 0;
}
