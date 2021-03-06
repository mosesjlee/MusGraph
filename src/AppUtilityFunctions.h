//
//  AppUtilityFunctions.h
//  MusGraph
//
//  Created by Moses Lee on 4/22/15.
//
//

#ifndef __MusGraph__AppUtilityFunctions__
#define __MusGraph__AppUtilityFunctions__

#include <stdio.h>
#include <math.h>
#include "ElementObject.h"
#include "LineConnect.h"

//Instance Variables I may need

//Methods
float euclideanDistance(float x_1, float y_1, float x_2, float y_2);
bool selectItemsHelper(int x, int y, ElementObject ** eObj, vector<ElementObject *> *, int);
void writeElementsToFile(vector<ElementObject *> *, int);
void loadElementsFromFile();
vector<string> * loadElementsFromFileToBuffer();
void loadElementsFromFile(string fileName);
void createFile();
string Convert(float);
void tickAllObjects();

int findPosition(string *, int start, char delimiter);
#endif /* defined(__MusGraph__AppUtilityFunctions__) */
