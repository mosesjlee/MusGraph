//
//  NumberBoxObject.cpp
//  MusGraph
//
//  Created by Moses Lee on 4/18/15.
//
//

#include "NumberBoxObject.h"

NumberBoxObject::NumberBoxObject(){
    
}

NumberBoxObject::NumberBoxObject(int x_coord, int y_coord){
    x = x_coord;
    y = y_coord;
    x_bound = x + NUMBER_WIDTH;
    y_bound = y + NUMBER_HEIGHT;
    numberRect.setPosition(x, y);
    numberRect.setHeight(NUMBER_HEIGHT);
    numberRect.setWidth(NUMBER_WIDTH);
    type = "NumberBox";
}

NumberBoxObject::~NumberBoxObject(){
    
}

void NumberBoxObject::setMyValue(float v){
    myValue = v;
    if(sinePtr != NULL) controlOutObject();
}

float NumberBoxObject::sendValue(){
    return myValue;
}

void NumberBoxObject::setOutputConnection(WaveTable * sptr){
    sinePtr = sptr;
}

void NumberBoxObject::controlOutObject(){
    sinePtr->setFreq(myValue);
}

void NumberBoxObject::draw(){
    if(!amIClicked){
        ofSetColor(0, 0, 0);
        ofNoFill();
    }
    else {
        ofSetColor(125, 100, 100);
        ofFill();
    }
    
    ofSetLineWidth(2);
    ofRect(numberRect);
    
    stringstream text;
    text << "" << myValue << endl;
    ofSetColor(0, 0, 0);
    ofDrawBitmapString(text.str(), x+5, y+20);
}