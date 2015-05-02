//
//  HitObject.h
//  MusGraph
//
//  Created by Moses Lee on 5/1/15.
//
//

#ifndef __MusGraph__HitObject__
#define __MusGraph__HitObject__
#define HIT_HEIGHT 25
#define HIT_WIDTH 25

#include <stdio.h>
#include "TickableElement.h"
#include "ofxUI.h"

class HitObject : public ElementObject {
    
public:
    HitObject(ofxUICanvas * parentCanvas, int x, int y, int id);
    ~HitObject();
    void setElementToHit(TickableElement *);
    void setHitSampleLength(int i);
    void receivedHit();
    void draw();
    string getHitType();
    
private:
    ofxUICanvas * hitBoxCanvas;
    ofxUIButton * hitBox;
    TickableElement * objToHit = NULL;
    string hitObject = "";
    int hitSampleLength = 1024;
};

#endif /* defined(__MusGraph__HitObject__) */
