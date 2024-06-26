#ifndef CAMERA_H
#define CAMERA_H

#include "ray.h"

typedef struct {
    double ratio;
    int width;
    int height;

    loc3 position;
    loc3 pixel00_position;

    vec3 pixel_delta_u;
    vec3 pixel_delta_v;
} camera;

void init_camera(camera *c, double ratio, int width);
ray camera_getRay(const camera *c, int i, int j);

#endif

