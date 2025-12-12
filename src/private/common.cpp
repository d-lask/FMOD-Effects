#include "common.h"
#include <math.h>

float sinWave(float freq, float t) {
    return sinf(2.0f * M_PI * t);
}

float squareWave(float freq, float t) {
    const float val = sinWave(freq, t);
    if(val >= 0.0f) {
        return 1.0f;
    } else {
        return -1.0f;
    }
}

float triangleWave(float freq, float t) {
    const float floorval = floor(t + 0.5f);
    return (4.0f * abs(t - floorval)) - 1.0f;
}

float sawWave(float freq, float t) {
    // todo: figure out how to do this
    return 0.0f;
}
