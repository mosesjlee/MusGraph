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
    if(DEBUG) fclose(outputFile);
}

void OutputElement::start(){
    stream.start();
}

void OutputElement::stop(){
    stream.stop();
}

void OutputElement::setReadBuffer(float * r){
    readBuffer = r;
}

void OutputElement::setUpAudio(ofBaseApp * parent){
    cout << "sample rate: " << sampleRate << endl;
    stream.setup(parent, DEFAULT_OUTPUT_NUM, DEFAULT_INPUT_NUM, sampleRate, bufsiz, DEFAULT_BUF_NUM);
    if(DEBUG) outputFile = fopen("/Users/moseslee/Desktop/of_v0.8.3_osx_release/apps/myApps/MusGraph/bin/data/output", "w");
}

void OutputElement::fillOutBuffer(float * output, int bufferSize, int nChannels){
    float lSample = 0.0f;
    float rSample = 0.0f;
    
    if(soundMode == MONO || soundMode == LEFT_AUDIO){
        for(int i = 0; i < bufferSize; i++){
            lSample = rSample = readBuffer[readIndex];
            if(lSample > 1.0) rSample = lSample = 1.0;
            if(lSample < -1.0) rSample = lSample = -1.0;
            readIndex = (readIndex + 1) % MAX_SAMPLES;
            //cout << "lSample: " << lSample << endl;
            output[i*nChannels    ] = lSample;
            output[i*nChannels + 1] = rSample;
        }
    }
    else if(soundMode == RIGHT_AUDIO){
        for(int i = 0; i < bufferSize; i++){
            output[i*nChannels + 1] = rSample;
        }
    }
    else if(soundMode == STEREO){
        for(int i = 0; i < bufferSize; i++){
            output[i*nChannels    ] = lSample;
            output[i*nChannels + 1] = rSample;
        }
    }
    if(DEBUG) fwrite(output, sizeof(float), bufferSize, outputFile);
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