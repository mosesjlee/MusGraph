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
#include "ElementObject.h"
#include "LineConnect.h"
#include "WaveTable.h"

class AdderObject : public ElementObject{
public:
    AdderObject();
    AdderObject(int x_coord, int y_coord);
    AdderObject(ElementObject * o1, ElementObject * o2);
    ~AdderObject();
    float add(float a, float b);
    float tick();
    void draw();
    void connectElement(ElementObject * o);
    
private:
    ofRectangle adderRect;
    float * buf;
    int numElementsConnected = 0;
    ElementObject * o1 = NULL;
    ElementObject * o2 = NULL;
};

#endif /* defined(__MusGraph__AdderObject__) */
