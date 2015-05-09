//
//  SoundClipObject.cpp
//  MusGraph
//
//  Created by Moses Lee on 5/6/15.
//
//

#include "SoundClipObject.h"

SoundClipObject::SoundClipObject(int x_coord, int y_coord, int myID){
    x = displayRect.x = x_coord;
    y = displayRect.y = y_coord;
    displayRect.setHeight(SOUNDCLIP_HEIGHT);
    displayRect.setWidth(SOUNDCLIP_WIDTH);
    x_bound = x + SOUNDCLIP_WIDTH;
    y_bound = y + SOUNDCLIP_HEIGHT;
    outBuffer = (float *) calloc(MAX_SAMPLES, sizeof(float));
    this->myID = myID;
    
    //This should not be called here, but for the sake of demo purposes
    //I am calling this in the constructor
    openFile();
    type = "SoundClip";
    hasHitControl = true;
}

SoundClipObject::~SoundClipObject(){
    //sf_close(myFile);
    free(outBuffer);
    fclose(rawFile);
}

float SoundClipObject::tick(){
    float val = 0.0;
    if(!hasHitControl){
        if(readCount >= sampleVector.size()){
            val = 0.0;
            readCount = 0;
            hasHitControl = true;
        }
        else {
            val = sampleVector.at(readCount);
            readCount++;
        }
    }
    
    outBuffer[readIndex] = val;
    readIndex = (readIndex + 1) % MAX_SAMPLES;
    return outBuffer[readIndex];
}

float * SoundClipObject::getOutBuffer(){
    return outBuffer;
}

/*This is just hard coded for demo purposes
  In the future this should allow users to 
  pick whichever audio file they want
 */
void SoundClipObject::openFile(){
//    string file = "/Users/moseslee/Desktop/of_v0.8.3_osx_release/apps/myApps/MusGraph/bin/data/soundclips/guitar1.raw";
    string file = "/Users/moseslee/Desktop/of_v0.8.3_osx_release/apps/myApps/MusGraph/bin/data/soundclips/emma16.raw";
    
    rawFile = fopen(&file[0], "r");
    
    float temp;
    
    if(rawFile != NULL){
        while(!feof(rawFile)){
            fread((void *)(&temp), sizeof(temp), 1, rawFile);
            sampleVector.push_back(temp);
        }
    }
    else {
        printf("File not opened\n");
    }
    
}

