#include "ray.h"

loc3 ray_orig(const ray *r) {
    return r->orig;
}

vec3 ray_dir(const ray *r) {
    return r->dir;
}

loc3 ray_at(const ray *r, const double t) {
    vec3 tmp = vec_muld(&r->dir, t);
    return vec_add(&r->orig, &tmp);
}
