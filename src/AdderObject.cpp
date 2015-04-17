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
    text << " + " << endl;
    ofSetColor(0, 0, 0);
    ofDrawBitmapString(text.str(), x+12, y+20);
}

float AdderObject::add(float a, float b){
    return a + b;
}

float AdderObject::tick(){
    return 0.00f;
}

void AdderObject::connectElement(ElementObject * o){
    
}