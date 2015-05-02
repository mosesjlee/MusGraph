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

class WaveTableObject;
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
    
    void setAmIClicked(bool clicked);
    
private:
    ofxUITextInput * textBox;
    ofxUICanvas * numberBoxCanvas;
    ofRectangle numberRect;
    WaveTableObject * sinePtr = NULL;
    int textBoxID;
    float myValue = 100.0f;
};

#endif /* defined(__MusGraph__NumberBoxObject__) */
