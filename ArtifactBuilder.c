#include <stdio.h>
#include <ctype.h>

typedef unsigned char UC;
typedef struct Artifact{
    UC alpha;
    UC beta;
    UC gamma;
    UC delta;
    
    float sigmoid;
} Artifact;
 
void Control( void* function() ){
    function();
}

void* Alpha(){
    
}

void* Beta(){
    
}

void* Gamma(){
    
}

void* Delta(){
    
}

int main(){
    Control( Alpha );
    Control( Beta );
    Control( Gamma );
    Control( Delta );

    return 0;
}
