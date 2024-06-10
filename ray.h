#ifndef RAY_H
#define RAY_H

#include "vec3.h"

typedef struct {
    loc3 orig;
    vec3 dir;
} ray;

loc3 ray_orig(ray *r);
vec3 ray_dir(ray *r);

loc3 ray_at(ray *r, double t);

#endif

