#pragma once
#include<stdint.h>

typedef struct teacher_t *teacher;

teacher teac_create(char fname[20], int teacher_number);

void set_teach_fm(teacher self, char string[20]);
void set_teach_num(teacher self, int id);
char* get_teach_fm(teacher self);
int* get_teach_num(teacher self);
