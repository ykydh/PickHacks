#include "Lander.h"
#include <cmath>
#include <algorithm>

enum propulsion { NO, LEFT, DOWNLEFT, UP, DOWNRIGHT, RIGHT };

#define PI 3.14159265;

const double g = -1.625;
const double a = 1.625;
// change the func type to a nested vector of pos and velocity
//<<velocity><position>>
std::pair<std::pair<double, double>, std::pair<double, double>>
calculateVelocity(std::pair<int, int> currentPosition,
                  std::pair<int, int> previousPosition, int deltaT,
                  propulsion input) {

  std::pair<std::pair<double, double>, std::pair<double, double>> currentVer;

  int currentX = currentPosition.first;
  int currentY = currentPosition.second;
  int previousX = previousPosition.first;
  int previousY = previousPosition.second;

  double nextX, nextY;

  switch (input) {
  case NO: {
    // No engine thrust, just free fall
    double vx = static_cast<double>(currentX - previousX) / deltaT;
    double vy = static_cast<double>(currentY - previousY) / deltaT + g * deltaT;

    // Calculate next position
    nextX = currentX + vx * deltaT +
            (1.0 / 2) * 0 * pow(deltaT, 2); // No acceleration
    nextY = currentY + vy * deltaT +
            (1.0 / 2) * g * pow(deltaT, 2); // Gravity acceleration

    currentVer.first.first = vx;      // Velocity X
    currentVer.first.second = vy;     // Velocity Y
    currentVer.second.first = nextX;  // Position X
    currentVer.second.second = nextY; // Position Y
    break;
  }
  case LEFT: {
    // Engine fires left
    double vx = static_cast<double>((currentX - previousX) / deltaT) -
                (1.0 / 2) * a * pow(deltaT, 2);
    double vy = static_cast<double>(currentY - previousY) / deltaT + g * deltaT;

    // Calculate next position
    nextX = currentX + vx * deltaT - (1.0 / 2) * a * pow(deltaT, 2);
    nextY = currentY + vy * deltaT + (1.0 / 2) * g * pow(deltaT, 2);

    currentVer.first.first = vx;      // Velocity X
    currentVer.first.second = vy;     // Velocity Y
    currentVer.second.first = nextX;  // Position X
    currentVer.second.second = nextY; // Position Y
    break;
  }
  case DOWNLEFT: {
    // Engine fires down-left (diagonal)
    double vx = (currentX - previousX) / deltaT - (a * sqrt(2) / 2) * deltaT;
    double vy = (currentY - previousY) / deltaT - (a * sqrt(2) / 2) * deltaT -
                g * deltaT;

    // Calculate next position
    nextX = currentX + vx * deltaT - (a * sqrt(2) / 2) * pow(deltaT, 2);
    nextY = currentY + vy * deltaT - (a * sqrt(2) / 2) * pow(deltaT, 2) -
            (1.0 / 2) * g * pow(deltaT, 2);

    currentVer.first.first = vx;      // Velocity X
    currentVer.first.second = vy;     // Velocity Y
    currentVer.second.first = nextX;  // Position X
    currentVer.second.second = nextY; // Position Y
    break;
  }
  case UP: {
    // Engine fires up
    double vx = (currentX - previousX) / deltaT;
    double vy = (currentY - previousY) / deltaT - a * deltaT - g * deltaT;

    // Calculate next position
    nextX = currentX + vx * deltaT;
    nextY = currentY + vy * deltaT - (1.0 / 2) * a * pow(deltaT, 2) -
            (1.0 / 2) * g * pow(deltaT, 2);

    currentVer.first.first = vx;      // Velocity X
    currentVer.first.second = vy;     // Velocity Y
    currentVer.second.first = nextX;  // Position X
    currentVer.second.second = nextY; // Position Y
    break;
  }
  case DOWNRIGHT: {
    // Engine fires down-right (diagonal)
    double vx = (currentX - previousX) / deltaT + (a / sqrt(2)) * deltaT;
    double vy =
        (currentY - previousY) / deltaT - (a / sqrt(2)) * deltaT - g * deltaT;

    // Calculate next position
    nextX = currentX + vx * deltaT + (a / sqrt(2)) * pow(deltaT, 2);
    nextY = currentY + vy * deltaT - (a / sqrt(2)) * pow(deltaT, 2) -
            (1.0 / 2) * g * pow(deltaT, 2);

    currentVer.first.first = vx;      // Velocity X
    currentVer.first.second = vy;     // Velocity Y
    currentVer.second.first = nextX;  // Position X
    currentVer.second.second = nextY; // Position Y
    break;
  }
  case RIGHT: {
    // Engine fires right
    double vx = (currentX - previousX) / deltaT + a * deltaT;
    double vy = (currentY - previousY) / deltaT - g * deltaT;

    // Calculate next position
    nextX = currentX + vx * deltaT + (1.0 / 2) * a * pow(deltaT, 2);
    nextY = currentY + vy * deltaT - (1.0 / 2) * g * pow(deltaT, 2);

    currentVer.first.first = vx;      // Velocity X
    currentVer.first.second = vy;     // Velocity Y
    currentVer.second.first = nextX;  // Position X
    currentVer.second.second = nextY; // Position Y
    break;
  }
  }

  return currentVer;
}

double refreshRate(std::pair<double, double> velocity, double currentFPS, double minFPS = 30, double maxFPS = 60) {
    double vx = velocity.first;
    double vy = velocity.second;

    // Calculate the magnitude of the velocity
    double v_magnitude = sqrt(vx * vx + vy * vy);

    // Define a scaling factor (adjust based on testing)
    double scalingFactor = 0.2;  // Adjust this to control the responsiveness to velocity
    double targetFPS = v_magnitude * scalingFactor;

    // Clamp the target FPS to a reasonable range
    targetFPS = std::clamp(targetFPS, minFPS, maxFPS);

    // Smooth transition (for example, use linear interpolation between current and target FPS)
    double smoothingFactor = 0.1;  // You can adjust this value to control the smoothness of the transition
    double newFPS = currentFPS + smoothingFactor * (targetFPS - currentFPS);

    return newFPS;
}
