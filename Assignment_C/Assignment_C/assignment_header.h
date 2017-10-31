#pragma once
#include<stdint.h>

typedef struct assignment *assignment_t;

assignment_t create_assignment(int teacher_no, int course_no);

void set_teach_num_asgmt(assignment_t self, int id);
int* get_teach_num_asgmt(assignment_t self);
void set_course_num_asgmt(assignment_t self, int id);
int* get_course_num_asgmt(assignment_t self);

