
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PI 3.14159265358979323846
#include <libgeometry/parser.h>

void error_isObject(int index)
{
    printf("Ошибка на элементе %d: Неправильный ввод названия объекта\n",
           index);
}

void error_isArguments(int index)
{
    printf("Ошибка на элементе %d: Неправильно введены данные объекта\n",
           index);
}

void error_isEnd(int index)
{
    printf("Ошибка на элементе %d: Неправильный завершающий символ\n", index);
}

double get_radius(char* str)
{
    int radius;

    for (int i = strlen(str); str[i] != '('; i--)
        if (str[i] >= 48 && str[i] <= 57) {
            radius = atoi(&str[i]);

            break;
        }
    return radius;
}
double calculate_area_circle(double radius)
{
    double area = PI * (radius * radius);
    return area;
}

double calculate_perimetr_circle(double radius)
{
    double perimetr = 2 * PI * radius;
    return perimetr;
}

int check_argument(char* str)
{
    int error = 0;
    int target;
    size_t index;
    for (size_t i = 0; i < strlen(str); i++)
        if (str[i] == '(') {
            index = i;
            break;
        }
    for (size_t i = index + 1; str[i] != ')'; i++) {
        if ((str[i] >= 48 && str[i] <= 57) || str[i] == '.' || str[i] == ','
            || str[i] == ' ')
            error = 0;
        else {
            error = 1;
            target = i;
            break;
        }
    }
    if (error) {
        error_isArguments(target);
        return 0;
    } else
        return 1;
}

int check_end(char* str)
{
    int error = 0;
    int index;
    int target;
    int endSymbol = strlen(str) - 2;
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] == ')') {
            index = i;
            break;
        }
    }
    if (index != endSymbol)
        error = 1;

    target = endSymbol;
    if (error) {
        error_isEnd(target);
        return 0;
    } else
        return 1;
}

int check_name_Object(char* str)
{
    int error = 0;
    char rec[100];
    int target;
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] != '(')
            rec[i] = str[i];
        else
            break;
    }
    char figure[] = "circle";

    for (size_t i = 0; i < strlen(rec); i++) {
        rec[i] = tolower(rec[i]);
    }

    if ((strcmp(figure, rec) != 0))
        for (size_t i = 0; str[i] != '('; i++)
            if (figure[i] != rec[i]) {
                target = i;
                error = 1;
                break;
            }

    if (error) {
        error_isObject(target);
        return 0;
    } else
        return 1;
}
