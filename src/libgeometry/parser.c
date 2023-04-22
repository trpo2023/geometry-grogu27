#include <libgeometry/parser.h>

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


// void calculate_circle(Circle circle)
// {
// 	circle.r = 5;
//     circle->perimetr = 2 * 3.14 * circle.r;
//     circle->area = 3.14 * circle.r * circle.r;
// }


double calculate_area_circle(char *str)
{
	int radius;
	double area;
	for (int i = strlen(str); str[i] != '('; i--)
		if (str[i] >= 48 && str[i] <= 57)
		{
			radius = atoi(&str[i]);
			area = 3.14 * (radius * radius);
			break;
		}
	return area;
}
double calculate_perimetr_circle(char *str)
{
	int radius;
	double perimetr;
	for (int i = strlen(str); str[i] != '('; i--)
		if (str[i] >= 48 && str[i] <= 57)
		{
			radius = atoi(&str[i]);
			perimetr = 2 * 3.14 * radius;
			break;
		}
	return perimetr;
	

}
int check_argument(char *str)
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
	{
		error_isArguments(target);
		return 0;
	}
	else
		return 1;
	
}

void check_end(char *str)
{
	int res = 1;
	int index;
	int target;
	int endSymbol = strlen(str) - 2;
	for (size_t i = 0; i < strlen(str); i++)
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

void check_name_Object(char *str)
{
	int res = 0;
	char rec[100];
	int target;
	for (size_t i = 0; i < strlen(str); i++)
	{
		if (str[i] != '(')
			rec[i] = str[i];
		else
			break;
	}
	char figure[] = "circle";
	
	for (size_t i = 0; i < strlen(rec); i++)
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
}	
