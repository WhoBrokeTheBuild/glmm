#ifndef GLMM_FUNC_H
#define GLMM_FUNC_H

#include "const.h"
#include "vec.h"
#include <math.h>

#define GLMM_RAD(N) ((N) * (GLMM_PI / 180))
#define GLMM_DEG(N) ((N) * (180 / GLMM_PI))
#define GLMM_MIN(A, B) ((A) < (B) ? (A) : (B))
#define GLMM_MAX(A, B) ((A) > (B) ? (A) : (B))

// TODO
#define GLMM_ABS(N)
#define GLMM_SIGN(N)
#define GLMM_FLOOR(N)
#define GLMM_TRUNC(N)
#define GLMM_ROUND_EVEN(N)
#define GLMM_CEIL(N)
#define GLMM_FRACT(N)
#define GLMM_CLAMP(A, B)

static inline float glmm_gauss1d(float x, float expected_value, float standard_dev)
{
    return exp(-((x - expected_value) * (x - expected_value)) / (2.0f * standard_dev * standard_dev)) / (standard_dev * GLMM_ROOT_TWO_PI);
}

static inline float glmm_gauss2d(glmm_vec2f_t * coord, glmm_vec2f_t * expected_value, glmm_vec2f_t * standard_dev)
{
    glmm_vec2f_t tmpa, tmpb;
    glmm_vec2f_xsub(&tmpa, coord, expected_value);
    glmm_vec2f_mul(&tmpa, &tmpa);
    glmm_vec2f_xmul(&tmpb, standard_dev, standard_dev);
    glmm_vec2f_muls(&tmpb, 2.0f);
    glmm_vec2f_div(&tmpa, &tmpb);
    return exp(-(tmpa.x + tmpa.y));
}

#endif // GLMM_FUNC_H
