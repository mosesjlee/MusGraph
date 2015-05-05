//
//  DelayLineObject.cpp
//  MusGraph
//
//  Created by Moses Lee on 5/1/15.
//
//

#include "DelayLineObject.h"

DelayLineObject::DelayLineObject(int x_coord, int y_coord, int id){
    delay = new DelayLine(8192);
    myID = id;
    displayRect.setPosition(x_coord, y_coord);
    displayRect.setHeight(DELAY_HEIGHT);
    displayRect.setWidth(DELAY_WIDTH);
    x = x_coord;
    y = y_coord;
    x_bound = x + DELAY_WIDTH;
    y_bound = y + DELAY_HEIGHT;
    type = "Delay Line";
    outBuffer = (float *) calloc(sizeof(float) * MAX_SAMPLES, sizeof(float));
}

DelayLineObject::DelayLineObject(int size, int id){
    int newSize = 2 * size * SR/1000.0;
    
    delay = new DelayLine(newSize);
}

DelayLineObject::~DelayLineObject(){
    delete delay;
    free(outBuffer);
}

void DelayLineObject::setInput(TickableElement * o){
    input = o;
}

void DelayLineObject::setOutput(TickableElement * o){
    output = o;
}

void DelayLineObject::setDelayTime(float t){
    float time = t * SR/1000.0;
    delay->setDelayLineDelay(time);
}

float DelayLineObject::tick(float t){
    
    if(input != NULL) xN = input->tick();
    
    float val = xN + t;
    
    return delay->tick(val);
}

float DelayLineObject::tick(){
    if(input == NULL) return 0.0f;
    
    return delay->tick(input->tick());
}

float DelayLineObject::getCurrentOut(){
    return delay->getCurrentOut();
}

