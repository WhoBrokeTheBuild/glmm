#ifndef GLMM_QUAT_H
#define GLMM_QUAT_H

#include "vec.h"

typedef glmm_vec4f_t glmm_quat_t;
#define glmm_quat_copy glmm_vec4f_copy
#define glmm_quat_norm glmm_vec4f_norm
#define glmm_quat_print glmm_vec4f_print

static inline void glmm_quat_init(glmm_quat_t this)
{
    this[0] = this[1] = this[2] = 0.0f;
    this[3] = 1.0f;
}

#ifndef GLMM_NO_SHORT_DEFINES

#define quat_t glmm_quat_t
#define quat_init glmm_quat_init
#define quat_copy glmm_quat_copy
#define quat_norm glmm_quat_norm
#define quat_print glmm_quat_print

#endif // GLMM_NO_SHORT_DEFINES

#endif // GLMM_QUAT_H
