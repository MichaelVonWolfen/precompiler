typedef struct HM
{
    char* Key;
    char* Value;
    struct HM* next;
    struct HM* last;
    
}HashMap;

typedef struct LL
{
    char* Value;
    struct LL* next;
    struct LL* last;
    
}LinkedList;

typedef struct Map{
    int length;
    HashMap* start;
    HashMap* end;
}Map;

typedef struct List{
    int length;
    LinkedList* start;
    LinkedList* end;
}List;

//Returns a new HashMap element that is alreaady linked to its last and next elements
HashMap* memory_alloc_Hash_Map(char* key, char* value, HashMap* last_element, HashMap* next_element);


Map* initialize_Map(HashMap* start);

HashMap* find_by_key(Map* map, char* key_searched);

//frees the memory allocated to a Map structure
void free_Map(Map* map);

//Extracts the key value pair situated in the str and saves it in a HashMap linked to last_element.next
HashMap* extract_key_value(char* str, HashMap* last_element);

void Add_to_map(char* str, Map* map);

void print_map(Map* map);

LinkedList* memory_alloc_Linked_List(char* value, LinkedList* last_element, LinkedList* next_element);

List* initialize_List(LinkedList* start);

void free_list(List* list);

LinkedList* extract_list(char* str, LinkedList* last_element);

void Add_to_list(char* str, List* list);

void print_list(List* list);





HashMap* memory_alloc_Hash_Map(char* key, char* value, HashMap* last_element, HashMap* next_element){
    HashMap* current = (HashMap*)malloc(sizeof(HashMap));
    current->Key = (char*)malloc(sizeof(char) * strlen(key));
    current->Key = key;
    current->Value = (char*)malloc(sizeof(char) * strlen(value));
    current->Value = value;
    current->last = last_element;
    if(last_element != NULL)
        last_element->next = current;
    current->next = next_element;
    if(next_element != NULL)
        next_element->last = current;
    return current;
}

LinkedList* memory_alloc_Linked_List(char* value, LinkedList* last_element, LinkedList* next_element){
    LinkedList* current = (LinkedList*)malloc(sizeof(LinkedList));
    current->Value = (char*)malloc(sizeof(char) * strlen(value));
    current->Value = value;
    current->last = last_element;
    if(last_element != NULL)
        last_element->next = current;
    current->next = next_element;
    if(next_element != NULL)
        next_element->last = current;
    
    return current;
}


Map* initialize_Map(HashMap* start){
    Map* map = (Map*)malloc(sizeof(map));
    map->length = 0;
    map->start = start;
    map->end = start;

    return map;
}

List* initialize_List(LinkedList* start){
    List* list = (List*)malloc(sizeof(List));
    list->length = 0;
    list->start = start;
    list->end = start;

    return list;
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

void free_list(List* list){
    LinkedList* current = list->start;
    LinkedList* next = current;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}
HashMap* extract_key_value(char* str, HashMap* last_element){
    char* key;
    char* value;
    char* temp = strtok(str, "=");
    key = (char*)malloc(sizeof(char) * strlen(temp));
    strcpy(key, temp);
    temp = strtok(NULL, "=");
    if(temp == NULL){
        value = "";
    }else{
        value = (char*)malloc(sizeof(char) * strlen(temp));
        strcpy(value, temp);
    }
    return memory_alloc_Hash_Map(key, value,last_element, NULL);
}

LinkedList* extract_list(char* str, LinkedList* last_element){
    char* value;
    value = (char*)malloc(strlen(str)*sizeof(char));
    strcpy(value, str);

    return memory_alloc_Linked_List(value,last_element, NULL);
}

void Add_to_map(char* str, Map* map){
    map->length++;
    if(map->start == NULL){
        map->start = extract_key_value(str, map->start);
        map->end = map->start;
    }else{
        map->end = extract_key_value(str, map->end);
    }
}
void Add_to_list(char* str, List* list){
    list->length++;
    if(list->start == NULL){
        list->start = extract_list(str, list->start);
        list->end = list->start;
    }else{
        list->end = extract_list(str, list->end);
    }
}

void print_map(Map* map){
    #ifndef DEBUG
        return;
    #else
        HashMap* current = map->start;
        while (current != NULL)
        {
            printf("Key: %s \t Value: \"%s\"\n", current->Key, current->Value);
            current = current->next;
        }
    #endif
}
void print_list(List* list){
    #ifndef DEBUG
        return;
    #else
        LinkedList* current = list->start;
        while (current != NULL)
        {
            printf("Value: %s\n",current->Value);
            current = current->next;
        }
    #endif
}