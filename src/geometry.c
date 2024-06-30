#include "geometry.h"
#include "interval.h"
#include "ray.h"
#include "vec3.h"
#include <math.h>


color ray_getColor(ray *r, const scene *s, int depth) {

    if(depth <= 0) {
        return (color) {0, 0, 0};
    }

    // Determine where on a sphere a ray may hit

    hit_record record;
    if(hit_scene(s, r, (interval) {0.001, INFINITY}, &record)) {
        vec3 direction = vec_randomSurfaceNormalOnHemisphere(&record.normal);

        ray tmpRay = (ray) {record.p, direction};
        color tmpColor = ray_getColor(&tmpRay, s, depth-1);
        return vec_muld(&tmpColor, 0.5);
    }

    // If a ray did not hit the sphere (draw background)

    vec3 unit_dir = vec_unit(&r->dir);
    
    double a = 0.5 * (vec_y(&unit_dir) + 1);
    
    color c1 = vec_muld(& (color){1.0, 1.0, 1.0}, (1.0-a));
    color c2 = vec_muld(& (color){0.5, 0.7, 1.0}, a);

    return vec_add(&c1, &c2);
}

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

bool hit_sphere(const surface *s, const ray *r, interval ray_t, hit_record *record) {
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
    if(!interval_surrounds(&ray_t, root)) {
        root = (-half_b + sqrtd) / a;
        if(!interval_surrounds(&ray_t, root)) {
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

bool hit_scene(const scene *s, const ray *r, interval ray_t, hit_record *record) {
    hit_record tmp_record;
    bool didHitSurface = false;
    double closest = ray_t.max;

    for (int i = 0; i < s->surface_count; i++) {
        const surface *current_surface = &s->surfaces[i];
        switch (current_surface->type) {
            case SURFACE_SPHERE:
                if (hit_sphere(current_surface, r, ray_t, &tmp_record)) {
                    didHitSurface = true;
                    closest = tmp_record.t;
                    *record = tmp_record;
                }
                break;
        }
    
    }
    return didHitSurface;
}
