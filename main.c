#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
int isArguments(char *str)
{
	int res = 1;
	for (int i = 7; str[i] != ')'; i++)
	{
		if ((str[i] >= 48 && str[i] <= 57) || str[i] == '.' || str[i] == ',' || str[i] == ' ')
			res = 0;
		else
		{
			res = 1;
			break;
		}
	}
	return res;
}

<<<<<<< HEAD
int main(int argc, char** argv)
{
	//for (int i = 0; i < argc; i++)
		//printf("%s\n", argv[i]);
	int a;
	FILE *file = fopen("data.txt", "r");
	while (fscanf(file, "%d", &a) != EOF)
		printf("%d\n", a);
	fclose(file);
	return 0;
=======
int isEnd(char *str)
{
	int res = 1;
	int index = 0;
	int endSymbol = strlen(str) - 2;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == ')')
		{
			index = i;
			break;
		}
	}
	if (index  == endSymbol)
	{
		res = 0;
		
	}	
	return res;
}

int isObject(char *str)
{
	int res = 1;
	char rec[100];
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
	
	if (strcmp(rec, figure) == 0)
	{
		res = 0;
	}
	return res;
>>>>>>> 72e5d920cfbc34703fb868db99e2aa25054450aa
}

int main(int argc, char **argv)
{
	setlocale(LC_ALL, " ");
	FILE *file;
	file = fopen("data.txt", "r");
	char str[100];
	fgets(str, 99, file);
	if (isObject(str))
		printf("Ошибка на элементе 0: Неправильный ввод названия объекта\n");
	else if (isArguments(str))
		printf("Ошибка на элементе 7: Неправильно введены данные объекта\n");
	else if (isEnd(str))
		printf("Ошибка на элементе %ld: Неправильный завершающий символ\n", strlen(str) - 1);
	else
		printf("%s\n", str);
	fclose(file);
	return 0;
}