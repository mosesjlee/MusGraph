//
//  LineConnect.cpp
//  MusGraph
//
//  Created by Moses Lee on 4/10/15.
//
//

#include "LineConnect.h"

LineConnect::LineConnect(){
    
}

LineConnect::LineConnect(ofPolyline * linePtr, int x_start, int y_start, int x_end, int y_end){
    line = linePtr;
    line->clear();
    line->addVertex(x_start, y_start);
    line->addVertex(x_end, y_end);
}

LineConnect::LineConnect(int x_start, int y_start, int x_end, int y_end){
    line->addVertex(x_start, y_start);
    line->addVertex(x_end, y_end);
    
    this->x_start = x_start;
    this->y_start = y_start;
    this->x_end = x_end;
    this->y_end = y_end;
}

LineConnect::~LineConnect(){
    if(line != NULL){
        line->clear();
        delete line;
    }
}

void LineConnect::draw(){
    ofSetColor(0, 0, 0);
    ofSetLineWidth(4);
    line->draw();
}

void LineConnect::setInitialCoord(int x_coord, int y_coord){
    x_start = x_coord;
    y_start = y_coord;
    line->addVertex(x, y);
}

void LineConnect::setFinalCoord(int x_coord, int y_coord){
    x_end = x_coord;
    y_end = y_coord;
    line->lineTo(x_end, y_end);
}

void LineConnect::setLine(ofPolyline * linePtr){
    line = linePtr;
}

void LineConnect::setFirstElement(ElementObject * o){
    o1 = o;
}

void LineConnect::setSecondElement(ElementObject * o){
    o2 = o;
}


//These make all the connections amongst the objects
void LineConnect::makeConnections(){
    string o1_type = o1->getType();
    string o2_type = o2->getType();
    
    if(o1_type == "Sine" && o2_type == "Output"){
        ((OutputElement *) o2)->setInput(o1);
    }
    else if(o2_type == "Sine" && o1_type == "Output"){
        ((OutputElement *) o1)->setInput(o2);
    }
    
    else if(o1_type == "Sine" && o2_type == "Slider"){
        ((SliderObject *) o2)->setObjectToControl(o1);
    }
    else if(o2_type == "Sine" && o1_type == "Slider"){
        ((SliderObject *) o1)->setObjectToControl(o2);
    }
    
    else if(o1_type == "NumberBox" && o2_type == "Slider"){
        ((SliderObject *) o2)->setObjectToControl(o1);
    }
    else if(o2_type == "NumberBox" && o1_type == "Slider"){
        ((SliderObject *) o1)->setObjectToControl(o2);
    }

    else if(o1_type == "NumberBox" && o2_type == "Sine"){
        ((NumberBoxObject *) o1)->setOutputConnection((WaveTable *) o2);
    }
    else if(o2_type == "NumberBox" && o1_type == "Sine"){
        ((NumberBoxObject *) o2)->setOutputConnection((WaveTable *) o1);
    }
    
    else if(o1_type == "NumberBox" && o2_type == "Adder"){
        ((AdderObject *) o2)->connectElement(o1);
    }
    else if(o2_type == "NumberBox" && o1_type == "Adder"){
        ((AdderObject *) o1)->connectElement(o2);
    }

    else if(o1_type == "NumberBox" && o2_type == "Multiplier"){
        ((MultiplierObject *) o2)->connectElement(o1);
    }
    else if(o2_type == "NumberBox" && o1_type == "Multiplier"){
        ((MultiplierObject *) o1)->connectElement(o2);
    }
    
    else if(o1_type == "Adder" && o2_type == "Sine"){
        ((AdderObject *) o1)->connectElement(o2);
    }
    else if(o2_type == "Adder" && o1_type == "Sine"){
        ((AdderObject *) o2)->connectElement(o1);
    }
    
    else if(o1_type == "Adder" && o2_type == "Output"){
        ((OutputElement *) o2)->setInput(o1);
    }
    else if(o2_type == "Adder" && o1_type == "Output"){
        ((OutputElement *) o1)->setInput(o2);
    }
    
    else if(o1_type == "Multiplier" && o2_type == "Sine"){
        ((MultiplierObject *) o1)->connectElement(o2);
    }
    else if(o2_type == "Multiplier" && o1_type == "Sine"){
        ((MultiplierObject *) o2)->connectElement(o1);
    }

    
    
    else if(o1_type == "Multiplier" && o2_type == "Adder"){
        ((AdderObject *) o2)->connectElement(o1);
    }
    else if(o1_type == "Adder" && o2_type == "Multiplier"){
        ((AdderObject *) o1)->connectElement(o2);
    }
}

double LineConnect::lerp(double x_1, double y_1, double x_2, double y_2, double x)
{
    return y_1 + (y_2 - y_1) * (x - x_1)/(x_2-x_1);
}