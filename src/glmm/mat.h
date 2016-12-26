#ifndef GLMM_MAT_H
#define GLMM_MAT_H

#include "vec.h"

typedef glmm_vec3f_t glmm_mat3x3_t[3];
typedef glmm_vec4f_t glmm_mat4x4_t[4];

#ifndef GLMM_NO_SHORT_DEFINES

#define mat3x3_t glmm_mat3x3_t
#define mat4x4_t glmm_mat4x4_t

#endif // GLMM_NO_SHORT_DEFINES

#endif // GLMM_MAT_H
