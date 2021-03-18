#include<stdlib.h>
#include <stdio.h>
#include<string.h>
 
// #define DEBUG
#define show_var(a) printf("Variable %s has value %d\n", #a, a)
#ifdef DEBUG
#define Dprintf(msg,...) printf(msg " ",  ##__VA_ARGS__)
#else
#define Dprintf(msg,...)                /* do nothing */
#endif

typedef struct HM
{
    char* Key;
    char* Value;
    struct HM* next;
    struct HM* last;
    
}HashMap;

typedef struct Map{
    int length;
    HashMap* start;
    HashMap* end;
}Map;

void memory_alloc_Hash_Map(char* key, char* value, HashMap* last_element, HashMap* next_element){
    HashMap* current = malloc(sizeof(HashMap));
    current->Key = (char*)malloc(sizeof(char) * strlen(key));
    current->Value = (char*)malloc(sizeof(char) * strlen(value));
    current->last = last_element;
    if(last_element !== NULL)
        last_element->next = current;
    current->next = next_element;
    if(next_element !== NULL)
        next_element->last == current;
}
Map* initialize_Map(HashMap* start){
    Map* map = (Map*)malloc(sizeof(map));
    map->length = 0;
    map->start = start;
    map->end = start;
}
HashMap* find_by_key(Map* map, char* key_searched){
    HashMap* current = map->start;
    while(current != NULL){
        if(!strcmp(current->Key, key_searched)){
            return current;
        }
        current = current->next;
    }
}
void free_Map(Map* map){
    HashMap* current = map->start;
    HashMap* next = current;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

int main(int argc, char **argv)
{
    int i;
    Dprintf("argc:%d", argc);
    for(i = 0; i < argc; i++){
        Dprintf("%s",argv[i]);
    }
    printf("\n\n");
    return 0;
}