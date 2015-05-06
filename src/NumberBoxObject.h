//
//  NumberBoxObject.h
//  MusGraph
//
//  Created by Moses Lee on 4/18/15.
//
//

#ifndef __MusGraph__NumberBoxObject__
#define __MusGraph__NumberBoxObject__

#define NUMBER_HEIGHT 30
#define NUMBER_WIDTH 70

#include <stdio.h>
#include <string>
#include "ElementObject.h"
#include "SliderObject.h"
#include "WaveTableObject.h"
#include "DelayLineObject.h"
#include "MathObject.h"

class NumberBoxObject : public ElementObject{
public:
    NumberBoxObject();
    NumberBoxObject(int x, int y);
    NumberBoxObject(int x, int y, ofxUICanvas *, int);
    ~NumberBoxObject();
    void setMyValue(float v);
    float sendValue();
    void draw();
    void setOutputConnection(WaveTableObject * sptr);
    void controlOutObject();
    void setControlElementConnection(ElementObject * o);
    void setAmIClicked(bool clicked);
    void setReadBuf(float * r);
    
private:
    ofxUITextInput * textBox;
    ofxUICanvas * numberBoxCanvas;
    ofRectangle numberRect;
    WaveTableObject * sinePtr = NULL;
    ElementObject * eObj = NULL;
    int textBoxID;
    float myValue = 100.0f;
    string typeElemControl = "";
    
    int readIndex = 0;
    float * readBuf;
    bool readBufConnected = false;
};

#endif /* defined(__MusGraph__NumberBoxObject__) */
