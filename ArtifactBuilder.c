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

void* Alpha( Artifact state ){
    
}

void* Beta( Artifact state ){
    
}

void* Gamma( Artifact state ){
    
}

void* Delta( Artifact state ){
    
}

int main(){
    Control( Alpha );
    Control( Beta );
    Control( Gamma );
    Control( Delta );

    return 0;
}
