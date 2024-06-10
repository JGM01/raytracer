#include <stdio.h>
#include "vec3.h"
#include "ray.h"

color ray_color(ray *r) {
    vec3 unit_dir = vec_unit(&r->dir);
    
    double a = 0.5 * (vec_y(&unit_dir) + 1);
    
    color c1 = vec_muld(& (color){1.0, 1.0, 1.0}, (1.0-a));
    color c2 = vec_muld(& (color){0.5, 0.7, 1.0}, a);

    return vec_add(&c1, &c2);
}

int main() {

    double ratio = 16.0/9.0;
    int image_width = 400;

    int image_height = (int) (image_width / ratio);

    if(image_height < 1) {
        image_height = 1;
    }

    double focal_length = 1.0;
    double viewport_height = 2.0;
    double viewport_width = viewport_height * ((double)image_width / image_height);

    loc3 camera_loc = { {0, 0, 0} };

    vec3 viewport_u = { {viewport_width, 0, 0} };
    vec3 viewport_v = { {0, -viewport_height, 0} };

    vec3 pixel_delta_u = vec_div(&viewport_u, image_width);
    vec3 pixel_delta_v = vec_div(&viewport_v, image_height);

    loc3 viewport_upper_left = vec_sub(&camera_loc, &(vec3) { {0, 0, focal_length} });

    vec3 dividedport_u = vec_div(&viewport_u, 2);
    vec3 dividedport_v = vec_div(&viewport_v, 2);
   
    viewport_upper_left = vec_sub(&viewport_upper_left, &dividedport_u);
    viewport_upper_left = vec_sub(&viewport_upper_left, &dividedport_v);

    // -----
    vec3 added_deltas = vec_add(&pixel_delta_u, &pixel_delta_v);
    vec3 mult_deltas = vec_muld(&added_deltas, 0.5);

    loc3 pixel00_loc = vec_add(&viewport_upper_left, &mult_deltas);

    printf("P3\n%d %d\n255\n", image_width, image_height);

    for(int j = 0; j < image_height; j++) {
        for(int i = 0; i < image_width; i++) {
            vec3 u = vec_muld(&pixel_delta_u, i);
            vec3 v = vec_muld(&pixel_delta_v, j);
            vec3 uv = vec_add(&u, &v);

            loc3 pixel_center = vec_add(&pixel00_loc, &uv);
            vec3 ray_direction = vec_sub(&pixel_center,&camera_loc);

            ray r = {camera_loc, ray_direction};
            color pixel_color = ray_color(&r);
            color_print(&pixel_color);
        }
    }
}
