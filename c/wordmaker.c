#include <stdlib.h>
#include <stdio.h>

#define table "!#%&()*+,-./0123456789:;=?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_abcdefghijklmnopqrstuvwxyz{}"

char* product(unsigned long int index, const char* chars){

    const unsigned short int base = strlen(chars);
    unsigned short int i;
    unsigned long int number = index*base;

    char *result = (char*) malloc(sizeof(char*));

    for (i = 0; number > 0; i++){
        number /= base;
        result[i] = chars[number%base];
    }
    return result;
}


int main(int argc, char* args[]){
    //only simple example of this function
    unsigned long int x = 0;
    while (1){
        printf("\n%i >> %s", x, product(x,table));
        x+=1;
    }


    return 0;
}

