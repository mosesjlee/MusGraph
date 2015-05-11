//
//  AdderObject.cpp
//  MusGraph
//
//  Created by Moses Lee on 4/14/15.
//
//

#include "AdderObject.h"
#include "MultiplierObject.h"

AdderObject::AdderObject(int x_coord, int y_coord){
    displayRect.setPosition(x_coord, y_coord);
    displayRect.setHeight(MATH_HEIGHT);
    displayRect.setWidth(MATH_WIDTH);
    x = x_coord;
    y = y_coord;
    x_bound = x + MATH_WIDTH;
    y_bound = y + MATH_HEIGHT;
    type = "Adder";
    mySymbol = "+";
    outBuf = (float *) calloc(MAX_SAMPLES, sizeof(float));
}

AdderObject::~AdderObject(){
    free(outBuf);
}

void AdderObject::setNboxConnection(NumberBoxObject * n){
    nBox = n;
    nBoxConnected = true;
}

void AdderObject::tick(){
    float left_sample, right_sample;
    for(int i = 0; i < MAX_BUF_SIZ; i++){
    if (!leftConnected) {
        left_sample = val;
    }
    else {
        left_sample = readBuf_1[readIndex];
    }
    if (!rightConnected) {
        right_sample = val;
    }
    else {
        right_sample = readBuf_2[readIndex];
    }
    
    float val = left_sample + right_sample;
    
    outBuf[readIndex] = val;
    readIndex = (readIndex + 1) % MAX_SAMPLES;
    }
}

void AdderObject::sendOut(float v){
    sPtr->setFreq(v);
}

