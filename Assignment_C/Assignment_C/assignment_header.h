#pragma once
#include<stdint.h>

typedef struct assignment_t *assignment;

assignment create_assignment(int teacher_no, int course_no);

void set_teach_num_asgmt(assignment self, int id);
int* get_teach_num_asgmt(assignment self);
void set_course_num_asgmt(assignment self, int id);
int* get_course_num_asgmt(assignment self);

