#include "utilities.h"
#include <stdlib.h>

double random_double(double min, double max) {
    return min + (max-min)*(rand()/(RAND_MAX + 1.0));
}
