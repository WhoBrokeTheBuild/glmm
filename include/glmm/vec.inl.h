
#define GLMM_VEC2_SHORT(ID, DATA) \
    GLMM_VEC2_SHORT_IMP(ID, DATA, glmm_vec2##ID, vec2##ID, glmm_vec2##ID##_t, vec2##ID##_t)

#define GLMM_VEC2_SHORT_IMP(ID, DATA, PREFIX, SHORT_PREFIX, TYPE, SHORT_TYPE)                \
                                                                                             \
    typedef TYPE SHORT_TYPE;                                                                 \
                                                                                             \
    static bool (*SHORT_PREFIX##_eq)(const SHORT_TYPE *, const SHORT_TYPE *) = &PREFIX##_eq; \
    static void (*SHORT_PREFIX##_print)(const SHORT_TYPE *) = &PREFIX##_print;               \
                                                                                             \
    GLMM_VEC_COMMON_SHORT(ID, DATA, PREFIX, SHORT_PREFIX, TYPE, SHORT_TYPE)

#define GLMM_VEC2_FUNCS(ID, DATA, FMT, PREFIX, TYPE)                      \
                                                                          \
    GLMM_VEC_COMMON_FUNCS(2, ID, DATA, PREFIX, TYPE)                      \
                                                                          \
    static inline bool PREFIX##_eq(const TYPE * this, const TYPE * other) \
    {                                                                     \
        return (this->x == other->x && this->y == other->y);              \
    }                                                                     \
                                                                          \
    static inline void PREFIX##_print(const TYPE * this)                  \
    {                                                                     \
        printf("[ " FMT ", " FMT "]\n", this->x, this->y);                \
    }

#define GLMM_VEC3_SHORT(ID, DATA) \
    GLMM_VEC3_SHORT_IMP(ID, DATA, glmm_vec3##ID, vec3##ID, glmm_vec3##ID##_t, vec3##ID##_t)

#define GLMM_VEC3_SHORT_IMP(ID, DATA, PREFIX, SHORT_PREFIX, TYPE, SHORT_TYPE)                                      \
                                                                                                                   \
    typedef TYPE SHORT_TYPE;                                                                                       \
                                                                                                                   \
    static bool (*SHORT_PREFIX##_eq)(const SHORT_TYPE *, const SHORT_TYPE *) = &PREFIX##_eq;                       \
    static void (*SHORT_PREFIX##_print)(const SHORT_TYPE *) = &PREFIX##_print;                                     \
    static void (*SHORT_PREFIX##_xcross)(SHORT_TYPE *, const SHORT_TYPE *, const SHORT_TYPE *) = &PREFIX##_xcross; \
    static void (*SHORT_PREFIX##_cross)(SHORT_TYPE *, const SHORT_TYPE *) = &PREFIX##_cross;                       \
                                                                                                                   \
    GLMM_VEC_COMMON_SHORT(ID, DATA, PREFIX, SHORT_PREFIX, TYPE, SHORT_TYPE)

#define GLMM_VEC3_FUNCS(ID, DATA, FMT, PREFIX, TYPE)                                         \
                                                                                             \
    GLMM_VEC_COMMON_FUNCS(3, ID, DATA, PREFIX, TYPE)                                         \
                                                                                             \
    static inline bool PREFIX##_eq(const TYPE * this, const TYPE * other)                    \
    {                                                                                        \
        return (this->x == other->x && this->y == other->y && this->z == other->z);          \
    }                                                                                        \
                                                                                             \
    static inline void PREFIX##_print(const TYPE * this)                                     \
    {                                                                                        \
        printf("[ " FMT ", " FMT "," FMT "]\n", this->x, this->y, this->z);                  \
    }                                                                                        \
                                                                                             \
    static inline void PREFIX##_xcross(TYPE * result, const TYPE * this, const TYPE * other) \
    {                                                                                        \
        TYPE tmp;                                                                            \
        tmp.x = this->y * other->z - this->z * other->y;                                     \
        tmp.y = this->z * other->x - this->x * other->z;                                     \
        tmp.z = this->x * other->y - this->y * other->x;                                     \
        PREFIX##_copy(result, &tmp);                                                         \
    }                                                                                        \
                                                                                             \
    static inline void PREFIX##_cross(TYPE * this, const TYPE * other)                       \
    {                                                                                        \
        PREFIX##_xcross(this, this, other);                                                  \
    }

#define GLMM_VEC4_SHORT(ID, DATA) \
    GLMM_VEC4_SHORT_IMP(ID, DATA, glmm_vec4##ID, vec4##ID, glmm_vec4##ID##_t, vec4##ID##_t)

#define GLMM_VEC4_SHORT_IMP(ID, DATA, PREFIX, SHORT_PREFIX, TYPE, SHORT_TYPE)                                      \
                                                                                                                   \
    typedef TYPE SHORT_TYPE;                                                                                       \
                                                                                                                   \
    static bool (*SHORT_PREFIX##_eq)(const SHORT_TYPE *, const SHORT_TYPE *) = &PREFIX##_eq;                       \
    static void (*SHORT_PREFIX##_print)(const SHORT_TYPE *) = &PREFIX##_print;                                     \
    static void (*SHORT_PREFIX##_xcross)(SHORT_TYPE *, const SHORT_TYPE *, const SHORT_TYPE *) = &PREFIX##_xcross; \
    static void (*SHORT_PREFIX##_cross)(SHORT_TYPE *, const SHORT_TYPE *) = &PREFIX##_cross;                       \
                                                                                                                   \
    GLMM_VEC_COMMON_SHORT(ID, DATA, PREFIX, SHORT_PREFIX, TYPE, SHORT_TYPE)

#define GLMM_VEC4_FUNCS(ID, DATA, FMT, PREFIX, TYPE)                                                       \
                                                                                                           \
    GLMM_VEC_COMMON_FUNCS(4, ID, DATA, PREFIX, TYPE)                                                       \
                                                                                                           \
    static inline bool PREFIX##_eq(const TYPE * this, const TYPE * other)                                  \
    {                                                                                                      \
        return (this->x == other->x && this->y == other->y && this->z == other->z && this->w == other->w); \
    }                                                                                                      \
                                                                                                           \
    static inline void PREFIX##_print(const TYPE * this)                                                   \
    {                                                                                                      \
        printf("[ " FMT ", " FMT "," FMT "," FMT "]\n", this->x, this->y, this->z, this->w);               \
    }                                                                                                      \
                                                                                                           \
    static inline void PREFIX##_xcross(TYPE * result, const TYPE * this, const TYPE * other)               \
    {                                                                                                      \
        TYPE tmp;                                                                                          \
        tmp.x = this->y * other->z - this->z * other->y;                                                   \
        tmp.y = this->z * other->x - this->x * other->z;                                                   \
        tmp.z = this->x * other->y - this->y * other->x;                                                   \
        tmp.w = 1.0f;                                                                                      \
        PREFIX##_copy(result, &tmp);                                                                       \
    }                                                                                                      \
                                                                                                           \
    static inline void PREFIX##_cross(TYPE * this, const TYPE * other)                                     \
    {                                                                                                      \
        PREFIX##_xcross(this, this, other);                                                                \
    }

#define GLMM_VEC_COMMON_SHORT(ID, DATA, PREFIX, SHORT_PREFIX, TYPE, SHORT_TYPE)                                \
                                                                                                               \
    static void (*SHORT_PREFIX##_set)(SHORT_TYPE *, DATA) = &PREFIX##_set;                                     \
    static void (*SHORT_PREFIX##_copy)(SHORT_TYPE *, const SHORT_TYPE *) = &PREFIX##_copy;                     \
    static void (*SHORT_PREFIX##_xadd)(SHORT_TYPE *, const SHORT_TYPE *, const SHORT_TYPE *) = &PREFIX##_xadd; \
    static void (*SHORT_PREFIX##_xadds)(SHORT_TYPE *, const SHORT_TYPE *, DATA) = &PREFIX##_xadds;             \
    static void (*SHORT_PREFIX##_add)(SHORT_TYPE *, const SHORT_TYPE *) = &PREFIX##_add;                       \
    static void (*SHORT_PREFIX##_adds)(SHORT_TYPE *, DATA) = &PREFIX##_adds;                                   \
    static void (*SHORT_PREFIX##_xsub)(SHORT_TYPE *, const SHORT_TYPE *, const SHORT_TYPE *) = &PREFIX##_xsub; \
    static void (*SHORT_PREFIX##_xsubs)(SHORT_TYPE *, const SHORT_TYPE *, DATA) = &PREFIX##_xsubs;             \
    static void (*SHORT_PREFIX##_sub)(SHORT_TYPE *, const SHORT_TYPE *) = &PREFIX##_sub;                       \
    static void (*SHORT_PREFIX##_subs)(SHORT_TYPE *, DATA) = &PREFIX##_subs;                                   \
    static void (*SHORT_PREFIX##_xmul)(SHORT_TYPE *, const SHORT_TYPE *, const SHORT_TYPE *) = &PREFIX##_xmul; \
    static void (*SHORT_PREFIX##_xmuls)(SHORT_TYPE *, const SHORT_TYPE *, DATA) = &PREFIX##_xmuls;             \
    static void (*SHORT_PREFIX##_mul)(SHORT_TYPE *, const SHORT_TYPE *) = &PREFIX##_mul;                       \
    static void (*SHORT_PREFIX##_muls)(SHORT_TYPE *, DATA) = &PREFIX##_muls;                                   \
    static void (*SHORT_PREFIX##_xdiv)(SHORT_TYPE *, const SHORT_TYPE *, const SHORT_TYPE *) = &PREFIX##_xdiv; \
    static void (*SHORT_PREFIX##_xdivs)(SHORT_TYPE *, const SHORT_TYPE *, DATA) = &PREFIX##_xdivs;             \
    static void (*SHORT_PREFIX##_div)(SHORT_TYPE *, const SHORT_TYPE *) = &PREFIX##_div;                       \
    static void (*SHORT_PREFIX##_divs)(SHORT_TYPE *, DATA) = &PREFIX##_divs;                                   \
    static DATA (*SHORT_PREFIX##_len)(const SHORT_TYPE *) = &PREFIX##_len;                                     \
    static DATA (*SHORT_PREFIX##_dot)(const SHORT_TYPE *, const SHORT_TYPE *) = &PREFIX##_dot;                 \
    static void (*SHORT_PREFIX##_norm)(SHORT_TYPE *) = &PREFIX##_norm;                                         \
    static void (*SHORT_PREFIX##_xnorm)(SHORT_TYPE *, const SHORT_TYPE *) = &PREFIX##_xnorm;

#define GLMM_VEC_COMMON_FUNCS(N, ID, DATA, PREFIX, TYPE)                                   \
                                                                                           \
    static inline void PREFIX##_set(TYPE * this, DATA value)                               \
    {                                                                                      \
        for (unsigned int i = 0; i < N; ++i)                                               \
            this->data[i] = value;                                                         \
    }                                                                                      \
                                                                                           \
    static inline void PREFIX##_copy(TYPE * this, const TYPE * other)                      \
    {                                                                                      \
        memcpy(this, other, sizeof(TYPE));                                                 \
    }                                                                                      \
                                                                                           \
    static inline void PREFIX##_xadd(TYPE * result, const TYPE * this, const TYPE * other) \
    {                                                                                      \
        for (unsigned int i = 0; i < N; ++i)                                               \
            result->data[i] = this->data[i] + other->data[i];                              \
    }                                                                                      \
                                                                                           \
    static inline void PREFIX##_xadds(TYPE * result, const TYPE * this, DATA scalar)       \
    {                                                                                      \
        for (unsigned int i = 0; i < N; ++i)                                               \
            result->data[i] = this->data[i] + scalar;                                      \
    }                                                                                      \
                                                                                           \
    static inline void PREFIX##_add(TYPE * this, const TYPE * other)                       \
    {                                                                                      \
        PREFIX##_xadd(this, this, other);                                                  \
    }                                                                                      \
                                                                                           \
    static inline void PREFIX##_adds(TYPE * this, DATA scalar)                             \
    {                                                                                      \
        PREFIX##_xadds(this, this, scalar);                                                \
    }                                                                                      \
                                                                                           \
    static inline void PREFIX##_xsub(TYPE * result, const TYPE * this, const TYPE * other) \
    {                                                                                      \
        for (unsigned int i = 0; i < N; ++i)                                               \
            result->data[i] = this->data[i] - other->data[i];                              \
    }                                                                                      \
                                                                                           \
    static inline void PREFIX##_xsubs(TYPE * result, const TYPE * this, DATA scalar)       \
    {                                                                                      \
        for (unsigned int i = 0; i < N; ++i)                                               \
            result->data[i] = this->data[i] - scalar;                                      \
    }                                                                                      \
                                                                                           \
    static inline void PREFIX##_sub(TYPE * this, const TYPE * other)                       \
    {                                                                                      \
        PREFIX##_xsub(this, this, other);                                                  \
    }                                                                                      \
                                                                                           \
    static inline void PREFIX##_subs(TYPE * this, DATA scalar)                             \
    {                                                                                      \
        PREFIX##_xsubs(this, this, scalar);                                                \
    }                                                                                      \
                                                                                           \
    static inline void PREFIX##_xmul(TYPE * result, const TYPE * this, const TYPE * other) \
    {                                                                                      \
        for (unsigned int i = 0; i < N; ++i)                                               \
            result->data[i] = this->data[i] * other->data[i];                              \
    }                                                                                      \
                                                                                           \
    static inline void PREFIX##_xmuls(TYPE * result, const TYPE * this, DATA scalar)       \
    {                                                                                      \
        for (unsigned int i = 0; i < N; ++i)                                               \
            result->data[i] = this->data[i] * scalar;                                      \
    }                                                                                      \
                                                                                           \
    static inline void PREFIX##_mul(TYPE * this, const TYPE * other)                       \
    {                                                                                      \
        PREFIX##_xmul(this, this, other);                                                  \
    }                                                                                      \
                                                                                           \
    static inline void PREFIX##_muls(TYPE * this, DATA scalar)                             \
    {                                                                                      \
        PREFIX##_xmuls(this, this, scalar);                                                \
    }                                                                                      \
                                                                                           \
    static inline void PREFIX##_xdiv(TYPE * result, const TYPE * this, const TYPE * other) \
    {                                                                                      \
        for (unsigned int i = 0; i < N; ++i)                                               \
            result->data[i] = this->data[i] / other->data[i];                              \
    }                                                                                      \
                                                                                           \
    static inline void PREFIX##_xdivs(TYPE * result, const TYPE * this, DATA scalar)       \
    {                                                                                      \
        for (unsigned int i = 0; i < N; ++i)                                               \
            result->data[i] = this->data[i] / scalar;                                      \
    }                                                                                      \
                                                                                           \
    static inline void PREFIX##_div(TYPE * this, const TYPE * other)                       \
    {                                                                                      \
        PREFIX##_xdiv(this, this, other);                                                  \
    }                                                                                      \
                                                                                           \
    static inline void PREFIX##_divs(TYPE * this, DATA scalar)                             \
    {                                                                                      \
        PREFIX##_xdivs(this, this, scalar);                                                \
    }                                                                                      \
                                                                                           \
    static inline DATA PREFIX##_len(const TYPE * this)                                     \
    {                                                                                      \
        DATA sum = 0;                                                                      \
        for (unsigned int i = 0; i < N; ++i)                                               \
            sum += this->data[i] * this->data[i];                                          \
        return (DATA)sqrt(sum);                                                            \
    }                                                                                      \
                                                                                           \
    static inline DATA PREFIX##_dot(const TYPE * this, const TYPE * other)                 \
    {                                                                                      \
        DATA result = 0;                                                                   \
        for (unsigned int i = 0; i < N; ++i)                                               \
            result += this->data[i] * other->data[i];                                      \
        return result;                                                                     \
    }                                                                                      \
                                                                                           \
    static inline void PREFIX##_norm(TYPE * this)                                          \
    {                                                                                      \
        DATA len = PREFIX##_len(this);                                                     \
        for (unsigned int i = 0; i < N; ++i)                                               \
            this->data[i] /= len;                                                          \
    }                                                                                      \
                                                                                           \
    static inline void PREFIX##_xnorm(TYPE * result, const TYPE * this)                    \
    {                                                                                      \
        DATA len = PREFIX##_len(this);                                                     \
        for (unsigned int i = 0; i < N; ++i)                                               \
            result->data[i] = this->data[i] / len;                                         \
    }
