
#define GLMM_VEC2_FUNCS(ID, TYPE, FMT, PREFIX, VECTYPE)                         \
                                                                                \
    GLMM_VEC_COMMON_FUNCS(2, ID, TYPE, PREFIX, VECTYPE)                         \
                                                                                \
    static inline bool PREFIX##_eq(const VECTYPE * this, const VECTYPE * other) \
    {                                                                           \
        return (this->x == other->x && this->y == other->y);                    \
    }                                                                           \
                                                                                \
    static inline void PREFIX##_print(const VECTYPE * this)                     \
    {                                                                           \
        printf("[ " FMT ", " FMT "]\n", this->x, this->y);                      \
    }

#define GLMM_VEC3_FUNCS(ID, TYPE, FMT, PREFIX, VECTYPE)                                               \
                                                                                                      \
    GLMM_VEC_COMMON_FUNCS(3, ID, TYPE, PREFIX, VECTYPE)                                               \
                                                                                                      \
    static inline bool PREFIX##_eq(const VECTYPE * this, const VECTYPE * other)                       \
    {                                                                                                 \
        return (this->x == other->x && this->y == other->y && this->z == other->z);                   \
    }                                                                                                 \
                                                                                                      \
    static inline void PREFIX##_print(const VECTYPE * this)                                           \
    {                                                                                                 \
        printf("[ " FMT ", " FMT "," FMT "]\n", this->x, this->y, this->z);                           \
    }                                                                                                 \
                                                                                                      \
    static inline void PREFIX##_xcross(VECTYPE * result, const VECTYPE * this, const VECTYPE * other) \
    {                                                                                                 \
        VECTYPE tmp;                                                                                  \
        tmp.x = this->y * other->z - this->z * other->y;                                              \
        tmp.y = this->z * other->x - this->x * other->z;                                              \
        tmp.z = this->x * other->y - this->y * other->x;                                              \
        PREFIX##_copy(result, &tmp);                                                                  \
    }                                                                                                 \
                                                                                                      \
    static inline void PREFIX##_cross(VECTYPE * this, const VECTYPE * other)                          \
    {                                                                                                 \
        PREFIX##_xcross(this, this, other);                                                           \
    }

#define GLMM_VEC4_FUNCS(ID, TYPE, FMT, PREFIX, VECTYPE)                                                    \
                                                                                                           \
    GLMM_VEC_COMMON_FUNCS(4, ID, TYPE, PREFIX, VECTYPE)                                                    \
                                                                                                           \
    static inline bool PREFIX##_eq(const VECTYPE * this, const VECTYPE * other)                            \
    {                                                                                                      \
        return (this->x == other->x && this->y == other->y && this->z == other->z && this->w == other->w); \
    }                                                                                                      \
                                                                                                           \
    static inline void PREFIX##_print(const VECTYPE * this)                                                \
    {                                                                                                      \
        printf("[ " FMT ", " FMT "," FMT "," FMT "]\n", this->x, this->y, this->z, this->w);               \
    }                                                                                                      \
                                                                                                           \
    static inline void PREFIX##_xcross(VECTYPE * result, const VECTYPE * this, const VECTYPE * other)      \
    {                                                                                                      \
        VECTYPE tmp;                                                                                       \
        tmp.x = this->y * other->z - this->z * other->y;                                                   \
        tmp.y = this->z * other->x - this->x * other->z;                                                   \
        tmp.z = this->x * other->y - this->y * other->x;                                                   \
        tmp.w = 1.0f;                                                                                      \
        PREFIX##_copy(result, &tmp);                                                                       \
    }                                                                                                      \
                                                                                                           \
    static inline void PREFIX##_cross(VECTYPE * this, const VECTYPE * other)                               \
    {                                                                                                      \
        PREFIX##_xcross(this, this, other);                                                                \
    }

#define GLMM_VEC_COMMON_FUNCS(N, ID, TYPE, PREFIX, VECTYPE)                                         \
                                                                                                    \
    static inline void PREFIX##_init(VECTYPE * this, TYPE value)                                    \
    {                                                                                               \
        for (unsigned int i = 0; i < N; ++i)                                                        \
            this->data[i] = value;                                                                  \
    }                                                                                               \
                                                                                                    \
    static inline void PREFIX##_copy(VECTYPE * this, const VECTYPE * other)                         \
    {                                                                                               \
        memcpy(this, other, sizeof(VECTYPE));                                                       \
    }                                                                                               \
                                                                                                    \
    static inline void PREFIX##_xadd(VECTYPE * result, const VECTYPE * this, const VECTYPE * other) \
    {                                                                                               \
        for (unsigned int i = 0; i < N; ++i)                                                        \
            result->data[i] = this->data[i] + other->data[i];                                       \
    }                                                                                               \
                                                                                                    \
    static inline void PREFIX##_xadds(VECTYPE * result, const VECTYPE * this, TYPE scalar)          \
    {                                                                                               \
        for (unsigned int i = 0; i < N; ++i)                                                        \
            result->data[i] = this->data[i] + scalar;                                               \
    }                                                                                               \
                                                                                                    \
    static inline void PREFIX##_add(VECTYPE * this, const VECTYPE * other)                          \
    {                                                                                               \
        PREFIX##_xadd(this, this, other);                                                           \
    }                                                                                               \
                                                                                                    \
    static inline void PREFIX##_adds(VECTYPE * this, TYPE scalar)                                   \
    {                                                                                               \
        PREFIX##_xadds(this, this, scalar);                                                         \
    }                                                                                               \
                                                                                                    \
    static inline void PREFIX##_xsub(VECTYPE * result, const VECTYPE * this, const VECTYPE * other) \
    {                                                                                               \
        for (unsigned int i = 0; i < N; ++i)                                                        \
            result->data[i] = this->data[i] - other->data[i];                                       \
    }                                                                                               \
                                                                                                    \
    static inline void PREFIX##_xsubs(VECTYPE * result, const VECTYPE * this, TYPE scalar)          \
    {                                                                                               \
        for (unsigned int i = 0; i < N; ++i)                                                        \
            result->data[i] = this->data[i] - scalar;                                               \
    }                                                                                               \
                                                                                                    \
    static inline void PREFIX##_sub(VECTYPE * this, const VECTYPE * other)                          \
    {                                                                                               \
        PREFIX##_xsub(this, this, other);                                                           \
    }                                                                                               \
                                                                                                    \
    static inline void PREFIX##_subs(VECTYPE * this, TYPE scalar)                                   \
    {                                                                                               \
        PREFIX##_xsubs(this, this, scalar);                                                         \
    }                                                                                               \
                                                                                                    \
    static inline void PREFIX##_xmul(VECTYPE * result, const VECTYPE * this, const VECTYPE * other) \
    {                                                                                               \
        for (unsigned int i = 0; i < N; ++i)                                                        \
            result->data[i] = this->data[i] * other->data[i];                                       \
    }                                                                                               \
                                                                                                    \
    static inline void PREFIX##_xmuls(VECTYPE * result, const VECTYPE * this, TYPE scalar)          \
    {                                                                                               \
        for (unsigned int i = 0; i < N; ++i)                                                        \
            result->data[i] = this->data[i] * scalar;                                               \
    }                                                                                               \
                                                                                                    \
    static inline void PREFIX##_mul(VECTYPE * this, const VECTYPE * other)                          \
    {                                                                                               \
        PREFIX##_xmul(this, this, other);                                                           \
    }                                                                                               \
                                                                                                    \
    static inline void PREFIX##_muls(VECTYPE * this, TYPE scalar)                                   \
    {                                                                                               \
        PREFIX##_xmuls(this, this, scalar);                                                         \
    }                                                                                               \
                                                                                                    \
    static inline void PREFIX##_xdiv(VECTYPE * result, const VECTYPE * this, const VECTYPE * other) \
    {                                                                                               \
        for (unsigned int i = 0; i < N; ++i)                                                        \
            result->data[i] = this->data[i] / other->data[i];                                       \
    }                                                                                               \
                                                                                                    \
    static inline void PREFIX##_xdivs(VECTYPE * result, const VECTYPE * this, TYPE scalar)          \
    {                                                                                               \
        for (unsigned int i = 0; i < N; ++i)                                                        \
            result->data[i] = this->data[i] / scalar;                                               \
    }                                                                                               \
                                                                                                    \
    static inline void PREFIX##_div(VECTYPE * this, const VECTYPE * other)                          \
    {                                                                                               \
        PREFIX##_xdiv(this, this, other);                                                           \
    }                                                                                               \
                                                                                                    \
    static inline void PREFIX##_divs(VECTYPE * this, TYPE scalar)                                   \
    {                                                                                               \
        PREFIX##_xdivs(this, this, scalar);                                                         \
    }                                                                                               \
                                                                                                    \
    static inline TYPE PREFIX##_len(const VECTYPE * this)                                           \
    {                                                                                               \
        TYPE sum = 0;                                                                               \
        for (unsigned int i = 0; i < N; ++i)                                                        \
            sum += this->data[i] * this->data[i];                                                   \
        return (TYPE)sqrt(sum);                                                                     \
    }                                                                                               \
                                                                                                    \
    static inline TYPE PREFIX##_dot(const VECTYPE * this, const VECTYPE * other)                    \
    {                                                                                               \
        TYPE result = 0;                                                                            \
        for (unsigned int i = 0; i < N; ++i)                                                        \
            result += this->data[i] * other->data[i];                                               \
        return result;                                                                              \
    }                                                                                               \
                                                                                                    \
    static inline void PREFIX##_norm(VECTYPE * this)                                                \
    {                                                                                               \
        TYPE len = PREFIX##_len(this);                                                              \
        for (unsigned int i = 0; i < N; ++i)                                                        \
            this->data[i] /= len;                                                                   \
    }                                                                                               \
                                                                                                    \
    static inline void PREFIX##_xnorm(VECTYPE * result, const VECTYPE * this)                       \
    {                                                                                               \
        TYPE len = PREFIX##_len(this);                                                              \
        for (unsigned int i = 0; i < N; ++i)                                                        \
            result->data[i] = this->data[i] / len;                                                  \
    }
