#ifndef CAMERA_H
#define CAMERA_H

#include "geometry.h"
#include "ray.h"

typedef struct {
    double ratio;
    int width;
    int height;

    int samples_per_pixel;
    double pixel_samples_scale;

    loc3 position;
    loc3 pixel00_position;

    vec3 pixel_delta_u;
    vec3 pixel_delta_v;
} camera;

void init_camera(camera *c, double ratio, int width);
ray camera_getRay(const camera *c, int i, int j);
void camera_render(const camera *c, const scene *s);
#endif

