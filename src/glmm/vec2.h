#ifndef GLMM_VEC2_H
#define GLMM_VEC2_H

#include <stdbool.h>

typedef struct 
{
    float x;
    float y;
} 
glmm_vec2;

typedef struct
{
    int x;
    int y;
}
glmm_vec2i;

typedef struct 
{
    unsigned int x;
    unsigned int y;
}
glmm_vec2u;

#ifndef GLMM_NO_SHORT_DEFINES
typedef glmm_vec2  vec2;
typedef glmm_vec2i vec2i;
typedef glmm_vec2u vec2u;
#endif // GLMM_NO_SHORT_DEFINES

void glmm_vec2_init(glmm_vec2* this);

bool glmm_vec2_eq(glmm_vec2* left, glmm_vec2* right);
void glmm_vec2_add(glmm_vec2* this, glmm_vec2* other);
void glmm_vec2_sub(glmm_vec2* this, glmm_vec2* other);

void glmm_vec2_print(glmm_vec2* this);

#endif // GLMM_VEC2_H
