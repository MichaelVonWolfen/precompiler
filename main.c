#include<stdlib.h>
#include <stdio.h>
#include<string.h>

#define DEBUG
#ifdef DEBUG
#define show_var(a) printf("\nVariable %s\n", #a)
#define Dprintf(msg,...) printf(msg " ",  ##__VA_ARGS__)
#else
#define Dprintf(msg,...)                /* do nothing */
#endif

#include "header.h"

int main(int argc, char **argv)
{
    int i;
    // Dprintf("argc:%d\n", argc);

    Map* defines = initialize_Map(NULL);
    List* includes = initialize_List(NULL);
    // HashMap* buffer = NULL;
    char* temp_Str;
    i = 1;
    Dprintf("\n");
    while (i < argc)
    {
        // Dprintf("%s", argv[i]);
        char* str = argv[i];
        if(!strcmp(str, "-D")){
            i++;
            Add_to_map(argv[i], defines);
        }else if(str[0] == '-' && str[1] == 'D'){
            temp_Str = (char*) malloc(sizeof (char) * strlen(str - 2));
            strncpy(temp_Str, str + 2, strlen(str) - 2);
            Add_to_map(temp_Str, defines);
        }else if(!strcmp(str, "-I")){
            i++;
            Dprintf("String 1 %s\n", str);
            Add_to_list(argv[i], includes);
            Dprintf("String 2 %s\n", str);
        }else if(str[0] == '-' && str[1] == 'I'){
            temp_Str = (char*) malloc(sizeof (char) * strlen(str - 2));
            Dprintf("String 3 %s\n", str);
            strncpy(temp_Str, str + 2, strlen(str) - 2);
            Dprintf("String 4 %s\n", temp_Str);
            Add_to_list(temp_Str, includes);
        }
        i++;
    }
    if(defines != NULL){
        show_var(defines);
        print_map(defines);
        free_Map(defines);
    }
    if(includes != NULL){
        show_var(includes);
        print_list(includes);
        free_list(includes);
    }
    printf("\n\n");
    return 0;
}