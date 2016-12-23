#ifndef GLMM_VEC_H
#define GLMM_VEC_H

#include <stdio.h>
#include <stdbool.h>

#define GLMM_VEC(N, ID, TYPE, FMT) \
typedef TYPE glmm_vec##N##ID[N]; \
\
static inline void glmm_vec##N##ID##_init(glmm_vec##N##ID this) \
{ \
    int i; \
    for (i = 0; i < N; ++i) \
        this[i] = 0; \
} \
\
static inline bool glmm_vec##N##ID##_eq(const glmm_vec##N##ID this, const glmm_vec##N##ID other) \
{ \
    int i; \
    for (i = 0; i < N; ++i) \
        if (this[i] != other[i]) \
            return false; \
    return true; \
} \
\
static inline void glmm_vec##N##ID##_add(glmm_vec##N##ID this, const glmm_vec##N##ID other) \
{ \
    int i; \
    for (i = 0; i < N; ++i) \
        this[i] += other[i]; \
} \
\
static inline void glmm_vec##N##ID##_sub(glmm_vec##N##ID this, const glmm_vec##N##ID other) \
{ \
    int i; \
    for (i = 0; i < N; ++i) \
        this[i] -= other[i]; \
} \
\
static inline void glmm_vec##N##ID##_print(const glmm_vec##N##ID this) \
{ \
    printf("[ "); \
    int i; \
    for (i = 0; i < N; ++i) { \
        printf(FMT, this[i]); \
        if (i != N - 1) printf(", "); \
    } \
    printf(" ]"); \
} \

GLMM_VEC(2, f, float, "%f");
GLMM_VEC(2, i, int, "%d");
GLMM_VEC(2, u, unsigned int, "%u");

GLMM_VEC(3, f, float, "%f");
GLMM_VEC(3, i, int, "%d");
GLMM_VEC(3, u, unsigned int, "%u");

GLMM_VEC(4, f, float, "%f");
GLMM_VEC(4, i, int, "%d");
GLMM_VEC(4, u, unsigned int, "%u");

#ifndef GLMM_NO_SHORT_DEFINES

#define glmm_vec2f vec2f
#define glmm_vec2f_init vec2f_init
#define glmm_vec2f_eq vec2f_init
#define glmm_vec2f_add vec2f_add
#define glmm_vec2f_sub vec2f_sub
#define glmm_vec2f_print vec2f_print

#define glmm_vec2i vec2i
#define glmm_vec2i_init vec2i_init
#define glmm_vec2i_eq vec2i_init
#define glmm_vec2i_add vec2i_add
#define glmm_vec2i_sub vec2i_sub
#define glmm_vec2i_print vec2i_print

#define glmm_vec2u vec2u
#define glmm_vec2u_init vec2u_init
#define glmm_vec2u_eq vec2u_init
#define glmm_vec2u_add vec2u_add
#define glmm_vec2u_sub vec2u_sub
#define glmm_vec2u_print vec2u_print

#define glmm_vec3f vec3f
#define glmm_vec3f_init vec3f_init
#define glmm_vec3f_eq vec3f_init
#define glmm_vec3f_add vec3f_add
#define glmm_vec3f_sub vec3f_sub
#define glmm_vec3f_print vec3f_print

#define glmm_vec3i vec3i
#define glmm_vec3i_init vec3i_init
#define glmm_vec3i_eq vec3i_init
#define glmm_vec3i_add vec3i_add
#define glmm_vec3i_sub vec3i_sub
#define glmm_vec3i_print vec3i_print

#define glmm_vec3u vec3u
#define glmm_vec3u_init vec3u_init
#define glmm_vec3u_eq vec3u_init
#define glmm_vec3u_add vec3u_add
#define glmm_vec3u_sub vec3u_sub
#define glmm_vec3u_print vec3u_print

#define glmm_vec4f vec4f
#define glmm_vec4f_init vec4f_init
#define glmm_vec4f_eq vec4f_init
#define glmm_vec4f_add vec4f_add
#define glmm_vec4f_sub vec4f_sub
#define glmm_vec4f_print vec4f_print

#define glmm_vec4i vec4i
#define glmm_vec4i_init vec4i_init
#define glmm_vec4i_eq vec4i_init
#define glmm_vec4i_add vec4i_add
#define glmm_vec4i_sub vec4i_sub
#define glmm_vec4i_print vec4i_print

#define glmm_vec4u vec4u
#define glmm_vec4u_init vec4u_init
#define glmm_vec4u_eq vec4u_init
#define glmm_vec4u_add vec4u_add
#define glmm_vec4u_sub vec4u_sub
#define glmm_vec4u_print vec4u_print

#endif // GLMM_NO_SHORT_DEFINES

#endif // GLMM_VEC_H
