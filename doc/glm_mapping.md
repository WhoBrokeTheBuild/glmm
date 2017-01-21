# Constants

| GLM                    | GLMM                   |
|------------------------|------------------------|
| glm::epsilon           | GLMM_EPSILON           |
| glm::pi                | GLMM_PI                |
| glm::two_pi            | GLMM_TWO_PI            |
| glm::root_pi           | GLMM_ROOT_PI           |
| glm::half_pi           | GLMM_HALF_PI           |
| glm::three_over_two_pi | GLMM_THREE_OVER_TWO_PI |
| glm::quarter_pi        | GLMM_QUARTER_PI        |
| glm::one_over_pi       | GLMM_ONE_OVER_PI       |
| glm::one_over_two_pi   | GLMM_ONE_OVER_TWO_PI   |
| glm::two_over_pi       | GLMM_TWO_OVER_PI       |
| glm::four_over_pi      | GLMM_FOUR_OVER_PI      |
| glm::two_over_root_pi  | GLMM_TWO_OVER_ROOT_PI  |
| glm::one_over_root_two | GLMM_ONE_OVER_ROOT_TWO |
| glm::root_half_pi      | GLMM_ROOT_HALF_PI      |
| glm::root_two_pi       | GLMM_ROOT_TWO_PI       |
| glm::root_ln_four      | GLMM_ROOT_LN_FOUR      |
| glm::e                 | GLMM_E                 |
| glm::euler             | GLMM_EULER             |
| glm::root_two          | GLMM_ROOT_TWO          |
| glm::root_three        | GLMM_ROOT_THREE        |
| glm::root_five         | GLMM_ROOT_FIVE         |
| glm::ln_two            | GLMM_LN_TWO            |
| glm::ln_ten            | GLMM_LN_TEN            |
| glm::ln_ln_two         | GLMM_LN_LN_TWO         |
| glm::third             | GLMM_THIRD             |
| glm::two_thirds        | GLMM_TWO_THIRDS        |
| glm::golden_ratio      | GLMM_GOLDEN_RATIO      |

# Types

| GLM       | GLMM                                     |
|-----------|------------------------------------------|
| glm::vec2 | glmm_vec2f_t, glmm_vec2i_t, glmm_vec2u_t |
| glm::vec3 | glmm_vec3f_t, glmm_vec3i_t, glmm_vec3u_t |
| glm::vec4 | glmm_vec4f_t, glmm_vec4i_t, glmm_vec4u_t |
| glm::quat | glmm_quat_t                              |
| glm::mat2 | glmm_mat2x2_t                            |
| glm::mat3 | glmm_mat3x3_t                            |
| glm::mat4 | glmm_mat4x4_t                            |

# Class Functions

| GLM  | GLMM      |
|------|-----------|
| ctor | TYPE_init |
| dtor | N/A       |

# Operators

| GLM        | GLMM                  |
|------------|-----------------------|
| =          | TYPE_copy             |
| + (TYPE)   | TYPE_add, TYPE_xadd   |
| + (scalar) | TYPE_adds, TYPE_xadds |
| - (TYPE)   | TYPE_sub, TYPE_xsub   |
| - (scalar) | TYPE_subs, TYPE_xsubs |
| * (TYPE)   | TYPE_mul, TYPE_xmul   |
| * (scalar) | TYPE_muls, TYPE_xmuls |
| / (TYPE)   | TYPE_div, TYPE_xdiv   |
| / (scalar) | TYPE_divs, TYPE_xdivs |

# Vector Functions
