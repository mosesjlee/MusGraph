#include "Wavetable.h"

WaveTable::WaveTable()
{
	//Create a new table
	table = new double[MAX_SAMPLES]; 
	index = 0;

	for(int i = 0; i < MAX_SAMPLES; i++)
	{
		table[i] = sin(2 * M_PI * (double) i/MAX_SAMPLES);
	}
}

WaveTable::WaveTable(int x_coord, int y_coord)
{
    table = new double[MAX_SAMPLES];
    index = 0;
    
    for(int i = 0; i < MAX_SAMPLES; i++)
    {
        table[i] = sin(2 * M_PI * (double) i/MAX_SAMPLES);
    }
    
    //Set the coordinates and the visual representation
    x = sineTab.x = x_coord;
    y = sineTab.y = y_coord;
    
    sineTab.setWidth(50.0);
    sineTab.setHeight(30.0);
    x_bound = x + 50;
    y_bound = y + 30;
    type = "sine";
    
}

WaveTable::~WaveTable()
{
	delete [] table;
}

void WaveTable::setFreq(double freq)
{
	delta_i = freq * MAX_SAMPLES/SR;
}

double WaveTable::tick()
{
	double val = table[(int) index];

	//Increment by delta i
	index += delta_i;

	//Out of bounds check
	if(index >= MAX_SAMPLES) index -= MAX_SAMPLES;
	if(index < 0) index += MAX_SAMPLES;

	return val;
}


double WaveTable::lerp(double x_1, double y_1, double x_2, double y_2, double x)
{
	return y_1 + (y_2 - y_1) * (x - x_1)/(x_2-x_1);
}

void WaveTable::draw(){
    if(!amIClicked){
        ofSetColor(0, 0, 0);
        ofNoFill();
    }
    else {
        ofSetColor(125, 100, 100);
        ofFill();
    }
    
    ofSetLineWidth(2);
    ofRect(sineTab);
    
    stringstream text;
    text << "Sine" << endl;
    ofSetColor(0, 0, 0);
    ofDrawBitmapString(text.str(), x+8, y+20);
}
