#include<stdlib.h>
#include <stdio.h>
#include<string.h>
 
#include "header.h"
#define DEBUG
#define show_var(a) printf("Variable %s has value %d\n", #a, a)
#ifdef DEBUG
#define Dprintf(msg,...) printf(msg " ",  ##__VA_ARGS__)
#else
#define Dprintf(msg,...)                /* do nothing */
#endif


int main(int argc, char **argv)
{
    int i;
    Dprintf("argc:%d\n", argc);

    Map* map = initialize_Map(NULL);
    HashMap* buffer = NULL;
    // char* temp_Str;
    i = 1;
    // Dprintf("%s\n", argv[i]);
    while (i < argc)
    {
        Dprintf("%s", argv[i]);
        char* str = argv[i];
        if(strcmp(str, "-D")){
            i++;
            Add_to_map(argv[i], map);
        }
        i++;
    }
    if(map != NULL){
        print_map(map);
        free_Map(map);
    }
    printf("\n\n");
    return 0;
}