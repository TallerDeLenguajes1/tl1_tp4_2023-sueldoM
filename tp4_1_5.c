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

void realizar_tareas(struct Tarea **tareas, int cantidad_tareas) {
    struct Tarea **tareas_realizadas = (struct Tarea **)malloc(cantidad_tareas * sizeof(struct Tarea *));
    memset(tareas_realizadas, 0, cantidad_tareas * sizeof(struct Tarea *));

    for (int i = 0; i < cantidad_tareas; i++) {
        printf("Tarea %d: %s, Duración: %d\n", tareas[i]->TareaID, tareas[i]->Descripcion, tareas[i]->Duracion);
        char respuesta[10];
        printf("¿Se realizó la tarea? (Si/No): ");
        scanf(" %s", respuesta);

        if (strcmp(respuesta, "Si") == 0 || strcmp(respuesta, "si") == 0) {
            tareas_realizadas[i] = tareas[i];
            tareas[i] = NULL;
        }
    }

    printf("Tareas realizadas:\n");
    for (int i = 0; i < cantidad_tareas; i++) {
        if (tareas_realizadas[i] != NULL) {
            printf("Tarea %d: %s, Duración: %d\n", tareas_realizadas[i]->TareaID, tareas_realizadas[i]->Descripcion, tareas_realizadas[i]->Duracion);
            free(tareas_realizadas[i]->Descripcion);
            free(tareas_realizadas[i]);
        }
    }

    printf("TAREAS REALIZADAS: \n");
    for (int i = 0; i < cantidad_tareas; i++) {
        if (tareas_realizadas[i] != NULL) {
            printf("ID de tarea: %d\n", tareas_realizadas[i]->TareaID);
            printf("Descripción: %s\n", tareas_realizadas[i]->Descripcion);
            printf("Duración: %d\n", tareas_realizadas[i]->Duracion);
            printf("\n");
        }
    }

    printf("TAREAS PENDIENTES: \n");
    for (int i = 0; i < cantidad_tareas; i++) {
        if (tareas[i] != NULL) {
            printf("ID de tarea: %d\n", tareas[i]->TareaID);
            printf("Descripción: %s\n", tareas[i]->Descripcion);
            printf("Duración: %d\n", tareas[i]->Duracion);
            printf("\n");
        }
    }

    free(tareas_realizadas);
}

int main() {
    int cantidad_tareas;
    printf("Ingrese la cantidad de tareas que desea cargar: ");
    scanf("%d", &cantidad_tareas);

    struct Tarea **tareas = (struct Tarea **)malloc(cantidad_tareas * sizeof(struct Tarea *));
    memset(tareas, 0, cantidad_tareas * sizeof(struct Tarea *));

    cargar_tareas(tareas, cantidad_tareas);

    realizar_tareas(tareas, cantidad_tareas);

    // Liberamos la memoria reservada dinámicamente
    for (int i = 0; i < cantidad_tareas; i++) {
        if (tareas[i] != NULL) {
            free(tareas[i]->Descripcion);
            free(tareas[i]);
        }
    }

    

    free(tareas);

    return 0;
}
