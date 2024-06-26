#ifndef RAY_H
#define RAY_H

#include "vec3.h"

typedef struct {
    loc3 orig;
    vec3 dir;
} ray;


loc3 ray_orig(const ray *r);
vec3 ray_dir(const ray *r);

loc3 ray_at(const ray *r, const double t);

#endif

