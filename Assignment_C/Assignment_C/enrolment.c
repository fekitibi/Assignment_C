#include "enrolment_header.h"

struct enrolment {
	int stud_num;
	int course_num;
};

enrolment_t enrol_create(int student_no, int course_no)
{
	enrolment_t enrolment = (enrolment_t)malloc(sizeof(struct enrolment));
	enrolment->stud_num = student_no;
	enrolment->course_num = course_no;

	return enrolment;
}

void set_student_num_enrol(enrolment_t self, int id)
{
	self->stud_num = id;
}

int* get_student_num_enrol(enrolment_t self)
{
	return self->stud_num;
}

void set_course_num_enrol(enrolment_t self, int id)
{
	self->course_num = id;
}

int* get_course_num_enrol(enrolment_t self)
{
	return self->course_num;
}


