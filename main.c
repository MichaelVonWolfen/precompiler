#include<stdlib.h>
#include <stdio.h>
#include<string.h>

//#define DEBUG
#define  REMOTE_DEBUGG
#ifdef DEBUG
    #define show_var(a) printf("\nVariable %s\n", #a)
    #define Dprintf(msg,...) printf(msg " ",  ##__VA_ARGS__)
#else
    #define show_var(a)
    #define Dprintf(msg,...)                /* do nothing */
#endif

#ifdef REMOTE_DEBUGG
    #define Rprintf(msg,...) printf(msg " ",  ##__VA_ARGS__)
#else
#define Rprintf(msg,...)                /* do nothing */
#endif

#include "header.h"
#include "functions.h"
int main(int argc, char **argv)
{
    int i;
    // Dprintf("argc:%d\n", argc);

    Map* defines = initialize_Map(NULL);
    List* includes = initialize_List(NULL);
    List* outputs = initialize_List(NULL);

    char* inFile;
    // HashMap* buffer = NULL;
    char* temp_Str = NULL;
    i = 1;
    Rprintf("Argumente Total: %d\n", argc);
    for(i = 1; i < argc; i++){
        Rprintf("Argumentul %i: %s\n",i, argv[i]);
    }
    while (i < argc)
    {
         Dprintf("%s", argv[i]);
        if(argv[i][0] == '-') {
            i += parameters_check(i, argv, defines, NULL, "-D");
            i += parameters_check(i, argv, NULL, includes, "-I");
            i += parameters_check(i, argv, NULL, outputs, "-o");
            if(strlen(argv[i]) == 2){
                //aka there is an argument received, but is a bad one, skip it
                i++;
            }
        }else{
            inFile = (char*)malloc(sizeof(char)*strlen(argv[i]));
            strcpy(inFile, argv[i]);
        }
        i++;
    }
    if(inFile == NULL){
        readCodeFromConsole();
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
    if(outputs != NULL) {
        show_var(outputs);
        print_list(outputs);
        free_list(outputs);
    }
    Dprintf("Infile: %s\n", inFile);
    return 0;
}