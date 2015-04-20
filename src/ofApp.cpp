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
    numMultiplierObjects = listOfMultipliers.size();
    numAdderObjects = listOfAdders.size();
    numNumBoxObjects = listOfNumBox.size();
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
    
    if(numAdderObjects > 0){
        for(int i = 0; i < numAdderObjects;i++){
            listOfAdders.at(i)->draw();
        }
    }
    
    if(numMultiplierObjects > 0){
        for(int i = 0; i < numMultiplierObjects;i++){
            listOfMultipliers.at(i)->draw();
        }
    }
    
    if(numNumBoxObjects > 0){
        for(int i = 0; i < numNumBoxObjects;i++){
            listOfNumBox.at(i)->draw();
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
    int x_bound = selectMenu.getXBound(), y_bound = selectMenu.getYBound();
    
    //If Right button is clicked display the menu
    switch(button){
        case LEFT_CLICK:
        
            if(selectMenu.getShowMenu()){
                if(x > x_coord && x < x_bound && y > y_coord && y < y_bound){
                    cout << "In menu: " << endl;
                    
                    if(y > y_coord && y < y_coord + 30){
                        addWaveTableObject(x, y);
                    }
                    else if(y > y_coord + 30 && y < y_coord + 60){
                        cout << "second menu" << endl;
                        addSliderObject(x, y);

                    }
                    else if(y > y_coord + 60 && y < y_coord + 90){
                        cout << "third menu" << endl;
                        addOutputObject(x, y);
                    }
                    else if(y > y_coord + 90 && y < y_coord + 120){
                        cout << "Adder " << endl;
                        addAdderObject(x, y);
                    }
                    else if(y > y_coord + 120 && y < y_coord + 140){
                        cout << "Multiplier " << endl;
                        addMultiplierObject(x, y);
                    }
                    else if(y > y_coord + 140 && y < y_coord + 180){
                        cout << "Number Box " << endl;
                        addNumberBoxObject(x, y);
                    }
                }
                selectMenu.setShowMenu(false);
                break;
            }
            
            //To select objects
            else if(onOff == 0){
                bool isSelected = selectItems(x, y, &currObject_1);
                if(isSelected){
                    initial_x = x;
                    initial_y = y;
                    currLine = new ofPolyline();
                    currLine->addVertex(initial_x, initial_y);
                    
                    //Create the line connect items
                    currObject_1->setAmIClicked(!currObject_1->getAmIClicked());
                }
            }

            
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
        
        int x_1, y_1, x_2, y_2;
        
        if(selectItems(x, y, &currObject_2) && euclideanDistance(initial_x, initial_y, x, y) > 10.0){
            x_1 = currObject_1->getXCoord();
            y_1 = currObject_1->getYCoord();
            x_2 = currObject_2->getXCoord();
            y_2 = currObject_2->getYCoord();
            
            lineConnectPtr = new LineConnect(currLine, x_1, y_1, x_2, y_2);
            
            lineConnectPtr->setFirstElement(currObject_1);
            lineConnectPtr->setSecondElement(currObject_2);
            lineConnectPtr->makeConnections();
            listOfLineConnects.push_back(lineConnectPtr);
            currLine = NULL;
            currObject_1 = NULL;
            currObject_2 = NULL;
            
        }
        else {
            if(currLine != NULL) {
                currLine->clear();
                currLine = NULL;
            }
        }
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
    //This is hard coded
    if(onOff == 1 && numOutput > 0) {
        listOfOutputs.at(0)->fillOutBuffer(output, bufferSize, nChannels);
    }
}

//--------------------------------------------------------------
void ofApp::guiEvent(ofxUIEventArgs & e){
    string name = e.getName();
    
    //For the getting of the value
    if(name == "On/Off") {
        onOff = e.getToggle()->getValue();
        cout << "Toggle value: " << onOff << endl;
    }
    
    else if(name == "Slider") {
        int currSliderID = e.getSlider()->getID();
        double val = e.getSlider()->getValue();
        string type = "";
        
        //Look for the slider ID
            
        if(listOfSliderObjects.at(currSliderID)->getSliderID() == currSliderID){
                
            if(listOfSliderObjects.at(currSliderID)->getObjectToControl() == NULL){
                return;
            }
                
            //cout << "currSliderID: " << currSliderID << " curr index: " << i << endl;
                
            type = listOfSliderObjects.at(currSliderID)->getObjectToControl()->getType();
                
            if(type == "Sine"){
                ((WaveTable *) listOfSliderObjects.at(currSliderID)->getObjectToControl())->setFreq(val);
            }
            else if(type == "Output"){
                    
            }
            else if(type == "Adder"){
                    
            }
            else if(type == "Multiplier"){
                    
            }
            else if(type == "NumberBox"){
                ((NumberBoxObject *) listOfSliderObjects.at(currSliderID)->
                 getObjectToControl())->setMyValue(val);
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
//--------------------------------------------------------------//
// Helper Functions to organize code                            //
//--------------------------------------------------------------//
//--------------------------------------------------------------//
//Set up ofxUI elements
void ofApp::setUpGUIElements(){
    
    //create the object for the menu element canvas
    menuGUI = new ofxUICanvas();
    menuGUI->setDimensions(150, 32);
    onOffButton = menuGUI->addLabelToggle("On/Off", false);
    ofAddListener(menuGUI->newGUIEvent,this,&ofApp::guiEvent);
    
}

void ofApp::addWaveTableObject(int x, int y){
    waveTablePtr = new WaveTable(x, y);
    waveTablePtr->setFreq(440);
    listOfWaveTables.push_back(waveTablePtr);
}

void ofApp::addOutputObject(int x, int y){
    outputPtr = new OutputElement(x, y);
    outputPtr->setUpAudio(this);
    listOfOutputs.push_back(outputPtr);
}

void ofApp::addSliderObject(int x, int y){
    string name = "Slider";
    elementsGUI = new ofxUICanvas();
    elementsGUI->setDimensions(SLIDER_WIDTH, SLIDER_HEIGHT);
    ofAddListener(elementsGUI->newGUIEvent,this,&ofApp::guiEvent);
    
    sliderPtr = new SliderObject(elementsGUI, name, 1, 1000, 440, numSliderObjects);
    sliderPtr->setCoord(x, y);
    listOfSliderObjects.push_back(sliderPtr);
}

void ofApp::addAdderObject(int x, int y){
    adderPtr = new AdderObject(x, y);
    listOfAdders.push_back(adderPtr);
}

void ofApp::addMultiplierObject(int x, int y){
    multiplierPtr = new MultiplierObject(x, y);
    listOfMultipliers.push_back(multiplierPtr);
}

void ofApp::addNumberBoxObject(int x, int y){
    nbPtr = new NumberBoxObject(x, y);
    listOfNumBox.push_back(nbPtr);
}

//-------------------------------------------------------------------------------
//Select Items based on locations
//-------------------------------------------------------------------------------
bool ofApp::selectItems(int x, int y, ElementObject ** eObj){
    bool itemSelected = false;
    //cout<< "Checking to see if wavetable object is clicked" << endl;
    for(int i = 0; i < numWaveTables; i++){
        if(listOfWaveTables.at(i)->inBound(x, y)){
            *eObj = listOfWaveTables.at(i);
            itemSelected = true;
            break;
        }
    }
    
    if(!itemSelected){
        //cout<< "Checking to see if slider object is clicked" << endl;
        for(int i = 0; i < numSliderObjects; i++){
            if(listOfSliderObjects.at(i)->inBound(x, y)){
                *eObj = listOfSliderObjects.at(i);
                itemSelected = true;
                break;
            }
        }
    }
    
    if(!itemSelected){
        //cout<< "Checking to see if output object is clicked" << endl;
        for(int i = 0; i < numOutput; i++){
            if(listOfOutputs.at(i)->inBound(x, y)){
                *eObj = listOfOutputs.at(i);
                itemSelected = true;
                break;
            }
        }
    }
    
    // Not yet for this. need to over ride function to do this
    //                if(!itemSelected){
    //                    for(int i = 0; i < numLineConnect; i++){
    //                        if(listOfLineConnects.at(i)->inBound(x, y)){
    //                            listOfLineConnects.at(i)->
    //                            setAmIClicked(!listOfLineConnects.at(i)->getAmIClicked());
    //                            itemSelected = true;
    //                        }
    //                    }
    //                }
    
    if(!itemSelected){
        //cout<< "Checking to see if adder object is clicked" << endl;
        for(int i = 0; i < numAdderObjects; i++){
            if(listOfAdders.at(i)->inBound(x, y)){
                *eObj = listOfAdders.at(i);
                itemSelected = true;
                break;
            }
        }
    }
    
    if(!itemSelected){
        //cout<< "Checking to see if Mult object is clicked" << endl;
        for(int i = 0; i < numMultiplierObjects; i++){
            if(listOfMultipliers.at(i)->inBound(x, y)){
                *eObj = listOfMultipliers.at(i);
                itemSelected = true;
                break;
            }
        }
    }
    
    if(!itemSelected){
        for(int i = 0; i < numNumBoxObjects; i++){
            if(listOfNumBox.at(i)->inBound(x, y)){
                *eObj = listOfNumBox.at(i);
                itemSelected = true;
                break;
            }
        }
    }
    
    return itemSelected;
}

//-------------------------------------------------------------------------------
float ofApp::euclideanDistance(float x_1, float y_1, float x_2, float y_2){
    float x_val = pow((x_2 - x_1), 2.0f);
    float y_val = pow((y_2 - y_1), 2.0f);
    return sqrt(x_val + y_val);
}
