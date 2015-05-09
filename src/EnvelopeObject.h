//
//  EnvelopeObject.h
//  MusGraph
//
//  Created by Moses Lee on 5/7/15.
//
//

#ifndef __MusGraph__EnvelopeObject__
#define __MusGraph__EnvelopeObject__

#include <stdio.h>
#include "TickableElement.h"
class EnvelopeObject : public TickableElement{
public:
    EnvelopeObject();
    ~EnvelopeObject();
private:
    float scaleUp;
    float scaleDown;
    float * readBuf;
    float * outBuf;
};

#endif /* defined(__MusGraph__EnvelopeObject__) */
