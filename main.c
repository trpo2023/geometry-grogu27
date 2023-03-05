#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>
void error_isObject(int index)
{
	printf("Ошибка на элементе %d: Неправильный ввод названия объекта\n", index);
}
void error_isArguments(int index)
{
	printf("Ошибка на элементе %d: Неправильно введены данные объекта\n", index);
}
void error_isEnd(int index)
{
	printf("Ошибка на элементе %d: Неправильный завершающий символ\n", index);
}
void isArguments(char *str)
{
	int res = 1;
	int target;
	for (int i = 7; str[i] != ')'; i++)
	{
		if ((str[i] >= 48 && str[i] <= 57) || str[i] == '.' || str[i] == ',' || str[i] == ' ')
			res = 0;
		else
		{
			res = 1;
			target = i;
			break;
		}
	}
	if (res)
		error_isArguments(target);
	
}

void isEnd(char *str)
{
	int res = 1;
	int index;
	int target;
	int endSymbol = strlen(str) - 2;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == ')')
		{
			index = i;
			break;
		}
	}
	if (index == endSymbol)
	{
		res = 0;
		
	}
	target = endSymbol;
	if (res)
		error_isEnd(target);
	
}

void isObject(char *str)
{
	int res = 0;
	char rec[100];
	int target;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] != '(')
			rec[i] = str[i];
		else
			break;
	}
	char figure[] = "circle";
	
	for (int i = 0; i < strlen(rec); i++)
	{
		rec[i] = tolower(rec[i]);
	}
	
	if (strcmp(rec, figure) )
	
	
		for (int i = 0; str[i] != '('; i++)
		{
			if (rec[i] != figure[i])
			{
				target = i;
				res = 1;
			}
				
		}
	
	if (res)
		error_isObject(target);
	


int main(int argc, char** argv)
{

	setlocale(LC_ALL, " ");
	FILE *file;
	file = fopen("data.txt", "r");
	char str[100];
	fgets(str, 99, file);
	printf("%s\n", str);	
	isObject(str);
	isArguments(str);
	isEnd(str);
	fclose(file);
	return 0;
}
