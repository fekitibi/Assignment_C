#include "assignment_header.h"
#include <string.h>
struct assignment {

	int teacher_ID;

	int course_ID;
};


assignment_t create_assignment(int teacher_no, int course_no)
{
	assignment_t assignment = (assignment_t)malloc(sizeof(struct assignment));
	assignment->teacher_ID = teacher_no;
	assignment->course_ID = course_no;

	return assignment;
}


void set_teach_num_asgmt(assignment_t self, int id)
{
	self->teacher_ID = id;
}

int* get_teach_num_asgmt(assignment_t self)
{
	return self->teacher_ID;
}

void set_course_num_asgmt(assignment_t self, int id)
{
	self->course_ID = id;
}

int* get_course_num_asgmt(assignment_t self)
{
	return self->course_ID;
}