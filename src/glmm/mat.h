#ifndef GLMM_MAT_H
#define GLMM_MAT_H

#include "vec.h"

typedef glmm_vec3f glmm_mat3x3[3];
typedef glmm_vec4f glmm_mat4x4[4];

#ifndef GLMM_NO_SHORT_DEFINES

#define mat3x3 glmm_mat3x3
#define mat4x4 glmm_mat4x4

#endif // GLMM_NO_SHORT_DEFINES

#endif // GLMM_MAT_H
