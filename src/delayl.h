#ifndef DELAYL_H
#define DELAYL_H
#define SR 44100

class DelayLine {
public:
    DelayLine();
    DelayLine(int);
    ~DelayLine();
    void setDelayLineDelay(float);
    float getDelayLineDelay();
    float getCurrentOut();
    float tick(float);

private:
    float *buffer;
    int maxDelay;
    float currDelay;
    int currIndex;
};

#endif
