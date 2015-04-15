#ifndef _mySketch__Wavetable_H
#define _mySketch__Wavetable_H
#define USE_MATH_DEFINES
#define MAX_SAMPLES 4096
#define SR 44100

#include "ElementObject.h"
#include <math.h>
class WaveTable : public ElementObject
{
public:
    WaveTable();
    WaveTable(int, int);
    ~WaveTable();
    void setFreq(double);
    double tick();
    void draw();

private:
    double * table;
    double initialPhase;
    double delta_i;
    double index;

    //For the visual representation
    ofRectangle sineTab;
    
    //Do i need?
    double lerp(double, double, double, double, double);
};
#endif
