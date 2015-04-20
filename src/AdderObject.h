//
//  AdderObject.h
//  MusGraph
//
//  Created by Moses Lee on 4/14/15.
//
//

#ifndef __MusGraph__AdderObject__
#define __MusGraph__AdderObject__

#define ADD_HEIGHT 30
#define ADD_WIDTH 30

#include <stdio.h>
#include "TickableElement.h"
#include "NumberBoxObject.h"
#include "MultiplierObject.h"
#include "WaveTable.h"

class AdderObject : public TickableElement{
public:
    AdderObject();
    AdderObject(int x_coord, int y_coord);
    AdderObject(ElementObject * o1, ElementObject * o2);
    ~AdderObject();
    float add();
    float tick();
    void draw();
    void fillBuf();
    void connectElement(ElementObject * o);
    void connectOutElement(WaveTable * wPtr);
    void sendOut(float);
    
private:
    ofRectangle adderRect;
    WaveTable * sPtr;
    float * buf;
    int countBufElem = 0;
    int outputCounter = 0;
    int numElementsConnected = 0;
    string o1_type;
    string o2_type;
    ElementObject * o1 = NULL;
    ElementObject * o2 = NULL;
};

#endif /* defined(__MusGraph__AdderObject__) */
