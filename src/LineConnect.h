//
//  LineConnect.h
//  MusGraph
//
//  Created by Moses Lee on 4/10/15.
//
//

#ifndef __MusGraph__LineConnect__
#define __MusGraph__LineConnect__

#include <stdio.h>
#include "ElementObject.h"

class LineConnect : public ElementObject{
public:
    LineConnect();
    LineConnect(ofPolyline * linePtr, int x_start, int y_start, int x_end, int y_end);
    LineConnect(int x_start, int y_start, int x_end, int y_end);
    ~LineConnect();
    void draw();
    void reDraw(int x_start, int y_start, int x_end, int y_end);
    float * getBuffer();
    void setBuffer(int bufsiz);
    void fillBuffer();
    void setLine(ofPolyline * linePtr);
    double lerp(double x_1, double y_1, double x_2, double y_2, double x);
    
    void setFirstElement(ElementObject o);
    void setSecondElement(ElementObject o);
private:
    ElementObject * o1;
    ElementObject * o2;
    ofPolyline * line;
    float * buffer;
    int x_start, y_start;
    int x_end, y_end;
};

#endif /* defined(__MusGraph__LineConnect__) */
