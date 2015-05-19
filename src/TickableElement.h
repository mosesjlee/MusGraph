//
//  TickableElement.h
//  MusGraph
//
//  Created by Moses Lee on 4/18/15.
//
//

#ifndef MusGraph_TickableElement_h
#define MusGraph_TickableElement_h
#define MAX_SAMPLES 4096
#define MAX_OUT_BUF_SIZ 128
#include "ElementObject.h"

class TickableElement : public ElementObject{
public:
    virtual void tick() = 0;
    virtual void draw();
    virtual void receivedHit(int hitLength);
    virtual void setHasHitControl(bool t);
    virtual void setIsTicked(bool b);
    virtual bool getIsTicked();
    
protected:
    ofRectangle displayRect;
    bool isTicked;
    bool hasHitControl = false;
    bool hit = true;
    int readIndex_buf1 = 0;
    int readIndex_buf2 = 0;
};

#endif
