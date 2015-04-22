//
//  MathObject.h
//  MusGraph
//
//  Created by Moses Lee on 4/21/15.
//
//

#ifndef MusGraph_MathObject_h
#define MusGraph_MathObject_h

#define MATH_HEIGHT 30
#define MATH_WIDTH 30

#include "TickableElement.h"
#include "NumberBoxObject.h"
#include "WaveTable.h"

class MathObject : public TickableElement{
public:
    virtual void connectElement(ElementObject * o) = 0;
    virtual void connectOutElement(WaveTable * wPtr) = 0;
    
    void draw(){
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
    
protected:
    string mySymbol;
    int outputCounter = 0;
    int numElementsConnected = 0;
    string o1_type;
    string o2_type;
    WaveTable * sPtr = NULL;
    ElementObject * o1 = NULL;
    ElementObject * o2 = NULL;
    
};

#endif
