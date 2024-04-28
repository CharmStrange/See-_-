#include <stdio.h>
#include <ctype.h>

typedef unsigned char UC;
typedef struct Artifact{
    UC alpha;
    UC beta;
    UC gamma;
    UC delta;
    
    float sigmoid;
    char signature;
} Artifact;

char *greekAlphabet[21] = {
        "Delta", "Epsilon", "Zeta", "Eta", "Theta", "Iota", "Kappa", "Lambda", "Mu",
        "Nu", "Xi", "Omicron", "Pi", "Rho", "Sigma", "Tau", "Upsilon", "Phi", "Chi", "Psi", "Omega"
    };
 
void Control( void* function() ){
    function();
}

void* Alpha( Artifact state ){
    
}

void* Beta( Artifact state ){
    
}

void* Gamma( Artifact state ){
    
}

void* Delta( Artifact state ){
    
}

int main(){
    Artifact test = { 'A', 'B', 'G', 'D', 0.5, greekAlphabet[15] };

    Control( Alpha(test) );
    Control( Beta(test) );
    Control( Gamma(test) );
    Control( Delta(test) );

    return 0;
}
