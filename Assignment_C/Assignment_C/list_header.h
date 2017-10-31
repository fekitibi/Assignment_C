#pragma once
#include<stdint.h>

typedef struct list *list_t;

list_t list_create();

void list_dest(list_t self);

int add_item(list_t self, void * item);
void *get_item(list_t self, uint16_t index);
int no_of_items(list_t self);
int rmv_item(list_t self, void *item);

