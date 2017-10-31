#pragma once
#include<stdint.h>

typedef struct student *student_t;

student_t student_create(char fname[20], int student_number);

void set_student_fn(student_t self, char string[20]);
char *get_student_fn(student_t self);
void set_student_num(student_t self, int id);
int *get_student_num(student_t self);
