#include "student_header.h"
#include <string.h>

struct student {

	int stud_num;
	char fn[20];

};

student_t student_create(char fname[20], int student_num) {
	student_t stud = (student_t)malloc(sizeof(struct student));

	strcpy_s(stud->fn, 20, fname);
	stud->stud_num = student_num;

	return stud;
}

void set_student_fn(student_t self, char string[20]) {
	strcpy_s(self->fn, 20, string);
}

char *get_student_fn(student_t self) {
	return self->fn;
}

void set_student_num(student_t self, int id) {
	self->stud_num = id;
}

int *get_student_num(student_t self) {
	return self->stud_num;
}