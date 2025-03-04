#include "LandScape.h"
#include <iostream>
using namespace std;

void LandScape::create_grid(int r, int c) {
  rows = r;
  cols = c;
  symbols = new char *[r];
  for (int i = 0; i < r; i++) {
    symbols[i] = new char[c];
  }
}

void LandScape::delete_grid() {
  for (int k = 0; k < rows; k++) {
    delete[] symbols[k];
  }
  delete[] symbols;
  symbols = nullptr;
}

void LandScape::fill_grid() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> symbols[i][j];
    }
  }
}

void LandScape::print_grid() const {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++)
      cout << symbols[i][j] << " ";
    cout << endl;
  }
  cout << endl;
}

const LandScape &LandScape::operator=(const LandScape &rhs) {
  delete_grid();
  create_grid(rhs.rows, rhs.cols);
  for (int r = 0; r < rhs.rows; r++)
    for (int c = 0; c < rhs.cols; c++)
      symbols[r][c] = rhs.symbols[r][c];

  return *this;
}

LandScape::LandScape(const LandScape &source) {
  symbols = nullptr;
  *this = source;
}

LandScape::~LandScape() {
  if (symbols != nullptr)
    delete_grid();
}

void LandScape::updateLander()
{
 std::pair<int, int>curpos;
 curpos =lander.getCurrentPosition();
 symbols[curpos.first][curpos.second] = 'A';
}
 
