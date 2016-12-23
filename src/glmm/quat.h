#ifndef GLMM_QUAT_H
#define GLMM_QUAT_H

#include "vec.h"

typedef glmm_vec4f glmm_quat;
#define glmm_vec4f_init glmm_quat_init
#define glmm_vec4f_print glmm_quat_print

#ifndef GLMM_NO_SHORT_DEFINES

#define glmm_quat quat
#define glmm_quat_init quat_init
#define glmm_quat_print quat_print

#endif // GLMM_NO_SHORT_DEFINES

#endif // GLMM_QUAT_H
