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
#include "WaveTable.h"
#include "SliderObject.h"


#define MONO 0
#define LEFT_AUDIO 1
#define RIGHT_AUDIO 2
#define STEREO 3
#define DEFAULT_SAMPLE_RATE 44100
#define DEFAULT_BUF_SIZE 512
#define DEFAULT_INPUT_NUM 1
#define DEFAULT_OUTPUT_NUM 1
#define DEFAULT_BUF_NUM 1

#define OUT_HEIGHT 30
#define OUT_WIDTH 70


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
    
    void setLeftInput(WaveTable * wPtr);
    void setRightInput(WaveTable * wPtr);
    void setInput(ElementObject * o);
    void draw();
private:
    ofRectangle outputTab;
    ofSoundStream stream;
    ElementObject * elmtPtr;
    WaveTable * lWavePtr = NULL;
    WaveTable * rWavePtr = NULL;
    AdderObject * adderPtr = NULL;
    SliderObject * sliderPtr = NULL;
    string inputType = "";
    int soundMode = MONO;
    float sampleRate = DEFAULT_SAMPLE_RATE;
    int bufsiz = DEFAULT_BUF_SIZE;

    vector<float> audio;
    
    float volume = 0.4;
};

#endif /* defined(__MusGraph__OutputElement__) */
