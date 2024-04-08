#include <stdio.h>
#include <stdlib.h>

// for Option Control
#define initialize_v1() do {for (unsigned char r = 0; r < 3; r++){for (unsigned char c = 0; c < 3; c++){Pixels[r][c] = (Spot){0, NULL};}}} while (0)
#define initialize_v2(parameter_1) do {for (unsigned char r = 0; r < 3; r++){for (unsigned char c = 0; c < 3; c++){Pixels[r][c] = (Spot){0, NULL};}}  parameter_1();} while (0)
#define initialize_v3(parameter_1, parameter_2) do {for (unsigned char r = 0; r < 3; r++){for (unsigned char c = 0; c < 3; c++){Pixels[r][c] = (Spot){0, NULL};}} parameter_1(); parameter_2();} while (0)

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
/*
void initialize( void *function_1(), void *function_2() ) {
    for (unsigned char r = 0; r < 3; r++){
        for (unsigned char c = 0; c < 3; c++){
            Pixels[r][c] = (Spot){0, NULL};
        }
    }
    function_1();
}
*/
void *simulate(){
    printf("Simulation");
}

void *unknown(){
    for (unsigned char r = 0; r < 3; r++){
        for (unsigned char c = 0; c < 3; c++){
            printf("/ %p ", &Pixels[r][c]);
            printf("[%d] ", sizeof(Pixels[r][c]));
        }
    }
}

int main() {
    // function parameters of init() method :
    // unknown
    // simulate
    
    initialize(unknown, simulate);
    return 0;
}
