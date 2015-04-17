//
//  InstrObj.h
//  mySketch
//
//  Created by Moses Lee on 4/8/15.
//
//

#ifndef mySketch_ElementObject_h
#define mySketch_ElementObject_h

#include <stdio.h>
#include <string>
#include <ctype.h>
#include <stdlib.h>
#include "ofRectangle.h"
#include "ofGraphics.h"
#include "ofPolyLine.h"

class ElementObject{
public:
    std::string getType(){return type;}
    void setType(std::string t){type = t;}
    
    int getNumInputs(){return inputs;}
    void setNumInputs(int i){inputs = i;}
    
    int getNumOutputs(){return outputs;}
    void setNumOutputs(int o){outputs = o;}
    
    bool getAmIClicked(){return amIClicked;}
    void setAmIClicked(bool clicked){amIClicked = clicked;}
    
    bool getConnectedByLine(){return connectedByLine;}
    void setConnectedByLine(bool c){connectedByLine = c;}
    
    void setCoordinates(int x_coord, int y_coord){
        x = x_coord;
        y = y_coord;
    }
    
    bool inBound(int x_coord, int y_coord){
        if(x_coord < x_bound && x_coord > x && y_coord < y_bound && y_coord > y){
            return true;
        }
        else {
            return false;
        }
    }
    
    //These functions will remain virtual so that subclasses
    //can implement however way they choose
    virtual void draw() = 0;
protected:
    std::string type;
    int x, y;
    int width, height;
    int x_bound, y_bound;
    int inputs;
    int outputs;
    bool amIClicked = false;
    bool connectedByLine = false;
};

#endif
