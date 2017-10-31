#pragma once
#include <stdio.h>
#include "assignment_header.h"
#include "course_header.h"
#include "list_header.h"
#include "enrolment_header.h"
#include "student_header.h"
#include "teacher_header.h"





void add_teacher(char fname[20], int teacher_number);
void add_student(char fname[20], int student_number);
void add_course(int course_number, char cname[20], int semester_number);
void students_print();
void print_all();  
void courses_print();
void teachers_print();

assignment_t find_assignment(int course_number);
student_t find_student(int student_number);
enrolment_t find_enrolment(int course_number);
teacher_t find_teacher(int teacher_number);
course_t find_course(int course_number);

void list_course_by_stud(int student_number);
void list_course_by_teach(int teacher_number);
void list_stud_by_courses(int course_number);
void list_teach_teaching_stud(int student_number);

int enrol_stud(int student_number, int course_number);
int asgnt_teac(int teacher_number, int course_number);
int rmv_stud(int student_number);
int rmv_enrol(int student_number);



