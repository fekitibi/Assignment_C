#pragma once
#include<stdint.h>

typedef struct teacher *teacher_t;

teacher_t teac_create(char fname[20], int teacher_number);

void set_teach_fm(teacher_t self, char string[20]);
void set_teach_num(teacher_t self, int id);
char* get_teach_fm(teacher_t self);
int* get_teach_num(teacher_t self);
