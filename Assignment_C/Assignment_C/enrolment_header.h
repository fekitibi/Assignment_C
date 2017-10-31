#pragma once
#include<stdint.h>

typedef struct enrolment_t *enrolment;

enrolment enrol_create(int student_no, int course_no);

void set_student_num_enrol(enrolment self, int id);
int* get_student_num_enrol(enrolment self);
void set_course_num_enrol(enrolment self, int id);
int* get_course_num_enrol(enrolment self);
