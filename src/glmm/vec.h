#ifndef GLMM_VEC_H
#define GLMM_VEC_H

#include <math.h>    /* for sqrt */
#include <stdbool.h> /* for true, false */
#include <stdio.h>   /* for printf */
#include <string.h>  /* for memcpy */

#define GLMM_VEC(N, ID, TYPE, FMT)                                                                                                          \
                                                                                                                                            \
    typedef TYPE glmm_vec##N##ID##_t[N];                                                                                                    \
                                                                                                                                            \
    static inline void glmm_vec##N##ID##_init(glmm_vec##N##ID##_t this, TYPE value)                                                         \
    {                                                                                                                                       \
        int i;                                                                                                                              \
        for (i = 0; i < N; ++i)                                                                                                             \
            this[i] = value;                                                                                                                \
    }                                                                                                                                       \
                                                                                                                                            \
    static inline void glmm_vec##N##ID##_copy(glmm_vec##N##ID##_t this, const glmm_vec##N##ID##_t other)                                    \
    {                                                                                                                                       \
        memcpy(this, other, sizeof(glmm_vec##N##ID##_t));                                                                                   \
        /* int i; */                                                                                                                        \
        /* for (i = 0; i < N; ++i) */                                                                                                       \
            /* this[i] = other[i]; */                                                                                                       \
    }                                                                                                                                       \
                                                                                                                                            \
    static inline bool glmm_vec##N##ID##_eq(const glmm_vec##N##ID##_t this, const glmm_vec##N##ID##_t other)                                \
    {                                                                                                                                       \
        int i;                                                                                                                              \
        for (i = 0; i < N; ++i)                                                                                                             \
            if (this[i] != other[i])                                                                                                        \
                return false;                                                                                                               \
        return true;                                                                                                                        \
    }                                                                                                                                       \
                                                                                                                                            \
    static inline bool glmm_vec##N##ID##_ne(const glmm_vec##N##ID##_t this, const glmm_vec##N##ID##_t other)                                \
    {                                                                                                                                       \
        return !glmm_vec##N##ID##_eq(this, other);                                                                                          \
    }                                                                                                                                       \
                                                                                                                                            \
    static inline void glmm_vec##N##ID##_add(glmm_vec##N##ID##_t this, const glmm_vec##N##ID##_t other)                                     \
    {                                                                                                                                       \
        int i;                                                                                                                              \
        for (i = 0; i < N; ++i)                                                                                                             \
            this[i] += other[i];                                                                                                            \
    }                                                                                                                                       \
                                                                                                                                            \
    static inline void glmm_vec##N##ID##_xadd(glmm_vec##N##ID##_t result, const glmm_vec##N##ID##_t this, const glmm_vec##N##ID##_t other)  \
    {                                                                                                                                       \
        int i;                                                                                                                              \
        for (i = 0; i < N; ++i)                                                                                                             \
            result[i] = this[i] + other[i];                                                                                                 \
    }                                                                                                                                       \
                                                                                                                                            \
    static inline void glmm_vec##N##ID##_adds(glmm_vec##N##ID##_t this, TYPE value)                                                         \
    {                                                                                                                                       \
        int i;                                                                                                                              \
        for (i = 0; i < N; ++i)                                                                                                             \
            this[i] += value;                                                                                                               \
    }                                                                                                                                       \
                                                                                                                                            \
    static inline void glmm_vec##N##ID##_xadds(glmm_vec##N##ID##_t result, const glmm_vec##N##ID##_t this, TYPE value)                      \
    {                                                                                                                                       \
        int i;                                                                                                                              \
        for (i = 0; i < N; ++i)                                                                                                             \
            result[i] = this[i] + value;                                                                                                    \
    }                                                                                                                                       \
                                                                                                                                            \
    static inline void glmm_vec##N##ID##_sub(glmm_vec##N##ID##_t this, const glmm_vec##N##ID##_t other)                                     \
    {                                                                                                                                       \
        int i;                                                                                                                              \
        for (i = 0; i < N; ++i)                                                                                                             \
            this[i] -= other[i];                                                                                                            \
    }                                                                                                                                       \
                                                                                                                                            \
    static inline void glmm_vec##N##ID##_xsub(glmm_vec##N##ID##_t result, const glmm_vec##N##ID##_t this, const glmm_vec##N##ID##_t other)  \
    {                                                                                                                                       \
        int i;                                                                                                                              \
        for (i = 0; i < N; ++i)                                                                                                             \
            result[i] = this[i] - other[i];                                                                                                 \
    }                                                                                                                                       \
                                                                                                                                            \
    static inline void glmm_vec##N##ID##_subs(glmm_vec##N##ID##_t this, TYPE value)                                                         \
    {                                                                                                                                       \
        int i;                                                                                                                              \
        for (i = 0; i < N; ++i)                                                                                                             \
            this[i] -= value;                                                                                                               \
    }                                                                                                                                       \
                                                                                                                                            \
    static inline void glmm_vec##N##ID##_xsubs(glmm_vec##N##ID##_t result, const glmm_vec##N##ID##_t this, TYPE value)                      \
    {                                                                                                                                       \
        int i;                                                                                                                              \
        for (i = 0; i < N; ++i)                                                                                                             \
            result[i] = this[i] - value;                                                                                                    \
    }                                                                                                                                       \
                                                                                                                                            \
    static inline void glmm_vec##N##ID##_mul(glmm_vec##N##ID##_t this, const glmm_vec##N##ID##_t other)                                     \
    {                                                                                                                                       \
        int i;                                                                                                                              \
        for (i = 0; i < N; ++i)                                                                                                             \
            this[i] *= other[i];                                                                                                            \
    }                                                                                                                                       \
                                                                                                                                            \
    static inline void glmm_vec##N##ID##_xmul(glmm_vec##N##ID##_t result, const glmm_vec##N##ID##_t this, const glmm_vec##N##ID##_t other)  \
    {                                                                                                                                       \
        int i;                                                                                                                              \
        for (i = 0; i < N; ++i)                                                                                                             \
            result[i] = this[i] * other[i];                                                                                                 \
    }                                                                                                                                       \
                                                                                                                                            \
    static inline void glmm_vec##N##ID##_muls(glmm_vec##N##ID##_t this, TYPE value)                                                         \
    {                                                                                                                                       \
        int i;                                                                                                                              \
        for (i = 0; i < N; ++i)                                                                                                             \
            this[i] *= value;                                                                                                               \
    }                                                                                                                                       \
                                                                                                                                            \
    static inline void glmm_vec##N##ID##_xmuls(glmm_vec##N##ID##_t result, const glmm_vec##N##ID##_t this, TYPE value)                      \
    {                                                                                                                                       \
        int i;                                                                                                                              \
        for (i = 0; i < N; ++i)                                                                                                             \
            result[i] = this[i] * value;                                                                                                    \
    }                                                                                                                                       \
                                                                                                                                            \
    static inline void glmm_vec##N##ID##_div(glmm_vec##N##ID##_t this, const glmm_vec##N##ID##_t other)                                     \
    {                                                                                                                                       \
        int i;                                                                                                                              \
        for (i = 0; i < N; ++i)                                                                                                             \
            this[i] /= other[i];                                                                                                            \
    }                                                                                                                                       \
                                                                                                                                            \
    static inline void glmm_vec##N##ID##_xdiv(glmm_vec##N##ID##_t result, const glmm_vec##N##ID##_t this, const glmm_vec##N##ID##_t other)  \
    {                                                                                                                                       \
        int i;                                                                                                                              \
        for (i = 0; i < N; ++i)                                                                                                             \
            result[i] = this[i] / other[i];                                                                                                 \
    }                                                                                                                                       \
                                                                                                                                            \
    static inline void glmm_vec##N##ID##_divs(glmm_vec##N##ID##_t this, TYPE value)                                                         \
    {                                                                                                                                       \
        int i;                                                                                                                              \
        for (i = 0; i < N; ++i)                                                                                                             \
            this[i] /= value;                                                                                                               \
    }                                                                                                                                       \
                                                                                                                                            \
    static inline void glmm_vec##N##ID##_xdivs(glmm_vec##N##ID##_t result, const glmm_vec##N##ID##_t this, TYPE value)                      \
    {                                                                                                                                       \
        int i;                                                                                                                              \
        for (i = 0; i < N; ++i)                                                                                                             \
            result[i] = this[i] / value;                                                                                                    \
    }                                                                                                                                       \
                                                                                                                                            \
    static inline TYPE glmm_vec##N##ID##_len(const glmm_vec##N##ID##_t this)                                                                \
    {                                                                                                                                       \
        int i;                                                                                                                              \
        TYPE sum = 0;                                                                                                                       \
        for (i = 0; i < N; ++i)                                                                                                             \
            sum += this[i] * this[i];                                                                                                       \
                                                                                                                                            \
        return sqrt(sum);                                                                                                                   \
    }                                                                                                                                       \
                                                                                                                                            \
    static inline void glmm_vec##N##ID##_norm(glmm_vec##N##ID##_t this)                                                                     \
    {                                                                                                                                       \
        int i;                                                                                                                              \
        TYPE len = glmm_vec##N##ID##_len(this);                                                                                             \
        for (i = 0; i < N; ++i)                                                                                                             \
            this[i] /= len;                                                                                                                 \
    }                                                                                                                                       \
                                                                                                                                            \
    static inline void glmm_vec##N##ID##_xnorm(glmm_vec##N##ID##_t result, const glmm_vec##N##ID##_t this)                                  \
    {                                                                                                                                       \
        int i;                                                                                                                              \
        TYPE len = glmm_vec##N##ID##_len(this);                                                                                             \
        for (i = 0; i < N; ++i)                                                                                                             \
            result[i] = this[i] / len;                                                                                                      \
    }                                                                                                                                       \
                                                                                                                                            \
    static inline TYPE glmm_vec##N##ID##_dot(const glmm_vec##N##ID##_t this, const glmm_vec##N##ID##_t other)                               \
    {                                                                                                                                       \
        int i = 0;                                                                                                                          \
        TYPE result = 0;                                                                                                                    \
        for (i = 0; i < N; ++i)                                                                                                             \
        {                                                                                                                                   \
            result += this[i] * other[i];                                                                                                   \
        }                                                                                                                                   \
        return result;                                                                                                                      \
    }                                                                                                                                       \
                                                                                                                                            \
    static inline void glmm_vec##N##ID##_print(const glmm_vec##N##ID##_t this)                                                              \
    {                                                                                                                                       \
        printf("[ ");                                                                                                                       \
        int i;                                                                                                                              \
        for (i = 0; i < N; ++i)                                                                                                             \
        {                                                                                                                                   \
            printf(FMT, this[i]);                                                                                                           \
            if (i != N - 1)                                                                                                                 \
                printf(", ");                                                                                                               \
        }                                                                                                                                   \
        printf(" ]");                                                                                                                       \
    }

// GLMM_VEC

GLMM_VEC(2, f, float, "%f");
GLMM_VEC(2, i, int, "%d");
GLMM_VEC(2, u, unsigned int, "%u");

GLMM_VEC(3, f, float, "%f");
GLMM_VEC(3, i, int, "%d");
GLMM_VEC(3, u, unsigned int, "%u");

GLMM_VEC(4, f, float, "%f");
GLMM_VEC(4, i, int, "%d");
GLMM_VEC(4, u, unsigned int, "%u");

#define GLMM_VEC3_SPECIAL(ID)                                                                                                        \
                                                                                                                                     \
    static inline void glmm_vec3##ID##_cross(const glmm_vec3##ID##_t this, const glmm_vec3##ID##_t other)                            \
    {                                                                                                                                \
        glmm_vec3##ID##_t result;                                                                                                    \
        result[0] = this[1] * other[2] - this[2] * other[1];                                                                         \
        result[1] = this[2] * other[0] - this[0] * other[2];                                                                         \
        result[2] = this[0] * other[1] - this[1] * other[0];                                                                         \
        glmm_vec3##ID##_copy(this, result);                                                                                          \
    }                                                                                                                                \
                                                                                                                                     \
    static inline void glmm_vec3##ID##_xcross(glmm_vec3##ID##_t result, const glmm_vec3##ID##_t this, const glmm_vec3##ID##_t other) \
    {                                                                                                                                \
        result[0] = this[1] * other[2] - this[2] * other[1];                                                                         \
        result[1] = this[2] * other[0] - this[0] * other[2];                                                                         \
        result[2] = this[0] * other[1] - this[1] * other[0];                                                                         \
    }

// GLMM_VEC3_SPECIAL

GLMM_VEC3_SPECIAL(f);
GLMM_VEC3_SPECIAL(i);
GLMM_VEC3_SPECIAL(u);

#define GLMM_VEC4_SPECIAL(ID)                                                                                                        \
                                                                                                                                     \
    static inline void glmm_vec4##ID##_cross(const glmm_vec4##ID##_t this, const glmm_vec4##ID##_t other)                            \
    {                                                                                                                                \
        glmm_vec3##ID##_cross(this, other);                                                                                          \
        this[3] = 1;                                                                                                                 \
    }                                                                                                                                \
                                                                                                                                     \
    static inline void glmm_vec4##ID##_xcross(glmm_vec4##ID##_t result, const glmm_vec4##ID##_t this, const glmm_vec4##ID##_t other) \
    {                                                                                                                                \
        glmm_vec3##ID##_xcross(result, this, other);                                                                                 \
        result[3] = 1;                                                                                                               \
    }

// GLMM_VEC4_SPECIAL

GLMM_VEC4_SPECIAL(f);
GLMM_VEC4_SPECIAL(i);
GLMM_VEC4_SPECIAL(u);

#ifndef GLMM_NO_SHORT_DEFINES

#define vec2f_t glmm_vec2f_t
#define vec2f_init glmm_vec2f_init
#define vec2f_copy glmm_vec2f_copy
#define vec2f_eq glmm_vec2f_eq
#define vec2f_ne glmm_vec2f_ne
#define vec2f_add glmm_vec2f_add
#define vec2f_adds glmm_vec2f_adds
#define vec2f_xadd glmm_vec2f_xadd
#define vec2f_xadds glmm_vec2f_xadds
#define vec2f_sub glmm_vec2f_sub
#define vec2f_subs glmm_vec2f_subs
#define vec2f_xsub glmm_vec2f_xsub
#define vec2f_xsubs glmm_vec2f_xsubs
#define vec2f_mul glmm_vec2f_mul
#define vec2f_muls glmm_vec2f_muls
#define vec2f_xmul glmm_vec2f_xmul
#define vec2f_xmuls glmm_vec2f_xmuls
#define vec2f_div glmm_vec2f_div
#define vec2f_divs glmm_vec2f_divs
#define vec2f_xdiv glmm_vec2f_xdiv
#define vec2f_xdivs glmm_vec2f_xdivs
#define vec2f_len glmm_vec2f_len
#define vec2f_norm glmm_vec2f_norm
#define vec2f_xnorm glmm_vec2f_xnorm
#define vec2f_dot glmm_vec2f_dot
#define vec2f_print glmm_vec2f_print

#define vec2i_t glmm_vec2i_t
#define vec2i_init glmm_vec2i_init
#define vec2i_copy glmm_vec2i_copy
#define vec2i_eq glmm_vec2i_eq
#define vec2i_ne glmm_vec2i_ne
#define vec2i_add glmm_vec2i_add
#define vec2i_adds glmm_vec2i_adds
#define vec2i_xadd glmm_vec2i_xadd
#define vec2i_xadds glmm_vec2i_xadds
#define vec2i_sub glmm_vec2i_sub
#define vec2i_subs glmm_vec2i_subs
#define vec2i_xsub glmm_vec2i_xsub
#define vec2i_xsubs glmm_vec2i_xsubs
#define vec2i_mul glmm_vec2i_mul
#define vec2i_muls glmm_vec2i_muls
#define vec2i_xmul glmm_vec2i_xmul
#define vec2i_xmuls glmm_vec2i_xmuls
#define vec2i_div glmm_vec2i_div
#define vec2i_divs glmm_vec2i_divs
#define vec2i_xdiv glmm_vec2i_xdiv
#define vec2i_xdivs glmm_vec2i_xdivs
#define vec2i_len glmm_vec2i_len
#define vec2i_norm glmm_vec2i_norm
#define vec2i_xnorm glmm_vec2i_xnorm
#define vec2i_dot glmm_vec2i_dot
#define vec2i_print glmm_vec2i_print

#define vec2u_t glmm_vec2u_t
#define vec2u_init glmm_vec2u_init
#define vec2u_copy glmm_vec2u_copy
#define vec2u_eq glmm_vec2u_eq
#define vec2u_ne glmm_vec2u_ne
#define vec2u_add glmm_vec2u_add
#define vec2u_adds glmm_vec2u_adds
#define vec2u_xadd glmm_vec2u_xadd
#define vec2u_xadds glmm_vec2u_xadds
#define vec2u_sub glmm_vec2u_sub
#define vec2u_subs glmm_vec2u_subs
#define vec2u_xsub glmm_vec2u_xsub
#define vec2u_xsubs glmm_vec2u_xsubs
#define vec2u_mul glmm_vec2u_mul
#define vec2u_muls glmm_vec2u_muls
#define vec2u_xmul glmm_vec2u_xmul
#define vec2u_xmuls glmm_vec2u_xmuls
#define vec2u_div glmm_vec2u_div
#define vec2u_divs glmm_vec2u_divs
#define vec2u_xdiv glmm_vec2u_xdiv
#define vec2u_xdivs glmm_vec2u_xdivs
#define vec2u_len glmm_vec2u_len
#define vec2u_norm glmm_vec2u_norm
#define vec2u_xnorm glmm_vec2u_xnorm
#define vec2u_dot glmm_vec2u_dot
#define vec2u_print glmm_vec2u_print

#define vec3u_t glmm_vec3u_t
#define vec3u_init glmm_vec3u_init
#define vec3u_copy glmm_vec3u_copy
#define vec3u_eq glmm_vec3u_eq
#define vec3u_ne glmm_vec3u_ne
#define vec3u_add glmm_vec3u_add
#define vec3u_adds glmm_vec3u_adds
#define vec3u_xadd glmm_vec3u_xadd
#define vec3u_xadds glmm_vec3u_xadds
#define vec3u_sub glmm_vec3u_sub
#define vec3u_subs glmm_vec3u_subs
#define vec3u_xsub glmm_vec3u_xsub
#define vec3u_xsubs glmm_vec3u_xsubs
#define vec3u_mul glmm_vec3u_mul
#define vec3u_muls glmm_vec3u_muls
#define vec3u_xmul glmm_vec3u_xmul
#define vec3u_xmuls glmm_vec3u_xmuls
#define vec3u_div glmm_vec3u_div
#define vec3u_divs glmm_vec3u_divs
#define vec3u_xdiv glmm_vec3u_xdiv
#define vec3u_xdivs glmm_vec3u_xdivs
#define vec3u_len glmm_vec3u_len
#define vec3u_norm glmm_vec3u_norm
#define vec3u_xnorm glmm_vec3u_xnorm
#define vec3u_dot glmm_vec3u_dot
#define vec3u_cross glmm_vec3u_cross
#define vec3u_xcross glmm_vec3u_xcross
#define vec3u_print glmm_vec3u_print

#define vec3i_t glmm_vec3i_t
#define vec3i_init glmm_vec3i_init
#define vec3i_copy glmm_vec3i_copy
#define vec3i_eq glmm_vec3i_eq
#define vec3i_ne glmm_vec3i_ne
#define vec3i_add glmm_vec3i_add
#define vec3i_adds glmm_vec3i_adds
#define vec3i_xadd glmm_vec3i_xadd
#define vec3i_xadds glmm_vec3i_xadds
#define vec3i_sub glmm_vec3i_sub
#define vec3i_subs glmm_vec3i_subs
#define vec3i_xsub glmm_vec3i_xsub
#define vec3i_xsubs glmm_vec3i_xsubs
#define vec3i_mul glmm_vec3i_mul
#define vec3i_muls glmm_vec3i_muls
#define vec3i_xmul glmm_vec3i_xmul
#define vec3i_xmuls glmm_vec3i_xmuls
#define vec3i_div glmm_vec3i_div
#define vec3i_divs glmm_vec3i_divs
#define vec3i_xdiv glmm_vec3i_xdiv
#define vec3i_xdivs glmm_vec3i_xdivs
#define vec3i_len glmm_vec3i_len
#define vec3i_norm glmm_vec3i_norm
#define vec3i_xnorm glmm_vec3i_xnorm
#define vec3i_dot glmm_vec3i_dot
#define vec3i_cross glmm_vec3i_cross
#define vec3i_xcross glmm_vec3i_xcross
#define vec3i_print glmm_vec3i_print

#define vec3u_t glmm_vec3u_t
#define vec3u_init glmm_vec3u_init
#define vec3u_copy glmm_vec3u_copy
#define vec3u_eq glmm_vec3u_eq
#define vec3u_ne glmm_vec3u_ne
#define vec3u_add glmm_vec3u_add
#define vec3u_adds glmm_vec3u_adds
#define vec3u_xadd glmm_vec3u_xadd
#define vec3u_xadds glmm_vec3u_xadds
#define vec3u_sub glmm_vec3u_sub
#define vec3u_subs glmm_vec3u_subs
#define vec3u_xsub glmm_vec3u_xsub
#define vec3u_xsubs glmm_vec3u_xsubs
#define vec3u_mul glmm_vec3u_mul
#define vec3u_muls glmm_vec3u_muls
#define vec3u_xmul glmm_vec3u_xmul
#define vec3u_xmuls glmm_vec3u_xmuls
#define vec3u_div glmm_vec3u_div
#define vec3u_divs glmm_vec3u_divs
#define vec3u_xdiv glmm_vec3u_xdiv
#define vec3u_xdivs glmm_vec3u_xdivs
#define vec3u_len glmm_vec3u_len
#define vec3u_norm glmm_vec3u_norm
#define vec3u_xnorm glmm_vec3u_xnorm
#define vec3u_dot glmm_vec3u_dot
#define vec3u_cross glmm_vec3u_cross
#define vec3u_xcross glmm_vec3u_xcross
#define vec3u_print glmm_vec3u_print

#define vec4f_t glmm_vec4f_t
#define vec4f_init glmm_vec4f_init
#define vec4f_copy glmm_vec4f_copy
#define vec4f_eq glmm_vec4f_eq
#define vec4f_ne glmm_vec4f_ne
#define vec4f_add glmm_vec4f_add
#define vec4f_adds glmm_vec4f_adds
#define vec4f_xadd glmm_vec4f_xadd
#define vec4f_xadds glmm_vec4f_xadds
#define vec4f_sub glmm_vec4f_sub
#define vec4f_subs glmm_vec4f_subs
#define vec4f_xsub glmm_vec4f_xsub
#define vec4f_xsubs glmm_vec4f_xsubs
#define vec4f_mul glmm_vec4f_mul
#define vec4f_muls glmm_vec4f_muls
#define vec4f_xmul glmm_vec4f_xmul
#define vec4f_xmuls glmm_vec4f_xmuls
#define vec4f_div glmm_vec4f_div
#define vec4f_divs glmm_vec4f_divs
#define vec4f_xdiv glmm_vec4f_xdiv
#define vec4f_xdivs glmm_vec4f_xdivs
#define vec4f_len glmm_vec4f_len
#define vec4f_norm glmm_vec4f_norm
#define vec4f_xnorm glmm_vec4f_xnorm
#define vec4f_dot glmm_vec4f_dot
#define vec4f_cross glmm_vec4f_cross
#define vec4f_xcross glmm_vec4f_xcross
#define vec4f_print glmm_vec4f_print

#define vec4i_t glmm_vec4i_t
#define vec4i_init glmm_vec4i_init
#define vec4i_copy glmm_vec4i_copy
#define vec4i_eq glmm_vec4i_eq
#define vec4i_ne glmm_vec4i_ne
#define vec4i_add glmm_vec4i_add
#define vec4i_adds glmm_vec4i_adds
#define vec4i_xadd glmm_vec4i_xadd
#define vec4i_xadds glmm_vec4i_xadds
#define vec4i_sub glmm_vec4i_sub
#define vec4i_subs glmm_vec4i_subs
#define vec4i_xsub glmm_vec4i_xsub
#define vec4i_xsubs glmm_vec4i_xsubs
#define vec4i_mul glmm_vec4i_mul
#define vec4i_muls glmm_vec4i_muls
#define vec4i_xmul glmm_vec4i_xmul
#define vec4i_xmuls glmm_vec4i_xmuls
#define vec4i_div glmm_vec4i_div
#define vec4i_divs glmm_vec4i_divs
#define vec4i_xdiv glmm_vec4i_xdiv
#define vec4i_xdivs glmm_vec4i_xdivs
#define vec4i_len glmm_vec4i_len
#define vec4i_norm glmm_vec4i_norm
#define vec4i_xnorm glmm_vec4i_xnorm
#define vec4i_dot glmm_vec4i_dot
#define vec4i_cross glmm_vec4i_cross
#define vec4i_xcross glmm_vec4i_xcross
#define vec4i_print glmm_vec4i_print

#define vec4u_t glmm_vec4u_t
#define vec4u_init glmm_vec4u_init
#define vec4u_copy glmm_vec4u_copy
#define vec4u_eq glmm_vec4u_eq
#define vec4u_ne glmm_vec4u_ne
#define vec4u_add glmm_vec4u_add
#define vec4u_adds glmm_vec4u_adds
#define vec4u_xadd glmm_vec4u_xadd
#define vec4u_xadds glmm_vec4u_xadds
#define vec4u_sub glmm_vec4u_sub
#define vec4u_subs glmm_vec4u_subs
#define vec4u_xsub glmm_vec4u_xsub
#define vec4u_xsubs glmm_vec4u_xsubs
#define vec4u_mul glmm_vec4u_mul
#define vec4u_muls glmm_vec4u_muls
#define vec4u_xmul glmm_vec4u_xmul
#define vec4u_xmuls glmm_vec4u_xmuls
#define vec4u_div glmm_vec4u_div
#define vec4u_divs glmm_vec4u_divs
#define vec4u_xdiv glmm_vec4u_xdiv
#define vec4u_xdivs glmm_vec4u_xdivs
#define vec4u_len glmm_vec4u_len
#define vec4u_norm glmm_vec4u_norm
#define vec4u_xnorm glmm_vec4u_xnorm
#define vec4u_dot glmm_vec4u_dot
#define vec4u_cross glmm_vec4u_cross
#define vec4u_xcross glmm_vec4u_xcross
#define vec4u_print glmm_vec4u_print

#endif // GLMM_NO_SHORT_DEFINES

#endif // GLMM_VEC_H
