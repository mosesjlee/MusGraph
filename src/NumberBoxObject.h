//
//  NumberBoxObject.h
//  MusGraph
//
//  Created by Moses Lee on 4/18/15.
//
//

#ifndef __MusGraph__NumberBoxObject__
#define __MusGraph__NumberBoxObject__

#include <stdio.h>
#include "ElementObject.h"

class NumberBoxObject : public ElementObject{
public:
    NumberBoxObject();
    NumberBoxObject(int x, int y);
    ~NumberBoxObject();
    void setMyValue(int v);
    int getValue();
private:
    ofRectangle numberRect;
    int myValue;
};

#endif /* defined(__MusGraph__NumberBoxObject__) */
