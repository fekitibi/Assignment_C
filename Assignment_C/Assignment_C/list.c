#include "list_header.h"

typedef struct node {
	void *data;
	struct node *next_link;
}node_t;

struct list {
	node_t *nodes;
	node_t *head;
};

list_t list_create() {

	list_t list = (list_t)malloc(sizeof(struct list));

	list->head = NULL;

	return list;
}

void list_dest(list_t self) {

	free(self);

}

int add_item(list_t self, void * item) {

	node_t *new_node = (node_t*)malloc(sizeof(node_t));

	if (new_node == NULL)
		return -1;

	new_node->data = item;

	new_node->next_link = self->head;

	self->head = new_node;

	return 0;
}

void *get_item(list_t self, uint16_t index) {
	node_t *node = self->head;

	for (int i = 0; i < index - 1; i++) {
		node = node->next_link;
	}

	return node->data;
}

int no_of_items(list_t self) {
	int cntr = 0;
	node_t *node = self->head;

	for (int i = 0; node != NULL; i++) {
		node = node->next_link;
		cntr++;
	}

	return cntr;
}

int rmv_item(list_t self, void *item) {

	node_t *curr = self->head;
	node_t *prev = self->head;

	if (self->head == NULL)
		return -1;

	if (curr->data == item) {
		self->head = curr->next_link;
		free(curr);
		return 0;
	}

	else {
		while (curr->data != item && curr->next_link != NULL) {
			prev = curr;
			curr = curr->next_link;
		}
	}
	if (curr->data != item && curr->next_link == NULL)
		return -1;

	prev->next_link = curr->next_link;
	free(curr);
	return 0;
}