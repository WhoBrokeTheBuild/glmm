#include "vec2.h"
#include <assert.h>
#include <stdio.h>

void glmm_vec2_init(glmm_vec2* this)
{
    assert(this != NULL);

    this->x = this->y = 0;
}

void glmm_vec2i_init(glmm_vec2i* this)
{
    assert(this != NULL);

    this->x = this->y = 0;
}

void glmm_vec2u_init(glmm_vec2u* this)
{
    assert(this != NULL);

    this->x = this->y = 0;
}

bool glmm_vec2_eq(glmm_vec2* left, glmm_vec2* right)
{
    assert(left != NULL);
    assert(right != NULL);

    return (left->x == right->x && left->y == right->y);
}

bool glmm_vec2i_eq(glmm_vec2i* left, glmm_vec2i* right)
{
    assert(left != NULL);
    assert(right != NULL);

    return (left->x == right->x && left->y == right->y);
}

bool glmm_vec2u_eq(glmm_vec2u* left, glmm_vec2u* right)
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

void glmm_vec2i_add(glmm_vec2i* this, glmm_vec2i* other)
{
    assert(this != NULL);
    assert(other != NULL);

    this->x += other->x;
    this->y += other->y;
}

void glmm_vec2u_add(glmm_vec2u* this, glmm_vec2u* other)
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

void glmm_vec2i_sub(glmm_vec2i* this, glmm_vec2i* other)
{
    assert(this != NULL);
    assert(other != NULL);

    this->x -= other->x;
    this->y -= other->y;
}

void glmm_vec2u_sub(glmm_vec2u* this, glmm_vec2u* other)
{
    assert(this != NULL);
    assert(other != NULL);

    this->x -= other->x;
    this->y -= other->y;
}

void glmm_vec2_print(glmm_vec2* this)
{
    assert(this != NULL);

    printf("[ %f, %f ]", this->x, this->y);
}

void glmm_vec2i_print(glmm_vec2i* this)
{
    assert(this != NULL);

    printf("[ %d, %d ]", this->x, this->y);
}

void glmm_vec2u_print(glmm_vec2u* this)
{
    assert(this != NULL);

    printf("[ %u, %u ]", this->x, this->y);
}
