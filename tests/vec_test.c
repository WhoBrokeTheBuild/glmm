#include <check.h>
#include <glmm/glmm.h>
#include <stdlib.h>

START_TEST(test_vec2f_init)
{
    glmm_vec2f_t a;
    glmm_vec2f_init(a);

    ck_assert(a[0] == 0);
    ck_assert(a[1] == 0);
}
END_TEST

START_TEST(test_vec2i_init)
{
    glmm_vec2i_t a;
    glmm_vec2i_init(a);

    ck_assert(a[0] == 0);
    ck_assert(a[1] == 0);
}
END_TEST

START_TEST(test_vec2u_init)
{
    glmm_vec2u_t a;
    glmm_vec2u_init(a);

    ck_assert(a[0] == 0);
    ck_assert(a[1] == 0);
}
END_TEST

START_TEST(test_vec2f_eq)
{
    glmm_vec2f_t a, b;
    glmm_vec2f_init(a);
    glmm_vec2f_init(b);

    a[0] = b[0] = 1;
    a[1] = b[1] = 2;

    ck_assert(glmm_vec2f_eq(a, b));

    a[0] = 3;

    ck_assert(!glmm_vec2f_eq(a, b));

    a[0] = 1;
    a[1] = 3;

    ck_assert(!glmm_vec2f_eq(a, b));
}
END_TEST

START_TEST(test_vec2i_eq)
{
    glmm_vec2i_t a, b;
    glmm_vec2i_init(a);
    glmm_vec2i_init(b);

    a[0] = b[0] = 1;
    a[1] = b[1] = 2;

    ck_assert(glmm_vec2i_eq(a, b));

    a[0] = 3;

    ck_assert(!glmm_vec2i_eq(a, b));

    a[0] = 1;
    a[1] = 3;

    ck_assert(!glmm_vec2i_eq(a, b));
}
END_TEST

START_TEST(test_vec2u_eq)
{
    glmm_vec2u_t a, b;
    glmm_vec2u_init(a);
    glmm_vec2u_init(b);

    a[0] = b[0] = 1;
    a[1] = b[1] = 2;

    ck_assert(glmm_vec2u_eq(a, b));

    a[0] = 3;

    ck_assert(!glmm_vec2u_eq(a, b));

    a[0] = 1;
    a[1] = 3;

    ck_assert(!glmm_vec2u_eq(a, b));
}
END_TEST

START_TEST(test_vec2f_add)
{
    glmm_vec2f_t a, b;
    glmm_vec2f_init(a);
    glmm_vec2f_init(b);

    b[0] = 1;
    b[1] = 2;

    glmm_vec2f_add(a, b);

    ck_assert(a[0] == 1);
    ck_assert(a[1] == 2);

    glmm_vec2f_add(b, a);

    ck_assert(b[0] == 2);
    ck_assert(b[1] == 4);
}
END_TEST

START_TEST(test_vec2i_add)
{
    glmm_vec2i_t a, b;
    glmm_vec2i_init(a);
    glmm_vec2i_init(b);

    b[0] = 1;
    b[1] = 2;

    glmm_vec2i_add(a, b);

    ck_assert(a[0] == 1);
    ck_assert(a[1] == 2);

    glmm_vec2i_add(b, a);

    ck_assert(b[0] == 2);
    ck_assert(b[1] == 4);
}
END_TEST

START_TEST(test_vec2u_add)
{
    glmm_vec2u_t a, b;
    glmm_vec2u_init(a);
    glmm_vec2u_init(b);

    b[0] = 1;
    b[1] = 2;

    glmm_vec2u_add(a, b);

    ck_assert(a[0] == 1);
    ck_assert(a[1] == 2);

    glmm_vec2u_add(b, a);

    ck_assert(b[0] == 2);
    ck_assert(b[1] == 4);
}
END_TEST

START_TEST(test_vec2f_sub)
{
    glmm_vec2f_t a, b;
    glmm_vec2f_init(a);
    glmm_vec2f_init(b);

    b[0] = 1;
    b[1] = 2;

    glmm_vec2f_sub(a, b);

    ck_assert(a[0] == -1);
    ck_assert(a[1] == -2);

    glmm_vec2f_sub(b, a);

    ck_assert(b[0] == 2);
    ck_assert(b[1] == 4);
}
END_TEST

START_TEST(test_vec2i_sub)
{
    glmm_vec2i_t a, b;
    glmm_vec2i_init(a);
    glmm_vec2i_init(b);

    b[0] = 1;
    b[1] = 2;

    glmm_vec2i_sub(a, b);

    ck_assert(a[0] == -1);
    ck_assert(a[1] == -2);

    glmm_vec2i_sub(b, a);

    ck_assert(b[0] == 2);
    ck_assert(b[1] == 4);
}
END_TEST

START_TEST(test_vec2u_sub)
{
    glmm_vec2u_t a, b;
    glmm_vec2u_init(a);
    glmm_vec2u_init(b);

    a[0] = 3;
    a[1] = 5;
    b[0] = 1;
    b[1] = 2;

    glmm_vec2u_sub(a, b);

    ck_assert(a[0] == 2);
    ck_assert(a[1] == 3);

    b[0] = 7;
    b[1] = 5;

    glmm_vec2u_sub(b, a);

    ck_assert(b[0] == 5);
    ck_assert(b[1] == 2);
}
END_TEST

Suite *vec2_suite()
{
    Suite *s;
    TCase *tc_float, *tc_int, *tc_uint;

    s = suite_create("vec2");

    tc_float = tcase_create("float");
    tcase_add_test(tc_float, test_vec2f_init);
    tcase_add_test(tc_float, test_vec2f_eq);
    tcase_add_test(tc_float, test_vec2f_add);
    tcase_add_test(tc_float, test_vec2f_sub);
    suite_add_tcase(s, tc_float);

    tc_int = tcase_create("int");
    tcase_add_test(tc_int, test_vec2i_init);
    tcase_add_test(tc_int, test_vec2i_eq);
    tcase_add_test(tc_int, test_vec2i_add);
    tcase_add_test(tc_int, test_vec2i_sub);
    suite_add_tcase(s, tc_int);

    tc_uint = tcase_create("uint");
    tcase_add_test(tc_uint, test_vec2u_init);
    tcase_add_test(tc_uint, test_vec2u_eq);
    tcase_add_test(tc_uint, test_vec2u_add);
    tcase_add_test(tc_uint, test_vec2u_sub);
    suite_add_tcase(s, tc_uint);

    return s;
}

int main(void)
{
    int num_failed;
    Suite *s;
    SRunner *sr;

    s = vec2_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    num_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (num_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
