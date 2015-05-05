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

float DividerObject::tick(){
    if (readBuf_1 == NULL || readBuf_2 == NULL) {
        cout << "one pointer in adder is NULL: " << endl;
        return 0.00;
    }
    
    readIndex_buf1 = (readIndex_buf1 + 1) % MAX_SAMPLES;
    
    float val = readBuf_1[readIndex_buf1] + readBuf_2[readIndex_buf1];;
    
    if(val > 1.0f) val = 1.0f;
    if(val < -1.0f) val = -1.0f;
    
    outBuf[outIndex] = val;
    outIndex = (outIndex + 1) % MAX_SAMPLES;
    return val;
}

