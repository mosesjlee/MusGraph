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
    outBuffer = (float *) calloc(sizeof(float) * MAX_SAMPLES, sizeof(float));
    
    mySine = new WaveTable();
}

WaveTableObject::~WaveTableObject(){
    delete mySine;
    free(outBuffer);
}

float * WaveTableObject::getOutBuffer(){
    return outBuffer;
}



float WaveTableObject::tick(){
    if(readBufferConnected) {
        setFreq(readBuffer[readIndex]);
        readIndex = (readIndex + 1) % MAX_SAMPLES;
    }
    
    float val;
    if(hasHitControl) val = 0.0f;
    else val = mySine->tick();
    
    outBuffer[outIndex] = val;
    
    outIndex = (outIndex + 1) % MAX_SAMPLES;
    
    return val;
}

void WaveTableObject::setReadBuffer(float * r){
    cout << "Wave Table setting read buffer" << endl;
    readBufferConnected = true;
    readBuffer = r;
}

void WaveTableObject::setDelayLine(DelayLineObject * dl){
    delayLine = dl;
}

void WaveTableObject::setFreq(float freq){
    mySine->setFreq(freq);
}

void WaveTableObject::setInput(ElementObject * o){
    cout << "Sine just connected Input: " << endl;
    input = o;
}