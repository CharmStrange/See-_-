#include<stdio.h>
#include <stdlib.h>

#define ROW 9
#define COLUMN 9

typedef struct Farmland{
    unsigned char fertility;
    unsigned char moisture;
    unsigned char light;
    unsigned char scale;
}Farmland;

Farmland Farm[ROW][COLUMN];

void intialize_Farmland() {
    for( unsigned char row = 0; row < ROW; row++ ) {
        for( unsigned char column = 0; column < COLUMN; column++ ) {
            Farm[row][column].fertility = 1;
            Farm[row][column].moisture = 1;
            Farm[row][column].light = 1;
            Farm[row][column].scale = 1;
        }
    }
}

unsigned char is_available() {
    unsigned char condition;
    
    for( unsigned char row = 0; row < ROW; row++ ) {
        for( unsigned char column = 0; column < COLUMN; column++ ) {
            
        }
    }
    
    return condition;
}

int main() {
    if ( ROW != COLUMN ) {
        exit(1);
    }
}
