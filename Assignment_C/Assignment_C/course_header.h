#pragma once
#include<stdint.h>

typedef struct course_t *course;

course course_create(int course_number, char cname[20], int semester_number);

void set_course_name(course self, char string[20]);
char* get_course_name(course self);
void set_course_num(course self, int id);
int* get_course_num(course self);
void set_course_sem(course self, int id);
int* get_course_sem(course self);

