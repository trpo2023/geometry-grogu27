#include <ctest.h>
#include <libgeometry/parser.h>

CTEST(PARSER_TEST, get_y_coordinate)
{
    char str[] = "circle(5 2, 5)";
    char str2[] = "circle(5       2, 5)";
    int test = get_y_coordinate(str);
    int test2 = get_y_coordinate(str2);
    ASSERT_EQUAL(9, test);
    ASSERT_EQUAL(15, test2);
}

CTEST(PARSER_TEST, get_x_coordinate)
{
    char str[] = "circle(5 2, 5)";
    char str2[] = "circle(       5 2, 5)";
    int test = get_x_coordinate(str);
    int test2 = get_x_coordinate(str2);
    ASSERT_EQUAL(7, test);
    ASSERT_EQUAL(14, test2);
}

CTEST(PARSER_TEST, get_radius)
{
    char str[] = "circle(5 2, 2)";
    char str2[] = "circle(5      2, 7)";
    int test = get_radius(str);
    int test2 = get_radius(str2);
    ASSERT_EQUAL(2, test);
    ASSERT_EQUAL(7, test2);
}

CTEST(PARSER_TEST, calculate_area_circle)
{
    int rad = 2;
    int rad2 = 8;
    int test = calculate_area_circle(rad);
    int test2 = calculate_area_circle(rad2);

    ASSERT_DBL_NEAR_TOL(12.566371, test, 1.0);
    ASSERT_DBL_NEAR_TOL(201.061930, test2, 2.0);
}

CTEST(PARSER_TEST, calculate_perimetr_circle)
{
    int rad = 2;
    int rad2 = 8;
    int test = calculate_perimetr_circle(rad);
    int test2 = calculate_perimetr_circle(rad2);

    ASSERT_DBL_NEAR_TOL(12.566371, test, 1.0);
    ASSERT_DBL_NEAR_TOL(50.265482, test2, 2.0);
}

CTEST(PARSER_TEST, check_argument)
{
    char a[] = "circle(6 3, 8)";
    char b[] = "circle(6a 3, 8)";
    int test = check_argument(a);
    int test2 = check_argument(b);
    ASSERT_EQUAL(1, test);
    ASSERT_EQUAL(0, test2);
}

CTEST(PARSER_TEST, check_end)
{
    char str[] = "circle(6 3, 8)";
    char str2[] = "circle(6 3,   8)";
    int test = check_end(str);
    int test2 = check_end(str2);
    ASSERT_EQUAL(1, test);
    ASSERT_EQUAL(1, test2);
}

CTEST(PARSER_TEST, check_name_Object)
{
    char a[] = "circle(6 3, 8)";
    char b[] = "ircle(6 3, 8)";
    int test = check_name_Object(a);
    int test2 = check_name_Object(b);
    ASSERT_EQUAL(1, test);
    ASSERT_EQUAL(0, test2);
}
