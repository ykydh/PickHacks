#ifndef LANDSCAPE_H
#define LANDSCAPE_H

#include <ctime>
#include <stdlib.h>

class LandScape {

private:
  int rows, cols;
  char **symbols;

public:
  LandScape() : rows(0), cols(0), symbols(nullptr) {}

  char **grid() { return symbols; } // FOR TESTING PURPOSES ONLY
  const int &get_rows() const { return rows; }
  const int &get_cols() const { return cols; }

  void create_grid(int rows, int cols);
  void fill_grid();
  void delete_grid();
  void print_grid() const;

  const LandScape &operator=(const LandScape &rhs);
  LandScape(const LandScape &source);
  ~LandScape();

    void random_fill_terrain() {
        time_t seed;
        srand(time(&seed));

        if (symbols == nullptr)
            return;

        // Define characters for terrain features
        char terrain_features[] = {'.', '^', '~', '#', ' '}; // Grass, peaks, water, rocks, empty

        // Loop through each column and randomly generate mountain height
        for (int c = 0; c < cols; c++) {
            // Random mountain height for each column
            int mountain_height = rand() % (rows / 2) + (rows / 4); // Heights between 25 and 75 (mountain-like)

            for (int r = 0; r < rows; r++) {
                if (r < rows - mountain_height) {
                    // Everything above the mountain is whitespace
                    symbols[r][c] = ' ';
                } else {
                    // Randomly assign terrain characters below mountain height
                    int terrain_type = rand() % 100;
                    if (terrain_type < 50) {
                        symbols[r][c] = '.';  // Grass or lower elevation
                    } else if (terrain_type < 70) {
                        symbols[r][c] = '~';  // Water or valley areas
                    } else if (terrain_type < 90) {
                        symbols[r][c] = '#';  // Rocky regions of the mountains
                    } else {
                        symbols[r][c] = '^';  // Peaks or upper rocky areas
                    }
                }
            }
        }
    }
};

#endif
