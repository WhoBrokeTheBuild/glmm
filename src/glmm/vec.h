#ifndef GLMM_VEC_H
#define GLMM_VEC_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define GLMM_VEC(N, ID, TYPE, FMT)                                                                                                         \
    typedef TYPE glmm_vec##N##ID##_t[N];                                                                                                   \
                                                                                                                                           \
    static inline void glmm_vec##N##ID##_init(glmm_vec##N##ID##_t this, TYPE value)                                                        \
    {                                                                                                                                      \
        int i;                                                                                                                             \
        for (i = 0; i < N; ++i)                                                                                                            \
            this[i] = value;                                                                                                               \
    }                                                                                                                                      \
                                                                                                                                           \
    static inline bool glmm_vec##N##ID##_eq(const glmm_vec##N##ID##_t left, const glmm_vec##N##ID##_t right)                               \
    {                                                                                                                                      \
        int i;                                                                                                                             \
        for (i = 0; i < N; ++i)                                                                                                            \
            if (left[i] != right[i])                                                                                                       \
                return false;                                                                                                              \
        return true;                                                                                                                       \
    }                                                                                                                                      \
                                                                                                                                           \
    static inline void glmm_vec##N##ID##_add(glmm_vec##N##ID##_t result, const glmm_vec##N##ID##_t left, const glmm_vec##N##ID##_t right)  \
    {                                                                                                                                      \
        int i;                                                                                                                             \
        for (i = 0; i < N; ++i)                                                                                                            \
            result[i] = left[i] + right[i];                                                                                                \
    }                                                                                                                                      \
                                                                                                                                           \
    static inline void glmm_vec##N##ID##_sub(glmm_vec##N##ID##_t result, const glmm_vec##N##ID##_t left, const glmm_vec##N##ID##_t right)  \
    {                                                                                                                                      \
        int i;                                                                                                                             \
        for (i = 0; i < N; ++i)                                                                                                            \
            result[i] = left[i] - right[i];                                                                                                \
    }                                                                                                                                      \
                                                                                                                                           \
    static inline void glmm_vec##N##ID##_mul(glmm_vec##N##ID##_t result, const glmm_vec##N##ID##_t left, const glmm_vec##N##ID##_t right) \
    {                                                                                                                                      \
        int i;                                                                                                                             \
        for (i = 0; i < N; ++i)                                                                                                            \
            result[i] = left[i] * right[i];                                                                                                \
    }                                                                                                                                      \
                                                                                                                                           \
    static inline void glmm_vec##N##ID##_mul_scalar(glmm_vec##N##ID##_t result, const glmm_vec##N##ID##_t left, TYPE right)                \
    {                                                                                                                                      \
        int i;                                                                                                                             \
        for (i = 0; i < N; ++i)                                                                                                            \
            result[i] = left[i] * right;                                                                                                   \
    }                                                                                                                                      \
                                                                                                                                           \
    static inline void glmm_vec##N##ID##_copy(glmm_vec##N##ID##_t this, const glmm_vec##N##ID##_t other)                                   \
    {                                                                                                                                      \
        int i;                                                                                                                             \
        for (i = 0; i < N; ++i)                                                                                                            \
            this[i] = other[i];                                                                                                            \
    }                                                                                                                                      \
                                                                                                                                           \
    static inline TYPE glmm_vec##N##ID##_len(glmm_vec##N##ID##_t this)                                                                     \
    {                                                                                                                                      \
        int i;                                                                                                                             \
        TYPE sum = 0;                                                                                                                      \
        for (i = 0; i < N; ++i)                                                                                                            \
            sum += this[i] * this[i];                                                                                                      \
                                                                                                                                           \
        return sqrt(sum);                                                                                                                  \
    }                                                                                                                                      \
                                                                                                                                           \
    static inline void glmm_vec##N##ID##_norm(glmm_vec##N##ID##_t this)                                                                    \
    {                                                                                                                                      \
        int i;                                                                                                                             \
        TYPE len = glmm_vec##N##ID##_len(this);                                                                                            \
        for (i = 0; i < N; ++i)                                                                                                            \
            this[i] = this[i] / len;                                                                                                       \
    }                                                                                                                                      \
                                                                                                                                           \
    static inline TYPE glmm_vec##N##ID##_dot(const glmm_vec##N##ID##_t left, const glmm_vec##N##ID##_t right)                              \
    {                                                                                                                                      \
        TYPE result = 0;                                                                                                                   \
        int i = 0;                                                                                                                         \
        for (i = 0; i < N; ++i)                                                                                                            \
        {                                                                                                                                  \
            result += left[i] * right[i];                                                                                                  \
        }                                                                                                                                  \
        return result;                                                                                                                     \
    }                                                                                                                                      \
                                                                                                                                           \
    static inline void glmm_vec##N##ID##_print(const glmm_vec##N##ID##_t this)                                                             \
    {                                                                                                                                      \
        printf("[ ");                                                                                                                      \
        int i;                                                                                                                             \
        for (i = 0; i < N; ++i)                                                                                                            \
        {                                                                                                                                  \
            printf(FMT, this[i]);                                                                                                          \
            if (i != N - 1)                                                                                                                \
                printf(", ");                                                                                                              \
        }                                                                                                                                  \
        printf(" ]");                                                                                                                      \
    }

GLMM_VEC(2, f, float, "%f");
GLMM_VEC(2, i, int, "%d");
GLMM_VEC(2, u, unsigned int, "%u");

GLMM_VEC(3, f, float, "%f");
GLMM_VEC(3, i, int, "%d");
GLMM_VEC(3, u, unsigned int, "%u");

GLMM_VEC(4, f, float, "%f");
GLMM_VEC(4, i, int, "%d");
GLMM_VEC(4, u, unsigned int, "%u");

#define GLMM_VEC3_SPECIAL(ID)                                                                                              \
    static inline void glmm_vec3##ID##_cross(glmm_vec3##ID##_t this, const glmm_vec3##ID##_t a, const glmm_vec3##ID##_t b) \
    {                                                                                                                      \
        this[0] = a[1] * b[2] - a[2] * b[1];                                                                               \
        this[1] = a[2] * b[0] - a[0] * b[2];                                                                               \
        this[2] = a[0] * b[1] - a[1] * b[0];                                                                               \
    }

GLMM_VEC3_SPECIAL(f);
GLMM_VEC3_SPECIAL(i);
GLMM_VEC3_SPECIAL(u);

#define GLMM_VEC4_SPECIAL(ID)                                                                                              \
    static inline void glmm_vec4##ID##_cross(glmm_vec4##ID##_t this, const glmm_vec4##ID##_t a, const glmm_vec4##ID##_t b) \
    {                                                                                                                      \
        this[0] = a[1] * b[2] - a[2] * b[1];                                                                               \
        this[1] = a[2] * b[0] - a[0] * b[2];                                                                               \
        this[2] = a[0] * b[1] - a[1] * b[0];                                                                               \
        this[3] = 1;                                                                                                       \
    }

GLMM_VEC4_SPECIAL(f);
GLMM_VEC4_SPECIAL(i);
GLMM_VEC4_SPECIAL(u);

#ifndef GLMM_NO_SHORT_DEFINES

#define vec2f_t glmm_vec2f_t
#define vec2f_init glmm_vec2f_init
#define vec2f_eq glmm_vec2f_init
#define vec2f_add glmm_vec2f_add
#define vec2f_sub glmm_vec2f_sub
#define vec2f_mul glmm_vec2f_mul
#define vec2f_mul_scalar glmm_vec2f_mul_scalar
#define vec2f_copy glmm_vec2f_copy
#define vec2f_set glmm_vec2f_set
#define vec2f_dot glmm_vec2f_dot
#define vec2f_print glmm_vec2f_print

#define vec2i_t glmm_vec2i_t
#define vec2i_init glmm_vec2i_init
#define vec2i_eq glmm_vec2i_init
#define vec2i_add glmm_vec2i_add
#define vec2i_sub glmm_vec2i_sub
#define vec2i_mul glmm_vec2i_mul
#define vec2i_mul_scalar glmm_vec2i_mul_scalar
#define vec2i_copy glmm_vec2i_copy
#define vec2i_set glmm_vec2i_set
#define vec2i_dot glmm_vec2i_dot
#define vec2i_print glmm_vec2i_print

#define vec2u_t glmm_vec2u_t
#define vec2u_init glmm_vec2u_init
#define vec2u_eq glmm_vec2u_init
#define vec2u_add glmm_vec2u_add
#define vec2u_sub glmm_vec2u_sub
#define vec2u_mul glmm_vec2u_mul
#define vec2u_mul_scalar glmm_vec2u_mul_scalar
#define vec2u_copy glmm_vec2u_copy
#define vec2u_set glmm_vec2u_set
#define vec2u_dot glmm_vec2u_dot
#define vec2u_print glmm_vec2u_print

#define vec3f_t glmm_vec3f_t
#define vec3f_init glmm_vec3f_init
#define vec3f_eq glmm_vec3f_init
#define vec3f_add glmm_vec3f_add
#define vec3f_sub glmm_vec3f_sub
#define vec3f_mul glmm_vec3f_mul
#define vec3f_mul_scalar glmm_vec3f_mul_scalar
#define vec3f_copy glmm_vec3f_copy
#define vec3f_set glmm_vec3f_set
#define vec3f_dot glmm_vec3f_dot
#define vec3f_print glmm_vec3f_print
#define vec3f_cross glmm_vec3f_cross

#define vec3i_t glmm_vec3i_t
#define vec3i_init glmm_vec3i_init
#define vec3i_eq glmm_vec3i_init
#define vec3i_add glmm_vec3i_add
#define vec3i_sub glmm_vec3i_sub
#define vec3i_mul glmm_vec3i_mul
#define vec3i_mul_scalar glmm_vec3i_mul_scalar
#define vec3i_copy glmm_vec3i_copy
#define vec3i_set glmm_vec3i_set
#define vec3i_dot glmm_vec3i_dot
#define vec3i_print glmm_vec3i_print
#define vec3i_cross glmm_vec3i_cross

#define vec3u_t glmm_vec3u_t
#define vec3u_init glmm_vec3u_init
#define vec3u_eq glmm_vec3u_init
#define vec3u_add glmm_vec3u_add
#define vec3u_sub glmm_vec3u_sub
#define vec3u_mul glmm_vec3u_mul
#define vec3u_mul_scalar glmm_vec3u_mul_scalar
#define vec3u_copy glmm_vec3u_copy
#define vec3u_set glmm_vec3u_set
#define vec3u_dot glmm_vec3u_dot
#define vec3u_print glmm_vec3u_print
#define vec3u_cross glmm_vec3u_cross

#define vec4f_t glmm_vec4f_t
#define vec4f_init glmm_vec4f_init
#define vec4f_eq glmm_vec4f_init
#define vec4f_add glmm_vec4f_add
#define vec4f_sub glmm_vec4f_sub
#define vec4f_mul glmm_vec4f_mul
#define vec4f_mul_scalar glmm_vec4f_mul_scalar
#define vec4f_copy glmm_vec4f_copy
#define vec4f_set glmm_vec4f_set
#define vec4f_dot glmm_vec4f_dot
#define vec4f_print glmm_vec4f_print
#define vec4f_cross glmm_vec4f_cross

#define vec4i_t glmm_vec4i_t
#define vec4i_init glmm_vec4i_init
#define vec4i_eq glmm_vec4i_init
#define vec4i_add glmm_vec4i_add
#define vec4i_sub glmm_vec4i_sub
#define vec4i_mul glmm_vec4i_mul
#define vec4i_mul_scalar glmm_vec4i_mul_scalar
#define vec4i_copy glmm_vec4i_copy
#define vec4i_set glmm_vec4i_set
#define vec4i_dot glmm_vec4i_dot
#define vec4i_print glmm_vec4i_print
#define vec4i_cross glmm_vec4i_cross

#define vec4u_t glmm_vec4u_t
#define vec4u_init glmm_vec4u_init
#define vec4u_eq glmm_vec4u_init
#define vec4u_add glmm_vec4u_add
#define vec4u_sub glmm_vec4u_sub
#define vec4u_mul glmm_vec4u_mul
#define vec4u_mul_scalar glmm_vec4u_mul_scalar
#define vec4u_copy glmm_vec4u_copy
#define vec4u_set glmm_vec4u_set
#define vec4u_dot glmm_vec4u_dot
#define vec4u_print glmm_vec4u_print
#define vec4u_cross glmm_vec4u_cross

#endif // GLMM_NO_SHORT_DEFINES

#endif // GLMM_VEC_H
