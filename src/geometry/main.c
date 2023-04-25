#include <stdio.h>

#include <libgeometry/parser.h>

int main()
{
    setlocale(LC_ALL, " ");
    FILE* file;
    file = fopen("../input/data.txt", "r");
    if (!file)
		return 0;
    char str[100];
    fgets(str, 99, file);
    printf("%s\n", str);
    check_name_Object(str);
    check_end(str);
    int flag = check_argument(str);
    if (flag) {
        double perimetr = calculate_perimetr_circle(str);
        double area = calculate_area_circle(str);
        printf("Perimetr = %lf\nArea = %lf\n", perimetr, area);
    }
    fclose(file);
    return 0;
}
