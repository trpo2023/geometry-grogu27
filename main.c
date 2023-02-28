#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>
int isArguments(char* str)
{
    int res = 1;
    int a;
    for (int i = 7; str[i] != ')'; i++) {
        if ((str[i] >= 48 && str[i] <= 57) || str[i] == '.' || str[i] == ',' || str[i] == ' ')
            
            res = 0;
        else {
            res = 1;
            a = i;
            break;
        }
    }
    
    return res;
}

int isEnd(char* str)
{
    int res = 1;
    int a;
    int index = 0;
    int endSymbol = strlen(str) - 2;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ')') {
            index = i;
            break;
        }
    }
    if (index == endSymbol) {
        res = 0;
    }
    return res;
}

int isObject(char* str)
{
    int res = 1;
    int a;
    char rec[100];
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != '(')
            rec[i] = str[i];
        else
            break;
    }
    char figure[] = "circle";

    for (int i = 0; i < strlen(rec); i++) {
        rec[i] = tolower(rec[i]);
    }

    if (strcmp(rec, figure) == 0) {
        res = 0;
    }
    
    return res;
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, " ");
    FILE* file;
			
    file = fopen("data.txt", "r");
    char str[100];
    fgets(str, 99, file);
    if (isObject(str))
        printf("%s\nНеправильный ввод названия объекта\n", str);
    else if (isArguments(str))
        printf("%s\nНеправильно введены данные объекта\n", str);
    else if (isEnd(str))
        printf("%s\nНеправильный завершающий символ\n",str);
               
    else
        printf("%s\n", str);
    fclose(file);
    return 0;
}
