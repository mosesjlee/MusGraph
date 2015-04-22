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
#include "MathObject.h"
#include "AdderObject.h"


class MultiplierObject : public MathObject{
public:
    MultiplierObject();
    MultiplierObject(int x_coord, int y_coord);
    MultiplierObject(ElementObject * o1, ElementObject * o2);
    MultiplierObject(ElementObject * o1, ElementObject * o2, int x_coord, int y_coord);
    ~MultiplierObject();
    float tick();
    
private:
    float * buf;
};
#endif /* defined(__MusGraph__MultiplierObject__) */
