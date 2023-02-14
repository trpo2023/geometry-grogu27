#include <stdio.h>

int main(int argc, char** argv)
{
	//for (int i = 0; i < argc; i++)
		//printf("%s\n", argv[i]);
	int a;
	FILE *file = fopen("data.txt", "r");
	while (fscanf(file, "%d", &a) != EOF)
		printf("%d\n", a);
	return 0;
}
