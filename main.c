#include <stdio.h>
#include <string.h>
#include <stdlib.h>
extern int registryCount;
//Creamos la estructura que seguira cada libro guardado
struct INVENTARIO{
    int id;
    char *titulo;
    char *autor;
    char *anio;
    char *estante_numero;
    char *estante_seccion;
    char *piso;
    char *edificio;
    char *sede;
};
typedef struct INVENTARIO inventario;

// Declaramos cada void que se utilizara ams adelante
void Ver_la_base_de_datos(FILE *file);
void Agregar_libro_nuevo(FILE *file);
void Quitar_un_libro(FILE *file);
void Agregar_una_sede(FILE *file);
void Quitar_una_sede(FILE *file);
void Editar_un_libro(FILE *file);
void Cambiar_libro_de_sede(FILE *file);
void Cambiar_libro_de_seccion(FILE *file);
void Cambiar_libro_de_piso(FILE *file);
void Agregar_una_seccion(FILE *file);
void Eliminar_una_seccion(FILE *file);
void Agregar_piso(FILE *file);
void Eliminar_piso(FILE *file);
void Buscar_un_libro(FILE *file);

//Tambien creamos una flag que se utilizara como metodo de salida del do while
int flag = 1;

FILE * openingFile(char *filename){
    FILE *fp;
    fp = fopen(filename,"r");
    return fp;
}

//Creamos la funcion que nos entregara la info del csv en forma de struct
int registryCount = 0;
inventario*getinfo(FILE*fp){
    inventario*Inventario=(inventario*)malloc(5000*sizeof(inventario));
    char row[1000];
    char *token;
    int cont = 0;
    fgets(row,1000,fp);
    while (!feof(fp)){
        if (!feof(fp)){
            //obtiene la linea siguiente
            fgets(row, 1000, fp);
            token = strtok(row, ",");
            //print id first
            inventario*inven = (inventario *) malloc(sizeof(inventario));;
            //convierto el id en entero
            int id = atoi(token);
            //lo paso a la persona
            inven->id = id;

            //repito para las siguientes variables
            token = strtok(NULL, ",");
            //inicializo el string en la estructura acorde al tamaño que venga del archivo
            inven->titulo = (char*)malloc( strlen(token) * sizeof(char));
            //finalmente lo copio en el campo de persona
            strcpy( inven->titulo, token);

            token = strtok(NULL, ",");
            //inicializo el string en la estructura acorde al tamaño que venga del archivo
            inven->autor = (char*)malloc( strlen(token) * sizeof(char));
            //finalmente lo copio en el campo de persona
            strcpy( inven->autor, token);

            token = strtok(NULL, ",");
            //inicializo el string en la estructura acorde al tamaño que venga del archivo
            inven->anio = (char*)malloc( strlen(token) * sizeof(char));
            //finalmente lo copio en el campo de persona
            strcpy( inven->anio, token);

            token = strtok(NULL, ",");
            //inicializo el string en la estructura acorde al tamaño que venga del archivo
            inven->estante_numero = (char*)malloc( strlen(token) * sizeof(char));
            //finalmente lo copio en el campo de persona
            strcpy( inven->estante_numero, token);

            token = strtok(NULL, ",");
            //inicializo el string en la estructura acorde al tamaño que venga del archivo
            inven->estante_seccion = (char*)malloc( strlen(token) * sizeof(char));
            //finalmente lo copio en el campo de persona
            strcpy( inven->estante_seccion, token);

            token = strtok(NULL, ",");
            //inicializo el string en la estructura acorde al tamaño que venga del archivo
            inven->piso = (char*)malloc( strlen(token) * sizeof(char));
            //finalmente lo copio en el campo de persona
            strcpy( inven->piso, token);

            token = strtok(NULL, ",");
            //inicializo el string en la estructura acorde al tamaño que venga del archivo
            inven->edificio = (char*)malloc( strlen(token) * sizeof(char));
            //finalmente lo copio en el campo de persona
            strcpy( inven->edificio, token);

            token = strtok(NULL, ",");
            //inicializo el string en la estructura acorde al tamaño que venga del archivo
            inven->sede = (char*)malloc( strlen(token) * sizeof(char));
            //finalmente lo copio en el campo de persona
            strcpy( inven->sede, token);

            Inventario[cont] = *inven;
            cont++;
        }
    }
    //guardo la cantidad de registros que lei
    registryCount = cont;
    return Inventario;
}



int main(int argc, char *argv[]){
    int opc;
    FILE *fp = openingFile(argv[1]);
    inventario *inven;
    inven = getinfo(fp);
    fclose(fp);
    while (flag == 1) {
        system("cls");
        printf("Menu de opciones\n");
        printf("1) Ver la  base de datos\n");
        printf("2) Agregar libro nuevo\n");
        printf("3) Quitar un libro\n");
        printf("4) Agregar una sede\n");
        printf("5) Quitar una sede\n");
        printf("6) Editar un libro\n");
        printf("7) Cambiar libro de sede\n");
        printf("8) Cambiar libro de seccion\n");
        printf("9) Cambiar libro de piso\n");
        printf("10) Agregar una seccion\n");
        printf("11) Eliminar una seccion\n");
        printf("12) Agregar piso\n");
        printf("13) Eliminar piso\n");
        printf("14) Buscar un libro\n");
        printf("ingrese la opcion que quiera realizar: \n");
        scanf("%d", &opc);
        flag = 0;
        }
        switch (opc) {
            case 1:
                printf("Opcion 1 seleccionada\n");
                for (int i = 0; i < registryCount; ++i) {
                    printf("%s,%s,%s,%s", inven[i].titulo,inven[i].autor,inven[i].anio,inven[i].estante_numero);
                    printf("%s,%s,%s,%s \n", inven[i].estante_seccion,inven[i].piso,inven[i].edificio,inven[i].sede);
                }
                break;
            case 2:
                printf("\n 2");
                break;
            case 3:
                printf("\n 3");
                break;
            case 4:
                printf("\n 4");
                break;
            case 5:
                printf("\n 5");
                break;
            case 6:
                printf("\n 6");
                break;
            case 7:
                printf("\n 7");
                break;
            case 8:
                printf("\n 8");
                break;
            case 9:
                printf("\n 9");
                break;
            case 10:
                printf("\n 10");
                break;
            case 11:
                printf("\n 11");
                break;
            case 12:
                printf("\n 12");
                break;
            case 13:
                printf("\n 13");
                break;
            case 14:
                printf("\n 14");
                break;
            default:
                printf("Intentelo nuevamente\n");
                break;
        }

    return 0;
}

void Ver_la_base_de_datos(FILE *file){
    printf("Elegiste la opcion 1");
};

void Agregar_libro_nuevo(FILE *file){

};

void Quitar_un_libro(FILE *file){

};

void Agregar_una_sede(FILE *file){

};

void Quitar_una_sede(FILE *file){

};

void Editar_un_libro(FILE *file){

};
void Cambiar_libro_de_sede(FILE *file){

};

void Cambiar_libro_de_seccion(FILE *file){

};

void Cambiar_libro_de_piso(FILE *file){

};

void Agregar_una_seccion(FILE *file){

};

void Eliminar_una_seccion(FILE *file){

};

void Agregar_piso(FILE *file){

};

void Eliminar_piso(FILE *file){

};

void Buscar_un_libro(FILE *file){

};