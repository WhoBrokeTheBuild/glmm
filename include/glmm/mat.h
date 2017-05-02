#ifndef GLMM_MAT_H
#define GLMM_MAT_H

#include "vec.h"
#include <math.h> /* for sqrt */
#include <stdbool.h> /* for true, false */
#include <stdio.h> /* for printf */
#include <string.h> /* for memcpy */

#define GLMM_MAT(W, H) \
    GLMM_MAT_IMP(W, H, glmm_mat##W##x##H, glmm_mat##W##x##H##_t)

#define GLMM_MAT_IMP(W, H, PREFIX, MATTYPE)                                 \
                                                                            \
    typedef union {                                                         \
        float data[W][H];                                                   \
        vec##W##f_t cols[W];                                                \
    } MATTYPE;                                                              \
                                                                            \
    static inline void PREFIX##_init(MATTYPE * this, float value)           \
    {                                                                       \
        int i, j;                                                           \
        for (i = 0; i < H; ++i)                                             \
            for (j = 0; j < W; ++j)                                         \
            {                                                               \
                this->data[i][j] = (i == j ? value : 0.0f);                 \
            }                                                               \
    }                                                                       \
                                                                            \
    static inline void PREFIX##_copy(MATTYPE * this, const MATTYPE * other) \
    {                                                                       \
        memcpy(this, other, sizeof(MATTYPE));                               \
    }                                                                       \
                                                                            \
    static inline void PREFIX##_print(MATTYPE * this)                       \
    {                                                                       \
        printf("[\n");                                                      \
        for (int y = 0; y < H; ++y)                                         \
        {                                                                   \
            printf("[ ");                                                   \
            for (int x = 0; x < W; ++x)                                     \
            {                                                               \
                printf("%.3f%s", this->data[y][x], (x == W ? "" : ", "));   \
            }                                                               \
            printf(" ]");                                                   \
        }                                                                   \
        printf("]");                                                        \
    }

GLMM_MAT(2, 2)
GLMM_MAT(3, 3)
GLMM_MAT(4, 4)

static inline void glmm_mat4x4_xmul(glmm_mat4x4_t * result, const glmm_mat4x4_t * this, const glmm_mat4x4_t * other)
{
    int i;
    glmm_mat4x4_t mtmp;
    glmm_vec4f_t vtmp1, vtmp2, vtmp3, vtmp4;

    glmm_mat4x4_init(&mtmp, 0.0f);
    for (i = 0; i < 4; ++i)
    {
        glmm_vec4f_xmuls(&vtmp1, &(this->cols[0]), other->data[i][0]);
        glmm_vec4f_xmuls(&vtmp2, &(this->cols[1]), other->data[i][1]);
        glmm_vec4f_xmuls(&vtmp3, &(this->cols[2]), other->data[i][2]);
        glmm_vec4f_xmuls(&vtmp4, &(this->cols[3]), other->data[i][3]);
        glmm_vec4f_xadd(&mtmp.cols[i], &vtmp1, &vtmp2);
        glmm_vec4f_add(&mtmp.cols[i], &vtmp3);
        glmm_vec4f_add(&mtmp.cols[i], &vtmp4);
    }
    glmm_mat4x4_copy(result, &mtmp);
}

static inline void glmm_mat4x4_mul(glmm_mat4x4_t * this, const glmm_mat4x4_t * other)
{
    glmm_mat4x4_xmul(this, this, other);
}

static inline void glmm_mat4x4_translate(glmm_mat4x4_t * this, const glmm_vec3f_t * vec)
{
    glmm_vec4f_t tmpa, tmpb, tmpc;
    glmm_vec4f_xmuls(&tmpa, &this->cols[0], vec->x);
    glmm_vec4f_xmuls(&tmpb, &this->cols[1], vec->y);
    glmm_vec4f_xmuls(&tmpc, &this->cols[2], vec->z);
    glmm_vec4f_add(&this->cols[3], &tmpa);
    glmm_vec4f_add(&this->cols[3], &tmpb);
    glmm_vec4f_add(&this->cols[3], &tmpc);
}

static inline void glmm_mat4x4_rotate(glmm_mat4x4_t * this, float angle, const glmm_vec3f_t * in_axis)
{
    int i;
    float c, s;
    c = cosf(angle);
    s = sinf(angle);

    glmm_vec3f_t axis;
    glmm_vec3f_xnorm(&axis, in_axis);

    glmm_vec3f_t invaxis;
    glmm_vec3f_xmuls(&invaxis, &axis, (1.0f - c));

    glmm_mat4x4_t rotate;
    glmm_mat4x4_init(&rotate, 0.0f);

    rotate.data[0][0] = c + invaxis.x * axis.x;
    rotate.data[0][1] = invaxis.x * axis.y + s * axis.z;
    rotate.data[0][2] = invaxis.x * axis.z - s * axis.y;

    rotate.data[1][0] = invaxis.y * axis.x - s * axis.z;
    rotate.data[1][1] = c + invaxis.y * axis.y;
    rotate.data[1][2] = invaxis.y * axis.z + s * axis.x;

    rotate.data[2][0] = invaxis.z * axis.x + s * axis.y;
    rotate.data[2][1] = invaxis.z * axis.y - s * axis.x;
    rotate.data[2][2] = c + invaxis.z * axis.z;

    glmm_vec4f_t tmpa, tmpb, tmpc;
    glmm_mat4x4_t result;
    glmm_mat4x4_init(&result, 0.0f);

    for (i = 0; i < 3; ++i)
    {
        glmm_vec4f_xmuls(&tmpa, &this->cols[0], rotate.data[i][0]);
        glmm_vec4f_xmuls(&tmpb, &this->cols[1], rotate.data[i][1]);
        glmm_vec4f_xmuls(&tmpc, &this->cols[2], rotate.data[i][2]);
        glmm_vec4f_xadd(&result.cols[i], &tmpa, &tmpb);
        glmm_vec4f_add(&result.cols[i], &tmpc);
    }
    glmm_vec4f_copy(&result.cols[3], &this->cols[3]);

    glmm_mat4x4_copy(this, &result);
}

static inline void glmm_mat4x4_scale(glmm_mat4x4_t * this, const glmm_vec3f_t * scale)
{
    int i;
    for (i = 0; i < 3; ++i)
    {
        glmm_vec4f_muls(&this->cols[i], scale->data[i]);
    }
}

static inline void glmm_look_at_rh(glmm_mat4x4_t * result, const glmm_vec3f_t * eye, const glmm_vec3f_t * center, const glmm_vec3f_t * up)
{
    glmm_vec3f_t f, s, u;

    glmm_vec3f_xsub(&f, center, eye);
    glmm_vec3f_norm(&f);

    glmm_vec3f_xcross(&s, &f, up);
    glmm_vec3f_norm(&s);

    glmm_vec3f_xcross(&u, &s, &f);

    glmm_mat4x4_init(result, 1.0f);
    result->data[0][0] = s.data[0];
    result->data[1][0] = s.data[1];
    result->data[2][0] = s.data[2];
    result->data[0][1] = u.data[0];
    result->data[1][1] = u.data[1];
    result->data[2][1] = u.data[2];
    result->data[0][2] = -f.data[0];
    result->data[1][2] = -f.data[1];
    result->data[2][2] = -f.data[2];
    result->data[3][0] = -glmm_vec3f_dot(&s, eye);
    result->data[3][1] = -glmm_vec3f_dot(&u, eye);
    result->data[3][2] = glmm_vec3f_dot(&f, eye);
}

static inline void glmm_look_at_lh(glmm_mat4x4_t * result, const glmm_vec3f_t * eye, const glmm_vec3f_t * center, const glmm_vec3f_t * up)
{
    glmm_vec3f_t f, s, u;

    glmm_vec3f_xsub(&f, center, eye);
    glmm_vec3f_norm(&f);

    glmm_vec3f_xcross(&s, up, &f);
    glmm_vec3f_norm(&s);

    glmm_vec3f_xcross(&u, &f, &s);

    glmm_mat4x4_init(result, 1.0f);
    result->data[0][0] = s.data[0];
    result->data[1][0] = s.data[1];
    result->data[2][0] = s.data[2];
    result->data[0][1] = u.data[0];
    result->data[1][1] = u.data[1];
    result->data[2][1] = u.data[2];
    result->data[0][2] = f.data[0];
    result->data[1][2] = f.data[1];
    result->data[2][2] = f.data[2];
    result->data[3][0] = -glmm_vec3f_dot(&s, eye);
    result->data[3][1] = -glmm_vec3f_dot(&u, eye);
    result->data[3][2] = -glmm_vec3f_dot(&f, eye);
}

static inline void glmm_perspective_rh(glmm_mat4x4_t * result, float aspect, float near, float far, float fov)
{
    //CHECK(abs(aspect - EPSILON) > 0, "Bad aspect?")

    float tan_half_fov = tanf(fov * 0.5f);

    glmm_mat4x4_init(result, 0.0f);
    result->data[0][0] = 1.0f / (aspect * tan_half_fov);
    result->data[1][1] = 1.0f / tan_half_fov;
    result->data[2][3] = -1.0f;

    // #if clip space?
    // result[2][2] = far / (near - far);
    // result[3][2] = -(far * near) / (far - near);
    // #else
    result->data[2][2] = -(far + near) / (far - near);
    result->data[3][2] = -(2.0f * far * near) / (far - near);
    // #endif
}

static inline void glmm_perspective_lh(glmm_mat4x4_t * result, float aspect, float near, float far, float fov)
{
    //CHECK(abs(aspect - EPSILON) > 0, "Bad aspect?");

    float tan_half_fov = tanf(fov * 0.5f);

    glmm_mat4x4_init(result, 0.0f);
    result->data[0][0] = 1.0f / (aspect * tan_half_fov);
    result->data[1][1] = 1.0f / tan_half_fov;
    result->data[2][3] = 1.0f;

    // #if clip space?
    // result[2][2] = far / (far - near);
    // result[3][2] = -(far * near) / (far - near);
    // #else
    result->data[2][2] = (far + near) / (far - near);
    result->data[3][2] = -(2.0f * far * near) / (far - near);
    // #endif
}

#if GLMM_COORDINATE_SYSTEM == GLMM_LEFT_HANDED
#define glmm_look_at glmm_look_at_lh
#define glmm_perspective glmm_perspective_lh
#else
#define glmm_look_at glmm_look_at_rh
#define glmm_perspective glmm_perspective_rh
#endif // GLMM_COORDINATE_SYSTEM == GLMM_LEFT_HANDED

#if !defined(GLMM_NO_SHORT_DEFINES)

#define mat2x2_t glmm_mat2x2_t
#define mat2x2_init glmm_mat2x2_init
#define mat2x2_copy glmm_mat2x2_copy
#define mat2x2_print glmm_mat2x2_print

#define mat3x3_t glmm_mat3x3_t
#define mat3x3_init glmm_mat3x3_init
#define mat3x3_copy glmm_mat3x3_copy
#define mat3x3_print glmm_mat3x3_print

#define mat4x4_t glmm_mat4x4_t
#define mat4x4_init glmm_mat4x4_init
#define mat4x4_copy glmm_mat4x4_copy
#define mat4x4_print glmm_mat4x4_print
#define mat4x4_mul glmm_mat4x4_mul
#define mat4x4_xmul glmm_mat4x4_xmul
#define mat4x4_translate glmm_mat4x4_translate
#define mat4x4_rotate glmm_mat4x4_rotate
#define mat4x4_scale glmm_mat4x4_scale

#endif // !defined(GLMM_NO_SHORT_DEFINES)

#endif // GLMM_MAT_H