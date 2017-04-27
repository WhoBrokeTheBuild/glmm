#ifndef GLMM_QUAT_H
#define GLMM_QUAT_H

#include "vec.h"

typedef glmm_vec4f_t glmm_quat_t;
#define glmm_quat_copy glmm_vec4f_copy
#define glmm_quat_eq glmm_vec4f_eq
#define glmm_quat_ne glmm_vec4f_ne
#define glmm_quat_norm glmm_vec4f_norm
#define glmm_quat_xnorm glmm_vec4f_xnorm

static inline void glmm_quat_init(glmm_quat_t * this, float value)
{
    this->x = this->y = this->z = value;
    this->w = 1.0f;
}

static inline void glmm_quat_xcross(glmm_quat_t * result, glmm_quat_t * this, const glmm_quat_t * other)
{
    glmm_quat_t * tmp;
    tmp.w = this->w * other->w - this->x * other->x - this->y * other->y - this->z * other->z;
    tmp.x = this->w * other->x + this->x * other->w + this->y * other->z - this->z * other->y;
    tmp.y = this->w * other->y + this->y * other->w + this->z * other->x - this->x * other->z;
    tmp.z = this->w * other->z + this->z * other->w + this->x * other->y - this->y * other->x;
    glmm_quat_copy(result, &tmp);
}

static inline void glmm_quat_cross(glmm_quat_t * this, const glmm_quat_t * other)
{
    glmm_quat_xcross(this, this, other);
}

static inline void glmm_quat_print(const glmm_quat_t * this)
{
    printf("[ %f, %f, %f, %f ]", this[3], this[0], this[1], this[2]);
}

static inline void glmm_angle_axis(glmm_quat_t * result, float angle, glmm_vec3f_t vec)
{
    float s = sinf(angle * 0.5f);

    result[3] = cosf(angle * 0.5f);
    result[0] = vec[0] * s;
    result[1] = vec[1] * s;
    result[2] = vec[2] * s;
}

static inline void glmm_rotate_vec3f_quat(glmm_vec3f_t result, const glmm_vec3f_t vec, const glmm_quat_t * quat)
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

#define quat_t glmm_quat_t *
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
