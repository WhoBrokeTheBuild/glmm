#include <check.h>
#include <glmm/glmm.h>
#include <stdlib.h>

START_TEST(test_vec_set)
{
    {
        glmm_vec2i_t a;
        glmm_vec2i_set(&a, 0);
        ck_assert(a.data[0] == 0);
        ck_assert(a.data[1] == 0);
    }
}
END_TEST

START_TEST(test_vec_initializer_list)
{
    {
        glmm_vec2i_t a = {{ 1, 2 }};
        ck_assert(a.data[0] == 1);
        ck_assert(a.data[1] == 2);
    }
}
END_TEST

START_TEST(test_vec_eq)
{
    {
        int i, j;
        for (i = 0; i < 2; ++i)
        {
            for (j = 0; j < 2; ++j)
            {
                {
                    glmm_vec2i_t a = {{ i, j }};
                    glmm_vec2i_t b = {{ i, j }};
                    ck_assert(glmm_vec2i_eq(&a, &b));
                }
                {
                    glmm_vec2i_t a = {{ 5, j }};
                    glmm_vec2i_t b = {{ j, 5 }};
                    ck_assert(!glmm_vec2i_eq(&a, &b));
                }
            }
        }
    }
}
END_TEST

START_TEST(test_vec_add)
{
    {
        glmm_vec2i_t a = {{ 1, 2 }};
        glmm_vec2i_t b = {{ 2, 3 }};
        glmm_vec2i_add(&a, &b);
        ck_assert(a.data[0] == 1 + 2);
        ck_assert(a.data[1] == 2 + 3);
    }
}
END_TEST

START_TEST(test_vec_adds)
{
    {
        glmm_vec2i_t a = {{ 1, 2 }};
        int b = 2;
        glmm_vec2i_adds(&a, b);
        ck_assert(a.data[0] == 1 + 2);
        ck_assert(a.data[1] == 2 + 2);
    }
}
END_TEST

START_TEST(test_vec_xadd)
{
    {
        glmm_vec2i_t r;
        glmm_vec2i_t a = {{ 1, 2 }};
        glmm_vec2i_t b = {{ 2, 3 }};
        glmm_vec2i_xadd(&r, &a, &b);
        ck_assert(r.data[0] == 1 + 2);
        ck_assert(r.data[1] == 2 + 3);
    }
}
END_TEST

START_TEST(test_vec_xadds)
{
    {
        glmm_vec2i_t r;
        glmm_vec2i_t a = {{ 1, 2 }};
        int b = 2;
        glmm_vec2i_xadds(&r, &a, b);
        ck_assert(r.data[0] == 1 + 2);
        ck_assert(r.data[1] == 2 + 2);
    }
}
END_TEST

START_TEST(test_vec_sub)
{
    {
        glmm_vec2i_t a = {{ 3, 4 }};
        glmm_vec2i_t b = {{ 1, 2 }};
        glmm_vec2i_sub(&a, &b);
        ck_assert(a.data[0] == 3 - 1);
        ck_assert(a.data[1] == 4 - 2);
    }
}
END_TEST

START_TEST(test_vec_subs)
{
    {
        glmm_vec2i_t a = {{ 3, 4 }};
        int b = 2;
        glmm_vec2i_subs(&a, b);
        ck_assert(a.data[0] == 3 - 2);
        ck_assert(a.data[1] == 4 - 2);
    }
}
END_TEST

START_TEST(test_vec_xsub)
{
    {
        glmm_vec2i_t r;
        glmm_vec2i_t a = {{ 3, 4 }};
        glmm_vec2i_t b = {{ 1, 2 }};
        glmm_vec2i_xsub(&r, &a, &b);
        ck_assert(r.data[0] == 3 - 1);
        ck_assert(r.data[1] == 4 - 2);
    }
}
END_TEST

START_TEST(test_vec_xsubs)
{
    {
        glmm_vec2i_t r;
        glmm_vec2i_t a = {{ 3, 4 }};
        int b = 2;
        glmm_vec2i_xsubs(&r, &a, b);
        ck_assert(r.data[0] == 3 - 2);
        ck_assert(r.data[1] == 4 - 2);
    }
}
END_TEST

Suite *vec_suite()
{
    Suite *s;
    TCase *tc_init,
          *tc_comp,
          *tc_ops;

    s = suite_create("vec");

    tc_init = tcase_create("init");
    tcase_add_test(tc_init, test_vec_set);
    tcase_add_test(tc_init, test_vec_initializer_list);
    suite_add_tcase(s, tc_init);

    tc_comp = tcase_create("comp");
    tcase_add_test(tc_comp, test_vec_eq);
    suite_add_tcase(s, tc_comp);

    tc_ops = tcase_create("ops");
    tcase_add_test(tc_ops, test_vec_add);
    tcase_add_test(tc_ops, test_vec_adds);
    tcase_add_test(tc_ops, test_vec_xadd);
    tcase_add_test(tc_ops, test_vec_xadds);
    tcase_add_test(tc_ops, test_vec_sub);
    tcase_add_test(tc_ops, test_vec_subs);
    tcase_add_test(tc_ops, test_vec_xsub);
    tcase_add_test(tc_ops, test_vec_xsubs);
    //tcase_add_test(tc_ops, test_vec_mul);
    //tcase_add_test(tc_ops, test_vec_muls);
    //tcase_add_test(tc_ops, test_vec_xmul);
    //tcase_add_test(tc_ops, test_vec_xmuls);
    //tcase_add_test(tc_ops, test_vec_div);
    //tcase_add_test(tc_ops, test_vec_divs);
    //tcase_add_test(tc_ops, test_vec_xdiv);
    //tcase_add_test(tc_ops, test_vec_xdivs);
    suite_add_tcase(s, tc_ops);

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
