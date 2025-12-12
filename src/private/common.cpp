#include "common.h"
#include <math.h>

float sinWave(float freq, float t) {
    return sinf(2.0f * M_PI * t);
}

float squareWave(float freq, float t) {
    float val = sinWave(freq, t);
    if(val >= 0.0f) {
        return 1.0f;
    } else {
        return -1.0f;
    }
}

float triangleWave(float freq, float t) {
    return asinf(cosf(t)) / M_PI_2;
}

float sawWave(float freq, float t) {
    // todo: figure out how to do this
    return 0.0f;
}
