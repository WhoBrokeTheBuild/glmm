#include <check.h>
#include <glmm/glmm.h>
#include <stdlib.h>

START_TEST(test_angle_axis)
{
    {
        glmm_vec3f_t v = { 1.0f, 0.0f, 0.0f };
        glmm_vec3f_t u = { 0.0f, 1.0f, 0.0f };
        glmm_quat_t q;
        float angle;
        glmm_angle_axis(q, v, u);
        // angle = glmm_quat_angle(q);
        // ck_assert(GLMM_ABS(angle - GLMM_PI * 0.5f) >= GLMM_EPSILON);
    }
}
END_TEST

Suite *vec_suite()
{
    Suite *s;
    TCase *tc_rotate;

    s = suite_create("quat");

    tc_rotate = tcase_create("rotation");
    tcase_add_test(tc_init, test_angle_axis);
    suite_add_tcase(s, tc_rotate);

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
