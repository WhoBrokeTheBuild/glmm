#ifndef GLMM_MAT_H
#define GLMM_MAT_H

#include "vec.h"
#include <string.h>

#define GLMM_MAT(W, H)                                                                                         \
    typedef glmm_vec##W##f_t glmm_mat##W##x##H##_t[H];                                                         \
                                                                                                               \
    static inline void glmm_mat##W##x##H##_init(glmm_mat##W##x##H##_t this, float value)                       \
    {                                                                                                          \
        int i, j;                                                                                              \
        for (i = 0; i < H; ++i)                                                                                \
            for (j = 0; j < W; ++j)                                                                            \
            {                                                                                                  \
                this[i][j] = (i == j ? value : 0.0f);                                                          \
            }                                                                                                  \
    }                                                                                                          \
                                                                                                               \
    static inline void glmm_mat##W##x##H##_copy(glmm_mat##W##x##H##_t this, const glmm_mat##W##x##H##_t other) \
    {                                                                                                          \
        int i;                                                                                                 \
        for (i = 0; i < H; ++i)                                                                                \
        {                                                                                                      \
            glmm_vec##W##f_copy(this[i], other[i]);                                                            \
        }                                                                                                      \
    }                                                                                                          \
                                                                                                               \
    static inline void glmm_mat##W##x##H##_print(glmm_mat##W##x##H##_t this)                                   \
    {                                                                                                          \
        int i;                                                                                                 \
        printf("[ ");                                                                                          \
        for (i = 0; i < H; ++i)                                                                                \
        {                                                                                                      \
            glmm_vec##W##f_print(this[i]);                                                                     \
            if (i != H - 1)                                                                                    \
                printf(", ");                                                                                  \
        }                                                                                                      \
        printf(" ]");                                                                                          \
    }

GLMM_MAT(2, 2);
GLMM_MAT(3, 3);
GLMM_MAT(4, 4);

static inline void glmm_mat4x4_mul(glmm_mat4x4_t result, const glmm_mat4x4_t left, const glmm_mat4x4_t right)
{
    int i;
    glmm_mat4x4_t mat;
    glmm_vec4f_t tmp1, tmp2, tmp3, tmp4;

    glmm_mat4x4_init(mat, 0.0f);
    for (i = 0; i < 4; ++i)
    {
        glmm_vec4f_mul_scalar(tmp1, left[0], right[i][0]);
        glmm_vec4f_mul_scalar(tmp2, left[1], right[i][1]);
        glmm_vec4f_mul_scalar(tmp3, left[2], right[i][2]);
        glmm_vec4f_mul_scalar(tmp4, left[3], right[i][3]);
        glmm_vec4f_add(tmp1, tmp1, tmp2);
        glmm_vec4f_add(tmp1, tmp1, tmp3);
        glmm_vec4f_add(tmp1, tmp1, tmp4);
        glmm_vec4f_copy(mat[i], tmp1);
    }
    glmm_mat4x4_copy(result, mat);
}

static inline void glmm_mat4x4_translate(glmm_mat4x4_t this, const glmm_vec3f_t vec)
{
    int i;
    glmm_vec4f_t tmp;
    glmm_vec4f_init(tmp, 0.0f);
    for (i = 0; i < 3; ++i)
    {
        tmp[0] += this[i][0] * vec[i];
        tmp[1] += this[i][1] * vec[i];
        tmp[2] += this[i][2] * vec[i];
        tmp[3] += this[i][3];
    }

    glmm_vec4f_copy(this[3], tmp);
}

static inline void glmm_mat4x4_rotate(glmm_mat4x4_t this, float angle, const glmm_vec3f_t axis)
{
    int i;
    float c, s;
    c = cosf(angle);
    s = sinf(angle);

    glmm_vec3f_t naxis;
    glmm_vec3f_copy(naxis, axis);
    glmm_vec3f_norm(naxis);

    glmm_vec3f_t tmp;
    glmm_vec3f_mul_scalar(tmp, tmp, (1.0f - c));

    glmm_mat4x4_t rotate;
    glmm_mat4x4_init(rotate, 0.0f);

    rotate[0][0] = c + tmp[0] * axis[0];
    rotate[0][1] = tmp[0] * axis[1] + s * axis[2];
    rotate[0][2] = tmp[0] * axis[2] - s * axis[1];

    rotate[1][0] = tmp[1] * axis[0] - s * axis[2];
    rotate[1][1] = c + tmp[1] * axis[1];
    rotate[1][2] = tmp[1] * axis[2] + s * axis[0];

    rotate[2][0] = tmp[2] * axis[0] + s * axis[1];
    rotate[2][1] = tmp[2] * axis[1] - s * axis[0];
    rotate[2][2] = c + tmp[2] * axis[2];

    glmm_mat4x4_t result;
    glmm_mat4x4_init(result, 0.0f);

    for (i = 0; i < 3; ++i) 
    {
        glmm_vec4f_mul_scalar(result[i], this[0], rotate[i][0]);
        glmm_vec4f_mul_scalar(tmp, this[1], rotate[i][1]);
        glmm_vec4f_add(result[i], result[i], tmp);
        glmm_vec4f_mul_scalar(tmp, this[2], rotate[i][2]);
        glmm_vec4f_add(result[i], result[i], tmp);
    }
    glmm_vec4f_copy(result[3], this[3]);

    glmm_mat4x4_copy(this, result);
}

static inline void glmm_look_at_rh(glmm_mat4x4_t result, const glmm_vec3f_t eye, const glmm_vec3f_t center, const glmm_vec3f_t up)
{
    glmm_vec3f_t f, s, u;

    glmm_vec3f_sub(f, center, eye);
    glmm_vec3f_norm(f);

    glmm_vec3f_cross(s, f, up);
    glmm_vec3f_norm(s);

    glmm_vec3f_cross(u, s, f);

    glmm_mat4x4_init(result, 1.0f);
    result[0][0] = s[0];
    result[1][0] = s[1];
    result[2][0] = s[2];
    result[0][1] = u[0];
    result[1][1] = u[1];
    result[2][1] = u[2];
    result[0][2] = -f[0];
    result[1][2] = -f[1];
    result[2][2] = -f[2];
    result[3][0] = -glmm_vec3f_dot(s, eye);
    result[3][1] = -glmm_vec3f_dot(u, eye);
    result[3][2] = glmm_vec3f_dot(f, eye);
}

static inline void glmm_look_at_lh(glmm_mat4x4_t result, const glmm_vec3f_t eye, const glmm_vec3f_t center, const glmm_vec3f_t up)
{
    glmm_vec3f_t f, s, u;

    glmm_vec3f_sub(f, center, eye);
    glmm_vec3f_norm(f);

    glmm_vec3f_cross(s, up, f);
    glmm_vec3f_norm(s);

    glmm_vec3f_cross(u, f, s);

    glmm_mat4x4_init(result, 1.0f);
    result[0][0] = s[0];
    result[1][0] = s[1];
    result[2][0] = s[2];
    result[0][1] = u[0];
    result[1][1] = u[1];
    result[2][1] = u[2];
    result[0][2] = f[0];
    result[1][2] = f[1];
    result[2][2] = f[2];
    result[3][0] = -glmm_vec3f_dot(s, eye);
    result[3][1] = -glmm_vec3f_dot(u, eye);
    result[3][2] = -glmm_vec3f_dot(f, eye);
}

static inline void glmm_perspective_rh(glmm_mat4x4_t result, float aspect, float near, float far, float fov)
{
    //CHECK(abs(aspect - EPSILON) > 0, "Bad aspect?")

    float tan_half_fov = tanf(fov * 0.5f);

    glmm_mat4x4_init(result, 0.0f);
    result[0][0] = 1.0f / (aspect * tan_half_fov);
    result[1][1] = 1.0f / tan_half_fov;
    result[2][3] = -1.0f;

    // #if clip space?
    // result[2][2] = far / (near - far);
    // result[3][2] = -(far * near) / (far - near);
    // #else
    result[2][2] = -(far + near) / (far - near);
    result[3][2] = -(2.0f * far * near) / (far - near);
    // #endif
}

static inline void glmm_perspective_lh(glmm_mat4x4_t result, float aspect, float near, float far, float fov)
{
    //CHECK(abs(aspect - EPSILON) > 0, "Bad aspect?");

    float tan_half_fov = tanf(fov * 0.5f);

    glmm_mat4x4_init(result, 0.0f);
    result[0][0] = 1.0f / (aspect * tan_half_fov);
    result[1][1] = 1.0f / tan_half_fov;
    result[2][3] = 1.0f;

    // #if clip space?
    // result[2][2] = far / (far - near);
    // result[3][2] = -(far * near) / (far - near);
    // #else
    result[2][2] = (far + near) / (far - near);
    result[3][2] = -(2.0f * far * near) / (far - near);
    // #endif
}

#if GLMM_COORDINATE_SYSTEM == GLMM_LEFT_HANDED
#define glmm_look_at glmm_look_at_lh
#define glmm_perspective glmm_perspective_lh
#else
#define glmm_look_at glmm_look_at_rh
#define glmm_perspective glmm_perspective_rh
#endif // GLMM_COORDINATE_SYSTEM == GLMM_LEFT_HANDED

#ifndef GLMM_NO_SHORT_DEFINES

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
#define mat4x4_translate glmm_mat4x4_translate
#define mat4x4_rotate glmm_mat4x4_rotate

#endif // GLMM_NO_SHORT_DEFINES

#endif // GLMM_MAT_H
