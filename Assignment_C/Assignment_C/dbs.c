#include "list_header.h"
#include "student_header.h"
#include <stdio.h>
#include "teacher_header.h"
#include "course_header.h"
#include "dbs_header.h"
#include "enrolment_header.h"
#include "assignment_header.h"


list_t students_list;
list_t teachers_list;
list_t courses_list;
list_t enrolments_list;
list_t assignments_list;



void list_alloc(void)
{
	students_list = list_create();
	teachers_list = list_create();
	courses_list = list_create();
	enrolments_list = list_create();
	assignments_list = list_create();
}


void add_student(char fname[20], int student_number)
{


	add_item(students_list, student_create(fname, student_number));

}

void add_teacher(char fname[20], int teacher_number)
{
	add_item(teachers_list, teacher_create(fname, teacher_number));

}

void add_course(int course_number, char cname[20], int semester_number)
{
	add_item(courses_list, course_create(course_number, cname, semester_number));

}

void students_print()
{
	printf("\n################Students################\n");
	for (size_t i = 1; i <= no_of_items(students_list); i++)
	{

		printf("%s : %d\n", get_student_firstname(get_item(students_list, i)), get_student_number(get_item(students_list, i)));


	}

}

void teachers_print()
{
	printf("################Teachers################\n");
	for (size_t i = 1; i <= no_of_items(teachers_list); i++)
	{

		printf("%s : %d\n", get_teacher_firstname(get_item(teachers_list, i)), get_teacher_number(get_item(teachers_list, i)));

	}

}

void courses_print()
{
	printf("################courses################\n");
	for (size_t i = 1; i <= no_of_items(courses_list); i++)
	{

		printf("%d : %s : %d\n", get_course_number(get_item(courses_list, i)), get_course_name(get_item(courses_list, i)), get_course_semester(get_item(courses_list, i)));

	}

}

void print_all()
{
	students_print();
	teachers_print();
	courses_print();

}




student_t find_student(int student_number)
{

	student_t student = NULL;

	for (size_t i = 1; i <= no_of_items(students_list); i++)
	{
		if (student_number == get_student_number(get_item(students_list, i)))
		{
			student = get_item(students_list, i);
		}
	}


	return student;
}

teacher_t find_teacher(int teacher_number)
{
	teacher_t teacher = NULL;

	for (size_t i = 1; i <= no_of_items(teachers_list); i++)
	{
		if (teacher_number == get_teacher_number(get_item(teachers_list, i)))
		{
			teacher = get_item(teachers_list, i);
		}
	}


	return teacher;
}

enrolment_t find_enrolment(int course_number)
{
	enrolment_t enrolment = NULL;
	for (size_t i = 1; i <= no_of_items(enrolments_list); i++)
	{
		if (course_number == get_course_number_enrolment(get_item(enrolments_list, i)))
		{
			enrolment = get_item(enrolments_list, i);
		}
	}

	return enrolment;
}

assignment_t find_assignment(int course_number)
{
	assignment_t assignment = NULL;
	for (size_t i = 1; i <= no_of_items(assignments_list); i++)
	{
		if (course_number == get_course_number_assignment(get_item(assignments_list, i)))
		{
			assignment = get_item(assignments_list, i);
		}
	}

	return assignment;
}



course_t find_course(int course_number)
{
	course_t course = NULL;
	for (size_t i = 1; i <= no_of_items(courses_list); i++)
	{
		if (course_number == get_course_number(get_item(courses_list, i)))
		{
			course = get_item(courses_list, i);
		}
	}


	return course;

}

int enrol_stud(int student_number, int course_number)
{
	int result = -1;
	if (find_student(student_number) == NULL)
	{
		printf("\nStudent Not found in database!");
	}
	else
		if (find_course(course_number) == NULL)
		{
			printf("\nCourse not found in database!");
		}
		else
		{
			add_item(enrolments_list, enrolment_create(student_number, course_number));
			printf("\nStudent:%s enrolled to the course:%s successfully!", get_student_firstname(find_student(student_number)), get_course_name(find_course(course_number)));

			result = 0;
		}



	return result;

}


int asgnt_teach(int teacher_number, int course_number)
{
	int result = -1;

	if (find_teacher(teacher_number) == NULL)
	{
		printf("\nTeacher not found in database!");
	}
	else
		if (find_course(course_number) == NULL)
		{
			printf("\nCourse Not found in database!");
		}
		else
		{
			add_item(assignments_list, assignment_create(teacher_number, course_number));
			printf("\nTeacher:%s assigned to course:%s successfully!", get_teacher_firstname(find_teacher(teacher_number)), get_course_name(find_course(course_number)));

			result = 0;
		}
	return result;

}



void list_course_by_stud(int student_number)
{
	int empty = -1;
	printf("\n################courses the student enrolled in################\n");

	for (size_t i = 1; i <= no_of_items(enrolments_list); i++)
	{
		if (get_student_number_enrolment(get_item(enrolments_list, i)) == student_number)
		{
			printf("%d : %s : %d\n", get_course_number_enrolment(get_item(enrolments_list, i)), get_course_name(find_course(get_course_number_enrolment(get_item(enrolments_list, i)))), get_course_semester(find_course(get_course_number_enrolment(get_item(enrolments_list, i)))));
			empty = 0;
		}
	}
	if (empty == -1)
	{
		printf("\nThe student is NOT enrolled to any courses!\n");
	}
}


void list_course_by_teach(int teacher_number)
{
	int empty = -1;
	printf("\n-################courses the teacher teaches################\n");
	for (size_t i = 1; i <= no_of_items(assignments_list); i++)
	{
		if (get_teacher_number_assignment(get_item(assignments_list, i)) == teacher_number)
		{
			printf("%d : %s : %d\n", get_course_number_assignment(get_item(assignments_list, i)), get_course_name(find_course(get_course_number_assignment(get_item(assignments_list, i)))), get_course_semester(find_course(get_course_number_assignment(get_item(assignments_list, i)))));
			empty = 0;
		}
	}
	if (empty == -1)
	{
		printf("\nThe teacher is NOT assigned to any courses!\n");
	}
}



void list_stud_by_courses(int course_number)
{
	int empty = -1;


	if (find_enrolment(course_number) != NULL)
	{

		printf("\n################students enrolled in the course################\n");
		for (size_t i = 1; i <= no_of_items(students_list); i++)
		{

			if (get_student_number(get_item(students_list, i)) == get_student_number_enrolment(find_enrolment(course_number)))
			{
				printf("%s : %d\n", get_student_firstname(get_item(students_list, i)), get_student_number(get_item(students_list, i)));
				empty = 0;
			}
		}
		if (empty == -1)
		{
			printf("\nThere are no students enrolled to the course!\n");
		}
	}
	else
	{
		printf("\ncourse NOT found!\n");
	}

}



void list_teach_teaching_stud(int student_number)
{
	int empty = -1;
	int teacher_number = NULL;

	if (find_student(student_number) != NULL)
	{

		printf("\n################teachers that are teaching the student################\n");
		for (size_t i = 1; i <= no_of_items(enrolments_list); i++)
		{

			if (student_number == get_student_number_enrolment(get_item(enrolments_list, i)))
			{
				if (find_assignment(get_course_number_enrolment(get_item(enrolments_list, i))) != NULL)
				{

					teacher_number = get_teacher_number_assignment(find_assignment(get_course_number_enrolment(get_item(enrolments_list, i))));

					printf("%s : %d\n", get_teacher_firstname(find_teacher(teacher_number)), teacher_number);
				}
				else
				{
					printf("\nNo teachers teaching the student!\n");
				}
			}
		}
	}
	else
	{
		printf("\nstudent NOT found!\n");
	}

}


int rmv_stud(int student_number)
{
	int result = 0;


	if (find_student(student_number) != NULL)
	{
		if (remove_item(students_list, find_student(student_number)) == 0 && remove_enrolment(student_number) == 1)
		{
			result = 1;
		}
	}

	return result;
}

int rmv_enrol(int student_number)
{
	int result = 0;

	for (size_t i = 1; i <= no_of_items(enrolments_list); i++)
	{
		if (student_number == get_student_number_enrolment(get_item(enrolments_list, i)))
		{
			if (remove_item(enrolments_list, get_item(enrolments_list, i)) == 0)
			{
				result = 1;
			}
		}
	}

	return result;

}