//
//  DelayLineObject.cpp
//  MusGraph
//
//  Created by Moses Lee on 5/1/15.
//
//

#include "DelayLineObject.h"

DelayLineObject::DelayLineObject(int x_coord, int y_coord, int id){
    delay = new DelayLine(8192 * SR/1000.00);
    myID = id;
    displayRect.setPosition(x_coord, y_coord);
    displayRect.setHeight(DELAY_HEIGHT);
    displayRect.setWidth(DELAY_WIDTH);
    x = x_coord;
    y = y_coord;
    x_bound = x + DELAY_WIDTH;
    y_bound = y + DELAY_HEIGHT;
    
    tickRegion.setHeight(5);
    tickRegion.setWidth(10);
    tickRegion.setPosition(x_bound - 10, y_bound - 5);
    
    currOutRegion.setHeight(5);
    currOutRegion.setWidth(10);
    currOutRegion.setPosition(x_bound - 10, y);
    type = "Delay Line";
    currOutBuffer = (float *) calloc(MAX_SAMPLES, sizeof(float));
    tickedBuffer = (float *) calloc(MAX_SAMPLES, sizeof(float));
}

DelayLineObject::~DelayLineObject(){
    delete delay;
    free(currOutBuffer);
    free(tickedBuffer);
}

void DelayLineObject::setDelayTime(float t){
    int time = t * SR/1000.0;
    //cout << "Delay time: " << time << endl;
    delay->setDelayLineDelay(time);
}

float * DelayLineObject::getBuffer(){
    cout << "connecting delay out buffer:" << endl;
    //return tickedBuffer;
    return currOutBuffer;
    
    
//    if(!currOutBufferConnected){
//        currOutBufferConnected = true;
//        cout << "currOutConnected: " << currOutBufferConnected << endl;
//        return currOutBuffer;
//    } else {
//        tickedBufferConnected = true;
//        cout << "tickedBuffer: " << tickedBufferConnected << endl;
//        return tickedBuffer;
//    }
}

void DelayLineObject::setFeedBackBuffer(float * r){
    cout << "feedback buffer connected: " << endl;
    feedbackBuffer = r;
}

void DelayLineObject::tick(){
    //Original IMplementation
//    currOutBuffer[readIndex] = delay->getCurrentOut();
//    tickedBuffer[readIndex] = delay->tick(readBuf[readIndex]);
//    
//    readIndex = (readIndex + 1) % MAX_SAMPLES;
//    
//    return currOutBuffer[readIndex];
//The below somewhat works
//    float feedBackGain = 0.95;
//    currOutBuffer[readIndex] = feedBackGain * delay->getCurrentOut();
//    
//    tickedBuffer[readIndex] = delay->tick(currOutBuffer[readIndex]+readBuf[readIndex]);
//    
//    readIndex = (readIndex + 1) % MAX_SAMPLES;
//    
//    return currOutBuffer[readIndex];
    
//Yet another attempt
    currOutBuffer[readIndex] = delay->getCurrentOut();
    tickedBuffer[readIndex] = delay->tick(feedbackBuffer[readIndex] + readBuf[readIndex]);
    
    readIndex = (readIndex + 1) % MAX_SAMPLES;
}

void DelayLineObject::setReadBuffer(float * r){
    if(!readBufConnected){
        cout << "readbufconnected " << endl;
        readBuf = r;
        readBufConnected = true;
    }
    else{
        cout << "feedbackbuffer connected: ";
        feedbackBuffer = r;
        feedbackBufConnected = true;
    }
}

void DelayLineObject::draw(){
    
    if(!amIClicked){
        ofSetColor(0, 0, 0);
        ofNoFill();
    }
    else {
        ofSetColor(125, 100, 100);
        ofFill();
    }
    
    ofSetLineWidth(2);
    ofRect(displayRect);
    ofRect(tickRegion);
    ofRect(currOutRegion);
    
    stringstream text;
    text << type << endl;
    ofSetColor(0, 0, 0);
    ofDrawBitmapString(text.str(), x+8, y+20);
}

bool DelayLineObject::isTickRegion(int x, int y){
    if((x >= x_bound - 10 && x <= x_bound) && (y >= y_bound - 5 && y <= y_bound))
        return true;
    else
        return false;
}

bool DelayLineObject::isGetCurrOutRegion(int x, int y){
    if((x >= x_bound - 10 && x <= x_bound) && (y >= y_bound && y <= y_bound-5))
        return true;
    else
        return false;
}

