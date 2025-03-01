#ifndef LANDER_H_
#define LANDER_H_

#include <utility>  // For std::pair

class Lander {
public:
    // Getters
    double getVelocity() const { return velocity; }
    double getFuel() const { return fuel; }
    double getAngle() const { return angle; }
    bool getEngineState() const { return engine; }
    std::pair<int, int> getCurrentPosition() const { return currentPosition; }
    std::pair<int, int> getPreviousPosition() const { return previousPosition; }

    // Setters
    void setVelocity(double x) { velocity = x; }
    void setFuel(double y) { fuel = y; }
    void setAngle(double z) { angle = z; }
    void setEngineState(bool j) { engine = j; }
    void setCurrentPosition(int a, int b) { currentPosition = {a, b}; }
    void setPreviousPosition(int c, int d) { previousPosition = {c, d}; }

private:
    std::pair<int, int> currentPosition = {0, 0};
    std::pair<int, int> previousPosition = {0, 0};

    double velocity = 0.0;
    double fuel = 100.0;
    double angle = 0.0;

    bool engine = false;
};

#endif // LANDER_H_
