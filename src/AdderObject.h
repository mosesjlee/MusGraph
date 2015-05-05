//
//  AdderObject.h
//  MusGraph
//
//  Created by Moses Lee on 4/14/15.
//
//

#ifndef __MusGraph__AdderObject__
#define __MusGraph__AdderObject__

#include "MathObject.h"
#include "MultiplierObject.h"

class AdderObject : public MathObject{
public:
    AdderObject();
    AdderObject(int x_coord, int y_coord);
    ~AdderObject();
    float tick();
    void fillBuf();
    void sendOut(float);
    
private:
    int outIndex = 0;
};

#endif /* defined(__MusGraph__AdderObject__) */
