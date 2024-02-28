#include <stdio.h>
#include <stdlib.h>

#define ROW 9
#define COLUMN 9

typedef struct Farmland {
    unsigned char fertility;
    unsigned char moisture;
    unsigned char light;
    unsigned char scale;
    char condition;
} Farmland;

Farmland Farm[ROW][COLUMN];

void initialize_Farmland() {
    for (unsigned char row = 0; row < ROW; row++) {
        for (unsigned char column = 0; column < COLUMN; column++) {
            Farm[row][column].fertility = 1;
            Farm[row][column].moisture = 1;
            Farm[row][column].light = 1;
            Farm[row][column].scale = 1;
            Farm[row][column].condition = (Farm[row][column].fertility + Farm[row][column].moisture + Farm[row][column].light + Farm[row][column].scale) / 4;
        }
    }
}

void update_neighbour_cells(unsigned char row, unsigned char column) {
    if (row > 0) {
        Farm[row - 1][column].fertility = (Farm[row - 1][column].fertility > 0) ? Farm[row - 1][column].fertility - 1 : 0;
        Farm[row - 1][column].moisture = (Farm[row - 1][column].moisture > 0) ? Farm[row - 1][column].moisture - 1 : 0;
        Farm[row - 1][column].light = (Farm[row - 1][column].light > 0) ? Farm[row - 1][column].light - 1 : 0;
        Farm[row - 1][column].scale = (Farm[row - 1][column].scale > 0) ? Farm[row - 1][column].scale - 1 : 0;
    }
    if (row < ROW - 1) {
        Farm[row + 1][column].fertility = (Farm[row + 1][column].fertility > 0) ? Farm[row + 1][column].fertility - 1 : 0;
        Farm[row + 1][column].moisture = (Farm[row + 1][column].moisture > 0) ? Farm[row + 1][column].moisture - 1 : 0;
        Farm[row + 1][column].light = (Farm[row + 1][column].light > 0) ? Farm[row + 1][column].light - 1 : 0;
        Farm[row + 1][column].scale = (Farm[row + 1][column].scale > 0) ? Farm[row + 1][column].scale - 1 : 0;
    }
    if (column > 0) {
        Farm[row][column - 1].fertility = (Farm[row][column - 1].fertility > 0) ? Farm[row][column - 1].fertility - 1 : 0;
        Farm[row][column - 1].moisture = (Farm[row][column - 1].moisture > 0) ? Farm[row][column - 1].moisture - 1 : 0;
        Farm[row][column - 1].light = (Farm[row][column - 1].light > 0) ? Farm[row][column - 1].light - 1 : 0;
        Farm[row][column - 1].scale = (Farm[row][column - 1].scale > 0) ? Farm[row][column - 1].scale - 1 : 0;
    }
    if (column < COLUMN - 1) {
        Farm[row][column + 1].fertility = (Farm[row][column + 1].fertility > 0) ? Farm[row][column + 1].fertility - 1 : 0;
        Farm[row][column + 1].moisture = (Farm[row][column + 1].moisture > 0) ? Farm[row][column + 1].moisture - 1 : 0;
        Farm[row][column + 1].light = (Farm[row][column + 1].light > 0) ? Farm[row][column + 1].light - 1 : 0;
        Farm[row][column + 1].scale = (Farm[row][column + 1].scale > 0) ? Farm[row][column + 1].scale - 1 : 0;
    }
}

unsigned char is_available() {
    unsigned char condition = 0;

    for (unsigned char row = 0; row < ROW; row++) {
        for (unsigned char column = 0; column < COLUMN; column++) {
            Farmland currentCell = Farm[row][column];
            if (currentCell.condition >= 4) {
                condition++;
                update_neighbour_cells(row, column);
            }
        }
    }

    return condition;
}

int main() {
    if (ROW != COLUMN) {
        exit(1);
    }

    initialize_Farmland();

    unsigned char available = is_available();
    printf("Number of available cells: %d\n", available);

    return 0;
}
