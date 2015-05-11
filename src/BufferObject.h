//
//  BufferObject.h
//  MusGraph
//
//  Created by Moses Lee on 5/6/15.
//
//

#ifndef __MusGraph__BufferObject__
#define __MusGraph__BufferObject__

#define BUFFER_BOX_HEIGHT 40
#define BUFFER_BOX_WIDTH 20

#include <stdio.h>
#include "TickableElement.h"
#include "NumberBoxObject.h"

class BufferObject : public TickableElement{
public:
    BufferObject(int x_coord, int y_coord, int myID);
    ~BufferObject();
    void setBuffer(float * r);
    float * getBuffer();
    void setDestinationObject(ElementObject * o);
    void tick();
    //void draw();
private:
    float * buffer;
    bool bufferConnected = false;
    int readIndex = 0;
    NumberBoxObject * nBox;
    bool destinationConnected = false;
};

#endif /* defined(__MusGraph__BufferObject__) */
