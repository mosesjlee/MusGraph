//
//  MenuView.cpp
//  mySketch
//
//  Created by Moses Lee on 4/8/15.
//
//

#include "MenuView.h"
MenuView::MenuView(int height, int width){
    menuBox.setHeight(height);
    menuBox.setHeight(width);
    
    
    //For now just push in one item
    menuListItems.push_back("Sine");
    menuListItems.push_back("Slider");
    menuListItems.push_back("Output");
    menuListItems.push_back("Adder");
    menuListItems.push_back("Multiplier");
    menuListItems.push_back("Divider");
    menuListItems.push_back("Number Box");
    menuListItems.push_back("Delay Line");
    menuListItems.push_back("Hit Box");
    menuListItems.push_back("Buffer");
    menuListItems.push_back("Sound Clip");
    
}

MenuView::MenuView()
{
    //For now just push in one item
    menuListItems.push_back("Sine");
    menuListItems.push_back("Slider");
    menuListItems.push_back("Output");
    menuListItems.push_back("Adder");
    menuListItems.push_back("Multiplier");
    menuListItems.push_back("Divider");
    menuListItems.push_back("Number Box");
    menuListItems.push_back("Delay Line");
    menuListItems.push_back("Hit Box");
    menuListItems.push_back("Buffer");
    menuListItems.push_back("Sound Clip");
}

MenuView::~MenuView()
{
}

void MenuView::setCoordinates(int x_coord, int y_coord)
{
    x = x_coord;
    y = y_coord;
    x_bound = x + width;
    y_bound = y + height;
    menuBox.setX(x_coord);
    menuBox.setY(y_coord);
}

ofRectangle * MenuView::getMenuBox(){
    return &menuBox;
}

void MenuView::setShowMenu(bool show)
{
    showMenu = show;
}

bool MenuView::getShowMenu()
{
    return showMenu;
}

void MenuView::setMenuColor(int r1, int g1, int b1)
{
    r = r1;
    g = g1;
    b = b1;
}

void MenuView::setSize(int _x, int _y)
{
    menuBox.setHeight(_x);
    menuBox.setWidth(_y);
    height = _x;
    width = _y;
}

int MenuView::getXCoord(){
    return x;
}

int MenuView::getYCoord(){
    return y;
}

void MenuView::setItemLoc(int x, int y){
    x_item_loc = x;
    y_item_loc = y;
}

int MenuView::getXItemLoc(){
    return x_item_loc;
}
int MenuView::getYItemLoc(){
    return y_item_loc;
}

void MenuView::setShowSettings(int x, int y){
    int x_c = x, y_c = y;
    if(x + 100 > 1024) x_c = x - (x + 100 - 1024);
    if(y + 310 > 768) y_c = y - (y + 310 - 768);
    setCoordinates(x_c, y_c);
    setItemLoc(x, y);
    setShowMenu(true);
}

void MenuView::drawMenu()
{
    ofSetColor(r, g, b);
    ofFill();
    ofRect(menuBox);
    
    ofSetColor(0, 0, 0);
    stringstream text;
    text << menuListItems.at(0) << endl;
    text << endl;
    text << menuListItems.at(1) << endl;
    text << endl;
    text << menuListItems.at(2) << endl;
    text << endl;
    text << menuListItems.at(3) << endl;
    text << endl;
    text << menuListItems.at(4) << endl;
    text << endl;
    text << menuListItems.at(5) << endl;
    text << endl;
    text << menuListItems.at(6) << endl;
    text << endl;
    text << menuListItems.at(7) << endl;
    text << endl;
    text << menuListItems.at(8) << endl;
    text << endl;
    text << menuListItems.at(9) << endl;
    text << endl;
    text << menuListItems.at(10) << endl;
    text << endl;
    
    ofDrawBitmapString(text.str(), x + 10, y + 20);
}

