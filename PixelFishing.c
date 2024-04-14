#include <stdio.h>
#include <stdlib.h>

// for Option Control
#define initialize_v1() do {for (unsigned char r = 0; r < 3; r++){ \
            for (unsigned char c = 0; c < 3; c++){ \
                Pixels[r][c] = (Spot){0, NULL};} \
            } printf("\nSpots successfully created!\n"); \
        } while (0)
        
#define initialize_v2(parameter_1) do {for (unsigned char r = 0; r < 3; r++){ \
            for (unsigned char c = 0; c < 3; c++){ \
                Pixels[r][c] = (Spot){0, NULL};} \
            } printf("\nSpots successfully created!\n"); \
            parameter_1(); \
        } while (0)
        
#define initialize_v3(parameter_1, parameter_2) do {for (unsigned char r = 0; r < 3; r++){ \
            for (unsigned char c = 0; c < 3; c++){ \
                Pixels[r][c] = (Spot){0, NULL};} \
            } printf("\nSpots successfully created!\n"); \
            parameter_1(); parameter_2(); \
        } while (0)

#define medium(_v1, _v2, _v3, name, ...) name
#define initialize(...) medium(_v1, ##__VA_ARGS__, initialize_v3, initialize_v2, initialize_v1)(__VA_ARGS__)

// unsigned char [8bit]
// self pointer [8bit]
// = [16bit]
typedef struct Spot {
    unsigned char status;
    struct Spot *ptr;
} Spot;

Spot Pixels[3][3];

// connecting
Pixels[0][0].ptr = &Pixels[0][1];
Pixels[0][1].ptr = &Pixels[0][2];
Pixels[0][2].ptr = &Pixels[1][0];
    
Pixels[1][0].ptr = &Pixels[1][1];
Pixels[1][1].ptr = &Pixels[1][2];
Pixels[1][2].ptr = &Pixels[2][0];
    
Pixels[2][0].ptr = &Pixels[2][1];
Pixels[2][1].ptr = &Pixels[2][2];
Pixels[2][2].ptr = &Pixels[0][0];

void *simulate(){
    printf("\nSimulation\n");
}

void *attribute(){
    printf("\n");
    for (unsigned char r = 0; r < 3; r++){
        for (unsigned char c = 0; c < 3; c++){
            printf("/ %p ", &Pixels[r][c]);
            printf("[%d] ", sizeof(Pixels[r][c]));
        }
    }
    printf("\n");
}

int main() {
    // max 2 parameters can be entered in initialize ... none available, one available, two available, three NO!
    // function parameters of initialize() method :
    // attribute
    // simulate
    
    initialize();
    initialize(attribute);
    initialize(attribute, simulate);
    return 0;
}
