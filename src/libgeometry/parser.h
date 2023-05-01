#pragma once

#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
double calculate_perimetr_circle(double radius);
double calculate_area_circle(double radius);
int area_calculation(char* str);
void error_isObject(int index);
void error_isArguments(int index);
void error_isEnd(int index);
int check_argument(char* str);
int check_end(char* str);
int check_name_Object(char* str);
int get_radius(char* str);
int get_x_coordinate(char *str);
int get_y_coordinate(char *str);
int intersects_circles(char *first_circle, char *second_circle);