#include "vec2.h"
#include <stdio.h>
#include <assert.h>

void glmm_vec2_init(glmm_vec2* this)
{
    assert(this != NULL);

    this->x = this->y = 0;
}

void glmm_vec2_print(glmm_vec2* this)
{
    assert(this != NULL);

    printf("[ %f, %f ]", this->x, this->y);
}

bool glmm_vec2_eq(glmm_vec2* left, glmm_vec2* right)
{
    assert(left != NULL);
    assert(right != NULL);

    return (left->x == right->x && left->y == right->y);
}

void glmm_vec2_add(glmm_vec2* this, glmm_vec2* other)
{
    assert(this != NULL);
    assert(other != NULL);

    this->x += other->x;
    this->y += other->y;
}

void glmm_vec2_sub(glmm_vec2* this, glmm_vec2* other)
{
    assert(this != NULL);
    assert(other != NULL);

    this->x -= other->x;
    this->y -= other->y;
}
