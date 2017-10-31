#pragma once
#include<stdint.h>

typedef struct course *course_t;

course_t course_create(int course_number, char cname[20], int semester_number);

void set_course_name(course_t self, char string[20]);
char* get_course_name(course_t self);
void set_course_num(course_t self, int id);
int* get_course_num(course_t self);
void set_course_sem(course_t self, int id);
int* get_course_sem(course_t self);

