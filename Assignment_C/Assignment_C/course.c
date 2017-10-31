#include"course_header.h"
#include <string.h>
#include "student_header.h"

struct course {

	int course_ID;

	char course_name[20];

	int semester_ID;
};


course_t course_create(int course_number, char cname[20], int semester_number)
{
	course_t course = (course_t)malloc(sizeof(struct course));


	strcpy_s(course->course_name, 20, cname);
	course->course_ID = course_number;
	course->semester_ID = semester_number;

	return course;
}

void set_course_name(course_t self, char string[20])
{
	strcpy_s(self->course_name, 20, string);

}

char* get_course_name(course_t self)
{

	return self->course_name;
}

void set_course_num(course_t self, int id)
{
	self->course_ID = id;
}

int* get_course_num(course_t self)
{
	return self->course_ID;
}

void set_course_sem(course_t self, int id)
{
	self->semester_ID = id;
}

int* get_course_sem(course_t self)
{
	return self->semester_ID;
}