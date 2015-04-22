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
    virtual void connectElement(ElementObject * o);
    virtual void connectOutElement(WaveTable * wPtr);
    
    void draw();
    
protected:
    string mySymbol;
    int numElementsConnected = 0;
    string o1_type;
    string o2_type;
    WaveTable * sPtr = NULL;
    ElementObject * o1 = NULL;
    ElementObject * o2 = NULL;
    
};

#endif
