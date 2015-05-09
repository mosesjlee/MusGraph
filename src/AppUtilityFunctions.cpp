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
    if (numElem <= 0) return false;
    
    for(int i = 0; i < numElem; i++){
        if(listOfObj->at(i)->inBound(x, y)){
            *eObj = listOfObj->at(i);
            itemSelected = true;
            return true;
        }
    }
    return itemSelected;
}

std::string Convert (int number){
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
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
void writeElementsToFile(vector<ElementObject *> * list, int size){
    if(list->size() <= 0) return;
    
    
    string fileName = "myconfig";
    string directoryText = "configs/" + fileName + ".txt";
    string textToSave;
    string tempText = "";
    ofBuffer bufToWrite;
    ofFile configFile;
    
    
    string type = list->at(0)->getType();
    
    if(type == "LineConnect"){
        cout << "Saving line connect: " << endl;
        for(int i = 0; i < list->size(); i++){
            tempText = (list->at(i)->getType()) + ";" +
                        Convert(((LineConnect *) list->at(i))->getXStart()) + ";" +
                        Convert(((LineConnect *) list->at(i))->getYStart()) + ";" +
                        Convert(((LineConnect *) list->at(i))->getXEnd()) + ";" +
                        Convert(((LineConnect *) list->at(i))->getYEnd()) + ";" +
                        Convert(((LineConnect *) list->at(i))->getElemID_1()) + ";" +
                        ((LineConnect *) list->at(i))->getType1() + ";" +
                        Convert(((LineConnect *) list->at(i))->getElemID_2()) + ";" +
                        ((LineConnect *) list->at(i))->getType2() + "\n";
            
            textToSave += tempText;
        }
    }
    else {
        cout << "List size: " << list->size() << endl;
        for(int i = 0; i < list->size(); i++){
            tempText = (list->at(i)->getType()) + ";" + Convert(list->at(i)->getXCoord()) +
                       ";" + Convert(list->at(i)->getYCoord()) + "\n";
            textToSave += tempText;
            cout << "Saving: " << tempText << endl;
        }
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
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
vector<string> * loadElementsFromFileToBuffer(){
    string fileName = "myconfig";
    string directoryText = "configs/" + fileName + ".txt";
    ofFile configFile;
    ofBuffer readBuf;
    vector<string> * listOfObjects = new vector<string>();
    
    if(configFile.doesFileExist(directoryText, true)){
        configFile.open(directoryText, ofFile::ReadOnly, false);
        readBuf = configFile.readToBuffer();
        cout << "Found file now reading: " << endl;

        while (!readBuf.isLastLine()) {
            listOfObjects->push_back(readBuf.getNextLine());
        }
    }
    return listOfObjects;
}

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
int findPosition(string * s, int start, char delimiter){
    int i = start;
    
    do{
        i++;
    }
    while(s->substr()[i] != delimiter);
    
    return i;
}