#include "vec3.h"
#include "interval.h"
#include "utilities.h"

#include <stdio.h>
#include <math.h>

double vec_x(const vec3 *v) {
    return v->e[0];
}

double vec_y(const vec3 *v) {
    return v->e[1];
}

double vec_z(const vec3 *v) {
    return v->e[2];
}

vec3 vec_negate(const vec3 *v) {
    vec3 res;
    res.e[0] = -v->e[0];
    res.e[1] = -v->e[1];
    res.e[2] = -v->e[2];
    return res;
}

double vec_len(const vec3 *v) {
    return sqrt(vec_len_squared(v));
}

double vec_len_squared(const vec3 *v) {
    return v->e[0]*v->e[0] + 
           v->e[1]*v->e[1] + 
           v->e[2]*v->e[2];
}

vec3 vec_sub(const vec3 *lhs, const vec3 *rhs) {
    vec3 res;
    res.e[0] = lhs->e[0] - rhs->e[0];
    res.e[1] = lhs->e[1] - rhs->e[1];
    res.e[2] = lhs->e[2] - rhs->e[2];
    return res;
}

vec3 vec_add(const vec3 *lhs, const vec3 *rhs) { 
    vec3 res;
    res.e[0] = lhs->e[0] + rhs->e[0];
    res.e[1] = lhs->e[1] + rhs->e[1];
    res.e[2] = lhs->e[2] + rhs->e[2];
    return res;
}

vec3 vec_mulv(const vec3 *lhs, const vec3 *rhs) { 
    vec3 res;
    res.e[0] = lhs->e[0] * rhs->e[0];
    res.e[1] = lhs->e[1] * rhs->e[1];
    res.e[2] = lhs->e[2] * rhs->e[2];
    return res;
}

vec3 vec_muld(const vec3 *lhs, const double rhs) { 
    vec3 res;
    res.e[0] = lhs->e[0] * rhs;
    res.e[1] = lhs->e[1] * rhs;
    res.e[2] = lhs->e[2] * rhs;
    return res;
}

vec3 vec_div(const vec3 *lhs, const double rhs) {
    return vec_muld(lhs, (1/rhs));
}

double vec_dot(const vec3 *lhs, const vec3 *rhs) {
    return lhs->e[0] * rhs->e[0] +
        lhs->e[1] * rhs->e[1] +
        lhs->e[2] * rhs->e[2];
}

vec3 vec_cross(const vec3 *lhs, const vec3 *rhs) {
    vec3 res;
    res.e[0] = lhs->e[1] * rhs->e[2] - lhs->e[2] * rhs->e[1];
    res.e[1] = lhs->e[2] * rhs->e[0] - lhs->e[0] * rhs->e[2];
    res.e[2] = lhs->e[0] * rhs->e[1] - lhs->e[1] * rhs->e[0];
    return res;
}

vec3 vec_unit(const vec3 *v) {
    return vec_div(v, vec_len(v));
}

vec3 vec_randomRange(double min, double max) {
    return (vec3) {random_double(min, max), random_double(min, max), random_double(min, max)};
}

vec3 vec_random() {
    return (vec3) {random_double(0, 1), random_double(0, 1), random_double(0, 1)};
}

vec3 vec_randomInUnitSphere() {
    while(true) {
        vec3 p = vec_randomRange(-1, 1);
        if(vec_len_squared(&p) < 1) {
            return p;
        }
    }
}

vec3 vec_randomUnitVector() {
    vec3 randomVecInUnitSphere= vec_randomInUnitSphere();
    return vec_unit(&randomVecInUnitSphere);
}

vec3 vec_randomSurfaceNormalOnHemisphere(const vec3 *normal) {
    vec3 onUnitSphere = vec_randomUnitVector();
    if(vec_dot(&onUnitSphere, normal) > 0.0) {
        return onUnitSphere;
    } else {
        return vec_negate(&onUnitSphere);
    }
}

// COLOR UTILS

double ltog(double linearValue) {
    if(linearValue > 0) {
        return sqrt(linearValue);
    }

    return 0;
}

void color_print(const vec3 *v) {
    double r = vec_x(v);
    double g = vec_y(v);
    double b = vec_z(v);

    r = ltog(r);
    g = ltog(g);
    b = ltog(b);

    interval intensity;
    intensity = (interval) {0.000, 0.999};

    int rbyte = (int) (256.0 * interval_clamp(&intensity, r));
    int gbyte = (int) (256.0 * interval_clamp(&intensity, g));
    int bbyte = (int) (256.0 * interval_clamp(&intensity, b));

    printf("%d %d %d\n", rbyte, gbyte, bbyte);
}
