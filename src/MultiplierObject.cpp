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
}


MultiplierObject::~MultiplierObject(){
    
}

float MultiplierObject::tick(){
    if (o1 == NULL || o2 == NULL) {
        cout << "one pointer in multiplier is NULL: " << endl;
        return;
    }
    
    
    float o1_sample;
    float o2_sample;
    
    if(o1_type == "NumberBox") o1_sample = ((NumberBoxObject *) o1)->sendValue();
    else o1_sample = ((TickableElement *) o1)->tick();
    
    if(o2_type == "NumberBox") o2_sample = ((NumberBoxObject *) o2)->sendValue();
    else o2_sample = ((TickableElement *) o2)->tick();
    
    
    float val = o1_sample * o2_sample;
    
    //    if(val > 1.0f) val = 1.0f;
    //    if(val < -1.0f) val = -1.0f;
    
    return val;
}