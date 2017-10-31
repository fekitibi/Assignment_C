#pragma once
#include<stdint.h>

typedef struct list *list_t;

list_t list_create();

void list_dest(list_t self);

int add_item(list_t self, void * item); // Return 0 if item added else -1
void *get_item(list_t self, uint16_t index); // Return pointer to item at given index in the list
int no_of_items(list_t self); // Return no of items in list
int rmv_item(list_t self, void *item); // Return 0 if item removed else -1

