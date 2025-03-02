#include "LandScape.h"
#include "Lander.h"
#include "Ground.h"
#include <iostream>

int numRows= 32;
int numColumns = 32;

int main(){
  char modeInp = 'N';
  std::cout<<"--------Moon Lander--------"<<std::endl;
  std::cout<<"Land a landing pod safely to the lunar surface"<<std::endl;
  
  do{
    LandScape landscape;
    do{
      

      landscape.create_grid(numRows, numColumns);

      landscape.random_fill_terrain();

      landscape.print_grid();

      landscape.delete_grid();
    }while(!landscape.lander.getCrash());
    std::cout<<"New Game: N"<<std::endl;
    std::cout<<"Quit: Q"<<std::endl;
    std::cin>>modeInp; 
  }while(modeInp != 'N');

  return 0;
}