//
//  AdderObject.h
//  MusGraph
//
//  Created by Moses Lee on 4/14/15.
//
//

#ifndef __MusGraph__AdderObject__
#define __MusGraph__AdderObject__

#include <stdio.h>
#include "ElementObject.h"
#include "LineConnect.h"
#include "WaveTable.h"

class AdderObject : public ElementObject{
public:
    AdderObject();
    AdderObject(ElementObject * o1, ElementObject * o2);
    ~AdderObject();
    float add(float a, float b);
    float tick();
    void connectElement(ElementObject * o);
    
private:
    ofRectangle adderRect;
    float * buf;
    int numElementsConnected = 0;
    ElementObject * o1 = NULL;
    ElementObject * o2 = NULL;
};

#endif /* defined(__MusGraph__AdderObject__) */
