//
//  DividerObject.h
//  MusGraph
//
//  Created by Moses Lee on 4/21/15.
//
//

#ifndef __MusGraph__DividerObject__
#define __MusGraph__DividerObject__

#include <stdio.h>
#include "MathObject.h"

class DividerObject : public MathObject{
public:
    DividerObject();
    DividerObject(int x, int y);
    ~DividerObject();
    float tick();
private:
    int outIndex = 0;
};

#endif /* defined(__MusGraph__DividerObject__) */
