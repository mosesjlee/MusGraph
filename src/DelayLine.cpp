#include <iostream>
#include "delayl.h"

using std::cout;
using std::endl;

DelayLine::DelayLine()
{
  maxDelay = 4096;
  buffer = new float [maxDelay+1];
  for (int i=0; i<maxDelay+1; i++) buffer[i] = 0.0;
  currDelay = maxDelay;
  currIndex = 0;
}

DelayLine::DelayLine(int size)
{
  maxDelay = size;
  buffer = new float [maxDelay+1];
  for (int i=0; i<maxDelay+1; i++) buffer[i] = 0.0;
  currDelay = maxDelay;
  currIndex = 0;
}

DelayLine::~DelayLine()
{
  delete [] buffer;
}

void DelayLine::setDelayLineDelay(float newDelay)
{
  if (newDelay > (float) maxDelay) {
    cout << "Error: setting delay greater than max delay...\n";
    return;
  }
  else {
    currDelay = newDelay;
  }
}

float DelayLine::getDelayLineDelay()
{
  return currDelay;
}

void DelayLine::getCurrentOut(float * buf, int blockSize, int blockPos){
    float output = 0.0f;
    float readIndex;
    float delayDifferential;
    
//    if(currDelay < (float) blockSize) delayDifferential = currDelay + (blockSize - currDelay);
//    else delayDifferential = currDelay;
    
    delayIndex = currIndex - currDelay;
    //cout << "delayIndex: " << delayIndex << " blockPos: " << blockPos << endl;
    
    for (int i = 0; i < blockSize; i++) {
        readIndex = delayIndex + i;
        if (readIndex < 0.0) readIndex = readIndex + ((float) maxDelay + 1.0);
    
        if (readIndex > (float) maxDelay) {
            output = buffer[(int) readIndex] + (buffer[0] -
                                             buffer[(int) readIndex]) * (readIndex -
                                                                          (float) ((int) readIndex));
        }
        else {
            output = buffer[(int) readIndex] + (buffer[(int) readIndex + 1] -
                                             buffer[(int) readIndex]) * (readIndex - (float) ((int) readIndex));
        }
    
        if (output > 1.0)
            output = 1.0;
        else if (output < -1.0)
            output = -1.0;
        
        buf[blockPos] = output;
        //cout << "readIndex: " << readIndex << " blockPos: " << blockPos << " output: " << output << endl;
        blockPos = (blockPos + 1) % 4096;
    }

}

float DelayLine::getCurrentOut()
{
  float output;

 //   for(int i = 0; i < MAX_BUF_SIZ; i++){
    delayIndex = currIndex - currDelay;
    
    //cout << "offSet: " << offSet << " currIndex: " << currIndex << endl;
    
        if (delayIndex < 0.0) delayIndex = delayIndex + ((float) maxDelay + 1.0);
    
        if (delayIndex > (float) maxDelay) {
            output = buffer[(int) delayIndex] + (buffer[0] -
                                                 buffer[(int) delayIndex]) * (delayIndex -
                                                (float) ((int) delayIndex));
        }
        else {
            output = buffer[(int) delayIndex] + (buffer[(int) delayIndex + 1] -
							buffer[(int) delayIndex]) * (delayIndex - (float) ((int) delayIndex));
        }

        if (output > 1.0)
            output = 1.0;
        else if (output < -1.0)
            output = -1.0;
    
    //offSet = (offSet + 1) % (1024+1);
    //cout << "Output: " << output << endl;
//
//        samples[i] = output;
//    }
  return output;
}


float DelayLine::tick(float input)
{
    float output;
    buffer[currIndex] = input;
    //cout << "currIndex: " << currIndex << " input: " << input << endl;
    output = getCurrentOut();

    currIndex = (currIndex + 1) % (maxDelay + 1);
    return output;
  
}

