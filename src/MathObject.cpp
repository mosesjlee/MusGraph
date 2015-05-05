//
//  MathObject.cpp
//  MusGraph
//
//  Created by Moses Lee on 4/22/15.
//
//

#include "MathObject.h"

void MathObject::draw(){
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
    text << mySymbol << endl;
    ofSetColor(0, 0, 0);
    ofDrawBitmapString(text.str(), x+12, y+20);
}

//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------
void MathObject::connectElement(ElementObject * o){
//    if (numElementsConnected == 0) {
//        o1 = o;
//        o1_type = o->getType();
//        numElementsConnected = 1;
//    }
//    else if(numElementsConnected == 1){
//        o2 = o;
//        o2_type = o->getType();
//        numElementsConnected = 2;
//    }
//    else {
//        cout << "S Pointer Connected: " << endl;
//        sPtr = (WaveTableObject *) o;
//        numElementsConnected = 3;
//    }
}

//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------

void MathObject::connectOutElement(WaveTableObject * wPtr){
    sPtr = wPtr;
}

//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------
void MathObject::setReadBuffers(float * r){
    cout << "numElementsConnected: " << numElementsConnected << endl;
    if(numElementsConnected == 0){
        leftConnected = true;
        readBuf_1 = r;
        numElementsConnected++;
        cout << "Pointer 1 is set: " << numElementsConnected << endl;
    }
    else if(numElementsConnected == 1){
        rightConnected = true;
        readBuf_2 = r;
        numElementsConnected = 2;
        cout << "Pointer 2 is set: " << numElementsConnected << endl;
    }
}

//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------
float * MathObject::getOutBuffer(){
    return outBuf;
}

//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------
void MathObject::setOtherValue(float v){
    val = v;
}
