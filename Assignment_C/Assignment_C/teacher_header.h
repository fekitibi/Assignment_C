#pragma once
#include<stdint.h>

typedef struct teacher *teacher_t;

teacher_t teach_create(char fname[20], int teacher_num);

void set_teach_fn(teacher_t self, char string[20]);
char* get_teach_fn(teacher_t self);
void set_teach_num(teacher_t self, int id);
int* get_teach_num(teacher_t self);
