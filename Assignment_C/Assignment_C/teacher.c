#include "teacher_header.h"
#include <string.h>

struct teacher
{
	int teach_num;

	char fn[20];
};

teacher_t teach_create(char fname[20], int teacher_num) {
	teacher_t lecturer = (teacher_t)malloc(sizeof(struct teacher));

	strcpy_s(lecturer->fn, 20, fname);
	lecturer->teach_num = teacher_num;

	return lecturer;
}

void set_teach_fn(teacher_t self, char string[20]) {
	strcpy_s(self->fn, 20, string);
}

char* get_teach_fn(teacher_t self) {
	return self->fn;
}

void set_teach_num(teacher_t self, int id) {
	self->teach_num = id;
}

int* get_teach_num(teacher_t self) {
	return self->teach_num;
}