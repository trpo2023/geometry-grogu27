#include <libgeometry/parser.h>

int main()
{

	setlocale(LC_ALL, " ");
	FILE *file;
	file = fopen("../data/data.txt", "r");
	if (!file){
		printf("Файл не открылся\n");
		return 0;
	}
	char str[100];
	fgets(str, 99, file);
	printf("%s\n", str);	
	isObject(str);
	isArguments(str);
	isEnd(str);
	fclose(file);
	return 0;
}
