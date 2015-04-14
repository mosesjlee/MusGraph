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
    outputTab.setPosition(_x, _y);
    outputTab.setHeight(30);
    outputTab.setWidth(70);
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
    ofSetColor(0, 0, 0);
    ofNoFill();
    ofSetLineWidth(2);
    ofRect(outputTab);
    
    stringstream text;
    text << "Output" << endl;
    ofSetColor(0, 0, 0);
    ofDrawBitmapString(text.str(), x+10, y+20);
    
}