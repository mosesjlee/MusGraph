#ifndef _mySketch__Wavetable_H
#define _mySketch__Wavetable_H
#define USE_MATH_DEFINES
#define MAX_SAMPLES 4096
#define SR 44100
#define WT_HEIGHT 30
#define WT_WIDTH 50

#include "ElementObject.h"
#include "TickableElement.h"
#include <math.h>
class WaveTable : public TickableElement
{
public:
    WaveTable();
    WaveTable(int, int);
    ~WaveTable();
    void setFreq(float);
    void setInput(ElementObject *);
    double tick();
    void draw();

private:
    WaveTable * sinePtr;
    ElementObject * input = NULL;
    double * table;
    double initialPhase;
    double delta_i;
    double index;
    double freq;
    //For the visual representation
    ofRectangle sineTab;
    
    
    
    //Do i need?
    double lerp(double, double, double, double, double);
};
#endif
