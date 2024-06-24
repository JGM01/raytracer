#include "geometry.h"
#include "ray.h"
#include "vec3.h"
#include <math.h>

void init_scene(scene *s) {
    s->surface_count = 0;
}
/*
 * append_sphere
 * 
 * @s: ptr to scene.
 * @center: center xyz of sphere to be added.
 * @radius: radius of sphere to be added.
 *
 * Return: index of added scene, or -1 if invalid.
 * */
int append_sphere(scene *s, loc3 center, double radius) {
    if(s->surface_count >= MAX_SURFACES) {
        return -1;
    }

    surface *new_surface = &s->surfaces[s->surface_count++];
    new_surface->type = SURFACE_SPHERE;
    new_surface->data.sphere.center = center;
    new_surface->data.sphere.radius = radius;

    return s->surface_count-1;
}

bool hit_sphere(const surface *s, const ray *r, double t_min, double t_max, hit_record *record) {
    vec3 oc = vec_sub(&r->orig, &s->data.sphere.center);
    double a = vec_len_squared(&r->dir);
    double half_b = vec_dot(&oc, &r->dir);

    double c = vec_len_squared(&oc) - s->data.sphere.radius * s->data.sphere.radius;
    
    double discriminant = half_b * half_b - a * c;
    if(discriminant < 0) {
        return false;
    }
    double sqrtd = sqrt(discriminant);

    double root = (-half_b - sqrtd) / a;
    if(root < t_min || t_max < root) {
        root = (-half_b + sqrtd) / a;
        if(root < t_min || t_max < root) {
            return false;
        }
    }

    record->t = root;
    record->p = ray_at(r, record->t);
    vec3 tmp = vec_sub(&record->p, &s->data.sphere.center);
    vec3 outward_normal = vec_div(&tmp, s->data.sphere.radius);
    record->normal = outward_normal;

    return true;
}

bool hit_scene(const scene *s, const ray *r, double t_min, double t_max, hit_record *record) {
    hit_record tmp_record;
    bool didHitSurface = false;
    double closest = t_max;

    for (int i = 0; i < s->surface_count; i++) {
        const surface *current_surface = &s->surfaces[i];
        switch (current_surface->type) {
            case SURFACE_SPHERE:
                if (hit_sphere(current_surface, r, t_min, t_max, &tmp_record)) {
                    didHitSurface = true;
                    closest = tmp_record.t;
                    *record = tmp_record;
                }
                break;
        }
    
    }
    return didHitSurface;
}
