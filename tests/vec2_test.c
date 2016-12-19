#include <glmm/glmm.h>
#include <stdlib.h>
#include <check.h>

START_TEST(test_vec2_init)
{
    glmm_vec2 a;
    glmm_vec2_init(&a);

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

Suite* vec2_suite()
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("vec2");

    tc_core = tcase_create("core");

    tcase_add_test(tc_core, test_vec2_init);
    tcase_add_test(tc_core, test_vec2_eq);
    tcase_add_test(tc_core, test_vec2_add);
    tcase_add_test(tc_core, test_vec2_sub);
    suite_add_tcase(s, tc_core);

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
