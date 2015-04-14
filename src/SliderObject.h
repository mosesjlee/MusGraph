//
//  SliderObject.h
//  mySketch
//
//  Created by Moses Lee on 4/8/15.
//
//

#ifndef __mySketch__SliderObject__
#define __mySketch__SliderObject__

#include <stdio.h>
#include "ofxUI.h"
#include "ofxGui.h"
#include "Wavetable.h"
#include "ElementObject.h"

class SliderObject : public ElementObject{
public:
    SliderObject(ofxUICanvas * parentCanvas, string name, float min, float max, float init);
    SliderObject();
    void setCoord(int x_coord, int y_coord);
    void setMinAndMax(float min, float max);
    void setObjectToControl(void * objPtr);
    WaveTable * getObjectToControl();
    void setSliderID(int id);
    int getSliderID();
    void draw();
    
    ofxUISlider * getSliderRef();
    ~SliderObject();
private:
    string sliderName;
    int sliderID;
    WaveTable * oscPtr;
    ofxUISlider * slider;
    ofxUICanvas * sliderCanvas;
    
    float maxVal;
    float minVal;
};

#endif /* defined(__mySketch__SliderObject__) */
