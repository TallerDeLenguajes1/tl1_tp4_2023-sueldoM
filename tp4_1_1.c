#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAREAS 50

struct Tarea {
    int TareaID;
    char *Descripcion;
    int Duracion;
};

void cargar_tareas(struct Tarea *tareas, int *cant_tareas);
void mostrar_tareas(struct Tarea *tareas, int cant_tareas);

int main() {
    struct Tarea tareas[MAX_TAREAS];
    int cant_tareas = 0;
    return 0;
}