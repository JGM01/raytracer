#include "interval.h"

void init_interval(interval *i, double min, double max) {
    i->min = min;
    i->max = max;
}

double interval_size(interval *i) {
    return i->max - i->min;
}

bool interval_contains(interval *i, double x) {
    return i->min <= x && x <= i->max;
}

bool interval_surrounds(interval *i, double x) {
    return i->min < x && x < i->max;
}
