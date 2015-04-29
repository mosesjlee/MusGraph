#include <iostream>
#include "delayef.h"
#include <stdio.h>
#define DEBUG 1

using std::cout;
using std::endl;

DelayEffect::DelayEffect(int inDelay)
{
  delayBuf = new DelayLine(inDelay);
}

DelayEffect::~DelayEffect()
{
  delete delayBuf;
}

void DelayEffect::setDelay(double newDelay)
{
  (*delayBuf).setDelayLineDelay(newDelay);
}

double DelayEffect::getDelay()
{
  return (*delayBuf).getDelayLineDelay();
}

void DelayEffect::setWetGain(double newGain)
{
  wetGain = newGain;
}

void DelayEffect::setFeedbackGain(double newGain)
{
	feedbackGain = newGain;
}

double DelayEffect::getFeedbackGain()
{
	return feedbackGain;
}

double DelayEffect::getWetGain()
{
  return wetGain;
}

void DelayEffect::setDryGain(double newGain)
{
  dryGain = newGain;
}

double DelayEffect::getDryGain()
{
  return dryGain;
}


double DelayEffect::tick(double input)
{
  return input * dryGain + (*delayBuf).tick(input) * wetGain;
}

//echo Effect
double DelayEffect::echo(double input)
{
	double x_n_G = input * dryGain;

	double currOut = delayBuf->getCurrentOut();

	double xN = input + feedbackGain * currOut;	

	//Limiter
	if(xN < -1.0) xN = -1.0;
	if(xN > 1.0) xN = 1.0;

	double echo_sgnl = delayBuf->tick(xN);

	double y_n = x_n_G + wetGain * echo_sgnl;

	//Limiter
	if(y_n < -1.0) y_n = -1.0;
	if(y_n > 1.0) y_n = 1.0;

	return y_n; 

}
