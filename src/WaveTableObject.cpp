//
//  WaveTableObject.cpp
//  MusGraph
//
//  Created by Moses Lee on 5/1/15.
//
//

#include "WaveTableObject.h"

WaveTableObject::WaveTableObject(int x_coord, int y_coord){
    //Set the coordinates and the visual representation
    x = displayRect.x = x_coord;
    y = displayRect.y = y_coord;
    
    displayRect.setWidth(WT_WIDTH);
    displayRect.setHeight(WT_HEIGHT);
    x_bound = x + WT_WIDTH;
    y_bound = y + WT_HEIGHT;
    type = "Sine";
    
    mySine = new WaveTable();
}

WaveTableObject::~WaveTableObject(){
    delete mySine;
}

float WaveTableObject::tick(){
    if(input != NULL) setFreq(((TickableElement *) input)->tick());
    float val;
    
    if(!hasHitControl)
        val = mySine->tick();
    else
        val = 0.0f;
    
    if(delayLine != NULL) delayLine->tick(val);
    
    return val;
}

void WaveTableObject::setDelayLine(DelayLineObject *dl){
    delayLine = dl;
}

void WaveTableObject::setFreq(float freq){
    mySine->setFreq(freq);
}

void WaveTableObject::setInput(ElementObject * o){
    cout << "Sine just connected Input: " << endl;
    input = o;
}