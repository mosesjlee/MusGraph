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
#include "AdderObject.h"
#include "MultiplierObject.h"
#include "OutputElement.h"
#include "WaveTableObject.h"
#include "SliderObject.h"
#include "DividerObject.h"
#include "TickableElement.h"
#include "HitObject.h"

class LineConnect : public ElementObject{
    
public:
    LineConnect();
    LineConnect(ofPolyline * linePtr, int x_start, int y_start, int x_end, int y_end);
    LineConnect(int x_start, int y_start, int x_end, int y_end);
    ~LineConnect();
    void draw();
    void setInitialCoord(int x, int y);
    void setFinalCoord(int x, int y);
    void reDraw(int x_start, int y_start, int x_end, int y_end);
    float * getBuffer();
    void setBuffer(int bufsiz);
    void fillBuffer();
    void setLine(ofPolyline * linePtr);
    double lerp(double x_1, double y_1, double x_2, double y_2, double x);
    
    void setFirstElement(ElementObject * o);
    void setSecondElement(ElementObject * o);
    
    bool makeConnections();
    void disconnect();
    
    int getXStart();
    int getYStart();
    int getXEnd();
    int getYEnd();
    
    int getElemID_1();
    int getElemID_2();
    
    string getType1();
    string getType2();
    
private:
    ElementObject * o1;
    string type_1;
    int id_1;
    ElementObject * o2;
    string type_2;
    int id_2;
    
    
    ofPolyline * line = NULL;
    float * buffer;
    int x_start, y_start;
    int x_end, y_end;
};

#endif /* defined(__MusGraph__LineConnect__) */
