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
    int flag = check_name_Object(str);
    int flag2 = check_end(str);
    int flag3 = check_argument(str);
    if (flag && flag2 && flag3) {
        double radius = get_radius(str);
        double perimetr = calculate_perimetr_circle(radius);
        double area = calculate_area_circle(radius);
        printf("Perimetr = %lf\nArea = %lf\n", perimetr, area);
    }
    fclose(file);
    return 0;
}
