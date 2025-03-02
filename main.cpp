#include "LandScape.h"
#include "Lander.h"
#include "Ground.h"
#include <iostream>

int main(){
  char modeInp;
  std::cout<<"--------Moon Lander--------"<<std::endl;
  std::cout<<"Land a landing pod safely to the lunar surface"<<std::endl;

  int numRows= 32;
  int numColumns = 32;

  LandScape landscape;
  Lander lander;

  landscape.create_grid(numRows, numColumns);

  landscape.random_fill_terrain();

  landscape.print_grid();

  landscape.delete_grid();
  return 0;
}