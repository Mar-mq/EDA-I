#include <stdio.h>
#include <string.h>

#define MAX_PELICULAS 20  
#define NUM_DIR 2        

struct pelicula {
    char nombre[40];
    char genero[40];
    int  anio;
    int  numDirectores;
    char directores[NUM_DIR][40];
};

int main(void) {
    struct pelicula videoteca[MAX_PELICULAS];
    int i, j, n;
    int opcion, subOpcion;
    int cantidadActual = 0; 
    char textoBusqueda[40];
    int anioBusqueda, encontrados;

    
    // Pelicula 0
    strcpy(videoteca[0].nombre, "Matrix");
    strcpy(videoteca[0].genero, "CienciaFiccion");
    videoteca[0].anio = 1999;
    videoteca[0].numDirectores = 2;
    strcpy(videoteca[0].directores[0], "Lana Wachowski");
    strcpy(videoteca[0].directores[1], "Lilly Wachowski");
    cantidadActual++;

    // Pelicula 1
    strcpy(videoteca[1].nombre, "Inception");
    strcpy(videoteca[1].genero, "Accion");
    videoteca[1].anio = 2010;
    videoteca[1].numDirectores = 1;
    strcpy(videoteca[1].directores[0], "Christopher Nolan");
    cantidadActual++;

    // Pelicula 2
    strcpy(videoteca[2].nombre, "Interestelar");
    strcpy(videoteca[2].genero, "Ciencia ficcion");
    videoteca[2].anio = 2014;
    videoteca[2].numDirectores = 1;
    strcpy(videoteca[2].directores[0], "Christopher Nolan");
    cantidadActual++;

    // Pelicula 3
    strcpy(videoteca[3].nombre, "La sociedad de los poetas muertos");
    strcpy(videoteca[3].genero, "Dramatico");
    videoteca[3].anio = 1989;
    videoteca[3].numDirectores = 1;
    strcpy(videoteca[3].directores[0], "Peter Weir");
    cantidadActual++;

    // Pelicula 4
    strcpy(videoteca[4].nombre, "Yo antes de ti");
    strcpy(videoteca[4].genero, "Romantico");
    videoteca[4].anio = 2016;
    videoteca[4].numDirectores = 1;
    strcpy(videoteca[4].directores[0], "Thea Sharrock");
    cantidadActual++;

    // Pelicula 5 
    strcpy(videoteca[5].nombre, "El rey leon"); 
    strcpy(videoteca[5].genero, "Animacion");
    videoteca[5].anio = 2019;
    videoteca[5].numDirectores = 1;
    strcpy(videoteca[5].directores[0], "Jon Favreau");
    cantidadActual++;

    // Pelicula 6
    strcpy(videoteca[6].nombre, "Titanic");
    strcpy(videoteca[6].genero, "Dramatico");
    videoteca[6].anio = 1997;
    videoteca[6].numDirectores = 1;
    strcpy(videoteca[6].directores[0], "James Cameron");
    cantidadActual++;

    // Pelicula 7
    strcpy(videoteca[7].nombre, "Avatar");
    strcpy(videoteca[7].genero, "Ciencia ficcion");
    videoteca[7].anio = 2009;
    videoteca[7].numDirectores = 1;
    strcpy(videoteca[7].directores[0], "James Cameron");
    cantidadActual++;

    // Pelicula 8 
    strcpy(videoteca[8].nombre, "Coco");
    strcpy(videoteca[8].genero, "Animacion");
    videoteca[8].anio = 2017;
    videoteca[8].numDirectores = 2;
    strcpy(videoteca[8].directores[0], "Adrian Molina");
    strcpy(videoteca[8].directores[1], "Lee Unkrich");
    cantidadActual++;

    // Pelicula 9
    strcpy(videoteca[9].nombre, "Pinocho");
    strcpy(videoteca[9].genero, "Animacion");
    videoteca[9].anio = 2022;
    videoteca[9].numDirectores = 2;
    strcpy(videoteca[9].directores[0], "Guillermo del Toro");
    strcpy(videoteca[9].directores[1], "Mark Gustafson");
    cantidadActual++;

    printf("***** VIDEOTECA ACTUAL (Orden Inverso) *****\n");
    for (i = cantidadActual - 1; i >= 0; i--) {
        printf("--------------------------------\n");
        printf("Pelicula: %s\n", videoteca[i].nombre);
        printf("Genero:   %s\n", videoteca[i].genero);
        printf("Año:     %d\n", videoteca[i].anio);
        printf("Directores:\n");
        for (j = 0; j < videoteca[i].numDirectores; j++) {
            printf("  - %s\n", videoteca[i].directores[j]);
        }
    }
    printf("--------------------------------\n");
    printf("Total de peliculas en la videoteca: %d\n\n", cantidadActual);


    do {
        printf("\n ¿Qué deseas hacer?\n");
        printf("1. Agregar nuevas peliculas\n");
        printf("2. Buscar peliculas \n");
        printf("3. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            int cuantasMas;
            do {
                printf("¿Cuantas peliculas deseas agregar? (Espacio disponible: %d): ", MAX_PELICULAS - cantidadActual);
                scanf("%d", &cuantasMas);
            } while (cuantasMas <= 0 || (cantidadActual + cuantasMas) > MAX_PELICULAS);

            for (i = 0; i < cuantasMas; i++) {
                int index = cantidadActual; 
                printf("\n--- Nueva Pelicula %d ---\n", i + 1);
                
                printf("Nombre: ");
                scanf(" %[^\n]", videoteca[index].nombre);
                printf("Genero: ");
                scanf(" %[^\n]", videoteca[index].genero);
                printf("Año: ");
                scanf("%d", &videoteca[index].anio);

                do {
                    printf("Numero de directores (1-%d): ", NUM_DIR);
                    scanf("%d", &videoteca[index].numDirectores);
                    if(videoteca[index].numDirectores <= 0 || videoteca[index].numDirectores > NUM_DIR)
                        printf("Error: Invalido.\n");
                } while (videoteca[index].numDirectores <= 0 || videoteca[index].numDirectores > NUM_DIR);

                for (j = 0; j < videoteca[index].numDirectores; j++) {
                    printf("Director %d: ", j + 1);
                    scanf(" %[^\n]", videoteca[index].directores[j]);
                }
                cantidadActual++; 
            }
            printf("\n¡Peliculas agregadas exitosamente!\n");

        } else if (opcion == 2) {
            printf("\n--- BUSQUEDA  ---\n");
            printf("1. Por Año\n");
            printf("2. Por Genero (te dice cuántas hay)\n");
            printf("3. Por Director\n");
            printf("Opcion: ");
            scanf("%d", &subOpcion);

            encontrados = 0;
            if (subOpcion == 1) {
                printf("Ingresa año: ");
                scanf("%d", &anioBusqueda);
                for (i = 0; i < cantidadActual; i++) {
                    if (videoteca[i].anio == anioBusqueda) {
                        printf(">> %s (%s)\n", videoteca[i].nombre, videoteca[i].genero);
                        encontrados++;
                    }
                }
            } else if (subOpcion == 2) { 
                printf("Ingresa genero exacto: ");
                scanf(" %[^\n]", textoBusqueda);
                for (i = 0; i < cantidadActual; i++) {
                    if (strcmp(videoteca[i].genero, textoBusqueda) == 0) {
                        encontrados++;
                    }
                }
                printf("Total de peliculas de '%s': %d\n", textoBusqueda, encontrados);
                encontrados = 1; 
            } else if (subOpcion == 3) {
                printf("Ingresa nombre director: ");
                scanf(" %[^\n]", textoBusqueda);
                for (i = 0; i < cantidadActual; i++) {
                    for (j = 0; j < videoteca[i].numDirectores; j++) {
                        if (strstr(videoteca[i].directores[j], textoBusqueda) != NULL) {
                            printf(">> %s (Dir: %s)\n", videoteca[i].nombre, videoteca[i].directores[j]);
                            encontrados++;
                        }
                    }
                }
            }

            if (encontrados == 0 && subOpcion != 2) printf("No se encontraron coincidencias.\n");
        }

    } while (opcion != 3);

    printf("Saliendo de la videoteca\n");
    return 0;
}
