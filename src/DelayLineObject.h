//
//  DelayLineObject.h
//  MusGraph
//
//  Created by Moses Lee on 5/1/15.
//
//

#ifndef __MusGraph__DelayLineObject__
#define __MusGraph__DelayLineObject__
#define DELAY_HEIGHT 30
#define DELAY_WIDTH 95

#include <stdio.h>
#include "TickableElement.h"
#include "delayl.h"

class DelayLineObject : public TickableElement{
public:

    DelayLineObject(int x_coord, int y_coord, int id);
    DelayLineObject(int size, int id);
    ~DelayLineObject();
    void setInput(TickableElement *);
    void setOutput(TickableElement *);
    void setDelayTime(float time);
    float tick(float);
    float tick();
    float getCurrentOut();
    
private:
    DelayLine * delay = NULL;
    TickableElement * input = NULL;
    TickableElement * output = NULL;
    float xN = 0.0f;
    float * outBuffer;
    int outIndex = 0;
    
    
};

#endif /* defined(__MusGraph__DelayLineObject__) */
