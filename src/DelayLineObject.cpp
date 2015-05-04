//
//  DelayLineObject.cpp
//  MusGraph
//
//  Created by Moses Lee on 5/1/15.
//
//

#include "DelayLineObject.h"

DelayLineObject::DelayLineObject(int x_coord, int y_coord, int id){
    delay = new DelayLine();
    myID = id;
    displayRect.setPosition(x_coord, y_coord);
    displayRect.setHeight(DELAY_HEIGHT);
    displayRect.setWidth(DELAY_WIDTH);
    x = x_coord;
    y = y_coord;
    x_bound = x + DELAY_WIDTH;
    y_bound = y + DELAY_HEIGHT;
    type = "Delay Line";
}

DelayLineObject::DelayLineObject(int size, int id){
    int newSize = 2 * size * SR/1000.0;
    
    delay = new DelayLine(newSize);
}

DelayLineObject::~DelayLineObject(){
    delete delay;
}

void DelayLineObject::setInput(TickableElement * o){
    input = o;
}

void DelayLineObject::setDelayTime(float t){
    float time = t * SR/1000.0;
    delay->setDelayLineDelay(time);
}

float DelayLineObject::tick(float t){
    return delay->tick(t);
}

//float DelayLineObject::tick(){
//    if(input != NULL) xN = input->tick();
//    return delay->tick(xN);
//}

float DelayLineObject::tick(){
    return delay->getCurrentOut();
}

float DelayLineObject::getCurrentOut(){
    return delay->getCurrentOut();
}

