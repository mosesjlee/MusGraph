//
//  MultiplierObject.h
//  MusGraph
//
//  Created by Moses Lee on 4/14/15.
//
//

#ifndef __MusGraph__MultiplierObject__
#define __MusGraph__MultiplierObject__

#define MULT_HEIGHT 30
#define MULT_WIDTH 30

#include <stdio.h>
#include "TickableElement.h"
#include "WaveTable.h"
#include "OutputElement.h"
#include "SliderObject.h"


class MultiplierObject : public TickableElement{
public:
    MultiplierObject(int x_coord, int y_coord);
    MultiplierObject();
    MultiplierObject(ElementObject * o1, ElementObject * o2);
    MultiplierObject(ElementObject * o1, ElementObject * o2, int x_coord, int y_coord);
    ~MultiplierObject();
    float multiply(float a, float b);
    void draw();
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
