#include "Lander.h"

std::pair<double, double>calculateVelocity(std::pair<int, int> current,std::pair<int, int> previous){
    std::pair<double, double>currentVer;
    //set deltaT
    int deltaT=0;
    int currentX = current.first;
    int currentY = current.second;
    int previousX = previous.first;
    int previousY = previous.second;
    double vx,vy;
    
    vx=(currentX-previousX)/deltaT;
    vy=(currentY-previousY)/deltaT;
 
    currentVer.first=vx;
    currentVer.second=vy;

    return currentVer;
}