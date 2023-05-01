#include <stdio.h>

#include <libgeometry/parser.h>

int main()
{
    setlocale(LC_ALL, " ");
    FILE* file;
    file = fopen("../input/data.txt", "r");
    if (!file)
        return -1;
    char str[100];
    int first_circle[3];
    int second_circle[3];
    int count = 1;
    while (fgets(str, 99, file))
    {
        printf("%s\n", str);
        int flag = check_name_Object(str);
        int flag2 = check_end(str);
        int flag3 = check_argument(str);
        if (flag && flag2 && flag3) {
            int radius = get_radius(str);
            double perimetr = calculate_perimetr_circle(radius);
            double area = calculate_area_circle(radius);
            printf("Perimetr = %lf\nArea = %lf\n\n", perimetr, area);
            int x_coordinate = get_x_coordinate(str);
            int y_coordinate = get_y_coordinate(str);
            printf("x_coordinate = %d y_coordinate = %d\n", x_coordinate, y_coordinate);
            int x = atoi(&str[x_coordinate]);
            int y = atoi(&str[y_coordinate]);
            printf("x = %d y = %d\n", x, y);
            printf("Radius = %d\n", radius);
            printf("\n\n");
            if (count == 1)
            {
                first_circle[0] = x;
                first_circle[1] = y;
                first_circle[2] = radius;
            }
            else if (count == 2)
            {
                second_circle[0] = x;
                second_circle[1] = y;
                second_circle[2] = radius;
            }
            }
            int check = intersects_circles(first_circle, second_circle);
            count++;
            if(check)
                printf("Окружности пересекаются\n");
            else
                printf("Окружности не пересекаются\n");
    }


    // printf("x = %d y = %d rad = %d\n", first_circle[0], first_circle[1], first_circle[2]);
    // printf("x = %d y = %d rad = %d\n", second_circle[0], second_circle[1], second_circle[2]);

    fclose(file);
    return 0;
}
