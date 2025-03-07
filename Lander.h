#ifndef LANDER_H_
#define LANDER_H_

#include <utility> // For std::pair

enum propulsion { NO, LEFT, DOWNLEFT, UP, DOWNRIGHT, RIGHT };

class Lander {
public:
  // Constructor
  Lander() {
    fuel = 20;
    angle = 0.0;
    currentPosition = std::make_pair(0, 16);
    engine = false;
    velocity = std::make_pair(2, 0);
    crash = false;
  }
  // Getters
  double getFuel() const { return fuel; }
  double getAngle() const { return angle; }
  bool getEngineState() const { return engine; }
  bool getCrash() const { return crash; }
  std::pair<int, int> getCurrentPosition() const { return currentPosition; }
  std::pair<int, int> getPreviousPosition() const { return previousPosition; }
  std::pair<double, double> getVelocity() const { return velocity; }
  // Setters

  void setFuel(double y) { fuel = y; }
  void setAngle(double z) { angle = z; }
  void setEngineState(bool j) { engine = j; }
  void setCrash(bool k) { engine = k; }
  void setCurrentPosition(int a, int b) {
    currentPosition = std::make_pair(a, b);
  }
  void setPreviousPosition(int c, int d) {
    previousPosition = std::make_pair(c, d);
  }
  void setVelocity(double x, double y) { velocity = std::make_pair(x, y); }
  // members
  std::vector<std::vector<double>>
  calculateVelocity(std::pair<int, int> currentPosition,
                    std::pair<int, int> previousPosition, int deltaT,
                    propulsion input);

private:
  double refreshRate(std::pair<double, double> velocity, double currentFPS,
                     double minFPS = 30, double maxFPS = 60);
  std::pair<int, int> currentPosition;
  std::pair<int, int> previousPosition;
  // grid per second
  std::pair<double, double> velocity;

  double fuel;
  double angle;

  int engine; // 0:No propulsion 1:^ 2:> 3:
  bool crash;
};

#endif
