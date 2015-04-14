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
    line->clear();
    delete line;
}

void LineConnect::draw(){
    ofSetColor(0, 0, 0);
    ofSetLineWidth(4);
    line->draw();
}


double LineConnect::lerp(double x_1, double y_1, double x_2, double y_2, double x)
{
    return y_1 + (y_2 - y_1) * (x - x_1)/(x_2-x_1);
}