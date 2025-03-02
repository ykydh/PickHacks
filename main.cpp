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
    do{
      

      landscape.create_grid(numRows, numColumns);

      std::cout << "Testing Testing 1,2,3" << std::endl;

      landscape.random_fill_terrain();

      landscape.print_grid();

      landscape.delete_grid();
      testing--;
    } while (testing > 0            /*!landscape.lander.getCrash()*/);



    std::cout<<"New Game: N"<<std::endl;
    std::cout<<"Quit: Q"<<std::endl;
    std::cin>>modeInp; 
  }while(modeInp != 'N' && modeInp != 'n');

  return 0;
}