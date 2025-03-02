/*#include "Lander.h"
#include <cmath>

const double g = 9.81;
std::pair<double, double> calculateVelocity(std::pair<int, int> current, std::pair<int, int> previous, int deltaT) {
    std::pair<double, double> currentVer;

    int currentX = current.first;
    int currentY = current.second;
    int previousX = previous.first;
    int previousY = previous.second;
    
    double vx = static_cast<double>(currentX - previousX) / deltaT;
    double vy = static_cast<double>(currentY - previousY) / deltaT + g * deltaT;
 
    currentVer.first = vx;
    currentVer.second = vy;

    return currentVer;
}

double refreshRate(std::pair<double, double> velocity) {
    double vx = velocity.first;
    double vy = velocity.second;
    
    double v_magnitude = sqrt(vx * vx + vy * vy);
    
    double fps = v_magnitude * 0.2;

    return fps;
}*/