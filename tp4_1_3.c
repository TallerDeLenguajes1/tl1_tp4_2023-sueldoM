#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tarea {
    int TareaID;
    char *Descripcion;
    int Duracion;
};

void cargar_tareas(struct Tarea **tareas, int cantidad_tareas) {
    char descripcion[100];
    int duracion;

    for (int i = 0; i < cantidad_tareas; i++) {
        printf("Ingrese la descripción de la tarea %d: ", i + 1);
        scanf(" %[^\n]", descripcion);

        printf("Ingrese la duración de la tarea %d (entre 10 y 100): ", i + 1);
        scanf("%d", &duracion);

        // Reservamos memoria para la descripción de la tarea
        tareas[i] = (struct Tarea *)malloc(sizeof(struct Tarea));
        tareas[i]->Descripcion = (char *)malloc(strlen(descripcion) + 1);
        strcpy(tareas[i]->Descripcion, descripcion);

        // Asignamos los demás campos de la tarea
        tareas[i]->TareaID = i + 1;
        tareas[i]->Duracion = duracion;
    }
}

int main() {
    int cantidad_tareas;
    printf("Ingrese la cantidad de tareas que desea cargar: ");
    scanf("%d", &cantidad_tareas);

    struct Tarea **tareas = (struct Tarea **)malloc(cantidad_tareas * sizeof(struct Tarea *));
    memset(tareas, 0, cantidad_tareas * sizeof(struct Tarea *));

    cargar_tareas(tareas, cantidad_tareas);

    printf("Se cargaron las siguientes tareas:\n");
    for (int i = 0; i < cantidad_tareas; i++) {
        printf("Tarea %d: %s, Duración: %d\n", tareas[i]->TareaID, tareas[i]->Descripcion, tareas[i]->Duracion);
    }

    // Liberamos la memoria reservada para las tareas
    for (int i = 0; i < cantidad_tareas; i++) {
        free(tareas[i]->Descripcion);
        free(tareas[i]);
    }
    free(tareas);

    return 0;
}
