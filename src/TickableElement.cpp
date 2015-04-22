//
//  TickableElement.cpp
//  MusGraph
//
//  Created by Moses Lee on 4/22/15.
//
//

#include <stdio.h>
#include "TickableElement.h"

void TickableElement::draw(){
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
    
    stringstream text;
    text << type << endl;
    ofSetColor(0, 0, 0);
    ofDrawBitmapString(text.str(), x+8, y+20);
}