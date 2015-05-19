//
//  SoundClipObject.h
//  MusGraph
//
//  Created by Moses Lee on 5/6/15.
//
//

#ifndef __MusGraph__SoundClipObject__
#define __MusGraph__SoundClipObject__
#define SOUNDCLIP_HEIGHT 30
#define SOUNDCLIP_WIDTH 90
#define BUFFER_LEN 1024
#include <stdio.h>
//#include <sndfile.h>
#include "TickableElement.h"

class SoundClipObject : public TickableElement{
public:
    SoundClipObject(int x_coord, int y_coord, int myID);
    ~SoundClipObject();
    void tick();
    float * getOutBuffer();
    void openFile();
    
private:
//    SNDFILE * myFile;
    FILE * rawFile;
//    SF_INFO fileInfo;
    float * outBuffer;
    int readIndex = 0;
    int readCount = 0;
    //float fileData[BUFFER_LEN];
    bool trigger = false;
    vector<float> sampleVector;
};

#endif /* defined(__MusGraph__SoundClipObject__) */
