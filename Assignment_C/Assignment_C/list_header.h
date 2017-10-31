#pragma once
#include<stdint.h>

typedef struct list_t *list;

list list_create();

void list_dest(list self);

int add_item(list self, void * item); // Return 0 if item added else -1
void *get_item(list self, uint16_t index); // Return pointer to item at given index in the list
int no_of_items(list self); // Return no of items in list
int rmv_item(list self, void *item); // Return 0 if item removed else -1

