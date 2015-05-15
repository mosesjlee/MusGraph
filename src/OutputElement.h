//
//  OutputElement.h
//  MusGraph
//
//  Created by Moses Lee on 4/10/15.
//
//

#ifndef __MusGraph__OutputElement__
#define __MusGraph__OutputElement__

#include <stdio.h>
#include "ElementObject.h"
#include "ofSoundStream.h"
#include "LineConnect.h"
#include "WaveTableObject.h"


#define MONO 0
#define LEFT_AUDIO 1
#define RIGHT_AUDIO 2
#define STEREO 3
#define DEFAULT_SAMPLE_RATE 44100
#define DEFAULT_BUF_SIZE 256
#define DEFAULT_INPUT_NUM 1
#define DEFAULT_OUTPUT_NUM 1
#define DEFAULT_BUF_NUM 1

#define OUT_HEIGHT 30
#define OUT_WIDTH 70
#define DEBUG 1

class OutputElement : public ElementObject{
public:
    OutputElement();
    OutputElement(int _x, int _y);
    ~OutputElement();
    
    void start();
    void stop();
    void setUpAudio(ofBaseApp * parent);
    void fillOutBuffer(float * output, int bufferSize, int nChannels);
    void setVolume(float newVolume);
    
    void setLeftInput(WaveTableObject * wPtr);
    void setRightInput(WaveTableObject * wPtr);
    void setInput(ElementObject * o);
    void draw();
    void setReadBuffer(float * r);
    
private:
    ofRectangle outputTab;
    ofSoundStream stream;
    ElementObject * elmtPtr;
    float * readBuffer;
    int readIndex = 0;
    FILE * outputFile;
    WaveTableObject * lWavePtr = NULL;
    WaveTableObject * rWavePtr = NULL;
    TickableElement * tickElmPtr = NULL;
    string inputType = "";
    int soundMode = MONO;
    float sampleRate = DEFAULT_SAMPLE_RATE;
    int bufsiz = DEFAULT_BUF_SIZE;
    vector<float> audio;
    
    float volume = 1.0;
};

#endif /* defined(__MusGraph__OutputElement__) */
