//
//  SoundClipObject.h
//  MusGraph
//
//  Created by Moses Lee on 5/6/15.
//
//

#ifndef __MusGraph__SoundClipObject__
#define __MusGraph__SoundClipObject__

#include <stdio.h>
#include <sndfile.h>
#include "TickableElement.h"

class SoundClipObject : public TickableElement{
public:
    SoundClipObject();
    
private:
    SNDFILE * myFile;
    
};

#endif /* defined(__MusGraph__SoundClipObject__) */
