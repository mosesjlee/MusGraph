//
//  NumberBoxObject.cpp
//  MusGraph
//
//  Created by Moses Lee on 4/18/15.
//
//

#include "NumberBoxObject.h"

std::string ConvertMyValue (float number){
    std::ostringstream buff;
    buff<<number;
    return buff.str();
}

NumberBoxObject::NumberBoxObject(){
    
}

NumberBoxObject::NumberBoxObject(int x_coord, int y_coord, ofxUICanvas * parentCanvas, int id){
    x = x_coord;
    y = y_coord;
    x_bound = x + NUMBER_WIDTH;
    y_bound = y + NUMBER_HEIGHT;
    numberRect.setPosition(x, y);
    numberRect.setHeight(NUMBER_HEIGHT);
    numberRect.setWidth(NUMBER_WIDTH);
    type = "NumberBox";
    
    numberBoxCanvas = parentCanvas;
    numberBoxCanvas->setDimensions(NUMBER_WIDTH, NUMBER_HEIGHT);
    numberBoxCanvas->setPosition(x, y);
    textBox = numberBoxCanvas->addTextInput(type, ConvertMyValue(myValue));
    textBox->setID(id);
    textBox->setOnlyNumericInput(true);
    textBox->setVisible(false);
    myID = id;
}

NumberBoxObject::~NumberBoxObject(){
    delete numberBoxCanvas;
}

void NumberBoxObject::setMyValue(float v){
    myValue = v;
    textBox->ofxUIWidget::setVisible(false);
    amIClicked = false;
    if(sinePtr != NULL) controlOutObject();
}

float NumberBoxObject::sendValue(){
    return myValue;
}

void NumberBoxObject::setOutputConnection(WaveTableObject * sptr){
    sinePtr = sptr;
}

void NumberBoxObject::controlOutObject(){
    if(sinePtr != NULL) sinePtr->setFreq(myValue);
}

void NumberBoxObject::setAmIClicked(bool clicked){
    textBox->setVisible(clicked);
    amIClicked = clicked;
}

void NumberBoxObject::draw(){
    if(!amIClicked){
        ofSetColor(0, 0, 0);
        ofNoFill();
        stringstream text;
        text << "" << myValue << endl;
        ofSetColor(0, 0, 0);
        ofDrawBitmapString(text.str(), x+5, y+20);
    }
    else {
        ofSetColor(125, 100, 100);
        ofFill();
    }
    
    ofSetLineWidth(2);
    ofRect(numberRect);
}