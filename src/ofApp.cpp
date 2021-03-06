#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //Set for all white background
    ofBackground(255,255,255);
    
    //Set up the ofxUI elements
    setUpGUIElements();
    
    //Create a menuView object
    selectMenu.setSize(310, 100);
    selectMenu.setMenuColor(101, 123, 140);
}

//--------------------------------------------------------------
void ofApp::update(){
    numWaveTables = listOfWaveTables.size();
    numOutput = listOfOutputs.size();
    numSliderObjects = listOfSliderObjects.size();
    numLineConnect = listOfLineConnects.size();
    numMultiplierObjects = listOfMultipliers.size();
    numAdderObjects = listOfAdders.size();
    numDividerObjects = listOfDividers.size();
    numNumBoxObjects = listOfNumBox.size();
    numDelayLine = listOfDelayLines.size();
    numHitObjects = listOfHitObjects.size();
    numBufferObjects = listOfBuffers.size();
    numSoundClipObjects = listOfSoundClips.size();
}

//--------------------------------------------------------------
void ofApp::draw(){
    //Show menu if right is clicked
    if(selectMenu.getShowMenu()) {
        selectMenu.drawMenu();
    }
    
    //Draw the list of wave tables
    if(numWaveTables > 0){
        for(int i = 0; i < numWaveTables; i++)
            listOfWaveTables.at(i)->draw();
    }
    
    //Draw the list of output items
    if(numOutput > 0){
        for(int i = 0; i < numOutput; i++)
            listOfOutputs.at(i)->draw();
    }
    
    //Draw the list of line connect items
    if (numLineConnect > 0) {
        for(int i = 0; i < numLineConnect;i++)
            listOfLineConnects.at(i)->draw();
    }
    
    if(numAdderObjects > 0){
        for(int i = 0; i < numAdderObjects;i++)
            listOfAdders.at(i)->draw();
    }
    
    if(numMultiplierObjects > 0){
        for(int i = 0; i < numMultiplierObjects;i++)
            listOfMultipliers.at(i)->draw();
    }
    
    if(numDividerObjects > 0){
        for(int i = 0; i < numDividerObjects;i++)
            listOfDividers.at(i)->draw();
    }
    
    if(numNumBoxObjects > 0){
        for(int i = 0; i < numNumBoxObjects;i++)
            listOfNumBox.at(i)->draw();
    }
    
    if(numDelayLine > 0){
        for(int i = 0; i < numDelayLine ;i++)
            listOfDelayLines.at(i)->draw();
    }
    
    if(numBufferObjects > 0){
        for(int i = 0; i < numBufferObjects; i++)
            listOfBuffers.at(i)->draw();
    }
    
    if(numSoundClipObjects > 0){
        for(int i = 0; i < numSoundClipObjects; i++)
            listOfSoundClips.at(i)->draw();
    }
    
    //Draw line connects
    if(currLine != NULL) {
        ofSetLineWidth(4);
        currLine->draw();
    }
    
    glfwWaitEvents();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == DELETE_KEY){
        if(currObject_1 != NULL){
        }
    } else if(key == SPACE_BAR) {
        if(onOff == 0) onOff = 1;
        if(onOff == 1) onOff = 0;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){}

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
        
            if(selectMenu.getShowMenu() && onOff == 0){
                if(x > x_coord && x < x_bound && y > y_coord && y < y_bound){
                    cout << "In menu: " << endl;
                    int x_loc = selectMenu.getXItemLoc();
                    int y_loc = selectMenu.getYItemLoc();
                    
                    if(y > y_coord && y < y_coord + 30){
                        addWaveTableObject(x_loc, y_loc);
                    }
                    else if(y > y_coord + 30 && y < y_coord + 60){
                        cout << "second menu" << endl;
                        addSliderObject(x_loc, y_loc);
                    }
                    else if(y > y_coord + 60 && y < y_coord + 90){
                        cout << "third menu" << endl;
                        addOutputObject(x_loc, y_loc);
                    }
                    else if(y > y_coord + 90 && y < y_coord + 110){
                        cout << "Adder " << endl;
                        addAdderObject(x_loc, y_loc);
                    }
                    else if(y > y_coord + 110 && y < y_coord + 140){
                        cout << "Multiplier " << endl;
                        addMultiplierObject(x_loc, y_loc);
                    }
                    else if(y > y_coord + 140 && y < y_coord + 170){
                        cout << "Divider " << endl;
                        addDividerObject(x_loc, y_loc);
                    }
                    else if(y > y_coord + 170 && y < y_coord + 200){
                        cout << "Number Box " << endl;
                        addNumberBoxObject(x_loc, y_loc);
                    }
                    else if(y > y_coord + 200 && y < y_coord + 225){
                        cout << "Delay Line " << endl;
                        addDelayLine(x_loc, y_loc);
                    }
                    else if(y > y_coord + 225 && y < y_coord + 250){
                        cout << "Hit Box " << endl;
                        addHitObject(x_loc, y_loc);
                    }
                    else if(y > y_coord + 250 && y < y_coord + 280){
                        cout << "Buffer " << endl;
                        addBufferObject(x_loc, y_loc);
                    }
                    else if(y > y_coord + 280 && y < y_coord + 310){
                        cout << "Sound Clip " << endl;
                        addSoundClipObject(x_loc, y_loc);
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
            if(onOff == 0){
                selectMenu.setShowSettings(x, y);
            }
            break;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    bool validConnection = false;
    
    if (button == LEFT_CLICK && !selectMenu.getShowMenu() && currLine != NULL && onOff == 0) {
        currLine->lineTo(x,y);
        
        int x_1, y_1, x_2, y_2;
        
        if(selectItems(x, y, &currObject_2) && euclideanDistance(initial_x, initial_y, x, y) > 10.0){
            x_1 = currObject_1->getXCoord();
            y_1 = currObject_1->getYCoord();
            
            x_2 = currObject_2->getXCoord();
            y_2 = currObject_2->getYCoord();
            
            lineConnectPtr = new LineConnect(currLine, x_1, y_1, x_2, y_2);
            //lineConnectPtr = new LineConnect(currLine);
            
            lineConnectPtr->setFirstElement(currObject_1);
            lineConnectPtr->setSecondElement(currObject_2);
            
            validConnection = lineConnectPtr->makeConnections();
            
            if(validConnection){
                listOfLineConnects.push_back(lineConnectPtr);
                if(currObject_2->getType() == "Delay Line"){
                    cout << "Adding another delay line element: \n";
                    if(currObject_1->getType() != "NumberBox"){
                        elementsConnectedToDelayLine.push_back((TickableElement *)currObject_1);
                    }
                }
            }
            else {
                delete lineConnectPtr;
            }
            
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
void ofApp::windowResized(int w, int h){}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){}

//--------------------------------------------------------------
void ofApp::audioOut(float *output, int bufferSize, int nChannels){
//    tickElements();
    //Noise
    //This is hard coded
    //cout << "goes in audioOut: " << onOff << " numOutput: " << numOutput <<endl;
    
    if(onOff == 1 && numOutput > 0) {
        fillDelayLineBuff();
        tickSoundClipObjects();
        tickOperators();
        tickElements();
        //cout << "goes in the if " << endl;
        listOfOutputs.at(0)->fillOutBuffer(output, bufferSize, nChannels);
    }
}

void ofApp::fillDelayLineBuff(){
    for (int i = 0; i < listOfDelayLines.size(); i++){
        listOfDelayLines.at(i)->fillCurrentOut();
    }
}

void ofApp::tickElements(){
    for(int i = 0; i < listOfTickableElements.size(); i++){
        listOfTickableElements.at(i)->tick();
    }
}

void ofApp::tickSoundClipObjects(){
    for(int i = 0; i < listOfSoundClips.size(); i++){
        listOfSoundClips.at(i)->tick();
    }
}

void ofApp::tickOperators(){
    for(int i = 0; i < listOfOperators.size(); i++){
        listOfOperators.at(i)->tick();
    }
}
//--------------------------------------------------------------
void ofApp::guiEvent(ofxUIEventArgs & e){
    string name = e.getName();
    
    if(name == "Slider") {
        int currSliderID = e.getSlider()->getID();
        double val = e.getSlider()->getValue();
        string type = "";
        
        //Look for the slider ID
            
        if(listOfSliderObjects.at(currSliderID)->getMyID() == currSliderID){
            
            if(listOfSliderObjects.at(currSliderID)->getObjectToControl() == NULL){
                return;
            }
                
            type = listOfSliderObjects.at(currSliderID)->getObjectToControl()->getType();
                
            if(type == "Sine"){
                ((WaveTableObject *) listOfSliderObjects.at(currSliderID)->getObjectToControl())->setFreq(val);
            }
            else if(type == "NumberBox"){
                ((NumberBoxObject *) listOfSliderObjects.at(currSliderID)->
                 getObjectToControl())->setMyValue(val);
            }
        }
    }
    
    else if(name == "HitBox"){
        int hitID = e.getButton()->getID();
        int value = e.getButton()->getValue();
        if(value == 1){
            if(listOfHitObjects.at(hitID)->getMyID() == hitID){
                listOfHitObjects.at(hitID)->receivedHit();
            }
        }
    }
    
    else if(name == "NumberBox"){
        //cout << "in number box" << endl;
        ofxUITextInput * ti = (ofxUITextInput *) e.widget;
        
        int numberBoxID = ti->getID();
        string newValue = ti->getTextString();
        //cout << "New text value: " << newValue << endl;
        
        if(listOfNumBox.at(numberBoxID)->getMyID() == numberBoxID){
            if(ti->getInputTriggerType() == OFX_UI_TEXTINPUT_ON_ENTER){
                listOfNumBox.at(numberBoxID)->setMyValue(atof(newValue.data()));
            }
        }
    }
    
    //For the MENU GUI
    else if(name == "On/Off") {
        onOff = e.getToggle()->getValue();
        cout << "Toggle value: " << onOff << endl;
    }
    
    else if (name == "Save Configuration"){
        cout << "Saving Configuration: " << endl;
        int value = e.getButton()->getValue();
        cout << "Value: " << value <<endl;
        
        if(value == 1){
            createFile();
            writeElementsToFile((ELEMVECT) &listOfWaveTables, numWaveTables);
            writeElementsToFile((ELEMVECT) &listOfSliderObjects, numSliderObjects);
            writeElementsToFile((ELEMVECT) &listOfNumBox, numNumBoxObjects);
            writeElementsToFile((ELEMVECT) &listOfOutputs, numOutput);
            writeElementsToFile((ELEMVECT) &listOfAdders, numAdderObjects);
            writeElementsToFile((ELEMVECT) &listOfMultipliers, numMultiplierObjects);
            writeElementsToFile((ELEMVECT) &listOfDividers, numDividerObjects);
            writeElementsToFile((ELEMVECT) &listOfDelayLines, numDelayLine);
            writeElementsToFile((ELEMVECT) &listOfHitObjects, numHitObjects);
            writeElementsToFile((ELEMVECT) &listOfBuffers, numBufferObjects);
            writeElementsToFile((ELEMVECT) &listOfSoundClips, numSoundClipObjects);
            writeElementsToFile((ELEMVECT) &listOfLineConnects, numLineConnect);
        }
    }
    
    else if(name == "Load Configuration"){
        cout << "Load Configs: " << endl;
        int value = e.getButton()->getValue();
        
        if(value == 1){
            createObjects(loadElementsFromFileToBuffer());
        }
    }
    
    else if(name == "Clear Elements"){
        int value = e.getButton()->getValue();
        if(value == 1 && onOff == 0){
            clearElements();
        }
    }
}
//--------------------------------------------------------------
//Deletes dynamically allocated objects
//--------------------------------------------------------------
void ofApp::exit(){
    delete menuGUI;
    delete saveMenuGUI;
    delete saveFileNameUI;
    clearElements();
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
    menuGUI->setDimensions(100, 32);
    onOffButton = menuGUI->addToggle("On/Off", false);
    ofAddListener(menuGUI->newGUIEvent,this,&ofApp::guiEvent);
    
    saveMenuGUI = new ofxUICanvas();
    saveMenuGUI->setDimensions(150, 32);
    saveMenuGUI->setPosition(100, 0);
    saveButton = saveMenuGUI->addButton("Save Configuration", false);
    ofAddListener(saveMenuGUI->newGUIEvent,this,&ofApp::guiEvent);
    
    saveFileNameUI = new ofxUICanvas();
    saveFileNameUI->setDimensions(150, 32);
    saveFileNameUI->setPosition(250, 0);
    saveNameField = saveFileNameUI->addTextInput("", "Save File Name");
    ofAddListener(saveFileNameUI->newGUIEvent,this,&ofApp::guiEvent);
    
    loadConfigMenu = new ofxUICanvas();
    loadConfigMenu->setDimensions(160, 32);
    loadConfigMenu->setPosition(400, 0);
    loadButton = loadConfigMenu->addButton("Load Configuration", false);
    ofAddListener(loadConfigMenu->newGUIEvent,this,&ofApp::guiEvent);
    
    clearElementsMenu = new ofxUICanvas();
    clearElementsMenu->setDimensions(160, 32);
    clearElementsMenu->setPosition(560, 0);
    clearElementsButton = clearElementsMenu->addButton("Clear Elements", false);
    ofAddListener(clearElementsMenu->newGUIEvent,this,&ofApp::guiEvent);
}

void ofApp::addWaveTableObject(int x, int y){
    waveTablePtr = new WaveTableObject(x, y);
    waveTablePtr->setFreq(440);
    waveTablePtr->setMyID(listOfWaveTables.size());
    listOfWaveTables.push_back(waveTablePtr);
    
    listOfTickableElements.push_back(waveTablePtr);
}

void ofApp::addOutputObject(int x, int y){
    outputPtr = new OutputElement(x, y);
    outputPtr->setUpAudio(this);
    outputPtr->setMyID(listOfOutputs.size());
    listOfOutputs.push_back(outputPtr);
    numOutput = listOfOutputs.size();
}

void ofApp::addSliderObject(int x, int y){
    elementsGUI = new ofxUICanvas();
    ofAddListener(elementsGUI->newGUIEvent, this, &ofApp::guiEvent);
    
    sliderPtr = new SliderObject(elementsGUI, 40, 80, 440, listOfSliderObjects.size());
    sliderPtr->setCoord(x, y);
    listOfSliderObjects.push_back(sliderPtr);
}

void ofApp::addAdderObject(int x, int y){
    adderPtr = new AdderObject(x, y);
    adderPtr->setMyID(listOfAdders.size());
    listOfAdders.push_back(adderPtr);
    //listOfTickableElements.push_back(adderPtr);
    listOfOperators.push_back(adderPtr);
}

void ofApp::addMultiplierObject(int x, int y){
    multiplierPtr = new MultiplierObject(x, y);
    multiplierPtr->setMyID(listOfMultipliers.size());
    listOfMultipliers.push_back(multiplierPtr);
    //listOfTickableElements.push_back(multiplierPtr);
    listOfOperators.push_back(multiplierPtr);
}

void ofApp::addDividerObject(int x, int y){
    dividerPtr = new DividerObject(x, y);
    dividerPtr->setMyID(listOfDividers.size());
    listOfDividers.push_back(dividerPtr);
    //listOfTickableElements.push_back(dividerPtr);
    listOfOperators.push_back(dividerPtr);
}


void ofApp::addNumberBoxObject(int x, int y){
    elementsGUI = new ofxUICanvas();
    ofAddListener(elementsGUI->newGUIEvent, this, &ofApp::guiEvent);
    nbPtr = new NumberBoxObject(x, y, elementsGUI, listOfNumBox.size());
    listOfNumBox.push_back(nbPtr);
}

void ofApp::addDelayLine(int x, int y){
    delayPtr = new DelayLineObject(x, y, listOfDelayLines.size());
    listOfDelayLines.push_back(delayPtr);
    listOfTickableElements.push_back(delayPtr);
}

void ofApp::addHitObject(int x, int y){
    elementsGUI = new ofxUICanvas();
    ofAddListener(elementsGUI->newGUIEvent, this, &ofApp::guiEvent);
    
    hitPtr = new HitObject(elementsGUI, x, y, listOfHitObjects.size());
    listOfHitObjects.push_back(hitPtr);
}

void ofApp::addBufferObject(int x, int y){
    bufferPtr = new BufferObject(x, y, listOfBuffers.size());
    listOfBuffers.push_back(bufferPtr);
    listOfTickableElements.push_back(bufferPtr);
}

void ofApp::addSoundClipObject(int x, int y){
    soundClipPtr = new SoundClipObject(x, y, listOfSoundClips.size());
    listOfSoundClips.push_back(soundClipPtr);
    //listOfTickableElements.push_back(soundClipPtr);
}

void ofApp::clearElements(){
    if(numWaveTables > 0){
        for(int i = 0; i < numWaveTables; i++)
            delete listOfWaveTables.at(i);
        listOfWaveTables.clear();
    }
    
    if(numSliderObjects > 0){
        for(int i = 0; i < numSliderObjects; i++)
            delete listOfSliderObjects.at(i);
        listOfSliderObjects.clear();
    }
    
    if(numOutput > 0) {
        for(int i = 0; i < numOutput; i++)
            delete listOfOutputs.at(i);
        listOfOutputs.clear();
    }
    
    if(numLineConnect > 0){
        for(int i = 0; i < numLineConnect; i++)
            delete listOfLineConnects.at(i);
        listOfLineConnects.clear();
    }
    
    if(numMultiplierObjects > 0){
        for(int i = 0; i < numMultiplierObjects; i++)
            delete listOfMultipliers.at(i);
        listOfMultipliers.clear();
    }
    
    if(numAdderObjects > 0){
        for(int i = 0; i < numAdderObjects; i++)
            delete listOfAdders.at(i);
        listOfAdders.clear();
    }
    
    if(numDividerObjects > 0){
        for(int i = 0; i < numDividerObjects; i++)
            delete listOfDividers.at(i);
        listOfDividers.clear();
    }
    
    if(numNumBoxObjects > 0){
        for(int i = 0; i < numNumBoxObjects; i++)
            delete listOfNumBox.at(i);
        listOfNumBox.clear();
    }
    
    if(numDelayLine > 0){
        for(int i = 0; i < numDelayLine; i++)
            delete listOfDelayLines.at(i);
        listOfDelayLines.clear();
    }
    
    if(numHitObjects > 0){
        for(int i = 0; i < numHitObjects; i++)
            delete listOfHitObjects.at(i);
        listOfHitObjects.clear();
    }
    
    if(numBufferObjects > 0){
        for(int i = 0; i < numBufferObjects; i++)
            delete listOfBuffers.at(i);
        listOfBuffers.clear();
    }
    
    if(numSoundClipObjects > 0){
        for(int i = 0; i < numSoundClipObjects; i++)
            delete listOfSoundClips.at(i);
        listOfSoundClips.clear();
    }
    
    listOfTickableElements.clear();
    elementsConnectedToDelayLine.clear();
    listOfOperators.clear();
    
    cout << "Deleted all objects sucessfully" << endl;
    numWaveTables = listOfWaveTables.size();
    numOutput = listOfOutputs.size();
    numSliderObjects = listOfSliderObjects.size();
    numLineConnect = listOfLineConnects.size();
    numMultiplierObjects = listOfMultipliers.size();
    numAdderObjects = listOfAdders.size();
    numDividerObjects = listOfDividers.size();
    numNumBoxObjects = listOfNumBox.size();
    numDelayLine = listOfDelayLines.size();
    numHitObjects = listOfHitObjects.size();
    numBufferObjects = listOfBuffers.size();
    numSoundClipObjects = listOfSoundClips.size();
}

//-------------------------------------------------------------------------------
//Select Items based on locations
//-------------------------------------------------------------------------------
bool ofApp::selectItems(int x, int y, ElementObject ** eObj){
    bool itemSelected = false;
    
    itemSelected = selectItemsHelper(x, y, eObj, (ELEMVECT) &listOfWaveTables, numWaveTables);
    
    if(!itemSelected)
        itemSelected = selectItemsHelper(x, y, eObj, (ELEMVECT) &listOfSliderObjects, numSliderObjects);
    
    if(!itemSelected)
        itemSelected = selectItemsHelper(x, y, eObj, (ELEMVECT) &listOfOutputs, numOutput);
    
    if(!itemSelected)
        itemSelected = selectItemsHelper(x, y, eObj, (ELEMVECT) &listOfAdders, numAdderObjects);
    
    if(!itemSelected)
        itemSelected = selectItemsHelper(x, y, eObj, (ELEMVECT) &listOfMultipliers, numMultiplierObjects);
    
    if(!itemSelected)
        itemSelected = selectItemsHelper(x, y, eObj, (ELEMVECT) &listOfDividers, numDividerObjects);
    
    if(!itemSelected)
        itemSelected = selectItemsHelper(x, y, eObj, (ELEMVECT) &listOfNumBox, numNumBoxObjects);
    
    if(!itemSelected)
        itemSelected = selectItemsHelper(x, y, eObj, (ELEMVECT) &listOfDelayLines, numDelayLine);
    
    if(!itemSelected)
        itemSelected = selectItemsHelper(x, y, eObj, (ELEMVECT) &listOfBuffers, numBufferObjects);
    
    if(!itemSelected)
        itemSelected = selectItemsHelper(x, y, eObj, (ELEMVECT) &listOfHitObjects, numHitObjects);
    
    if(!itemSelected)
        itemSelected = selectItemsHelper(x, y, eObj, (ELEMVECT) &listOfSoundClips, numSoundClipObjects);
    
    return itemSelected;
}

//Create the objects based on the config file string
void ofApp::createObjects(vector<string> * listOfObjects){
    cout << "in creating objects: " << endl;
    
    string temp = "", x_pos = "", y_pos = "", x_end_pos = "", y_end_pos = "", id_1 = "", id_2 = "";
    string type_1 = "";
    string type_2 = "";
    
    const string delimiter = ";";
    string holder = "";
    
    int first_pos = 0, second_pos = 0, third_pos = 0, fourth_pos = 0;
    int fifth_pos = 0, sixth_pos = 0, seventh_pos = 0, eighth_pos = 0;
    
    for(int i = 0; i < listOfObjects->size(); i++){
        holder = "";
        temp = "";
        x_pos = "";
        y_pos = "";
        
        //Only for line connects
        x_end_pos = "";
        y_end_pos = "";
        id_1 = "";
        id_2 = "";
        type_1 = "";
        type_2 = "";
        
        holder = listOfObjects->at(i);
        first_pos = holder.find(delimiter);
        second_pos = findPosition(&holder, first_pos+1, delimiter.substr()[0]);
        
        for ( int j = 0; j < first_pos; j++){
            temp += holder.substr()[j];
        }
        for ( int j = first_pos + 1; j < second_pos; j++){
            x_pos += holder.substr()[j];
        }
        
        for ( int j = second_pos + 1; j < holder.size(); j++){
            if(holder.substr()[j] == delimiter.substr()[0]) break;
            y_pos += holder.substr()[j];
        }
        
        if(temp != "LineConnect"){
            cout << "Creating: " << temp << " At: " << x_pos << ", " << y_pos << endl;
        
            if(temp == "Sine"){
                addWaveTableObject(atoi(&x_pos.substr()[0]), atoi(&y_pos.substr()[0]));
            }
            else if(temp == "Output"){
                addOutputObject(atoi(&x_pos.substr()[0]), atoi(&y_pos.substr()[0]));
            }
            else if(temp == "Slider"){
                addSliderObject(atoi(&x_pos.substr()[0]), atoi(&y_pos.substr()[0]));
            }
            else if(temp == "NumberBox"){
                addNumberBoxObject(atoi(&x_pos.substr()[0]), atoi(&y_pos.substr()[0]));
            }
            else if(temp == "Adder"){
                addAdderObject(atoi(&x_pos.substr()[0]), atoi(&y_pos.substr()[0]));
            }
            else if(temp == "Multiplier"){
                addMultiplierObject(atoi(&x_pos.substr()[0]), atoi(&y_pos.substr()[0]));
            }
            else if(temp == "Divider"){
                addDividerObject(atoi(&x_pos.substr()[0]), atoi(&y_pos.substr()[0]));
            }
            else if(temp == "Delay Line"){
                addDelayLine(atoi(&x_pos.substr()[0]), atoi(&y_pos.substr()[0]));
            }
            else if(temp == "HitBox"){
                addHitObject(atoi(&x_pos.substr()[0]), atoi(&y_pos.substr()[0]));
            }
            else if(temp == "Buffer"){
                addBufferObject(atoi(&x_pos.substr()[0]), atoi(&y_pos.substr()[0]));
            }
            else if(temp == "SoundClip"){
                addSoundClipObject(atoi(&x_pos.substr()[0]), atoi(&y_pos.substr()[0]));
            }
        }
        else {
            third_pos = findPosition(&holder, second_pos+1, delimiter.substr()[0]);
            fourth_pos = findPosition(&holder, third_pos+1, delimiter.substr()[0]);
            fifth_pos = findPosition(&holder, fourth_pos+1, delimiter.substr()[0]);
            sixth_pos = findPosition(&holder, fifth_pos+1, delimiter.substr()[0]);
            seventh_pos = findPosition(&holder, sixth_pos+1, delimiter.substr()[0]);
            eighth_pos = findPosition(&holder, seventh_pos+1, delimiter.substr()[0]);
            
            for ( int j = third_pos + 1; j < fourth_pos; j++)
                x_end_pos += holder.substr()[j];
            
            for ( int j = fourth_pos + 1; j < fifth_pos; j++)
                y_end_pos += holder.substr()[j];

            for ( int j = fifth_pos + 1; j < sixth_pos; j++)
                id_1 += holder.substr()[j];
            
            for ( int j = sixth_pos + 1; j < seventh_pos; j++)
                type_1 += holder.substr()[j];

            for ( int j = seventh_pos + 1; j < eighth_pos; j++)
                id_2 += holder.substr()[j];
            
            for ( int j = eighth_pos + 1; j < holder.size(); j++)
                type_2 += holder.substr()[j];
            
            
            //cout << "Creating: " << temp << " from: " << x_pos << ", " << y_pos << " to: " <<
            //x_end_pos << ", " << y_end_pos << " connects: " << type_1 << " to: " << type_2 << endl;
            
            lineConnectPtr = new LineConnect(atoi(&x_pos.substr()[0]),
                                             atoi(&y_pos.substr()[0]),
                                             atoi(&x_end_pos.substr()[0]),
                                             atoi(&y_end_pos.substr()[0]));
            
            ELEMVECT o1, o2;
            
            if(type_1 == "Sine"){
                o1 = (ELEMVECT) listOfWaveTables.at(atoi(&id_1.substr()[0]));
            }
            else if(type_1 == "Output"){
                o1 = (ELEMVECT) listOfOutputs.at(atoi(&id_1.substr()[0]));
            }
            else if(type_1 == "NumberBox"){
                o1 = (ELEMVECT) listOfNumBox.at(atoi(&id_1.substr()[0]));
            }
            else if(type_1 == "Slider"){
                o1 = (ELEMVECT) listOfSliderObjects.at(atoi(&id_1.substr()[0]));
            }
            else if(type_1 == "Multiplier"){
                o1 = (ELEMVECT) listOfMultipliers.at(atoi(&id_1.substr()[0]));
            }
            else if(type_1 == "Adder"){
                o1 = (ELEMVECT) listOfAdders.at(atoi(&id_1.substr()[0]));
            }
            else if(type_1 == "Divider"){
                o1 = (ELEMVECT) listOfDividers.at(atoi(&id_1.substr()[0]));
            }
            else if(type_1 == "Delay Line"){
                o1 = (ELEMVECT) listOfDelayLines.at(atoi(&id_1.substr()[0]));
            }
            else if(type_1 == "HitBox"){
                o1 = (ELEMVECT) listOfHitObjects.at(atoi(&id_1.substr()[0]));
            }
            else if(type_1 == "Buffer"){
                o1 = (ELEMVECT) listOfBuffers.at(atoi(&id_1.substr()[0]));
            }
            else if(type_1 == "SoundClip"){
                o1 = (ELEMVECT) listOfSoundClips.at(atoi(&id_1.substr()[0]));
            }
            
            if(type_2 == "Sine"){
                o2 = (ELEMVECT) listOfWaveTables.at(atoi(&id_2.substr()[0]));
            }
            else if(type_2 == "Output"){
                o2 = (ELEMVECT) listOfOutputs.at(atoi(&id_2.substr()[0]));
            }
            else if(type_2 == "NumberBox"){
                o2 = (ELEMVECT) listOfNumBox.at(atoi(&id_2.substr()[0]));
            }
            else if(type_2 == "Slider"){
                o2 = (ELEMVECT) listOfSliderObjects.at(atoi(&id_2.substr()[0]));
            }
            else if(type_2 == "Multiplier"){
                o2 = (ELEMVECT) listOfMultipliers.at(atoi(&id_2.substr()[0]));
            }
            else if(type_2 == "Adder"){
                o2 = (ELEMVECT) listOfAdders.at(atoi(&id_2.substr()[0]));
            }
            else if(type_2 == "Divider"){
                o2 = (ELEMVECT) listOfDividers.at(atoi(&id_2.substr()[0]));
            }
            else if(type_2 == "Delay Line"){
                o2 = (ELEMVECT) listOfDelayLines.at(atoi(&id_2.substr()[0]));
            }
            else if(type_2 == "HitBox"){
                o2 = (ELEMVECT) listOfHitObjects.at(atoi(&id_2.substr()[0]));
            }
            else if(type_2 == "Buffer"){
                o2 = (ELEMVECT) listOfBuffers.at(atoi(&id_2.substr()[0]));
            }
            else if(type_2 == "SoundClip"){
                o2 = (ELEMVECT) listOfSoundClips.at(atoi(&id_2.substr()[0]));
            }
            
            lineConnectPtr->setFirstElement((ElementObject *) o1);
            lineConnectPtr->setSecondElement((ElementObject *) o2);
            lineConnectPtr->makeConnections();
            listOfLineConnects.push_back(lineConnectPtr);
        }
    }
    delete listOfObjects;
}