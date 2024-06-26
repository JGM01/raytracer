#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "vec3.h"
#include "ray.h"

#include <stdbool.h>
#define MAX_SURFACES 100


/*
 * hit_record - contains info on ray->surface intersection.
 * 
 * @p: (x, y, z) location of intersection.
 * @normal: normal vector at point of intersection.
 * @t: value at p.
 * */
typedef struct {
    loc3 p;
    vec3 normal;
    double t;
} hit_record;

/*
 * surface_type
 *
 * Makes it easy to distinguish different surface types when in the same array.
 * */
typedef enum {
    SURFACE_SPHERE,
} surface_type;


typedef struct {
    surface_type type;
    union {
        /* Different surface type declarations go here */
        struct {loc3 center; double radius;} sphere;
    } data;
} surface;

typedef struct {
    surface surfaces[MAX_SURFACES];
    int surface_count;
} scene;

void init_scene(scene *s);

int append_sphere(scene *s, loc3 center, double radius);

bool hit_sphere(const surface *s, const ray *r, double t_min, double t_max, hit_record *record);
bool hit_scene(const scene *s, const ray *r, double t_min, double t_max, hit_record *record);

color ray_getColor(ray *r, const scene *s);

#endif
