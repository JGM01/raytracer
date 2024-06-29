#include <stdio.h>

#include "camera.h"
#include "ray.h"
#include "vec3.h"

void init_camera(camera *c, double ratio, int width) {
    c->ratio = ratio;
    c->width = width;
    c->height = (int) (width / ratio);

    if(c->height < 1) {
        c->height = 1;
    }

    double focal_length = 1.0;
    double viewport_height = 2.0;
    double viewport_width = viewport_height * ((double)c->width/c->height);

    c->position = (loc3) {{0, 0, 0}};

    vec3 viewport_u = {{viewport_width, 0, 0}};
    vec3 viewport_v = {{0, -viewport_height, 0}};

    c->pixel_delta_u = vec_div(&viewport_u, c->width);
    c->pixel_delta_v = vec_div(&viewport_v, c->height);

    loc3 viewport_upper_left = vec_sub(&c->position, &(vec3){{0, 0, focal_length}});
    vec3 half_viewport_u = vec_div(&viewport_u, 2);
    vec3 half_viewport_v = vec_div(&viewport_v, 2);
    viewport_upper_left = vec_sub(&viewport_upper_left, &half_viewport_u);
    viewport_upper_left = vec_sub(&viewport_upper_left, &half_viewport_v);

    vec3 pixel_delta_sum = vec_add(&c->pixel_delta_u, &c->pixel_delta_v);
    vec3 pixel_delta_half = vec_muld(&pixel_delta_sum, 0.5);
    c->pixel00_position = vec_add(&viewport_upper_left, &pixel_delta_half);
}

ray camera_getRay(const camera *c, int i, int j) {
    vec3 u = vec_muld(&c->pixel_delta_u, i);
    vec3 v = vec_muld(&c->pixel_delta_v, j);
    vec3 uv = vec_add(&u, &v);

    loc3 pixel_center = vec_add(&c->pixel00_position, &uv);
    vec3 ray_direction = vec_sub(&pixel_center, &c->position);

    return (ray) {c->position, ray_direction};
}

void camera_render(const camera *c, const scene *s) {
    printf("P3\n%d %d\n255\n", c->width, c->height);
    
    for(int j = 0; j < c->height; j++) {
        for(int i = 0; i < c->width; i++) {
            ray r = camera_getRay(c, i, j);
            color pixel_color = ray_getColor(&r, s);
            color_print(&pixel_color);
        }
    }
}
