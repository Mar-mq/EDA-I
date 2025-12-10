#include <stdio.h>
int main(void) {
	int a[5] = {2, 4, 6, 8, 10};          // se declara un arreglo "a" de 5 elementos
	int *p = a;                           // p apunta a a[0]
	printf("1) a[1] = %d\n", a[1]);       // imprime: 1) a[1] = 4
	printf("2) *(a+3) = %d\n", *(a+3));   // imprime: 2) *(a+3) = 8
	printf("3) *p++ = %d\n", *p++);       // imprime: 3) *p++ = 2
	printf("4) *++p = %d\n", *++p);       // imprime: 4) *++p = 6
	printf("5) p[1] = %d\n", p[1]);       // imprime: 5) p[1] = 8
	printf("6) *(p+=2) = %d\n", *(p+=2)); // imprime: 6) *(p+=2) =10
	printf("7) p - a = %ld\n", p - a);    // imprime: 7) p - a = 4
	return 0;
}
