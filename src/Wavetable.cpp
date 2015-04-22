#include "Wavetable.h"
#include "AdderObject.h"

WaveTable::WaveTable()
{
	//Create a new table
	table = new float[MAX_SAMPLES];
	index = 0;
    freq = 440.0;
	for(int i = 0; i < MAX_SAMPLES; i++)
	{
		table[i] = sin(2 * M_PI * (float) i/MAX_SAMPLES);
	}
}

WaveTable::WaveTable(int x_coord, int y_coord)
{
    table = new float[MAX_SAMPLES];
    index = 0;
    freq = 440.0;
    
    for(int i = 0; i < MAX_SAMPLES; i++)
    {
        table[i] = sin(2 * M_PI * (float) i/MAX_SAMPLES);
    }
    
    //Set the coordinates and the visual representation
    x = displayRect.x = x_coord;
    y = displayRect.y = y_coord;
    
    displayRect.setWidth(WT_WIDTH);
    displayRect.setHeight(WT_HEIGHT);
    x_bound = x + WT_WIDTH;
    y_bound = y + WT_HEIGHT;
    type = "Sine";
    
}

WaveTable::~WaveTable()
{
	delete [] table;
}

void WaveTable::setFreq(float newFreq)
{
    freq = newFreq;
	delta_i = freq * MAX_SAMPLES/SR;
}

float WaveTable::tick()
{
    if(input != NULL) setFreq(((AdderObject *) input)->tick());
    
	float val = table[(int) index];

	//Increment by delta i
	index += delta_i;

	//Out of bounds check
	if(index >= MAX_SAMPLES) index -= MAX_SAMPLES;
	if(index < 0) index += MAX_SAMPLES;

	return val;
}

void WaveTable::setInput(ElementObject * o){
    cout << "Sine just connected Input: " << endl;
    input = o;
}

double WaveTable::lerp(double x_1, double y_1, double x_2, double y_2, double x)
{
	return y_1 + (y_2 - y_1) * (x - x_1)/(x_2-x_1);
}
