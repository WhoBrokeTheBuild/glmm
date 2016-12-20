#include <check.h>
#include <glmm/glmm.h>
#include <stdlib.h>

START_TEST(test_vec2_init)
{
    glmm_vec2 a;
    glmm_vec2_init(&a);

    ck_assert(a.x == 0);
    ck_assert(a.y == 0);
}
END_TEST

START_TEST(test_vec2i_init)
{
    glmm_vec2i a;
    glmm_vec2i_init(&a);

    ck_assert(a.x == 0);
    ck_assert(a.y == 0);
}
END_TEST

START_TEST(test_vec2u_init)
{
    glmm_vec2u a;
    glmm_vec2u_init(&a);

    ck_assert(a.x == 0);
    ck_assert(a.y == 0);
}
END_TEST

START_TEST(test_vec2_eq)
{
    glmm_vec2 a, b;
    glmm_vec2_init(&a);
    glmm_vec2_init(&b);

    a.x = b.x = 1;
    a.y = b.y = 2;

    ck_assert(glmm_vec2_eq(&a, &b));

    a.x = 3;

    ck_assert(!glmm_vec2_eq(&a, &b));

    a.x = 1;
    a.y = 3;

    ck_assert(!glmm_vec2_eq(&a, &b));
}
END_TEST

START_TEST(test_vec2i_eq)
{
    glmm_vec2i a, b;
    glmm_vec2i_init(&a);
    glmm_vec2i_init(&b);

    a.x = b.x = 1;
    a.y = b.y = 2;

    ck_assert(glmm_vec2i_eq(&a, &b));

    a.x = 3;

    ck_assert(!glmm_vec2i_eq(&a, &b));

    a.x = 1;
    a.y = 3;

    ck_assert(!glmm_vec2i_eq(&a, &b));
}
END_TEST

START_TEST(test_vec2u_eq)
{
    glmm_vec2u a, b;
    glmm_vec2u_init(&a);
    glmm_vec2u_init(&b);

    a.x = b.x = 1;
    a.y = b.y = 2;

    ck_assert(glmm_vec2u_eq(&a, &b));

    a.x = 3;

    ck_assert(!glmm_vec2u_eq(&a, &b));

    a.x = 1;
    a.y = 3;

    ck_assert(!glmm_vec2u_eq(&a, &b));
}
END_TEST

START_TEST(test_vec2_add)
{
    glmm_vec2 a, b;
    glmm_vec2_init(&a);
    glmm_vec2_init(&b);

    b.x = 1;
    b.y = 2;

    glmm_vec2_add(&a, &b);

    ck_assert(a.x == 1);
    ck_assert(a.y == 2);

    glmm_vec2_add(&b, &a);

    ck_assert(b.x == 2);
    ck_assert(b.y == 4);
}
END_TEST

START_TEST(test_vec2i_add)
{
    glmm_vec2i a, b;
    glmm_vec2i_init(&a);
    glmm_vec2i_init(&b);

    b.x = 1;
    b.y = 2;

    glmm_vec2i_add(&a, &b);

    ck_assert(a.x == 1);
    ck_assert(a.y == 2);

    glmm_vec2i_add(&b, &a);

    ck_assert(b.x == 2);
    ck_assert(b.y == 4);
}
END_TEST

START_TEST(test_vec2u_add)
{
    glmm_vec2u a, b;
    glmm_vec2u_init(&a);
    glmm_vec2u_init(&b);

    b.x = 1;
    b.y = 2;

    glmm_vec2u_add(&a, &b);

    ck_assert(a.x == 1);
    ck_assert(a.y == 2);

    glmm_vec2u_add(&b, &a);

    ck_assert(b.x == 2);
    ck_assert(b.y == 4);
}
END_TEST

START_TEST(test_vec2_sub)
{
    glmm_vec2 a, b;
    glmm_vec2_init(&a);
    glmm_vec2_init(&b);

    b.x = 1;
    b.y = 2;

    glmm_vec2_sub(&a, &b);

    ck_assert(a.x == -1);
    ck_assert(a.y == -2);

    glmm_vec2_sub(&b, &a);

    ck_assert(b.x == 2);
    ck_assert(b.y == 4);
}
END_TEST

START_TEST(test_vec2i_sub)
{
    glmm_vec2i a, b;
    glmm_vec2i_init(&a);
    glmm_vec2i_init(&b);

    b.x = 1;
    b.y = 2;

    glmm_vec2i_sub(&a, &b);

    ck_assert(a.x == -1);
    ck_assert(a.y == -2);

    glmm_vec2i_sub(&b, &a);

    ck_assert(b.x == 2);
    ck_assert(b.y == 4);
}
END_TEST

START_TEST(test_vec2u_sub)
{
    glmm_vec2u a, b;
    glmm_vec2u_init(&a);
    glmm_vec2u_init(&b);

    a.x = 3;
    a.y = 5;
    b.x = 1;
    b.y = 2;

    glmm_vec2u_sub(&a, &b);

    ck_assert(a.x == 2);
    ck_assert(a.y == 3);

    b.x = 7;
    b.y = 5;

    glmm_vec2u_sub(&b, &a);

    ck_assert(b.x == 5);
    ck_assert(b.y == 2);
}
END_TEST

Suite *vec2_suite()
{
    Suite *s;
    TCase *tc_float, *tc_int, *tc_uint;

    s = suite_create("vec2");

    tc_float = tcase_create("float");
    tcase_add_test(tc_float, test_vec2_init);
    tcase_add_test(tc_float, test_vec2_eq);
    tcase_add_test(tc_float, test_vec2_add);
    tcase_add_test(tc_float, test_vec2_sub);
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
