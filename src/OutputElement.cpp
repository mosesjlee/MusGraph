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
    float lSample = 0.0f;
    float rSample = 0.0f;
    
    if(lWavePtr == NULL && rWavePtr == NULL && adderPtr == NULL && multPtr == NULL) return;
    
    //cout << "In fill out buffer... type: " << inputType << endl;
    if(soundMode == MONO || soundMode == LEFT_AUDIO){
        for(int i = 0; i < bufferSize; i++){
            rSample = lSample = tickElmPtr->tick();
            output[i*nChannels    ] = lSample * volume;
            output[i*nChannels + 1] = rSample * volume;
        }
    }
    else if(soundMode == RIGHT_AUDIO){
        for(int i = 0; i < bufferSize; i++){
            output[i*nChannels + 1] = rSample * volume;
        }
    }
    else if(soundMode == STEREO){
        for(int i = 0; i < bufferSize; i++){
            output[i*nChannels    ] = lSample * volume;
            output[i*nChannels + 1] = rSample * volume;
        }
    }
}

void OutputElement::setInput(ElementObject * o){
    inputType = o->getType();
    
    cout << "Connecting: " << inputType << endl;

    
    tickElmPtr = (TickableElement *) o;
//    if(inputType == "Sine"){
//        lWavePtr = (WaveTable *) o;
//    }
//    else if(inputType == "Adder"){
//        adderPtr = (AdderObject *) o;
//        cout << "I am: " << adderPtr->getType() << endl;
//    }
//    else if(inputType == "Multiplier"){
//        multPtr = (MultiplierObject *) o;
//        cout << "I am: " << multPtr->getType() << endl;
//    }
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