#include <stdbool.h>

#include "vec3.h"
#include "geometry.h"
#include "camera.h"
// #include "utilities.h"

int main() {
    camera cam;
    init_camera(&cam, 16.0/9.0, 400);

    scene s;
    init_scene(&s);
    
    append_sphere(&s, (loc3) {0, -100.5, -1}, 100);
    append_sphere(&s, (loc3) {0, 0, -1}, 0.5);
    
    camera_render(&cam, &s);
}
