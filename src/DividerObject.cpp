//
//  DividerObject.cpp
//  MusGraph
//
//  Created by Moses Lee on 4/21/15.
//
//

#include "DividerObject.h"

DividerObject::DividerObject(){
    
}

DividerObject::DividerObject(int x_coord, int y_coord){
    displayRect.setPosition(x_coord, y_coord);
    displayRect.setHeight(MATH_HEIGHT);
    displayRect.setWidth(MATH_WIDTH);
    x = x_coord;
    y = y_coord;
    x_bound = x + MATH_WIDTH;
    y_bound = y + MATH_HEIGHT;
    type = "Divider";
    mySymbol = "/";
    outBuf = (float *) calloc(sizeof(float) * MAX_SAMPLES, sizeof(float));
}

DividerObject::~DividerObject(){
    free(outBuf);
}

void DividerObject::tick(){
    float left_sample, right_sample;
    if (!leftConnected) {
        left_sample = val;
    }
    else {
        left_sample = readBuf_1[readIndex];
    }
    if (!rightConnected) {
        //Below is hard coded. Have to figure out a way to connect more than one number box
        right_sample = 2.0;
    }
    else {
        right_sample = readBuf_2[readIndex];
    }
    
    readIndex = (readIndex + 1) % MAX_SAMPLES;
    
    float val;
    
    if(right_sample <= 0) val = 0.0f;
    else val = left_sample/right_sample;
    
    //    if(val > 1.0f) val = 1.0f;
    //    if(val < -1.0f) val = -1.0f;
    
    outBuf[outIndex] = val;
    outIndex = (outIndex + 1) % MAX_SAMPLES;
}

