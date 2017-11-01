#include "list_header.h"
#include "teacher_header.h"
#include "course_header.h"
#include "student_header.h"
#include "dbs_header.h"
#include <stdio.h>

void main() {

	list_alloc();

	add_student("Ivan", 123456);
	add_student("Georgi", 654321);

	add_teacher("Jesper", 123456);
	add_teacher("Ole", 123457);
	add_teacher("Lars", 123458);
	add_teacher("Erland", 123459);

	add_course(31, "CALI1", 3);
	add_course(11, "WDDI1", 1);
	add_course(21, "SDJI2", 2);


	print_all(); 

	enrol_student(123456, 31);
	enrol_student(123456, 11);
	enrol_student(654321, 21);

	assign_teacher(123456, 31);
	assign_teacher(123457, 11);

	list_courses_by_student(123456);
	list_courses_by_teacher(123456);
	list_students_by_courses(21);
	list_teachers_teaching_student(123456);




	while (1);

}