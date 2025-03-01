#ifndef LANDER_H_
#define LANDER_H_
#include<list>
class lander{
  public:
    //getter
    double getVelocity(){return velocity;};
    double getFuel(){return fuel;};
    double getAngle(){return angle;};
    bool   getEngineState(){return engine;};
    std::list<int> getPosition(){return currentPosition;};
    std::list<int> getPosition(){return currentPosition;};
    //setter
  private:
    std::list<int> currentPosition={0,0};
    std::list<int> previousPosition={0,0};

    double velocity;
    double fuel;
    double angle;

    bool engine;
    
};
#endif LANDER_H_