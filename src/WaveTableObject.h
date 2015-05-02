//
//  WaveTableObject.h
//  MusGraph
//
//  Created by Moses Lee on 5/1/15.
//
//

#ifndef __MusGraph__WaveTableObject__
#define __MusGraph__WaveTableObject__

#define WT_HEIGHT 30
#define WT_WIDTH 50

#include <stdio.h>
#include "Wavetable.h"
#include "TickableElement.h"


class WaveTableObject : public TickableElement{
public:
    WaveTableObject(int x, int y);
    ~WaveTableObject();
    float tick();
    void setInput(ElementObject *);
    void setFreq(float);
protected:
    WaveTable * mySine;
    ElementObject * input = NULL;
};

#endif /* defined(__MusGraph__WaveTableObject__) */
