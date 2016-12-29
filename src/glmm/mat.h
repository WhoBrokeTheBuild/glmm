#ifndef GLMM_MAT_H
#define GLMM_MAT_H

#include "vec.h"
#include <string.h>

#define GLMM_MAT(W, H)                                                                                         \
    typedef glmm_vec##W##f_t glmm_mat##W##x##H##_t[H];                                                         \
                                                                                                               \
    static inline void glmm_mat##W##x##H##_init(glmm_mat##W##x##H##_t this)                                    \
    {                                                                                                          \
        memset(this, 0, sizeof(glmm_mat##W##x##H##_t));                                                        \
    }                                                                                                          \
                                                                                                               \
    static inline void glmm_mat##W##x##H##_eye(glmm_mat##W##x##H##_t this)                                     \
    {                                                                                                          \
        int i, j;                                                                                              \
        for (i = 0; i < H; ++i)                                                                                \
            for (j = 0; j < W; ++j)                                                                            \
            {                                                                                                  \
                this[i][j] = (i == j ? 1.0f : 0.0f);                                                           \
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

static inline void glmm_look_at(glmm_mat4x4_t result, const glmm_vec3f_t eye, const glmm_vec3f_t center, const glmm_vec3f_t up)
{
    float coord_mod;
    glmm_vec3f_t f, s, u;

    glmm_vec3f_sub(f, eye, center);
    glmm_vec3f_norm(f);

#if GLMM_COORDINATE_SYSTEM == GLMM_LEFT_HANDED

    coord_mod = -1.0f;

    glmm_vec3f_cross(s, up, f);
    glmm_vec3f_norm(s);

    glmm_vec3f_cross(u, f, s);

#else // GLMM_RIGHT_HANDED

    coord_mod = 1.0f;

    glmm_vec3f_cross(s, f, up);
    glmm_vec3f_norm(s);

    glmm_vec3f_cross(u, s, f);

#endif // GLMM_COORDINATE_SYSTEM == GLMM_LEFT_HANDED

    glmm_mat4x4_eye(result);
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
    result[3][2] = glmm_vec3f_dot(f, eye) * coord_mod;
}

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

#define look_at glmm_look_at

#endif // GLMM_NO_SHORT_DEFINES

#endif // GLMM_MAT_H
