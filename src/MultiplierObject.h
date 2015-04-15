//
//  MultiplierObject.h
//  MusGraph
//
//  Created by Moses Lee on 4/14/15.
//
//

#ifndef __MusGraph__MultiplierObject__
#define __MusGraph__MultiplierObject__

#include <stdio.h>
#include "ElementObject.h"

class MultiplierObject : public ElementObject{
public:
    MultiplierObject();
    MultiplierObject(ElementObject * o1, ElementObject * o2);
    ~MultiplierObject();
    float multiply(float a, float b);
    float tick();
    void connectElement(ElementObject * o);
private:
    ofRectangle multiplierRect;
    float * buf;
    int numElementsConnected = 0;
    ElementObject * o1 = NULL;
    ElementObject * o2 = NULL;
};
#endif /* defined(__MusGraph__MultiplierObject__) */
