//
//  main.c
//  operacionesListasEstaticas
//
//  Created by Caleb on 05/03/20.
//  Copyright © 2020 Caleb. All rights reserved.
//
#define MAX 11
#include <stdio.h>
#include <stdlib.h>

int lista1[MAX];
int lista2[MAX];

int listaInicializada(int lista[]);
int listaLlena(int lista[]);
void insertarEnPosicion(int lista[], int valor, int posicion);
void inicializarLista(int lista[]);
void insertar(int lista[], int valor);
void imprimir(int lista[]);
int tamano(int lista[]);
void borrar(int lista[], int posicion);
void menu(void);
int buscar(int lista[], int valor);
int buscarKesimo(int lista[], int posicion);
int *elegirLista(void);
void unirListas(int listax[], int listay[]);
void intercalarElementos(int listax[], int listay[]);
void copiarLista(int listax[], int listay[]);
int sonIguales(int listax[], int listay[]);
void intercambiarListas(int listax[], int listay[]);
void obtenerInterseccion(int listax[], int listay[]);
void obtenerElementosDistintos(int listax[], int listay[]);

/*operaciones entre listas
 1. Unir las dos listas: se va a tener una lista y se inicia la siguiente
 2. Intercalar los elementos de las dos listas (toma un elemento de la lista intercalados *uno y uno*)
 3. Copiar una lista en otra (las dos listas terminan siendo las mismas)
 4. Verificar si las listas son iguales
 5. Intercambiar dos listas(lista uno se vulve lista dos, y lista dos se vuelve lista una)
 6. Elementos en comun de las listas(interseccion)
 7. Elementos distintos
 */

int main(int argc, const char * argv[]) {
    inicializarLista(lista1);
    inicializarLista(lista2);
    menu();
    return 0;
}

void menu(){
    int opc = 0;
    printf("Lista 1:\n");
    imprimir(lista1);
    printf("Lista 2:\n");
    imprimir(lista2);
    printf("\nOpciones\n");
    printf("1. Insertar\n");
    printf("2. Insertar en posicion\n");
    printf("3. Buscar\n");
    printf("4. Buscar k esimo\n");
    printf("5. Borrar\n");
    printf("6. Unir listas\n");
    printf("7. Intercalar listas\n");
    printf("8. Copiar lista\n");
    printf("9. Verificar si las listas son iguales\n");
    printf("10. Intercambiar listas\n");
    printf("11. Obtener interseccion de listas\n");
    printf("12. Obtener elementos distintos\n");
    printf("13. Salir\n");
    printf("Digite una opcion\n");
    scanf("%d", &opc);
    int valor, posicion;
    int *listax;
    switch (opc) {
        case 1:
            listax = elegirLista();
            printf("Escribe el valor del dato\n");
            scanf("%d", &valor);
            insertar(listax, valor);
            break;
        case 2:
            listax = elegirLista();
            printf("Escribe el valor del dato\n");
            scanf("%d", &valor);
            printf("Escribe la posicion\n");
            scanf("%d", &posicion);
            insertarEnPosicion(listax, valor, posicion);
            break;
        case 3:
            listax = elegirLista();
            printf("Escribe el valor del dato a buscar\n");
            scanf("%d", &valor);
            posicion = buscar(listax, valor);
            if(posicion != -1){
                printf("El dato %i se encuentra en la posicion %i\n", valor, posicion);
            }
            else{
                printf("El dato no esta en la lista\n");
            }
            break;
        case 4:
            listax = elegirLista();
            printf("Escribe la posicion del dato a buscar\n");
            scanf("%d", &posicion);
            valor = buscarKesimo(listax, posicion);
            if(valor != -1){
                printf("En la posicion %i se encuentra el valor %i\n", posicion, valor);
            }
            else{
                printf("La posicion no esta en la lista\n");
            }

            break;
        case 5:
            listax = elegirLista();
            printf("Escribe la posicion del dato que deseas borrar\n");
            scanf("%d", &posicion);
            borrar(listax, posicion);
            break;
        case 6:
            printf("Elige una opcion\n");
            printf("1. Unir lista 1 con lista 2\n");
            printf("2. Unir lista 2 con lista 1\n");
            scanf("%d", &opc);
            switch (opc) {
                case 1:
                    unirListas(lista1, lista2);
                    break;
                case 2:
                    unirListas(lista2, lista1);
                    break;
                default:
                    printf("Elige una opcion");
                    break;
            }
            break;
        case 7:
            printf("Elige una opcion\n");
            printf("1. Intercalar lista 1 con lista 2\n");
            printf("2. Intercalar lista 2 con lista 1\n");
            scanf("%d", &opc);
            switch (opc) {
                case 1:
                    intercalarElementos(lista1, lista2);
                    break;
                case 2:
                    intercalarElementos(lista2, lista1);
                    break;
                default:
                    printf("Elige una opcion");
                    break;
            }
            break;
        case 8:
            printf("Elige una opcion\n");
            printf("1. Copiar lista 1 en lista 2\n");
            printf("2. Copiar lista 2 en lista 1\n");
            scanf("%d", &opc);
            switch (opc) {
                case 1:
                    copiarLista(lista1, lista2);
                    break;
                case 2:
                    copiarLista(lista2, lista1);
                    break;
                default:
                    printf("Elige una opcion");
                    break;
            }
            break;
        case 9:
            if(sonIguales(lista1, lista2)){
                printf("Las listas son iguales");
            }
            else{
                printf("Las listas no son iguales, tienen elementos distintos\n");
            }
            break;
        case 10:
            intercambiarListas(lista1, lista2);
            break;
        case 11:
            obtenerInterseccion(lista1, lista2);
            break;
        case 12:
            obtenerElementosDistintos(lista1, lista2);
            break;
        case 13:
            exit(0);
            break;
        default:
            printf("Selecciona una opcion\n");
            menu();
            break;
    }
    menu();
}

int *elegirLista(){
    int opc;
    printf("Elige la lista que deseas manipular\n");
    printf("1. Lista 1\n");
    printf("2. Lista 2\n");
    scanf("%d", &opc);
    switch (opc) {
        case 1:
            return lista1;
            break;
        case 2:
            return lista2;
            break;
        default:
            printf("Elige una opcion valida \n");
            return elegirLista();
            break;
    }
}

void inicializarLista(int lista[]){
    lista[0] = 0;//indica que se inicializa la lista con tamaño de 0
}

void insertarEnPosicion(int lista[], int valor, int posicion){
    if(!listaLlena(lista)){
        if(posicion>0 && posicion<lista[0]){
            int auxiliar[(lista[0]-posicion)];
            int i, j=0;
            for (i=posicion; i<=lista[0]; i++) {
                auxiliar[j] = lista[i];//guarda los elementos posteriores a la insercion
                j++;
            }
            lista[posicion]=valor;
            j=0;
            for (i=posicion+1; i<=lista[0]+1; i++) {
                lista[i] = auxiliar[j];//inserta los elementos al arreglo original
                j++;
            }
            lista[0]++;
            return;
        }
        if(posicion == lista[0]){
            int aux = lista[posicion];
            lista[posicion] = valor;
            lista[posicion+1] = aux;
            lista[0]++;
            return;
        }
        printf("Escribe una posicion dentro de la lista\n");
    }
    else{
        printf("La lista esta llena\n");
    }
}

void insertar(int lista[], int valor){//inserta al ultimo por default
    if(!listaLlena(lista)){
        lista[lista[0]+1] = valor;
        lista[0]++;
    }
}

void borrar(int lista[], int posicion){
    if(listaInicializada(lista)){
        if(posicion>0 && posicion<lista[0]){
            int auxiliar[(lista[0]-posicion)];
            int i, j=0;
            for (i=posicion+1; i<=lista[0]; i++) {
                auxiliar[j] = lista[i];//guarda los elementos posteriores a la insercion
                j++;
            }
            j=0;
            for (i=posicion; i<=lista[0]-1; i++) {
                lista[i] = auxiliar[j];//inserta los elementos al arreglo original
                j++;
            }
            lista[0]--;
            return;
        }
        if(posicion == lista[0]){
            lista[0]--;
            return;
        }
    }
    else{
        printf("La lista esta vacia\n");
    }
}

int buscar(int lista[], int valor){
    if(lista[0]>0){
        for (int i=1; i<=lista[0]; i++) {
            if(valor == lista[i]){
                return i;
            }
        }
    }
    return -1;
}

int buscarKesimo(int lista[], int posicion){
    if(lista[0]>0){
        if(posicion>0 && posicion<=lista[0]){
            return lista[posicion];
        }
    }
    return -1;
}

void imprimir(int lista[]){
    int i;
    for (i = 1; i<=lista[0]; i++) {
        printf("%i- %i\t", i, lista[i]);
    }
    printf("\n");
}

int listaInicializada(int lista[]){
    return lista[0] >= 0;
}

int listaLlena(int lista[]){
    return lista[0] >= MAX-1;
}

int tamano(int lista[]){
    return lista[0];
}

void unirListas(int listax[], int listay[]){
    int tamanoUnion = listax[0]+listay[0];
    int j = 0;
    if((tamanoUnion) < MAX) {
        for (int i = listax[0]; i<=tamanoUnion; i++) {
            listax[i] = listay[j];
            j++;
        }
        for(int i = 1; i<MAX; i++){
            listay[i] = 0;
        }
        listax[0] = tamanoUnion;
        listay[0] = 0;
    }
    else{
        printf("No se puede hacer la union");
    }
}

void intercalarElementos(int listax[], int listay[]){
    int tamanoUnion = listax[0]+listay[0];
    int listaAuxiliar[MAX];
    if((tamanoUnion) < MAX) {
        listaAuxiliar[0] = tamanoUnion;
        int i=1, j=1, k=1;
        while(i<=tamanoUnion){
            if(listax[0]>=j){
                listaAuxiliar[i] = listax[j];
                i++;
                j++;
            }
            if(listay[0]>=k){
                listaAuxiliar[i] = listay[k];
                i++;
                k++;
            }
        }
        listax[0] = 0;
        listay[0] = 0;
        for (int i = 1; i<=tamanoUnion; i++) {
            listax[i] = listaAuxiliar[i];
        }
        listax[0] = tamanoUnion;
    }
    else{
        printf("No se puede hacer la interseccion");
    }
}

void copiarLista(int listax[], int listay[]){
    for (int i=1; i<=listax[0]; i++) {
        listay[i]=listax[i];
    }
    listay[0]=listax[0];
}

int sonIguales(int listax[], int listay[]){
    if(listax[0] == listay[0]){
        for (int i=0; i<=listax[0]; i++) {
            if(!(listax[i] == listay[i])){
                return 0;
            }
        }
        return 1;
    }
    else{
        return 0;
    }
}

void intercambiarListas(int listax[], int listay[]){
    int auxiliar[MAX];
    auxiliar[0] = listax[0];
    for (int i=1; i<=listax[0]; i++) {
        auxiliar[i] = listax[i];
    }
    for (int i = 1; i<=listay[0]; i++) {
        listax[i] = listay[i];
    }
    listax[0]=listay[0];
    for (int i = 1; i<auxiliar[0]; i++) {
        listay[i] = auxiliar[i];
    }
    listay[0]=auxiliar[0];
}

void obtenerInterseccion(int listax[], int listay[]){
    int auxiliar[MAX];
    auxiliar[0] = 0;
    int k=1;
    for (int i=1; i<=listax[0]; i++) {
        for (int j=1; j<=listay[0]; j++) {
            if(listax[i] == listay[j]){
                auxiliar[k] = listax[i];
                auxiliar[0]++;
                k++;
            }
        }
    }
    printf("los elementos de la interseccion entre las listas son:\n");
    imprimir(auxiliar);
}

void obtenerElementosDistintos(int listax[], int listay[]){
    int auxiliar[MAX], distintos[MAX];
    auxiliar[0] = 0;//interseccion
    distintos[0] = 0;
    int k=1;
    for (int i=1; i<=listax[0]; i++) {
        for (int j=1; j<=listay[0]; j++) {
            if(listax[i] == listay[j]){
                auxiliar[k] = listax[i];
                auxiliar[0]++;
                k++;
            }
        }
    }
    k=1;
    for (int i=1; i<=listax[0]; i++) {
        if(listax[i] != auxiliar[i]){
            distintos[k] = listax[i];
            distintos[0]++;
            k++;
        }
    }
    for (int i=1; i<=listay[0]; i++) {
        if(listay[i] != auxiliar[i]){
            distintos[k] = listay[i];
            distintos[0]++;
            k++;
        }
    }
    printf("los elementos distintos entre las listas son:\n");
    imprimir(distintos);
}
