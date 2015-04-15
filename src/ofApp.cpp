#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
    
    //Set for all white background
    ofBackground(255,255,255);
    
    //Set up the ofxUI elements
    setUpGUIElements();
    
    //Create a menuView object
    selectMenu.setSize(200, 100);
    selectMenu.setMenuColor(101, 123, 140);
    
    
    ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){
    numWaveTables = listOfWaveTables.size();
    numOutput = listOfOutputs.size();
    numSliderObjects = listOfSliderObjects.size();
    numLineConnect = listOfLineConnects.size();
}

//--------------------------------------------------------------
void ofApp::draw(){
    //Show menu if right is clicked
    if(selectMenu.getShowMenu()) {
        selectMenu.drawMenu();
    }
    
    //Draw the list of wave tables
    if(numWaveTables > 0){
        for(int i = 0; i < numWaveTables; i++){
            listOfWaveTables.at(i)->draw();
        }
    }
    
    //Draw the list of output items
    if(numOutput > 0){
        for(int i = 0; i < numOutput; i++){
            listOfOutputs.at(i)->draw();
        }
    }
    
    //Draw the list of line connect items
    if (numLineConnect > 0) {
        for(int i = 0; i < numLineConnect;i++){
            listOfLineConnects.at(i)->draw();
        }
    }
    
    //Draw line connects
    if(currLine != NULL) {
        ofSetLineWidth(4);
        currLine->draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    //cout << "mouse is at x: " << x << " y: " << y << endl;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if(currLine != NULL) currLine->lineTo(x, y);
}

//--------------------------------------------------------------
//TODO abstract some of this away to the menuObject
void ofApp::mousePressed(int x, int y, int button){
    
    //If its near the top menu area just ignore the input
    if(y < 35) return;
    
    
    int x_coord = selectMenu.getXCoord(), y_coord = selectMenu.getYCoord();
    int menuWidth = selectMenu.getWidth(), menuHeight = selectMenu.getHeight();
    
//    cout << "x_coord: " << x_coord << " y_coord: " << y_coord << endl;
//    cout << "menuWidth: " << menuWidth << " menuHeight: " << menuHeight << endl;
//    cout << "x: " << x << " y: " << y << endl;
    
    //If Right button is clicked display the menu
    switch(button){
        case LEFT_CLICK:
        
            if(selectMenu.getShowMenu()){
                if(x > x_coord && x < x_coord + menuWidth &&
                   y > y_coord && y < y_coord + menuHeight){
                    cout << "In menu: " << endl;
                    
                    if(y > y_coord && y < y_coord + 30){
                        waveTablePtr = new WaveTable(x, y);
                        waveTablePtr->setFreq(440);
                        listOfWaveTables.push_back(waveTablePtr);
                    }
                    else if(y > y_coord + 30 && y < y_coord + 60){
                        cout << "second menu" << endl;
                        string name = "Slider";
                        elementsGUI = new ofxUICanvas();
                        elementsGUI->setDimensions(100, 25);
                        elementsGUI->setPosition(x,y);
                        ofAddListener(elementsGUI->newGUIEvent,this,&ofApp::guiEvent);
                        
                        sliderPtr = new SliderObject(elementsGUI, name, 100, 1200, 440);
                        sliderPtr->setCoord(x, y);
                        listOfSliderObjects.push_back(sliderPtr);
                        
                        //This is just hard coded
                        sliderPtr->setObjectToControl(listOfWaveTables.at(numWaveTables-1));
                        

                    }
                    else if(y > y_coord + 60 && y < y_coord + 90){
                        cout << "third menu" << endl;
                        
                        outputPtr = new OutputElement(x, y);
                        outputPtr->setUpAudio(this);
                        listOfOutputs.push_back(outputPtr);
                        
                        //This is hard coded This should not be like this
                        outputPtr->setLeftInput(listOfWaveTables.at(numWaveTables-1));
                    }
                }
                selectMenu.setShowMenu(false);
                break;
            }
            
            //To select objects
            else {
                cout<< "Checking to see if wavetable object is clicked" << endl;
                for(int i = 0; i < numWaveTables; i++){
                    if(listOfWaveTables.at(i)->inBound(x, y)){
                    //Set the negation of the previous value
                        listOfWaveTables.at(i)->setAmIClicked(!listOfWaveTables.at(i)->getAmIClicked());
                        break;
                    }
                }
            
                cout<< "Checking to see if slider object is clicked" << endl;
                for(int i = 0; i < numSliderObjects; i++){
                
                }
            
                cout<< "Checking to see if output object is clicked" << endl;
                for(int i = 0; i < numOutput; i++){
                
                }
            
                for(int i = 0; i < numLineConnect; i++){
                
                }
            }

            
            
            //Draw the line connect items
            /*else if(onOff == 0){
                initial_x = x;
                initial_y = y;
                currLine = new ofPolyline();
                currLine->addVertex(initial_x, initial_y);
            }*/
            
            break;
        case RIGHT_CLICK:
            selectMenu.setCoordinates(x, y);
            selectMenu.setShowMenu(true);
            break;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    if (button == LEFT_CLICK && !selectMenu.getShowMenu() && currLine != NULL && onOff == 0) {
        currLine->lineTo(x,y);
        lineConnectPtr = new LineConnect(currLine, initial_x, initial_y, x, y);
        listOfLineConnects.push_back(lineConnectPtr);
        currLine = NULL;
    }
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

//--------------------------------------------------------------
void ofApp::audioOut(float *output, int bufferSize, int nChannels){
    float volume = 1.0;
    float sample;
    
    //Noise
    if(onOff == 1 && numOutput > 0) {
        listOfOutputs.at(0)->fillOutBuffer(output, bufferSize, nChannels);
    }
}

//--------------------------------------------------------------
void ofApp::guiEvent(ofxUIEventArgs & e){
    string name = e.getName();
    
    //For the getting of the value
    if(name == "On/Off"){
        onOff = e.getToggle()->getValue();
        cout << "Toggle value: " << onOff << endl;
    }
    
    else if(name == "Slider"){
        double freq = e.getSlider()->getValue();
        int currSliderID = e.getSlider()->getID();
        
        //Look for the slider ID
        for (int i = 0; i < numSliderObjects; i++) {
            cout << "CurrSliderID: " << currSliderID << " SliderID: " <<
            listOfSliderObjects.at(i)->getSliderID() << endl;
            
            if(listOfSliderObjects.at(i)->getSliderID() == currSliderID){
                listOfSliderObjects.at(i)->getObjectToControl()->setFreq(freq);
                break;
            }
        }
    }
    
    //These are for future inputs
    //    else if(){
    //
    //    }
    
}
//--------------------------------------------------------------
//TODO find a way to delete dynamically allocated objects without
//seg fault
//--------------------------------------------------------------
void ofApp::exit(){
    delete menuGUI;
    delete elementsGUI;
    //Free the objects
    int listSize = 0;
    
    
    /*if((listSize = listOfWaveTables->size()) > 0){
     for(int i = 0; i < listSize; i++){
     //delete listOfWaveTables->at(i);
     }
     }*/
}

//--------------------------------------------------------------//
// Helper Functions to organize code
//--------------------------------------------------------------//
//Set up ofxUI elements
void ofApp::setUpGUIElements(){
    
    //create the object for the menu element canvas
    menuGUI = new ofxUICanvas();
    menuGUI->setDimensions(150, 32);
    onOffButton = menuGUI->addLabelToggle("On/Off", false);
    ofAddListener(menuGUI->newGUIEvent,this,&ofApp::guiEvent);
    
}
