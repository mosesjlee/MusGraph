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
    void setDelayTime(float time);
    float tick(float);
    void tick();
    float getCurrentOut();
    bool isTickRegion(int x, int y);
    bool isGetCurrOutRegion(int x, int y);
    void draw();
    void setReadBuffer(float * r);
    void setFeedBackBuffer(float * r);
    void fillCurrentOut();
    float * getCurrOutBuffer();
    float * getTickedBuffer();
    float * getBuffer();
    float readInputBuffers();
    
    
private:
    DelayLine * delay = NULL;
    ofRectangle tickRegion;
    ofRectangle currOutRegion;
    vector<float *> inBuffers;
    float xN = 0.0f;
    bool currOutBufferConnected = false;
    bool tickedBufferConnected = false;
    bool readBufConnected = false;
    bool feedbackBufConnected = false;
    float * currOutBuffer;
    float * tickedBuffer;
    float * feedbackBuffer;
    float * readBuf;
    int currTickedIndex = 0;
    int readIndex = 0;
    int currOutIndex = 0;
    
};

#endif /* defined(__MusGraph__DelayLineObject__) */
