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
    readBuf = (float *) calloc(MAX_SAMPLES, sizeof(float));
    currOutIndex = readIndex = 0;
//    tickedBuffer = (float *) calloc(MAX_SAMPLES, sizeof(float));
}

DelayLineObject::~DelayLineObject(){
    delete delay;
    inBuffers.clear();
    free(currOutBuffer);
    free(readBuf);
  //  free(tickedBuffer);
}

void DelayLineObject::setDelayTime(float t){
    int time = t * SR/1000.0;
    //cout << "Delay time: " << time << endl;
    delay->setDelayLineDelay(time);
}

float * DelayLineObject::getBuffer(){
    cout << "connecting delay out buffer:" << endl;
    return currOutBuffer;
}

void DelayLineObject::fillCurrentOut(){
    delay->getCurrentOut(currOutBuffer, MAX_OUT_BUF_SIZ, currOutIndex);
    currOutIndex += MAX_OUT_BUF_SIZ;
    if(currOutIndex >= MAX_SAMPLES) currOutIndex = 0;
}

float DelayLineObject::readInputBuffers(){
    float val = 0.0f;
    for(int i = 0; i < inBuffers.size(); i++){
        val += inBuffers.at(i)[readIndex];
    }
    return val;
}

void DelayLineObject::tick(){
    for(int i = 0; i < MAX_OUT_BUF_SIZ; i++){
        //readBuf[readIndex] = inBuffers.at(0)[readIndex] + inBuffers.at(1)[readIndex];
        readBuf[readIndex] = readInputBuffers();
        delay->tick(readBuf[readIndex]);
        readIndex = (readIndex + 1) % MAX_SAMPLES;
    }
}

void DelayLineObject::setReadBuffer(float * r){
    inBuffers.push_back(r);
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

