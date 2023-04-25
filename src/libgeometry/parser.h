#pragma once

#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double calculate_perimetr_circle(char* str);
double calculate_area_circle(char* str);
int area_calculation(char* str);
void error_isObject(int index);
void error_isArguments(int index);
void error_isEnd(int index);
int check_argument(char* str);
int check_end(char* str);
int check_name_Object(char* str);
