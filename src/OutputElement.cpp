//
//  OutputElement.cpp
//  MusGraph
//
//  Created by Moses Lee on 4/10/15.
//
//

#include "OutputElement.h"
OutputElement::OutputElement(){
}

OutputElement::OutputElement(int _x, int _y){
    x = _x; y = _y;
    x_bound = x + OUT_WIDTH;
    y_bound = y + OUT_HEIGHT;
    outputTab.setPosition(_x, _y);
    outputTab.setHeight(OUT_HEIGHT);
    outputTab.setWidth(OUT_WIDTH);
    type = "Output";
}

OutputElement::~OutputElement(){
    stream.close();
}

void OutputElement::start(){
    stream.start();
}

void OutputElement::stop(){
    stream.stop();
}

void OutputElement::setUpAudio(ofBaseApp * parent){
    
    stream.setup(parent, DEFAULT_OUTPUT_NUM, DEFAULT_INPUT_NUM, sampleRate, bufsiz, DEFAULT_BUF_NUM);
}

void OutputElement::fillOutBuffer(float * output, int bufferSize, int nChannels){
    float lSample;
    float rSample;
    
    if(lWavePtr == NULL && rWavePtr == NULL) return;
    
    if(soundMode == MONO || soundMode == LEFT_AUDIO){
        for(int i = 0; i < bufferSize; i++){
            lSample = lWavePtr->tick();
            output[i*nChannels    ] = lSample * volume;
        }
    }
    else if(soundMode == RIGHT_AUDIO){
        for(int i = 0; i < bufferSize; i++){
            rSample = rWavePtr->tick();
            output[i*nChannels + 1] = rSample * volume;
        }
    }
    else if(soundMode == STEREO){
        for(int i = 0; i < bufferSize; i++){
            lSample = lWavePtr->tick();
            rSample = rWavePtr->tick();
            output[i*nChannels    ] = lSample * volume;
            output[i*nChannels + 1] = rSample * volume;
        }
    }
}

void OutputElement::setVolume(float newVolume){
    volume = newVolume;
}

void OutputElement::setLeftInput(WaveTable * wPtr){
    lWavePtr = wPtr;
}

void OutputElement::setRightInput(WaveTable * wPtr){
    rWavePtr = wPtr;
}

void OutputElement::draw(){
    if(!amIClicked){
        ofSetColor(0, 0, 0);
        ofNoFill();
    }
    else {
        ofSetColor(125, 100, 100);
        ofFill();
    }
    
    ofSetLineWidth(2);
    ofRect(outputTab);
    
    stringstream text;
    text << "Output" << endl;
    ofSetColor(0, 0, 0);
    ofDrawBitmapString(text.str(), x+10, y+20);
    
}