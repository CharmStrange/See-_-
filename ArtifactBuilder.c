#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

void Control(void (*function)(Artifact), Artifact state); 

void Alpha(Artifact state);
void Beta(Artifact state);
void Gamma(Artifact state);
void Delta(Artifact state);

char* Buffer(); 

Artifact Maker(UC Alpha, UC Beta, UC Gamma, UC Delta);

void Begin(char* (*function)()); 

int main(){
    Begin(Buffer);
    
    Artifact test = Maker('A', 'B', 'G', 'D');
    
    Control(Alpha, test);
    Control(Beta, test);
    Control(Gamma, test);
    Control(Delta, test);

    return 0;
}

void Control(void (*function)(Artifact), Artifact state){
    function(state);
}

void Alpha(Artifact state){
    printf("Alpha: %c\n", state.Alpha);
}

void Beta(Artifact state){
    printf("Beta: %c\n", state.Beta);
}

void Gamma(Artifact state){
    printf("Gamma: %c\n", state.Gamma);
}

void Delta(Artifact state){
    printf("Delta: %c\n", state.Delta);
}

char* Buffer(){
    char* buffer = (char*)malloc(100 * sizeof(char)); 
    return buffer;
}

void Begin(char* (*function)()){ 
    char* buffer = function();
    printf("Type Something: ");
    fgets(buffer, 100, stdin); 
    printf("You typed: %s\n", buffer); 
}

Artifact Maker(UC Alpha, UC Beta, UC Gamma, UC Delta){
    Artifact artifact = { Alpha, Beta, Gamma, Delta };
    return artifact;
}
