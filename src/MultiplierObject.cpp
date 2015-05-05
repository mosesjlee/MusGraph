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
    displayRect.setPosition(x_coord, y_coord);
    displayRect.setHeight(MATH_HEIGHT);
    displayRect.setWidth(MATH_WIDTH);
    x = x_coord;
    y = y_coord;
    x_bound = x + MATH_WIDTH;
    y_bound = y + MATH_HEIGHT;
    type = "Multiplier";
    mySymbol = "*";
    outBuf = (float *) calloc(sizeof(float) * MAX_SAMPLES, sizeof(float));
}


MultiplierObject::~MultiplierObject(){
    free(outBuf);
}

float MultiplierObject::tick(){
    float left_sample, right_sample;
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
    
    readIndex = (readIndex + 1) % MAX_SAMPLES;
    
    float val = left_sample * right_sample;
    
    outBuf[outIndex] = val;
    outIndex = (outIndex + 1) % MAX_SAMPLES;
    //cout << "Multiplier val: " << val << endl;
    return val;
}


