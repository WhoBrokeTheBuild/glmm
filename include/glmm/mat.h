#ifndef GLMM_MAT_H
#define GLMM_MAT_H

#include "vec.h"
#include <string.h>
/*
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

static inline void glmm_mat4x4_xmul(glmm_mat4x4_t result, const glmm_mat4x4_t this, const glmm_mat4x4_t other)
{
    int i;
    glmm_mat4x4_t mtmp;
    glmm_vec4f_t vtmp1, vtmp2, vtmp3, vtmp4;

    glmm_mat4x4_init(mtmp, 0.0f);
    for (i = 0; i < 4; ++i)
    {
        glmm_vec4f_xmuls(vtmp1, this[0], other[i][0]);
        glmm_vec4f_xmuls(vtmp2, this[1], other[i][1]);
        glmm_vec4f_xmuls(vtmp3, this[2], other[i][2]);
        glmm_vec4f_xmuls(vtmp4, this[3], other[i][3]);
        glmm_vec4f_xadd(mtmp[i], vtmp1, vtmp2);
        glmm_vec4f_add(mtmp[i], vtmp3);
        glmm_vec4f_add(mtmp[i], vtmp4);
    }
    glmm_mat4x4_copy(result, mtmp);
}

static inline void glmm_mat4x4_mul(glmm_mat4x4_t this, const glmm_mat4x4_t other)
{
    glmm_mat4x4_xmul(this, this, other);
}

static inline void glmm_mat4x4_translate(glmm_mat4x4_t this, const glmm_vec3f_t vec)
{
    glmm_vec4f_t tmpa, tmpb, tmpc;
    glmm_vec4f_xmuls(tmpa, this[0], vec[0]);
    glmm_vec4f_xmuls(tmpb, this[1], vec[1]);
    glmm_vec4f_xmuls(tmpc, this[2], vec[2]);
    glmm_vec4f_add(this[3], tmpa);
    glmm_vec4f_add(this[3], tmpb);
    glmm_vec4f_add(this[3], tmpc);
}

static inline void glmm_mat4x4_rotate(glmm_mat4x4_t this, float angle, const glmm_vec3f_t in_axis)
{
    int i;
    float c, s;
    c = cosf(angle);
    s = sinf(angle);

    glmm_vec3f_t axis;
    glmm_vec3f_xnorm(axis, in_axis);

    glmm_vec3f_t invaxis;
    glmm_vec3f_xmuls(invaxis, axis, (1.0f - c));

    glmm_mat4x4_t rotate;
    glmm_mat4x4_init(rotate, 0.0f);

    rotate[0][0] = c + invaxis[0] * axis[0];
    rotate[0][1] = invaxis[0] * axis[1] + s * axis[2];
    rotate[0][2] = invaxis[0] * axis[2] - s * axis[1];

    rotate[1][0] = invaxis[1] * axis[0] - s * axis[2];
    rotate[1][1] = c + invaxis[1] * axis[1];
    rotate[1][2] = invaxis[1] * axis[2] + s * axis[0];

    rotate[2][0] = invaxis[2] * axis[0] + s * axis[1];
    rotate[2][1] = invaxis[2] * axis[1] - s * axis[0];
    rotate[2][2] = c + invaxis[2] * axis[2];

    glmm_vec4f_t tmpa, tmpb, tmpc;
    glmm_mat4x4_t result;
    glmm_mat4x4_init(result, 0.0f);

    for (i = 0; i < 3; ++i)
    {
        glmm_vec4f_xmuls(tmpa, this[0], rotate[i][0]);
        glmm_vec4f_xmuls(tmpb, this[1], rotate[i][1]);
        glmm_vec4f_xmuls(tmpc, this[2], rotate[i][2]);
        glmm_vec4f_xadd(result[i], tmpa, tmpb);
        glmm_vec4f_add(result[i], tmpc);
    }
    glmm_vec4f_copy(result[3], this[3]);

    glmm_mat4x4_copy(this, result);
}

static inline void glmm_mat4x4_scale(glmm_mat4x4_t this, const glmm_vec3f_t scale)
{
    int i;
    for (i = 0; i < 3; ++i)
    {
        glmm_vec4f_muls(this[i], scale[i]);
    }
}

static inline void glmm_look_at_rh(glmm_mat4x4_t result, const glmm_vec3f_t eye, const glmm_vec3f_t center, const glmm_vec3f_t up)
{
    glmm_vec3f_t f, s, u;

    glmm_vec3f_xsub(f, center, eye);
    glmm_vec3f_norm(f);

    glmm_vec3f_xcross(s, f, up);
    glmm_vec3f_norm(s);

    glmm_vec3f_xcross(u, s, f);

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

    glmm_vec3f_xsub(f, center, eye);
    glmm_vec3f_norm(f);

    glmm_vec3f_xcross(s, up, f);
    glmm_vec3f_norm(s);

    glmm_vec3f_xcross(u, f, s);

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
#define mat4x4_xmul glmm_mat4x4_xmul
#define mat4x4_translate glmm_mat4x4_translate
#define mat4x4_rotate glmm_mat4x4_rotate
#define mat4x4_scale glmm_mat4x4_scale

#endif // GLMM_NO_SHORT_DEFINES
*/
#endif // GLMM_MAT_H
