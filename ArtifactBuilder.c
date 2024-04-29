#include <stdio.h>
#include <ctype.h>

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

int main(){
    Artifact test = { 'A', 'B', 'G', 'D', 0.5, *type[15] };
    
    Control( Alpha, test );
    Control( Beta, test );
    Control( Gamma, test );
    Control( Delta, test );

    return 0;
}
