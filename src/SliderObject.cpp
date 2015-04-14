//
//  SliderObject.cpp
//  mySketch
//
//  Created by Moses Lee on 4/8/15.
//
//

#include "SliderObject.h"
SliderObject::SliderObject(ofxUICanvas * parentCanvas, string name, float min, float max, float init){
    sliderCanvas = parentCanvas;
    slider = sliderCanvas->addSlider(name, min, max, init);
    maxVal = max;
    minVal = min;
    sliderName = name;
    type = "Slider";
}

SliderObject::~SliderObject(){
    delete slider;
    delete sliderCanvas;
}

void SliderObject::setCoord(int x_coord, int y_coord){
    x = x_coord;
    y = y_coord;
    sliderCanvas->setPosition(x_coord, y_coord);
}

void SliderObject::setMinAndMax(float min, float max){
    slider->setMaxAndMin(max, min);
    maxVal = max;
    minVal = min;
}

void SliderObject::draw(){
    
}

void SliderObject::setObjectToControl(void * objPtr){
    
    string type = ((ElementObject *)objPtr)->getType();
    cout << "Slider control type: " << type << endl;
    if(type == "sine"){
        oscPtr = (WaveTable *) objPtr;
    }
    
    //For future types
//    else if (condition){
//        
//    }
//    else if (condition){
//        
//    }
//    else if (condition){
//        
//    }
}

WaveTable * SliderObject::getObjectToControl(){
    return oscPtr;
}

ofxUISlider * SliderObject::getSliderRef()
{
    return slider;
}