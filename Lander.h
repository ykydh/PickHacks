#ifndef LANDER_H_
#define LANDER_H_

#include <utility>  // For std::pair

class Lander {
public:
    //Constructor
    Lander(){fuel = 100; angle = 0.0; currentPosition = std::make_pair(0, 0); engine = false; velocity = std::make_pair(2,0);}
    // Getters
    double getFuel() const { return fuel; }
    double getAngle() const { return angle; }
    bool getEngineState() const { return engine; }
    std::pair<int, int> getCurrentPosition() const { return currentPosition; }
    std::pair<int, int> getPreviousPosition() const { return previousPosition; }
    std::pair<double, double> getVelocity() const { return velocity; }
    // Setters

    void setFuel(double y) { fuel = y; }
    void setAngle(double z) { angle = z; }
    void setEngineState(bool j) { engine = j; }
    void setCurrentPosition(int a, int b) { currentPosition = std::make_pair(a, b); }
    void setPreviousPosition(int c, int d) { previousPosition = std::make_pair(c, d); }
    void setVelocity(double x, double y) { velocity = std::make_pair(x,y); }
    //members
    std::pair<double, double>calculateVelocity(std::pair<int, int> current,std::pair<int, int> previous, int deltaT);
private:
    double refreshRate(std::pair<double, double> velocity);
    std::pair<int, int> currentPosition;
    std::pair<int, int> previousPosition;
    //grid per second
    std::pair<double, double> velocity;

    double fuel;
    double angle;

    bool engine = false;
};

#endif
