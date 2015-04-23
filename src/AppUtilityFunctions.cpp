//
//  AppUtilityFunctions.cpp
//  MusGraph
//
//  Created by Moses Lee on 4/22/15.
//
//

#include "AppUtilityFunctions.h"

//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
float euclideanDistance(float x_1, float y_1, float x_2, float y_2){
    float x_val = pow((x_2 - x_1), 2.0f);
    float y_val = pow((y_2 - y_1), 2.0f);
    return sqrt(x_val + y_val);
}

//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
bool selectItemsHelper(int x, int y, ElementObject ** eObj, vector<ElementObject *> * listOfObj, int numElem){
    bool itemSelected = false;
    
    //cout<< "Checking to see if wavetable object is clicked" << endl;
    for(int i = 0; i < numElem; i++){
        if(listOfObj->at(i)->inBound(x, y)){
            *eObj = listOfObj->at(i);
            itemSelected = true;
            return true;
        }
    }
    return itemSelected;
}

std::string Convert (float number){
    std::ostringstream buff;
    buff<<number;
    return buff.str();
}

void createFile(){
    string fileName = "myconfig";
    string directoryText = "configs/" + fileName + ".txt";
    ofFile configFile(directoryText, ofFile::ReadWrite);
    configFile.create();
}

//-------------------------------------------------------------------------------------
void writeElementsToFile(vector<ElementObject *> * list, int size){
    if(list->size() <= 0) return;
    
    
    string fileName = "myconfig";
    string directoryText = "configs/" + fileName + ".txt";
    string textToSave;
    string tempText;
    ofBuffer bufToWrite;
    ofFile configFile;
    
    for(int i = 0; i < list->size(); i++){
        tempText = (list->at(i)->getType()) + ";" + Convert(list->at(i)->getXCoord()) +
                       ";" + Convert(list->at(i)->getYCoord()) + "\n";
        textToSave += tempText;
    }
    
    char * s = new char[textToSave.length()];
    for(int i = 0; i < textToSave.length(); i++){
        s[i] = textToSave.at(i);
    }
    
    bufToWrite.set(s, textToSave.length());
    
    configFile.open(directoryText, ofFile::Append, false);
    configFile.writeFromBuffer(bufToWrite);
    configFile.close();
    
    delete [] s;
}

//-------------------------------------------------------------------------------------
void loadElementsFromFile(){
    string fileName = "myconfig";
    string directoryText = "configs/" + fileName + ".txt";
    ofFile configFile;
    ofBuffer readBuf;
    
    if(configFile.doesFileExist(directoryText, true)){
        configFile.open(directoryText, ofFile::ReadOnly, false);
        readBuf = configFile.readToBuffer();
        //if(readBuf.getText() != "") tagList.push_back(readBuf.getText());
        return true;
    }
    
}