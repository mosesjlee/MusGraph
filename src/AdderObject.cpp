//
//  AdderObject.cpp
//  MusGraph
//
//  Created by Moses Lee on 4/14/15.
//
//

#include "AdderObject.h"

AdderObject::AdderObject(){
    
}

AdderObject::AdderObject(int x_coord, int y_coord){
    adderRect.setPosition(x_coord, y_coord);
    adderRect.setHeight(ADD_HEIGHT);
    adderRect.setWidth(ADD_WIDTH);
    x = x_coord;
    y = y_coord;
    x_bound = x + ADD_WIDTH;
    y_bound = y + ADD_HEIGHT;
    type = "Adder";
}

AdderObject::AdderObject(ElementObject * o1, ElementObject * o2){
    type = "Adder";
}

AdderObject::~AdderObject(){
}

void AdderObject::draw(){
    if(!amIClicked){
        ofSetColor(0, 0, 0);
        ofNoFill();
    }
    else {
        ofSetColor(125, 100, 100);
        ofFill();
    }
    
    ofSetLineWidth(2);
    ofRect(adderRect);
    
    stringstream text;
    text << "+" << endl;
    ofSetColor(0, 0, 0);
    ofDrawBitmapString(text.str(), x+12, y+20);
}


float AdderObject::tick(){
    if (o1 == NULL || o2 == NULL) {
        cout << "one pointer in adder is NULL: " << endl;
        return;
    }
    
    
    float o1_sample;
    float o2_sample;
    
    if(o1_type == "Sine")
        o1_sample = ((WaveTable *) o1)->tick();
    else if(o1_type == "Adder")
        o1_sample = ((AdderObject *) o1)->tick();
    else if(o1_type == "Multiplier")
        o1_sample = ((MultiplierObject *) o1)->tick();
    else if(o1_type == "NumberBox")
        o1_sample = ((NumberBoxObject *) o1)->sendValue();
    
    if(o2_type == "Sine")
        o2_sample = ((WaveTable *) o2)->tick();
    else if(o2_type == "Adder")
        o2_sample = ((AdderObject *) o2)->tick();
    else if(o2_type == "Multiplier")
        o2_sample = ((MultiplierObject *) o2)->tick();
    else if(o2_type == "NumberBox")
        o2_sample = ((NumberBoxObject *) o2)->sendValue();
    
    float val = o1_sample + o2_sample;
    
//    if(val > 1.0f) val = 1.0f;
//    if(val < -1.0f) val = -1.0f;
    if(sPtr != NULL) sendOut(val);
    return val;
}

void AdderObject::connectOutElement(WaveTable * wPtr){
    sPtr = wPtr;
}

void AdderObject::sendOut(float v){
    sPtr->setFreq(v);
}

void AdderObject::connectElement(ElementObject * o){
    if (numElementsConnected == 0) {
        o1 = o;
        o1_type = o->getType();
        numElementsConnected = 1;
    }
    else if(numElementsConnected == 1){
        o2 = o;
        o2_type = o->getType();
        numElementsConnected = 2;
    }
    else {
        sPtr = (WaveTable *) o;
        numElementsConnected = 3;
    }
}