#include "LandScape.h"
//#include "Lander.h"
#include "Ground.h"
#include <iostream>

int numRows= 32;
int numColumns = 32;
int testing = 1;


int main(){
  char modeInp = 'N';
  std::cout<<"--------Moon Lander--------"<<std::endl;
  std::cout<<"Land a landing pod safely to the lunar surface"<<std::endl;
  
  do {
    LandScape landscape;
    landscape.create_grid(numRows, numColumns);
    landscape.random_fill_terrain();
    do{
      

      

      landscape.updateLander();

      

      landscape.print_grid();

      
      testing--;
    } while (testing > 0            /*!landscape.lander.getCrash()*/);

    landscape.delete_grid();

    std::cout<<"New Game: N"<<std::endl;
    std::cout<<"Quit: Q"<<std::endl;
    std::cin>>modeInp; 
  }while(modeInp != 'Q');

  return 0;
}