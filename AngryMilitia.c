#include<stdio.h>
#include <stdlib.h>

#define ROW 9
#define COLUMN 9

typedef struct Farmland{
    unsigned char fertility;
    unsigned char moisture;
    unsigned char light;
}Farmland;

Farmland Farm[ROW][COLUMN];

unsigned char is_available() {
    unsigned char state;
    
    for( unsigned char row = 0; row < ROW; row++ ) {
        for( unsigned char column = 0; column < COLUMN; column++ ) {
            
        }
    }
    
    return state;
}

int main() {
    if ( ROW != COLUMN ) {
        exit(1);
    }
}
