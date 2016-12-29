#ifndef GLMM_H
#define GLMM_H

#define GLMM_LEFT_HANDED 1
#define GLMM_RIGHT_HANDED 2

#ifdef GLMM_FORCE_LEFT_HANDED
#define GLMM_COORDINATE_SYSTEM GLM_LEFT_HANDED
#else
#define GLMM_COORDINATE_SYSTEM GLM_RIGHT_HANDED
#endif // GLMM_FORCE_LEFT_HANDED

#define GLMM_VER_STRING "0.0.1"

#define GLMM_PI 3.1415926535

#include "mat.h"
#include "quat.h"
#include "vec.h"

#endif // GLMM_H
