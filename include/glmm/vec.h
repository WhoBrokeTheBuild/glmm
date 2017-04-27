#ifndef GLMM_VEC_H
#define GLMM_VEC_H

#include <math.h> /* for sqrt */
#include <stdbool.h> /* for true, false */
#include <stdio.h> /* for printf */
#include <string.h> /* for memcpy */

#define GLMM_VEC2(ID, DATA, FMT) \
    GLMM_VEC2_IMP(ID, DATA, FMT, glmm_vec2##ID, glmm_vec2##ID##_t)

#define GLMM_VEC2_IMP(ID, DATA, FMT, PREFIX, TYPE) \
                                                   \
    typedef union {                                \
        DATA data[2];                              \
        struct                                     \
        {                                          \
            DATA x;                                \
            DATA y;                                \
        };                                         \
        struct                                     \
        {                                          \
            DATA u;                                \
            DATA v;                                \
        };                                         \
    } TYPE;                                        \
                                                   \
    GLMM_VEC2_FUNCS(ID, DATA, FMT, PREFIX, TYPE)

#define GLMM_VEC3(ID, DATA, FMT) \
    GLMM_VEC3_IMP(ID, DATA, FMT, glmm_vec3##ID, glmm_vec3##ID##_t)

#define GLMM_VEC3_IMP(ID, DATA, FMT, PREFIX, TYPE) \
                                                   \
    typedef union {                                \
        DATA data[3];                              \
        struct                                     \
        {                                          \
            DATA x;                                \
            DATA y;                                \
            DATA z;                                \
        };                                         \
        struct                                     \
        {                                          \
            DATA u;                                \
            DATA v;                                \
            DATA w;                                \
        };                                         \
        struct                                     \
        {                                          \
            DATA r;                                \
            DATA g;                                \
            DATA b;                                \
        };                                         \
    } TYPE;                                        \
                                                   \
    GLMM_VEC3_FUNCS(ID, DATA, FMT, PREFIX, TYPE)

#define GLMM_VEC4(ID, DATA, FMT) \
    GLMM_VEC4_IMP(ID, DATA, FMT, glmm_vec4##ID, glmm_vec4##ID##_t)

#define GLMM_VEC4_IMP(ID, DATA, FMT, PREFIX, TYPE) \
                                                   \
    typedef union {                                \
        DATA data[4];                              \
        struct                                     \
        {                                          \
            DATA x;                                \
            DATA y;                                \
            DATA z;                                \
            DATA w;                                \
        };                                         \
        struct                                     \
        {                                          \
            DATA r;                                \
            DATA g;                                \
            DATA b;                                \
            DATA a;                                \
        };                                         \
    } TYPE;                                        \
                                                   \
    GLMM_VEC4_FUNCS(ID, DATA, FMT, PREFIX, TYPE)

#include "vec.inl.h"

GLMM_VEC2(f, float, "%.3f")
GLMM_VEC3(f, float, "%.3f")
GLMM_VEC4(f, float, "%.3f")

GLMM_VEC2(d, double, "%.6f")
GLMM_VEC3(d, double, "%.6f")
GLMM_VEC4(d, double, "%.6f")

GLMM_VEC2(i, int, "%d")
GLMM_VEC3(i, int, "%d")
GLMM_VEC4(i, int, "%d")

GLMM_VEC2(u, unsigned int, "%u")
GLMM_VEC3(u, unsigned int, "%u")
GLMM_VEC4(u, unsigned int, "%u")

#ifndef GLMM_NO_SHORT_DEFINES

GLMM_VEC2_SHORT(f, float)
GLMM_VEC3_SHORT(f, float)
GLMM_VEC4_SHORT(f, float)

GLMM_VEC2_SHORT(d, double)
GLMM_VEC3_SHORT(d, double)
GLMM_VEC4_SHORT(d, double)

GLMM_VEC2_SHORT(i, int)
GLMM_VEC3_SHORT(i, int)
GLMM_VEC4_SHORT(i, int)

GLMM_VEC2_SHORT(u, unsigned int)
GLMM_VEC3_SHORT(u, unsigned int)
GLMM_VEC4_SHORT(u, unsigned int)

#endif // GLMM_NO_SHORT_DEFINES

#endif // GLMM_VEC_H
