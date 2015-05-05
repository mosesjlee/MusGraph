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

float AdderObject::tick(){
    float left_sample, right_sample;
    if (!leftConnected) {
       // cout << "pointer one in adder is NULL: " << endl;
        left_sample = val;
    }our
    else {
        left_sample = readBuf_1[readIndex];
    }
    if (!rightConnected) {
        //cout << "pointer two in adder is NULL: " << endl;
        right_sample = val;
    }
    else {
        right_sample = readBuf_2[readIndex];
    }
    
    readIndex = (readIndex + 1) % MAX_SAMPLES;
    
    float val = left_sample + right_sample;
    
//    if(val > 1.0f) val = 1.0f;
//    if(val < -1.0f) val = -1.0f;
    
    outBuf[outIndex] = val;
    outIndex = (outIndex + 1) % MAX_SAMPLES;
    //cout << "Adder val: " << val << endl;
    return val;
}

void AdderObject::sendOut(float v){
    sPtr->setFreq(v);
}

