#pragma once
#include<stdint.h>

typedef struct student_t *student;

student student_create(char fname[20], int student_number);

void set_student_fn(student self, char string[20]);
char *get_student_fn(student self);
void set_student_num(student self, int id);
int *get_student_num(student self);
