//
//  BufferObject.cpp
//  MusGraph
//
//  Created by Moses Lee on 5/6/15.
//
//

#include "BufferObject.h"

BufferObject::BufferObject(int x_coord, int y_coord, int myID){
    type = "Buffer";
    displayRect.setHeight(BUFFER_BOX_HEIGHT);
    displayRect.setWidth(BUFFER_BOX_WIDTH);
    displayRect.setPosition(x_coord, y_coord);
    x = x_coord;
    y = y_coord;
    x_bound = x + BUFFER_BOX_WIDTH;
    y_bound = y + BUFFER_BOX_HEIGHT;
    this->myID = myID;
}

BufferObject::~BufferObject(){
    
}


void BufferObject::tick(){
    float val = 0.0;
    for(int i = 0; i < MAX_OUT_BUF_SIZ; i++){
    if(bufferConnected){
        val = buffer[readIndex];
    }
    
    if(destinationConnected){
        nBox->setMyValue(val);
    }
    
    readIndex = (readIndex + 1) % MAX_SAMPLES;
    }
}

void BufferObject::setBuffer(float * r){
    bufferConnected = true;
    buffer = r;
}

float * BufferObject::getBuffer(){
    return buffer;
}

void BufferObject::setDestinationObject(ElementObject * o){
    destinationConnected = true;
    nBox = (NumberBoxObject *) o;
}

