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

LineConnect::LineConnect(ofPolyline * linePtr){
    line = linePtr;
    line->clear();
}

LineConnect::LineConnect(ofPolyline * linePtr, int x_start, int y_start, int x_end, int y_end){
    line = linePtr;
    line->clear();
    line->addVertex(x_start, y_start);
    line->addVertex(x_end, y_end);
    this->x_start = x_start;
    this->y_start = y_start;
    this->x_end = x_end;
    this->y_end = y_end;
    type = "LineConnect";
}

LineConnect::LineConnect(int x_start, int y_start, int x_end, int y_end){
    
    this->x_start = x_start;
    this->y_start = y_start;
    this->x_end = x_end;
    this->y_end = y_end;
    
    line = new ofPolyline();
    line->addVertex(x_start, y_start);
    line->addVertex(x_end, y_end);
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

int LineConnect::getXStart(){
    return x_start;
}

int LineConnect::getYStart(){
    return y_start;
}

int LineConnect::getXEnd(){
    return x_end;
}

int LineConnect::getYEnd(){
    return y_end;
}

int LineConnect::getElemID_1(){
    return id_1;
}

int LineConnect::getElemID_2(){
    return id_2;
}

string LineConnect::getType1(){
    return type_1;
}
string LineConnect::getType2(){
    return type_2;
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
    type_1 = o1->getType();
    id_1 = o1->getMyID();
}

void LineConnect::setSecondElement(ElementObject * o){
    o2 = o;
    type_2 = o2->getType();
    id_2 = o2->getMyID();
}


//These make all the connections amongst the objects
bool LineConnect::makeConnections(){
    
    //Always NULL check
    if(o1 == NULL || o2 == NULL) return false;
    
    string o1_type = o1->getType();
    string o2_type = o2->getType();
    
    //Connections below this line order does not matter
    if(o1_type == "Sine" && o2_type == "Output"){
        ((OutputElement *) o2)->setReadBuffer(((WaveTableObject *) o1)->getOutBuffer());
        return true;
    }
    else if(o2_type == "Sine" && o1_type == "Output"){
        ((OutputElement *) o1)->setReadBuffer(((WaveTableObject *) o2)->getOutBuffer());
        return true;
    }
    
    else if(o1_type == "Sine" && o2_type == "Slider"){
        ((SliderObject *) o2)->setObjectToControl(o1);
        return true;
    }
    else if(o2_type == "Sine" && o1_type == "Slider"){
        ((SliderObject *) o1)->setObjectToControl(o2);
        return true;
    }
    
    else if(o1_type == "NumberBox" && o2_type == "Slider"){
        ((SliderObject *) o2)->setObjectToControl(o1);
        return true;
    }
    else if(o2_type == "NumberBox" && o1_type == "Slider"){
        ((SliderObject *) o1)->setObjectToControl(o2);
        return true;
    }

    //Order Matters from this point on---------------------------
    else if(o1_type == "NumberBox" && o2_type == "Sine"){
        ((NumberBoxObject *) o1)->setOutputConnection((WaveTableObject *) o2);
        return true;
    }
    
    else if(o1_type == "NumberBox" && o2_type == "Adder"){
        ((NumberBoxObject *) o1)->setControlElementConnection(o2);
        return true;
    }

    else if(o1_type == "NumberBox" && o2_type == "Multiplier"){
        ((NumberBoxObject *) o1)->setControlElementConnection(o2);
        return true;
    }
    
    else if(o1_type == "NumberBox" && o2_type == "Divider"){
        ((NumberBoxObject *) o1)->setControlElementConnection(o2);
        return true;
    }
    
//----------------------------------------------------------
    //This is hard coded
    else if(o1_type == "Adder" && o2_type == "Sine"){
        ((WaveTableObject *) o2)->setReadBuffer(((MathObject *) o1)->getOutBuffer());
        return true;
    }
    //ABOVE IS HARD CODED
    
    else if(o1_type == "Sine" && o2_type == "Multiplier"){
        ((MultiplierObject *) o2)->setReadBuffers(((WaveTableObject *) o1)->getOutBuffer());
        return true;
    }
    
    else if(o1_type == "Sine" && o2_type == "Adder" ){
        ((AdderObject *) o2)->setReadBuffers(((WaveTableObject *) o1)->getOutBuffer());
        return true;
    }
    
    
//----------------------------------------------------------
    
    else if(o1_type == "Adder" && o2_type == "Output"){
        ((OutputElement *) o2)->setReadBuffer(((MathObject *) o1)->getOutBuffer());
        return true;
    }
    else if(o2_type == "Adder" && o1_type == "Output"){
        ((OutputElement *) o1)->setReadBuffer(((MathObject *) o2)->getOutBuffer());
        return true;
    }
    
    else if(o1_type == "Divider" && o2_type == "Output"){
        ((OutputElement *) o2)->setInput(o1);
        return true;
    }
    else if(o2_type == "Divider" && o1_type == "Output"){
        ((OutputElement *) o1)->setInput(o2);
        return true;
    }

    else if(o1_type == "Divider" && o2_type == "Sine"){
        ((DividerObject *) o1)->connectElement(o2);
        return true;
    }
    else if(o2_type == "Divider" && o1_type == "Sine"){
        ((DividerObject *) o2)->connectElement(o1);
        return true;
    }
    
    else if(o1_type == "Multiplier" && o2_type == "Adder"){
        ((AdderObject *) o2)->setReadBuffers(((MathObject *) o1)->getOutBuffer());
        return true;
    }
    
    else if(o1_type == "HitBox" && o2_type == "Sine"){
        ((HitObject *) o1)->setElementToHit((TickableElement *) o2);
        ((TickableElement *) o2)->setHasHitControl(true);
        return true;
    }
    
    else if(o1_type == "Sine" && o2_type == "Delay Line"){
        ((WaveTableObject *) o1)->setDelayLine((DelayLineObject *) o2);
        return true;
    }
    
    else if(o1_type == "Delay Line" && o2_type == "Adder"){
        ((AdderObject *) o2)->connectElement(o1);
        return true;
    }
    
    else if(o1_type == "Adder" && o2_type == "Delay Line"){
        ((DelayLineObject *) o2)->setInput((TickableElement *) o1);
        return true;
    }
    
    else if(o1_type == "NumberBox" && o2_type == "Delay Line"){
        ((NumberBoxObject *) o1)->setControlElementConnection(o2);
        return true;
    }
    
    return false;
}

double LineConnect::lerp(double x_1, double y_1, double x_2, double y_2, double x){
    return y_1 + (y_2 - y_1) * (x - x_1)/(x_2-x_1);
}