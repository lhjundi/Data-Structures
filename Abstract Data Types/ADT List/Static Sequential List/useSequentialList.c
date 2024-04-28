#include <stdio.h>
#include "SequentialList.c"

void insert(LIST *list){
    KEY_TYPE key;
    scanf("%d", &key);
    REGISTER reg;
    reg.key = key;
    if (insertElementSortedList(reg, list))
        printf("Inserted element.\n");
    else
        printf("Unable to insert element.\n");
}

void delete(LIST *list){
    KEY_TYPE key;
    scanf("%d", &key);
    if(deleteElement(key, list))
        printf("Deleted element.\n");
    else
        printf("Unable to delete element.\n");
}

void show(LIST *list){
    showList(list);
}

void help(){
    printf("Valid commands:\n");
    printf("\t i <key1>: insert element with key=<key1>\n");
    printf("\t e <key1>: delete element with key=<key1>");
    printf("\t p : print list\n");
    printf("\t d : destroy list\n");
    printf("\t h : show help message\n");
    printf("\t q : quit program\n");
}

void destroy(LIST *list){
    destroyList(list);
    printf("Destroyed list\n");
}

int main(){
    LIST list;
    initList(&list);
    help();
    char command = ' ';
    scanf("%c", &command);
    while(command != 'q'){
        switch (command){
            case 'i' : insert(&list); break;
            case 'e' : delete(&list); break;
            case 'p' : show(&list); break;
            case 'd' : destroy(&list); break;
            case 'h' : help(); break;        
            default: {while (command != '\n') scanf("%c", &command);};
        }
        scanf("%c", &command);
    }
    return 0;
}