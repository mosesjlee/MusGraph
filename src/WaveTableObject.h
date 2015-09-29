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
#include "DelayLineObject.h"


class WaveTableObject : public TickableElement{
public:
    WaveTableObject(int x, int y);
    ~WaveTableObject();
    void tick();
    void setInput(ElementObject *);
    void setFreq(float);
    void setDelayLine(DelayLineObject * dl);
    float * getOutBuffer();
    void setReadBuffer(float * r);
    
protected:
    WaveTable * mySine;
    ElementObject * input = NULL;
    float * outBuffer;
    float * readBuffer = NULL;
    int outIndex = 0;
    int readIndex = 0;
    bool readBufferConnected = false;
};

#endif /* defined(__MusGraph__WaveTableObject__) */
