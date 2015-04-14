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

class ElementObject{
public:
    std::string getType(){return type;}
    void setType(std::string t){type = t;}
    
    int getNumInputs(){return inputs;}
    void setNumInputs(int i){inputs = i;}
    
    int getNumOutputs(){return outputs;}
    void setNumOutputs(int o){outputs = o;}
    
    virtual void draw() = 0;
protected:
    std::string type;
    int inputs;
    int outputs;
    bool amIClicked;
};

#endif
