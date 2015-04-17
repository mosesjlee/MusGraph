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
    setSliderID(slider->getID());
    type = "Slider";
}

SliderObject::~SliderObject(){
    delete slider;
    delete sliderCanvas;
}

void SliderObject::setSliderID(int id){
    sliderID = id;
}
int SliderObject::getSliderID(){
    return sliderID;
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
    
    string type = objPtr->getType();
    cout << "Slider control type: " << type << endl;
    elementPtr = objPtr;
    
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

ElementObject * SliderObject::getObjectToControl(){
    return elementPtr;
}

ofxUISlider * SliderObject::getSliderRef()
{
    return slider;
}