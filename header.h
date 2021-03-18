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


HashMap* memory_alloc_Hash_Map(char* key, char* value, HashMap* last_element, HashMap* next_element);

Map* initialize_Map(HashMap* start);

HashMap* find_by_key(Map* map, char* key_searched);

void free_Map(Map* map);

HashMap* extract_key_value(char* str, HashMap* last_element);

void Add_to_map(char* str, Map* map);

void print_map(Map* map);

#include "functions.h"