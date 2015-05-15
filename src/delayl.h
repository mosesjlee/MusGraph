#ifndef DELAYL_H
#define DELAYL_H
#define SR 44100
#define MAX_BUF_SIZ 512

class DelayLine {
public:
    DelayLine();
    DelayLine(int);
    ~DelayLine();
    void setDelayLineDelay(float);
    float getDelayLineDelay();
    float getCurrentOut();
    void getCurrentOut(float * buf, int block_size, int blockPos);
    float tick(float);
//    float * buffer;
//    int currIndex;
private:
    float *buffer;
    int maxDelay;
    int prevCurrIndex;
    float delayIndex = 0;
    int offSet = 1024;
    float currDelay;
    int currIndex;
};

#endif
