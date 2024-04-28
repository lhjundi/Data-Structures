#include <stdio.h>
#include "SequentialList.c"

void insert(LIST *list){
    KEY_TYPE key;
    scanf("%d%*c", key);
    REGISTER reg;
    reg.key = key;
    if (insertElementSortedList(reg, list))
        printf("Inserted element.\n");
    else
        printf("Unable to insert element.\n");
}
