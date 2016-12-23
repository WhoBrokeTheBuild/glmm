#ifndef GLMM_VEC_H
#define GLMM_VEC_H

#include <stdbool.h>
#include <stdio.h>

#define GLMM_VEC(N, ID, TYPE, FMT)                                                                   \
    typedef TYPE glmm_vec##N##ID[N];                                                                 \
                                                                                                     \
    static inline void glmm_vec##N##ID##_init(glmm_vec##N##ID this)                                  \
    {                                                                                                \
        int i;                                                                                       \
        for (i = 0; i < N; ++i)                                                                      \
            this[i] = 0;                                                                             \
    }                                                                                                \
                                                                                                     \
    static inline bool glmm_vec##N##ID##_eq(const glmm_vec##N##ID this, const glmm_vec##N##ID other) \
    {                                                                                                \
        int i;                                                                                       \
        for (i = 0; i < N; ++i)                                                                      \
            if (this[i] != other[i])                                                                 \
                return false;                                                                        \
        return true;                                                                                 \
    }                                                                                                \
                                                                                                     \
    static inline void glmm_vec##N##ID##_add(glmm_vec##N##ID this, const glmm_vec##N##ID other)      \
    {                                                                                                \
        int i;                                                                                       \
        for (i = 0; i < N; ++i)                                                                      \
            this[i] += other[i];                                                                     \
    }                                                                                                \
                                                                                                     \
    static inline void glmm_vec##N##ID##_sub(glmm_vec##N##ID this, const glmm_vec##N##ID other)      \
    {                                                                                                \
        int i;                                                                                       \
        for (i = 0; i < N; ++i)                                                                      \
            this[i] -= other[i];                                                                     \
    }                                                                                                \
                                                                                                     \
    static inline void glmm_vec##N##ID##_print(const glmm_vec##N##ID this)                           \
    {                                                                                                \
        printf("[ ");                                                                                \
        int i;                                                                                       \
        for (i = 0; i < N; ++i)                                                                      \
        {                                                                                            \
            printf(FMT, this[i]);                                                                    \
            if (i != N - 1)                                                                          \
                printf(", ");                                                                        \
        }                                                                                            \
        printf(" ]");                                                                                \
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

#define GLMM_VEC3_SPECIAL(ID)                                                                                  \
    static inline void glmm_vec3##ID##_cross(glmm_vec3##ID this, const glmm_vec3##ID a, const glmm_vec3##ID b) \
    {                                                                                                          \
        this[0] = a[1] * b[2] - a[2] * b[1];                                                                   \
        this[1] = a[2] * b[0] - a[0] * b[2];                                                                   \
        this[2] = a[0] * b[1] - a[1] * b[0];                                                                   \
    }

GLMM_VEC3_SPECIAL(f);
GLMM_VEC3_SPECIAL(i);
GLMM_VEC3_SPECIAL(u);

#define GLMM_VEC4_SPECIAL(ID)                                                                                  \
    static inline void glmm_vec4##ID##_cross(glmm_vec4##ID this, const glmm_vec4##ID a, const glmm_vec4##ID b) \
    {                                                                                                          \
        this[0] = a[1] * b[2] - a[2] * b[1];                                                                   \
        this[1] = a[2] * b[0] - a[0] * b[2];                                                                   \
        this[2] = a[0] * b[1] - a[1] * b[0];                                                                   \
        this[3] = 1;                                                                                           \
    }

GLMM_VEC4_SPECIAL(f);
GLMM_VEC4_SPECIAL(i);
GLMM_VEC4_SPECIAL(u);

#ifndef GLMM_NO_SHORT_DEFINES

#define vec2f glmm_vec2f
#define vec2f_init glmm_vec2f_init
#define vec2f_eq glmm_vec2f_init
#define vec2f_add glmm_vec2f_add
#define vec2f_sub glmm_vec2f_sub
#define vec2f_print glmm_vec2f_print

#define vec2i glmm_vec2i
#define vec2i_init glmm_vec2i_init
#define vec2i_eq glmm_vec2i_init
#define vec2i_add glmm_vec2i_add
#define vec2i_sub glmm_vec2i_sub
#define vec2i_print glmm_vec2i_print

#define vec2u glmm_vec2u
#define vec2u_init glmm_vec2u_init
#define vec2u_eq glmm_vec2u_init
#define vec2u_add glmm_vec2u_add
#define vec2u_sub glmm_vec2u_sub
#define vec2u_print glmm_vec2u_print

#define vec3f glmm_vec3f
#define vec3f_init glmm_vec3f_init
#define vec3f_eq glmm_vec3f_init
#define vec3f_add glmm_vec3f_add
#define vec3f_sub glmm_vec3f_sub
#define vec3f_print glmm_vec3f_print
#define vec3f_cross glmm_vec3_cross

#define vec3i glmm_vec3i
#define vec3i_init glmm_vec3i_init
#define vec3i_eq glmm_vec3i_init
#define vec3i_add glmm_vec3i_add
#define vec3i_sub glmm_vec3i_sub
#define vec3i_print glmm_vec3i_print
#define vec3i_cross glmm_vec3_cross

#define vec3u glmm_vec3u
#define vec3u_init glmm_vec3u_init
#define vec3u_eq glmm_vec3u_init
#define vec3u_add glmm_vec3u_add
#define vec3u_sub glmm_vec3u_sub
#define vec3u_print glmm_vec3u_print
#define vec3u_cross glmm_vec3_cross

#define vec4f glmm_vec4f
#define vec4f_init glmm_vec4f_init
#define vec4f_eq glmm_vec4f_init
#define vec4f_add glmm_vec4f_add
#define vec4f_sub glmm_vec4f_sub
#define vec4f_print glmm_vec4f_print
#define vec4f_cross glmm_vec4f_cross

#define vec4i glmm_vec4i
#define vec4i_init glmm_vec4i_init
#define vec4i_eq glmm_vec4i_init
#define vec4i_add glmm_vec4i_add
#define vec4i_sub glmm_vec4i_sub
#define vec4i_print glmm_vec4i_print
#define vec4i_cross glmm_vec4i_cross

#define vec4u glmm_vec4u
#define vec4u_init glmm_vec4u_init
#define vec4u_eq glmm_vec4u_init
#define vec4u_add glmm_vec4u_add
#define vec4u_sub glmm_vec4u_sub
#define vec4u_print glmm_vec4u_print
#define vec4u_cross glmm_vec4u_cross

#endif // GLMM_NO_SHORT_DEFINES

#endif // GLMM_VEC_H
