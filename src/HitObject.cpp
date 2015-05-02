//
//  HitObject.cpp
//  MusGraph
//
//  Created by Moses Lee on 5/1/15.
//
//

#include "HitObject.h"

HitObject::HitObject(ofxUICanvas * parentCanvas, int x_coord, int y_coord, int id){
    hitBoxCanvas = parentCanvas;
    hitBoxCanvas->setDimensions(HIT_WIDTH, HIT_HEIGHT);
    hitBoxCanvas->setPosition(x_coord, y_coord);
    hitBox = hitBoxCanvas->addButton("HitBox", false);
    hitBox->setID(id);
    type = "HitBox";
    myID = id;
    x = x_coord;
    y = y_coord;
    
    x_bound = x + HIT_WIDTH;
    y_bound = y + HIT_HEIGHT;
    width = HIT_WIDTH;
    height = HIT_HEIGHT;
}

HitObject::~HitObject(){
    delete hitBoxCanvas;
}

void HitObject::draw(){
    
}

string HitObject::getHitType(){
    return hitObject;
}

void HitObject::setElementToHit(TickableElement * o){
    objToHit = o;
    hitObject = o->getType();
}

void HitObject::setHitSampleLength(int i){
    hitSampleLength = i;
}

void HitObject::receivedHit(){
    if(objToHit == NULL) return;
    
    objToHit->receivedHit(hitSampleLength);
}