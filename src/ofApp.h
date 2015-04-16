#pragma once

//TODO Think of ways to connect objects with each other

#include "ofMain.h"
#include "MenuView.h"
#include "Wavetable.h"
#include "ofxUI.h"
#include "SliderObject.h"
#include "OutputElement.h"
#include "LineConnect.h"
#include "AdderObject.h"
#include "MultiplierObject.h"

//Pred
#define LEFT_CLICK 0
#define RIGHT_CLICK 2
#define UP_ARROW 357
#define DOWN_ARROW 359
#define LEFT_ARROW 356
#define RIGHT_ARROW 358
#define LEFT_CHEVRON 44
#define RIGHT_CHEVRON 46
#define RETURN_KEY 13
#define SPACE_BAR 32

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void guiEvent(ofxUIEventArgs &e);
    void audioOut(float * output, int bufferSize, int nChannels);
    void exit();
    
    MenuView selectMenu;
    WaveTable * waveTablePtr;
    SliderObject * sliderPtr;
    OutputElement * outputPtr;
    LineConnect * lineConnectPtr;
    AdderObject * adderPtr;
    MultiplierObject * multiplierPtr;
    ElementObject * currObject;
    
    //For UI Elements
    ofxUICanvas * menuGUI;
    ofxUIButton * onOffButton;
    ofxUICanvas * elementsGUI;
    ofPolyline * currLine;
    
    //Counters for the different objects on screen
    int menuItem = 0;
    int numWaveTables = 0;
    int numOutput = 0;
    int numLineConnect = 0;
    int numSliderObjects = 0;
    int numAdderObjects = 0;
    int numMultiplierObjects = 0;
    
    
private:
    vector<WaveTable *> listOfWaveTables;
    vector<SliderObject *> listOfSliderObjects;
    vector<OutputElement *> listOfOutputs;
    vector<LineConnect *> listOfLineConnects;
    vector<AdderObject *> listOfAdders;
    vector<MultiplierObject *> listOfMultipliers;
    
    //For the output
    int onOff = 0;
    
    //For drawing lines
    int initial_x;
    int initial_y;
    
    //Helper functions
    void tickAllObjects();
    void setUpGUIElements();
    void addWaveTableObject(int x, int y);
    void addOutputObject(int x, int y);
    void addSliderObject(int x, int y);
    void addAdderObject(int x, int y);
    void addMultiplierObject(int x, int y);
    
};

