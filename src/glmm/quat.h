#ifndef GLMM_QUAT_H
#define GLMM_QUAT_H

#include "vec.h"

typedef glmm_vec4f_t glmm_quat_t;
#define glmm_quat_init glmm_vec4f_init
#define glmm_quat_copy glmm_vec4f_copy
#define glmm_quat_norm glmm_vec4f_norm
#define glmm_quat_print glmm_vec4f_print

#ifndef GLMM_NO_SHORT_DEFINES

#define quat_t glmm_quat_t
#define quat_init glmm_quat_init
#define quat_copy glmm_quat_copy
#define quat_norm glmm_quat_norm
#define quat_print glmm_quat_print

#endif // GLMM_NO_SHORT_DEFINES

#endif // GLMM_QUAT_H
