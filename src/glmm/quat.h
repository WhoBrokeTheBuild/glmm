#ifndef GLMM_QUAT_H
#define GLMM_QUAT_H

#include "vec.h"

typedef glmm_vec4f_t glmm_quat_t;
#define glmm_quat_copy glmm_vec4f_copy
#define glmm_quat_eq glmm_vec4f_eq
#define glmm_quat_ne glmm_vec4f_ne
#define glmm_quat_norm glmm_vec4f_norm
#define glmm_quat_xnorm glmm_vec4f_xnorm

static inline void glmm_quat_init(glmm_quat_t this, float value)
{
    this[0] = this[1] = this[2] = value;
    this[3] = 1.0f;
}

static inline void glmm_quat_xcross(glmm_quat_t result, glmm_quat_t this, const glmm_quat_t other)
{
    glmm_quat_t tmp;
    tmp[3] = this[3] * other[3] - this[0] * other[0] - this[1] * other[1] - this[2] * other[2];
    tmp[0] = this[3] * other[0] + this[0] * other[3] + this[1] * other[2] - this[2] * other[1];
    tmp[1] = this[3] * other[1] + this[1] * other[3] + this[2] * other[0] - this[0] * other[2];
    tmp[2] = this[3] * other[2] + this[2] * other[3] + this[0] * other[1] - this[1] * other[0];
    glmm_quat_copy(result, tmp);
}

static inline void glmm_quat_cross(glmm_quat_t this, const glmm_quat_t other)
{
    glmm_quat_xcross(this, this, other);
}

static inline void glmm_quat_print(const glmm_quat_t this)
{
    printf("[ %f, %f, %f, %f ]", this[3], this[0], this[1], this[2]);
}

static inline void glmm_angle_axis(glmm_quat_t result, float angle, glmm_vec3f_t vec)
{
    float s = sinf(angle * 0.5f);

    result[3] = cosf(angle * 0.5f);
    result[0] = vec[0] * s;
    result[1] = vec[1] * s;
    result[2] = vec[2] * s;
}

static inline void glmm_rotate_vec3f_quat(glmm_vec3f_t result, const glmm_vec3f_t vec, const glmm_quat_t quat)
{
    glmm_vec3f_t quatvec = { quat[0], quat[1], quat[2] };
    glmm_vec3f_t tmp, uv, uuv;
    glmm_vec3f_xcross(uv, quatvec, vec);
    glmm_vec3f_xcross(uuv, quatvec, uv);

    glmm_vec3f_xmuls(tmp, uv, quat[3]);
    glmm_vec3f_add(tmp, uuv);
    glmm_vec3f_muls(tmp, 2.0f);
    glmm_vec3f_xadd(result, tmp, vec);
}

#ifndef GLMM_NO_SHORT_DEFINES

#define quat_t glmm_quat_t
#define quat_init glmm_quat_init
#define quat_copy glmm_quat_copy
#define quat_cross glmm_quat_cross
#define quat_xcross glmm_quat_xcross
#define quat_norm glmm_quat_norm
#define quat_xnorm glmm_quat_xnorm
#define quat_print glmm_quat_print

#define angle_axis glmm_angle_axis
#define rotate_vec3f_quat glmm_rotate_vec3f_quat

#endif // GLMM_NO_SHORT_DEFINES

#endif // GLMM_QUAT_H
