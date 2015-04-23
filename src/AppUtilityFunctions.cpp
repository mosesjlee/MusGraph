//
//  AppUtilityFunctions.cpp
//  MusGraph
//
//  Created by Moses Lee on 4/22/15.
//
//

#include "AppUtilityFunctions.h"

//Variables I may need
ofFile configFile;

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

//-------------------------------------------------------------------------------------
void writeElementsToFile(vector<ElementObject *> *, int){
    configFile.open("configs.txt");
    
}