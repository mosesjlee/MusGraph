//
//  DelayLineObject.h
//  MusGraph
//
//  Created by Moses Lee on 5/1/15.
//
//

#ifndef __MusGraph__DelayLineObject__
#define __MusGraph__DelayLineObject__

#include <stdio.h>
#include "TickableElement.h"
#include "delayl.h"

class DelayLineObject : public TickableElement{
public:

    DelayLineObject();
    ~DelayLineObject();
    void setInput(ElementObject *);
    float tick();
    
private:
    DelayLine delay;
    ElementObject * input;
    
    
    
};

#endif /* defined(__MusGraph__DelayLineObject__) */
