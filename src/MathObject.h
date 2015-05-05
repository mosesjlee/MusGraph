//
//  MathObject.h
//  MusGraph
//
//  Created by Moses Lee on 4/21/15.
//
//

#ifndef MusGraph_MathObject_h
#define MusGraph_MathObject_h

#define MATH_HEIGHT 30
#define MATH_WIDTH 30

#include "TickableElement.h"
#include "NumberBoxObject.h"
#include "WaveTableObject.h"
#include <stdio.h>

class MathObject : public TickableElement{
public:
    virtual void connectElement(ElementObject * o);
    virtual void connectOutElement(WaveTableObject *);
    virtual void setReadBuffers(float * r);
    virtual float * getOutBuffer();
    void draw();
    virtual void setOtherValue(float value);
    
    
protected:
    float * readBuf_1 = NULL, * readBuf_2 = NULL, * outBuf;
    
    float val = 0.0f;
    string mySymbol;
    int readIndex = 0;
    int numElementsConnected = 0;
    string o1_type;
    string o2_type;
    bool leftConnected = false;
    bool rightConnected = false;
    WaveTableObject * sPtr = NULL;
    ElementObject * o1 = NULL;
    ElementObject * o2 = NULL;
};

#endif
