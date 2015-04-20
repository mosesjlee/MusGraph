//
//  MultiplierObject.cpp
//  MusGraph
//
//  Created by Moses Lee on 4/14/15.
//
//

#include "MultiplierObject.h"

MultiplierObject::MultiplierObject(){
    
}

MultiplierObject::MultiplierObject(int x_coord, int y_coord){
    multiplierRect.setPosition(x_coord, y_coord);
    multiplierRect.setHeight(MULT_HEIGHT);
    multiplierRect.setWidth(MULT_WIDTH);
    x = x_coord;
    y = y_coord;
    x_bound = x + MULT_WIDTH;
    y_bound = y + MULT_HEIGHT;
    type = "Multiplier";
}

MultiplierObject::MultiplierObject(ElementObject * o1, ElementObject * o2){
    
}

MultiplierObject::~MultiplierObject(){
    
}

void MultiplierObject::draw(){
    if(!amIClicked){
        ofSetColor(0, 0, 0);
        ofNoFill();
    }
    else {
        ofSetColor(125, 100, 100);
        ofFill();
    }
    
    ofSetLineWidth(2);
    ofRect(multiplierRect);
    
    stringstream text;
    text << "*" << endl;
    ofSetColor(0, 0, 0);
    ofDrawBitmapString(text.str(), x+10, y+20);
}

float MultiplierObject::tick(){
    if (o1 == NULL || o2 == NULL) {
        cout << "one pointer in adder is NULL: " << endl;
        return;
    }
    
    
    float o1_sample;
    float o2_sample;
    
    if(o1_type == "Sine")
        o1_sample = ((WaveTable *) o1)->tick();
    else if(o1_type == "NumberBox")
        o1_sample = ((NumberBoxObject *) o1)->sendValue();
    
    if(o2_type == "Sine")
        o2_sample = ((WaveTable *) o2)->tick();
    else if(o2_type == "NumberBox")
        o2_sample = ((NumberBoxObject *) o2)->sendValue();
    
    
    float val = o1_sample * o2_sample;
    
    if(val > 1.0f) val = 1.0f;
    if(val < -1.0f) val = -1.0f;
    
    return val;
}

void MultiplierObject::connectElement(ElementObject * o){
    if (numElementsConnected == 0) {
        o1 = o;
        o1_type = o->getType();
        numElementsConnected = 1;
    }
    else {
        o2 = o;
        o2_type = o->getType();
        numElementsConnected = 2;
    }
}