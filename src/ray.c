#include "ray.h"

loc3 ray_orig(ray *r) {
    return r->orig;
}

vec3 ray_dir(ray *r) {
    return r->dir;
}

loc3 ray_at(ray *r, double t) {
    vec3 tmp = vec_muld(&r->dir, t);
    return vec_add(&r->orig, &tmp);
}
