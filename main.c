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
void Agregar_libro_nuevo(char *inven);
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
                Agregar_libro_nuevo(inven);
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

void Agregar_libro_nuevo(char *inven){
    inventario *Inventario = (inventario *) malloc(sizeof(inventario));
    printf("Ingrese el id \n");
    int id;
    scanf("%d", &id);
    Inventario->id = id;

    char tokenn = (char*)malloc( 50 * sizeof(char));
    printf("Ingrese el titulo \n");
    scanf("%s", &tokenn);
    Inventario->titulo = (char*)malloc(strlen(tokenn)* sizeof(char));
    strcpy(Inventario->titulo, tokenn);

    printf("Ingrese el autor \n");
    scanf("%s", &tokenn);
    Inventario->autor = (char*)malloc( strlen(tokenn) * sizeof(char));
    strcpy(Inventario->autor, tokenn);

    printf("Ingrese el año \n");
    scanf("%s", &tokenn);
    Inventario->anio = (char*)malloc( strlen(tokenn) * sizeof(char));
    strcpy(Inventario->anio, tokenn);

    printf("Ingrese el número del estante \n");
    scanf("%s", &tokenn);
    Inventario->estante_numero = (char*)malloc( strlen(tokenn) * sizeof(char));
    strcpy(Inventario->estante_numero, tokenn);

    printf("Ingrese la sección del estante \n");
    scanf("%s", &tokenn);
    Inventario->estante_seccion = (char*)malloc( strlen(tokenn) * sizeof(char));
    strcpy(Inventario->estante_seccion, tokenn);

    printf("Ingrese el piso \n");
    scanf("%s", &tokenn);
    Inventario->piso = (char*)malloc( strlen(tokenn) * sizeof(char));
    strcpy(Inventario->piso, tokenn);

    printf("Ingrese el edificio \n");
    scanf("%s", &tokenn);
    Inventario->edificio = (char*)malloc( strlen(tokenn) * sizeof(char));
    strcpy(Inventario->edificio, tokenn);

    printf("Ingrese la sede \n");
    scanf("%s", &tokenn);
    Inventario->sede = (char*)malloc( strlen(tokenn) * sizeof(char));
    strcpy(Inventario->sede, tokenn);


    Inventario = (inventario*) realloc(Inventario, (registryCount+1)*sizeof(Inventario));
    Inventario[registryCount] = *Inventario;
    registryCount++;
    printf("Agregado con exito! \n");

};

void Quitar_un_libro(FILE *file){

};

void Agregar_una_sede(FILE *file){
    
};

void Quitar_una_sede(FILE *file){
    
    char *sede = (char*)malloc( 50 * sizeof(char));;
    printf("Ingrese el nombre de la sede que quiere eliminar:\n");
    scanf("%s", sede);

    int i = 0;
    int encontre = 0;
    while (i<registryCount && encontre == 0){
        char *sedeConverted = toLowerC(inven[i].sede);
        char *sedeToLook = toLowerC(sede);
        char *ret = strstr(sedeConverted, sedeToLook);

        if(ret && inven[i].borrar == 0){
            encontre = 1;
        } else {
            i++;
        }
    }

    if (encontre == 1){
        printf("La sede tiene libros asociados");
        printf("A continuacion se muestran los libros que estan asociados:\n");
        printf("Libro: %s \n", inven[i].titulo);
        printf("Desea eliminar estos libros para proceder a borrar la sede?\n");
        char *rta = (char*)malloc(1 * sizeof(char));
        scanf("%s", rta);

        if (strcmp(toLowerC(rta), "s") == 0){
            inven[i].borrar = 1;
            printf("Borrado con los libros asociados y la sede! \n");
        }

    }
    else {
        printf("La sede no existe! \n");
    }

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
    char *seccion = (char*)malloc( 50 * sizeof(char));
    printf("Ingrese la seccion que quiere eliminar \n");
    scanf("%s", seccion);

    int i = 0;
    int encontre = 0;
    while (i<registryCount && encontre == 0){
        char *seccionConverted1 = toLowerC(inven[i].estante_seccion);
        char *seccionToLook1 = toLowerC(seccion);
        char *ret1 = strstr(seccionConverted1, seccionToLook1);

        if(ret1 && inven[i].borrar == 0){
            encontre = 1;
        } else {
            i++;
        }
    }

    if (encontre == 1){
        printf("La seccion tiene libros asociados.\n");
        printf("A continuacion se muestran los libros que estan asociados:\n\n");
        printf("Libro: %s \n\n", inven[i].titulo);
        printf("Desea eliminar estos libros para proceder a borrar la seccion?\n");


        char *rta = (char*)malloc(1 * sizeof(char));
        scanf("%s", rta);

        if (strcmp(toLowerC(rta), "s") == 0){
            inven[i].borrar = 1;
            printf("Borrado con los libros asociados y la seccion! \n");
        }

    }
    else {
        printf("La sede no existe! \n");
    }

};

void Agregar_piso(FILE *file){

};

void Eliminar_piso(FILE *file){
    char *piso = (char*)malloc( 50 * sizeof(char));;
    printf("Ingrese el nombre del piso que quiere eliminar \n");
    scanf("%s", piso);

    int i = 0;
    int encontre = 0;
    while (i<registryCount && encontre == 0){
        char *pisoConverted = toLowerC(inven[i].piso);
        char *pisoToLook = toLowerC(piso);
        char *ret = strstr(pisoConverted, pisoToLook);

        if(ret && inven[i].borrar == 0){
            encontre = 1;
        } else {
            i++;
        }
    }

    if (encontre == 1){
        printf("El piso tiene libros asociados");
        printf("A continuacion se muestran los libros que se encuentran en los pisos.\n");
        printf("Libro: %s \n", inven[i].titulo);
        printf("Desea eliminar estos libros para proceder a borrar el piso?\n");
        char *rta = (char*)malloc(1 * sizeof(char));
        scanf("%s", rta);

        if (strcmp(toLowerC(rta), "s") == 0){
            inven[i].borrar = 1;
            printf("Borrado los libros asociados al piso y el piso que selecciono! \n");
        }

    }
    else {
        printf("El piso no existe! \n");
    }

};

void Buscar_un_libro(FILE *file){

};
