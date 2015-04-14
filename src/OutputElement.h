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
#include "ofGraphics.h"
#include "ofRectangle.h"
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
    
    void draw();
private:
    int x, y;
    int width, height;
    ofRectangle outputTab;
    ofSoundStream stream;
    WaveTable * lWavePtr;
    WaveTable * rWavePtr;
    int soundMode = MONO;
    float sampleRate = DEFAULT_SAMPLE_RATE;
    int bufsiz = DEFAULT_BUF_SIZE;
    float volume = 0.6;
    vector<float> audio;
    
};

#endif /* defined(__MusGraph__OutputElement__) */
