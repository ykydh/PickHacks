#include "LandScape.h"
#include "Lander.h"
#include "Ground.h"
#include <iostream>

int main(){
  int numRows= 32;
  int numColumns = 32;

  LandScape landscape;

  landscape.create_grid(numRows, numColumns);

  landscape.random_fill_terrain();

  landscape.print_grid();

  landscape.delete_grid();

  return 0;
}