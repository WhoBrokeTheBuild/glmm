#ifndef GLMM_QUAT_H
#define GLMM_QUAT_H

#include "vec.h"

typedef glmm_vec4f_t glmm_quat_t;
#define glmm_quat_eq glmm_vec4f_eq
#define glmm_quat_copy glmm_vec4f_copy
#define glmm_quat_norm glmm_vec4f_norm

static inline void glmm_quat_cross(glmm_quat_t this, const glmm_quat_t a, const glmm_quat_t b)
{
    glmm_quat_t tmp;
    tmp[3] = a[3] * b[3] - a[0] * b[0] - a[1] * b[1] - a[2] * b[2];
    tmp[0] = a[3] * b[0] + a[0] * b[3] + a[1] * b[2] - a[2] * b[1];
    tmp[1] = a[3] * b[1] + a[1] * b[3] + a[2] * b[0] - a[0] * b[2];
    tmp[2] = a[3] * b[2] + a[2] * b[3] + a[0] * b[1] - a[1] * b[0];
    glmm_quat_copy(this, tmp);
}

static inline void glmm_quat_init(glmm_quat_t this)
{
    this[0] = this[1] = this[2] = 0.0f;
    this[3] = 1.0f;
}

static inline void glmm_quat_angle_axis(glmm_quat_t result, float angle, vec3f_t vec)
{
    float s = sinf(angle * 0.5f);

    result[3] = cosf(angle * 0.5f);
    result[0] = vec[0] * s;
    result[1] = vec[1] * s;
    result[2] = vec[2] * s;
}

static inline void glmm_vec3f_rotate_by_quat(glmm_vec3f_t result, glmm_vec3f_t v, glmm_quat_t q)
{
    glmm_vec3f_t quat_v = { q[0], q[1], q[2] };
    glmm_vec3f_t tmp, uv, uuv;
    glmm_vec3f_xcross(uv, quat_v, v);
    glmm_vec3f_xcross(uuv, quat_v, uv);

    glmm_vec3f_xmuls(tmp, uv, q[3]);
    glmm_vec3f_add(tmp, uuv);
    glmm_vec3f_muls(tmp, 2.0f);
    glmm_vec3f_xadd(result, tmp, v);
}

static inline void glmm_quat_print(const glmm_quat_t this)
{
    printf("[ %f, %f, %f, %f ]", this[3], this[0], this[1], this[2]);
}

#ifndef GLMM_NO_SHORT_DEFINES

#define quat_t glmm_quat_t
#define quat_init glmm_quat_init
#define quat_copy glmm_quat_copy
#define quat_cross glmm_quat_cross
#define quat_norm glmm_quat_norm
#define quat_angle_axis glmm_quat_angle_axis
#define vec3f_rotate_by_quat glmm_vec3f_rotate_by_quat
#define quat_print glmm_quat_print

#endif // GLMM_NO_SHORT_DEFINES

#endif // GLMM_QUAT_H
