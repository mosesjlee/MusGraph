//
//  TickableElement.h
//  MusGraph
//
//  Created by Moses Lee on 4/18/15.
//
//

#ifndef MusGraph_TickableElement_h
#define MusGraph_TickableElement_h

#include "ElementObject.h"

class TickableElement : public ElementObject{
public:
    virtual float tick() = 0;
    void draw();
protected:
    ofRectangle displayRect;
};

#endif
