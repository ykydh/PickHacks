#include "Lander.h"
#include <cmath>

enum propulsion{NO,LEFT,DOWNLEFT,UP,DOWNRIGHT,RIGHT};

const double g = -1.625;
//change the func type to a nested vector of pos and velocity 
//<<velocity><position>>
std::pair<std::pair<double,double>,std::pair<double,double>> calculateVelocity(std::pair<int, int> currentPosition, std::pair<int, int> previousPosition, int deltaT) {
    std::pair<std::pair<double,double>,std::pair<double,double>> currentVer;
    int currentX = currentPosition.first;
    int currentY = currentPosition.second;
    int previousX = previousPosition.first;
    int previousY = previousPosition.second;
    double a; //acceleration
    propulsion input = NO;
    
    switch(input){
        case 0:{
            double vx = static_cast<double>(currentX-previousX)/deltaT;
            double vy = static_cast<double>(currentY - previousY) / deltaT + g * deltaT;
        
            currentVer.first.first = vx;
            currentVer.first.second = vy;
        }
        case 1:{
            
        }
        case 2:{
            
        }
        case 3:{

        }
        case 4:{

        }
        case 5:{

        }
        return currentVer;
    }
}

double refreshRate(std::pair<double, double> velocity) {
    double vx = velocity.first;
    double vy = velocity.second;
    
    double v_magnitude = sqrt(vx * vx + vy * vy);
    
    double fps = v_magnitude * 0.2;

    return fps;
}