#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 50

typedef unsigned char UC;
typedef struct Artifact{
    UC Alpha;
    UC Beta;
    UC Gamma;
    UC Delta;

    char signature;
} Artifact;

char *type[21] = {
        "Epsilon", "Zeta", "Eta", "Theta", 
        "Iota", "Kappa", "Lambda", "Mu",
        "Nu", "Xi", "Omicron", "Pi", 
        "Rho", "Sigma", "Tau", "Upsilon", 
        "Phi", "Chi", "Psi", "Omega"
};

// Functions, Forward Declarations
void Control(void (*function)(Artifact), const Artifact state); 

void Alpha(Artifact state);
void Beta(Artifact state);
void Gamma(Artifact state);
void Delta(Artifact state);

char* Buffer(); 

void Begin(char* (*function)()); 

Artifact Maker(UC Alpha, UC Beta, UC Gamma, UC Delta);

Artifact Build_Artifact(const Artifact before, void (*function)());

///
int main(){
    Begin(Buffer);
    
    Artifact test = Maker('A', 'B', 'G', 'D');
    
    Control(Alpha, test);
    Control(Beta, test);
    Control(Gamma, test);
    Control(Delta, test);

    return 0;
}
///
void Control(void (*function)(Artifact), const Artifact state){
    function(state);
}

void Alpha(const Artifact state){
    printf("Alpha: %c\n", state.Alpha);
}

void Beta(const Artifact state){
    printf("Beta: %c\n", state.Beta);
}

void Gamma(const Artifact state){
    printf("Gamma: %c\n", state.Gamma);
}

void Delta(const Artifact state){
    printf("Delta: %c\n", state.Delta);
}

char* Buffer(){
    char* buffer = (char*)malloc(SIZE * sizeof(char)); 
    return buffer;
}

void Begin(char* (*function)()){ 
    char* buffer = function();
    printf("Type Something: ");
    fgets(buffer, SIZE, stdin); 
    printf("You typed: %s\n", buffer); 
}

Artifact Maker(UC Alpha, UC Beta, UC Gamma, UC Delta){
    Artifact artifact = { Alpha, Beta, Gamma, Delta };
    artifact.signature = *type[0]; // temporary
    return artifact;
}

Artifact Build_Artifact(const Artifact before, void (*function)()){
    Artifact after = before;
    //functions
    return after;
}
