#ifndef LANDSCAPE_H
#define LANDSCAPE_H

#include "Lander.h"
#include <ctime>
#include <stdlib.h>
#include <iostream>

class LandScape {

private:
    int rows, cols;
    char** symbols;

public:
    //Lander lander;

    void updateLander();

    LandScape() : rows(0), cols(0), symbols(nullptr) {}

    char** grid() { return symbols; } // FOR TESTING PURPOSES ONLY
    const int& get_rows() const { return rows; }
    const int& get_cols() const { return cols; }

    void create_grid(int rows, int cols);
    void fill_grid();
    void delete_grid();
    void print_grid() const;

    const LandScape& operator=(const LandScape& rhs);
    LandScape(const LandScape& source);
    ~LandScape();

    void random_fill_terrain() {
        time_t seed;
        srand(time(&seed));

        if (symbols == nullptr)
            return;

        int* heights = new int[cols];
        heights[0] = rand() % (rows / 4) + (rows / 8);

        for (int c = 1; c < cols; c++) {
            int height_variation = rand() % 5 - 2;
            heights[c] = heights[c - 1] + height_variation;
            if (heights[c] < rows / 8) heights[c] = rows / 8;
            if (heights[c] > rows / 4 + rows / 8) heights[c] = rows / 4 + rows / 8;
        }

        // Randomly determine a landing zone position
        int lz_start = rand() % (cols - 2); // Ensure at least 3 spaces available
        int lz_height = heights[lz_start];

        // Ensure the landing zone is level
        heights[lz_start + 1] = lz_height;
        heights[lz_start + 2] = lz_height;

        for (int c = 0; c < cols; c++) {
            for (int r = 0; r < rows; r++) {
                if (r < rows - heights[c]) {
                    symbols[r][c] = ' ';
                }
                else {
                    if (c >= lz_start && c <= lz_start + 2 && heights[c] == lz_height) {
                        symbols[r][c] = '_'; // Landing zone
                    }
                    else {
                        int terrain_type = rand() % 100;
                        if (r >= rows - heights[c]) {
                            if (terrain_type < 50) {
                                symbols[r][c] = '.'; // Plains
                            }
                            else if (terrain_type < 70) {
                                symbols[r][c] = '~'; // Water
                            }
                            else if (terrain_type < 90) {
                                symbols[r][c] = '#'; // Mountain
                            }
                            else {
                                symbols[r][c] = '^'; // Steep Mountain
                            }
                        }
                    }
                }
            }
        }

        delete[] heights;
    }
};



#endif