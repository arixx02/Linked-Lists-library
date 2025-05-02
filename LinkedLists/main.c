// main.c
#define NULL ((void *)0)
#include <stdio.h>
#include "linkedLists.h"
int main()
{
    int data;
    int opcion;
    List* list=initList();
    do{
        printf("ingresa un valor para meter en la linkedlist(0 para terminar): ");
        scanf("%d",&data);
        if(data!=0){
            printf("ingresa una opcion de ingreso\n1-append\n2-add(agregar al principio)\nIngreso: ");
            scanf("%d",&opcion);
            if(opcion==1)append(data,list);
            if(opcion==2)add(data,list);
        }
    }while(data!=0);
    printList(list);
    printf("\nLa lista tiene %d elementos\n",list->length);

    return 0;
}
