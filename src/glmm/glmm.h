#ifndef GLMM_H
#define GLMM_H

#define GLMM_LEFT_HANDED 1
#define GLMM_RIGHT_HANDED 2

#ifdef GLMM_FORCE_LEFT_HANDED
#define GLMM_COORDINATE_SYSTEM GLM_LEFT_HANDED
#else
#define GLMM_COORDINATE_SYSTEM GLM_RIGHT_HANDED
#endif // GLMM_FORCE_LEFT_HANDED

#define GLMM_VER_STRING "0.0.2"

#define GLMM_PI 3.1415926535
#define GLMM_2PI 6.283185307

#define GLMM_RAD(N) (N * (GLMM_PI / 180))
#define GLMM_DEG(N) (N * (180 / GLMM_PI))

#include "vec.h"
#include "mat.h"
#include "quat.h"

#endif // GLMM_H
