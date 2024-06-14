#ifndef VEC3_H
#define VEC3_H

typedef struct {
    double e[3];
} vec3;

typedef vec3 color;
typedef vec3 loc3;

double vec_x(vec3 *v);
double vec_y(vec3 *v);
double vec_z(vec3 *v);

vec3 vec_negate(vec3 *v);

vec3 vec_sub(vec3 *lhs, vec3 *rhs);
vec3 vec_add(vec3 *lhs, vec3 *rhs);

vec3 vec_mulv(vec3 *lhs, vec3 *rhs);
vec3 vec_muld(vec3 *lhs, double rhs);

vec3 vec_div(vec3 *lhs, double rhs);

double vec_dot(vec3 *lhs, vec3 *rhs);
vec3 vec_cross(vec3 *lhs, vec3 *rhs);
vec3 vec_unit(vec3 *v);

double vec_len(vec3 *v);

double vec_len_squared(vec3 *v);

void color_print(vec3 *v);

#endif
