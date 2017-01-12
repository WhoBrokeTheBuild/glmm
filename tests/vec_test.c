#include <check.h>
#include <glmm/glmm.h>
#include <stdlib.h>

START_TEST(test_vec2_init)
{
    glmm_vec2i_t a;
    glmm_vec2i_init(a, 0);

    ck_assert(a[0] == 0);
    ck_assert(a[1] == 0);
}
END_TEST

START_TEST(test_vec2_eq)
{
    glmm_vec2i_t a, b;
    glmm_vec2i_init(a, 0);
    glmm_vec2i_init(b, 0);

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

START_TEST(test_vec2_add)
{
    glmm_vec2i_t a, b;
    glmm_vec2i_init(a, 0);
    glmm_vec2i_init(b, 0);

    b[0] = 1;
    b[1] = 2;

    glmm_vec2i_add(a, a, b);

    ck_assert(a[0] == 1);
    ck_assert(a[1] == 2);

    glmm_vec2i_add(b, b, a);

    ck_assert(b[0] == 2);
    ck_assert(b[1] == 4);
}
END_TEST

START_TEST(test_vec2_sub)
{
    glmm_vec2i_t a, b;
    glmm_vec2i_init(a, 0);
    glmm_vec2i_init(b, 0);

    b[0] = 1;
    b[1] = 2;

    glmm_vec2i_sub(a, a, b);

    ck_assert(a[0] == -1);
    ck_assert(a[1] == -2);

    glmm_vec2i_sub(b, b, a);

    ck_assert(b[0] == 2);
    ck_assert(b[1] == 4);
}
END_TEST

Suite *vec_suite()
{
    Suite *s;
    TCase *tc_vec2, *tc_vec3, *tc_vec4;

    s = suite_create("vec");

    tc_vec2 = tcase_create("vec2");
    tcase_add_test(tc_vec2, test_vec2_init);
    tcase_add_test(tc_vec2, test_vec2_eq);
    tcase_add_test(tc_vec2, test_vec2_add);
    tcase_add_test(tc_vec2, test_vec2_sub);
    suite_add_tcase(s, tc_vec2);

    return s;
}

int main(void)
{
    int num_failed;
    Suite *s;
    SRunner *sr;

    s = vec_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    num_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (num_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
