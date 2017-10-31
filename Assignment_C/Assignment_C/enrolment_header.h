#pragma once
#include<stdint.h>

typedef struct enrolment *enrolment_t;

enrolment_t enrol_create(int student_no, int course_no);

void set_student_num_enrol(enrolment_t self, int id);
int* get_student_num_enrol(enrolment_t self);
void set_course_num_enrol(enrolment_t self, int id);
int* get_course_num_enrol(enrolment_t self);
