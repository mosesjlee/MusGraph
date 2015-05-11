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
#include "NumberBoxObject.h"

class AdderObject : public MathObject{
public:
    AdderObject();
    AdderObject(int x_coord, int y_coord);
    ~AdderObject();
    void tick();
    void fillBuf();
    void sendOut(float);
    
    void setNboxConnection(NumberBoxObject * n);
    
private:
    int outIndex = 0;
    NumberBoxObject * nBox;
    bool nBoxConnected = false;
};

#endif /* defined(__MusGraph__AdderObject__) */
