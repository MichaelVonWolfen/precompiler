#include<stdio.h>
#include<stdlib.h>

#define DEBUGG 1
#ifdef DEBUGG
    #define Dprint(a) printf("Variable %s has value %d\n", #a, a);
#else
    #define Dprint(a) ''
#endif
int main(int argc, char **argv){
    Dprint(argc);
    return 0;
}