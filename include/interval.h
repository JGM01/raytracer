#ifndef INTERVAL_H
#define INTERVAL_H

#include <stdbool.h>

typedef struct {
    double min, max;
} interval;

void init_interval(interval *i, double min, double max);

double interval_size(interval *i);

bool interval_contains(interval *i, double x);

bool interval_surrounds(interval *i, double x);

#endif
