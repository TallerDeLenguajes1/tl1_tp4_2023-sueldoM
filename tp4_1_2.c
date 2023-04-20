#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tarea {
    int TareaID;
    char *Descripcion;
    int Duracion;
};

int main() {
    int cantidad_tareas;
    printf("Ingrese la cantidad de tareas que desea cargar: ");
    scanf("%d", &cantidad_tareas);

    struct Tarea **tareas = (struct Tarea **)malloc(cantidad_tareas * sizeof(struct Tarea *));
    memset(tareas, 0, cantidad_tareas * sizeof(struct Tarea *));

    printf("Se generó un arreglo de doble puntero dinámicamente con %d elementos.\n", cantidad_tareas);

    return 0;
}
