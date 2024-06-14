#include "vec3.h"

#include <stdio.h>
#include <math.h>

double vec_x(vec3 *v) {
    return v->e[0];
}

double vec_y(vec3 *v) {
    return v->e[1];
}

double vec_z(vec3 *v) {
    return v->e[2];
}

vec3 vec_negate(vec3 *v) {
    vec3 res;
    res.e[0] = -v->e[0];
    res.e[1] = -v->e[1];
    res.e[2] = -v->e[2];
    return res;
}

double vec_len(vec3 *v) {
    return sqrt(vec_len_squared(v));
}

double vec_len_squared(vec3 *v) {
    return v->e[0]*v->e[0] + 
           v->e[1]*v->e[1] + 
           v->e[2]*v->e[2];
}

vec3 vec_sub(vec3 *lhs, vec3 *rhs) {
    vec3 res;
    res.e[0] = lhs->e[0] - rhs->e[0];
    res.e[1] = lhs->e[1] - rhs->e[1];
    res.e[2] = lhs->e[2] - rhs->e[2];
    return res;
}

vec3 vec_add(vec3 *lhs, vec3 *rhs) { 
    vec3 res;
    res.e[0] = lhs->e[0] + rhs->e[0];
    res.e[1] = lhs->e[1] + rhs->e[1];
    res.e[2] = lhs->e[2] + rhs->e[2];
    return res;
}

vec3 vec_mulv(vec3 *lhs, vec3 *rhs) { 
    vec3 res;
    res.e[0] = lhs->e[0] * rhs->e[0];
    res.e[1] = lhs->e[1] * rhs->e[1];
    res.e[2] = lhs->e[2] * rhs->e[2];
    return res;
}

vec3 vec_muld(vec3 *lhs, double rhs) { 
    vec3 res;
    res.e[0] = lhs->e[0] * rhs;
    res.e[1] = lhs->e[1] * rhs;
    res.e[2] = lhs->e[2] * rhs;
    return res;
}

vec3 vec_div(vec3 *lhs, double rhs) {
    return vec_muld(lhs, (1/rhs));
}

double vec_dot(vec3 *lhs, vec3 *rhs) {
    return lhs->e[0] * rhs->e[0] +
        lhs->e[1] * rhs->e[1] +
        lhs->e[2] * rhs->e[2];
}

vec3 vec_cross(vec3 *lhs, vec3 *rhs) {
    vec3 res;
    res.e[0] = lhs->e[1] * rhs->e[2] - lhs->e[2] * rhs->e[1];
    res.e[1] = lhs->e[2] * rhs->e[0] - lhs->e[0] * rhs->e[2];
    res.e[2] = lhs->e[0] * rhs->e[1] - lhs->e[1] * rhs->e[0];
    return res;
}

vec3 vec_unit(vec3 *v) {
    return vec_div(v, vec_len(v));
}

// COLOR UTILS

void color_print(vec3 *v) {
    double r = vec_x(v);
    double g = vec_y(v);
    double b = vec_z(v);

    int rbyte = (int) (255.999 * r);
    int gbyte = (int) (255.999 * g);
    int bbyte = (int) (255.999 * b);

    printf("%d %d %d\n", rbyte, gbyte, bbyte);
}
