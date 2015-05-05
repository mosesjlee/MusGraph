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
    
    tickRegion.setHeight(5);
    tickRegion.setWidth(10);
    tickRegion.setPosition(x_bound - 10, y_bound - 5);
    
    currOutRegion.setHeight(5);
    currOutRegion.setWidth(10);
    currOutRegion.setPosition(x_bound - 10, y);
    type = "Delay Line";
    currOutBuffer = (float *) calloc(MAX_SAMPLES, sizeof(float));
    tickedBuffer = (float *) calloc(MAX_SAMPLES, sizeof(float));
}

DelayLineObject::DelayLineObject(int size, int id){
    int newSize = 2 * size * SR/1000.0;
    
    delay = new DelayLine(newSize);
}

DelayLineObject::~DelayLineObject(){
    delete delay;
    free(currOutBuffer);
    free(tickedBuffer);
}

void DelayLineObject::setDelayTime(float t){
    float time = t * SR/1000.0;
    delay->setDelayLineDelay(time);
}

float * DelayLineObject::getBuffer(){
    cout << "currOutConnected: " << currOutBufferConnected <<
    "tickedBuffer: " << tickedBufferConnected << endl;
    
    if(!currOutBufferConnected){
        currOutBufferConnected = true;
        cout << "currOutConnected: " << currOutBufferConnected << endl;
        return currOutBuffer;
    } else {
        tickedBufferConnected = true;
        cout << "tickedBuffer: " << tickedBufferConnected << endl;
        return tickedBuffer;
    }
}

float DelayLineObject::tick(){
    currOutBuffer[readIndex] = delay->getCurrentOut();
    tickedBuffer[readIndex] = delay->tick(readBuf[readIndex]);
    
    readIndex = (readIndex + 1) % MAX_SAMPLES;
    
    return currOutBuffer[readIndex];
}

void DelayLineObject::setReadBuffer(float * r){
    readBuf = r;
}

void DelayLineObject::draw(){
    
    if(!amIClicked){
        ofSetColor(0, 0, 0);
        ofNoFill();
    }
    else {
        ofSetColor(125, 100, 100);
        ofFill();
    }
    
    ofSetLineWidth(2);
    ofRect(displayRect);
    ofRect(tickRegion);
    ofRect(currOutRegion);
    
    stringstream text;
    text << type << endl;
    ofSetColor(0, 0, 0);
    ofDrawBitmapString(text.str(), x+8, y+20);
}

bool DelayLineObject::isTickRegion(int x, int y){
    if((x >= x_bound - 10 && x <= x_bound) && (y >= y_bound - 5 && y <= y_bound))
        return true;
    else
        return false;
}

bool DelayLineObject::isGetCurrOutRegion(int x, int y){
    if((x >= x_bound - 10 && x <= x_bound) && (y >= y_bound && y <= y_bound-5))
        return true;
    else
        return false;
}

