#pragma once

//TODO Think of ways to connect objects with each other

#include "ofMain.h"
#include "GLFW/glfw3.h"
#include "MenuView.h"
#include "WavetableObject.h"
#include "ofxUI.h"
#include "DelayLineObject.h"
#include "SliderObject.h"
#include "OutputElement.h"
#include "LineConnect.h"
#include "AdderObject.h"
#include "MultiplierObject.h"
#include "DividerObject.h"
#include "NumberBoxObject.h"
#include "HitObject.h"
#include "BufferObject.h"
#include "AppUtilityFunctions.h"
#include "SoundClipObject.h"

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
#define DELETE_KEY 127
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
    
    
private:
    //To create the visual elements
    MenuView selectMenu;
    WaveTableObject * waveTablePtr;
    SliderObject * sliderPtr;
    OutputElement * outputPtr;
    LineConnect * lineConnectPtr;
    AdderObject * adderPtr;
    MultiplierObject * multiplierPtr;
    DividerObject * dividerPtr;
    NumberBoxObject * nbPtr;
    DelayLineObject * delayPtr;
    HitObject * hitPtr;
    BufferObject * bufferPtr;
    SoundClipObject * soundClipPtr;
    
    vector<WaveTableObject *> listOfWaveTables;
    vector<SliderObject *> listOfSliderObjects;
    vector<OutputElement *> listOfOutputs;
    vector<LineConnect *> listOfLineConnects;
    vector<AdderObject *> listOfAdders;
    vector<MultiplierObject *> listOfMultipliers;
    vector<DividerObject *> listOfDividers;
    vector<NumberBoxObject *> listOfNumBox;
    vector<DelayLineObject *> listOfDelayLines;
    vector<HitObject *> listOfHitObjects;
    vector<BufferObject *> listOfBuffers;
    vector<SoundClipObject *> listOfSoundClips;
    vector<TickableElement *> listOfTickableElements;
    
    //For casting purposes
    typedef vector<ElementObject *> * ELEMVECT;
    
    //Counters for the different objects on screen
    int menuItem = 0;
    int numWaveTables = 0;
    int numOutput = 0;
    int numLineConnect = 0;
    int numSliderObjects = 0;
    int numAdderObjects = 0;
    int numMultiplierObjects = 0;
    int numNumBoxObjects = 0;
    int numDividerObjects = 0;
    int numDelayLine = 0;
    int numHitObjects = 0;
    int numBufferObjects = 0;
    int numSoundClipObjects = 0;
    
    //For the output
    int onOff = 0;
    
    //For drawing lines
    int initial_x;
    int initial_y;
    
    ElementObject * currObject_1;
    ElementObject * currObject_2;
    
    //For UI Elements
    ofxUICanvas * menuGUI;
    ofxUIButton * onOffButton;
    
    ofxUICanvas * saveMenuGUI;
    ofxUIButton * saveButton;
    
    ofxUICanvas * saveFileNameUI;
    ofxUITextInput * saveNameField;
    
    ofxUICanvas * loadConfigMenu;
    ofxUIButton * loadButton;
    
    ofxUICanvas * clearElementsMenu;
    ofxUIButton * clearElementsButton;
    
    ofxUICanvas * elementsGUI;
    ofPolyline * currLine;

    //To save Configurations
    ofFile file;
    
    //Helper functions
    void setUpGUIElements();
    void addWaveTableObject(int x, int y);
    void addOutputObject(int x, int y);
    void addSliderObject(int x, int y);
    void addAdderObject(int x, int y);
    void addMultiplierObject(int x, int y);
    void addDividerObject(int x, int y);
    void addNumberBoxObject(int x, int y);
    void addDelayLine(int x, int y);
    void addHitObject(int x, int y);
    void addBufferObject(int x, int y);
    void addSoundClipObject(int x, int y);
    void clearElements();
    bool selectItems(int x, int y, ElementObject ** obj);
    void createObjects(vector<string> * listOfObjects);
    void tickElements();
    
};

