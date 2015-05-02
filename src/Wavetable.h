#ifndef _mySketch__Wavetable_H
#define _mySketch__Wavetable_H
#define USE_MATH_DEFINES
#define MAX_SAMPLES 4096
#define SR 44100

#include <math.h>
class WaveTable
{
public:
    WaveTable();
    WaveTable(int, int);
    ~WaveTable();
    void setFreq(float);
    float tick();

private:
    float * table;
    float initialPhase;
    float delta_i;
    float index;
    float freq;
    
    
    
    //Do i need?
    double lerp(double, double, double, double, double);
};
#endif
