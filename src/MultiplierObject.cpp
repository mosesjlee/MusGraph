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
    
    float o1_sample = ((WaveTable *) o1)->tick();
    float o2_sample = ((WaveTable *) o2)->tick();
    float val = o1_sample * o2_sample;
    
    if(val > 1.0f) val = 1.0f;
    if(val < -1.0f) val = -1.0f;
    cout << "What is val: " << val <<endl;
    return val;
}

void MultiplierObject::connectElement(ElementObject * o){
    if (numElementsConnected == 0) {
        o1 = o;
        numElementsConnected = 1;
    }
    else {
        o2 = o;
        numElementsConnected = 2;
    }
}