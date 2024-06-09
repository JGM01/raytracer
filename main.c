#include <stdio.h>

#define IMAGE_WIDTH 256
#define IMAGE_HEIGHT 256

int main() {
    printf("P3\n%d %d\n255\n", IMAGE_WIDTH, IMAGE_HEIGHT);

    for(int j = 0; j < IMAGE_HEIGHT; j++) {
        for(int i = 0; i < IMAGE_WIDTH; i++) {
            double r = (double) i / (IMAGE_WIDTH-1);
            double g = (double) j / (IMAGE_HEIGHT-1);
            double b = 0.0;

            int ir = (int) (255.999 * r);
            int ig = (int) (255.999 * g);
            int ib = (int) (255.999 * b);
            
            printf("%d %d %d\n", ir, ig, ib);
        }
    }
}
