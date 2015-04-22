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
#include "MathObject.h"
#include "MultiplierObject.h"

class AdderObject : public MathObject{
public:
    AdderObject();
    AdderObject(int x_coord, int y_coord);
    AdderObject(ElementObject * o1, ElementObject * o2);
    ~AdderObject();
    float tick();
    void fillBuf();
    void sendOut(float);
    
private:
    float * buf;
};

#endif /* defined(__MusGraph__AdderObject__) */
