#include <stdio.h>
#include <stdbool.h>

#include "vec3.h"
#include "ray.h"
#include "geometry.h"
#include "camera.h"

int main() {
    camera cam;
    init_camera(&cam, 16.0/9.0, 400);

    scene s;
    init_scene(&s);
    append_sphere(&s, (loc3) {0, 0, -1}, 0.5);
    append_sphere(&s, (loc3) {.5, 0, -1}, 0.4);
    append_sphere(&s, (loc3) {-.5, 0, -1}, 0.25);

    printf("P3\n%d %d\n255\n", cam.width, cam.height);
    
    for(int j = 0; j < cam.height; j++) {
        for(int i = 0; i < cam.width; i++) {
            ray r = camera_getRay(&cam, i, j);
            color pixel_color = ray_getColor(&r, &s);
            color_print(&pixel_color);
        }
    }
}
