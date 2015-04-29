//
//  SliderObject.cpp
//  mySketch
//
//  Created by Moses Lee on 4/8/15.
//
//

#include "SliderObject.h"
SliderObject::SliderObject(ofxUICanvas * parentCanvas, string name, float min, float max, float init, int id){
    sliderCanvas = parentCanvas;
    sliderCanvas->setDimensions(SLIDER_WIDTH, SLIDER_HEIGHT);
    slider = sliderCanvas->addSlider(name, min, max, init);
    maxVal = max;
    minVal = min;
    sliderName = name;
    slider->setID(id);
    myID = id;
    type = "Slider";
}

SliderObject::~SliderObject(){
    delete sliderCanvas;
}

void SliderObject::setCoord(int x_coord, int y_coord){
    x = x_coord;
    y = y_coord;
    x_bound = x + SLIDER_WIDTH;
    y_bound = y + SLIDER_HEIGHT;
    sliderCanvas->setPosition(x_coord, y_coord);
}

void SliderObject::setMinAndMax(float min, float max){
    slider->setMaxAndMin(max, min);
    maxVal = max;
    minVal = min;
}

void SliderObject::draw(){
    
}

void SliderObject::setObjectToControl(ElementObject * objPtr){
    
    elementPtr = objPtr;
    
}

ElementObject * SliderObject::getObjectToControl(){
    return elementPtr;
}

ofxUISlider * SliderObject::getSliderRef()
{
    return slider;
}