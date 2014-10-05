#include <stdlib.h>
#include <stdio.h>
#include "builder.h"



int main(int argc, char* args[]){
    //only simple example of this function
    unsigned long int x = 0;
    while (1){
        printf("\n%i >> %s", x, product(x));
        x+=1;
    }


    return 0;
}

