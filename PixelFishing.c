#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define EULER_NUMBER 2.71828

typedef unsigned char UC;
typedef struct Artifact{
    UC Alpha;
    UC Beta;
    UC Gamma;
    UC Delta;
    
    float sigmoid;
    char signature;
} Artifact;

char *type[20] = {
        "Epsilon", "Zeta", "Eta", "Theta", 
        "Iota", "Kappa", "Lambda", "Mu",
        "Nu", "Xi", "Omicron", "Pi", 
        "Rho", "Sigma", "Tau", "Upsilon", 
        "Phi", "Chi", "Psi", "Omega"
};
 
double sigmoid(double n) {
    return (1 / (1 + pow(EULER_NUMBER, -n)));
} 
 
void Control( void* function(), Artifact state){
    function(state);
}

void* Alpha( Artifact state ){
    
}

void* Beta( Artifact state ){
    
}

void* Gamma( Artifact state ){
    
}

void* Delta( Artifact state ){
    
}

Artifact Maker( char Alpha, char Beta, char Gamma, char Delta ){
    
}

void Begin(  ){
    char buffer[6]; 
    printf("Type Something : ");
    fgets(buffer, sizeof(buffer), stdin); 

    if (buffer[0] != '\0') { 
        printf("%s", buffer); 
    }
}

int main(){
    Begin();
    
    Artifact test = { 'A', 'B', 'G', 'D', 0.5, *type[15] };
    
    Control( Alpha, test );
    Control( Beta, test );
    Control( Gamma, test );
    Control( Delta, test );

    return 0;
}
