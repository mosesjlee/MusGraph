//
//  menuView.h
//  mySketch
//
//  Created by Moses Lee on 4/8/15.
//
//

#ifndef __mySketch__MenuView__
#define __mySketch__MenuView__

#include <stdio.h>
#include "ofRectangle.h"
#include "ofGraphics.h"

class MenuView{
public:
    MenuView();
    MenuView(int height, int width);
    void setCoordinates(int x, int y);
    void setSize(int x, int y);
    void setShowMenu(bool show);
    bool getShowMenu();
    void setMenuColor(int r, int g, int b);
    void drawMenu();
    int getXCoord();
    int getYCoord();
    int getHeight() {return height;}
    int getWidth() {return width;}
    int getXBound() {return x_bound;}
    int getYBound() {return y_bound;}
    void menuChoice(int x, int y);
    ofRectangle * getMenuBox();
    ~MenuView();
    
private:
    ofRectangle menuBox;
    bool showMenu = false;
    int x;
    int y;
    int x_bound, y_bound;
    int height;
    int width;
    int r,g,b;
    vector <string> menuListItems;
    
};

#endif /* defined(__mySketch__menuView__) */
