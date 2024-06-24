#ifndef VEC3_H
#define VEC3_H

typedef struct {
    double e[3];
} vec3;

typedef vec3 color;
typedef vec3 loc3;

double vec_x(const vec3 *v);
double vec_y(const vec3 *v);
double vec_z(const vec3 *v);

vec3 vec_negate(const vec3 *v);

vec3 vec_sub(const vec3 *lhs, const vec3 *rhs);
vec3 vec_add(const vec3 *lhs, const vec3 *rhs);

vec3 vec_mulv(const vec3 *lhs, const vec3 *rhs);
vec3 vec_muld(const vec3 *lhs, const double rhs);

vec3 vec_div(const vec3 *lhs, const double rhs);

double vec_dot(const vec3 *lhs, const vec3 *rhs);
vec3 vec_cross(const vec3 *lhs, const vec3 *rhs);
vec3 vec_unit(const vec3 *v);

double vec_len(const vec3 *v);

double vec_len_squared(const vec3 *v);

void color_print(const vec3 *v);

#endif
