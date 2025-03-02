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

    // Array to store the height of the mountain for each column
    int heights[cols];

    // Generate the initial random height for the first column
    heights[0] = rand() % (rows / 4) + (rows / 8);  // Lower heights between rows/8 and rows/4

    // Smoothly generate the height of mountains across columns
    for (int c = 1; c < cols; c++) {
        // The height of the current column is based on the previous column
        int height_variation = rand() % 5 - 2;  // Small variation between -2 and +2
        heights[c] = heights[c - 1] + height_variation;

        // Clamp the height to avoid it going out of bounds
        if (heights[c] < rows / 8) heights[c] = rows / 8;  // Minimum height is lower
        if (heights[c] > rows / 4 + rows / 8) heights[c] = rows / 4 + rows / 8;  // Maximum height is lower too
    }

    // Randomly choose a position for the landing zone (ensuring it fits within the bounds)
    int landing_start_col = rand() % (cols - 2);  // Ensures at least 3 columns available for landing zone
    int landing_height = heights[landing_start_col];  // Set the landing zone at the height of the first landing column

    // Set the same height for the landing zone (3 consecutive columns)
    heights[landing_start_col + 1] = landing_height;
    heights[landing_start_col + 2] = landing_height;

    // Fill the grid based on the generated mountain heights
    for (int c = 0; c < cols; c++) {
        for (int r = 0; r < rows; r++) {
            if (r < rows - heights[c]) {
                // Everything above the mountain is whitespace
                symbols[r][c] = ' ';
            } else {
                // Check if the current column is part of the landing zone
                if (c >= landing_start_col && c < landing_start_col + 3 && r == rows - heights[c]) {
                    symbols[r][c] = '_';  // Flat landing zone
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
}
};

#endif
