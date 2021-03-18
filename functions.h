
HashMap* memory_alloc_Hash_Map(char* key, char* value, HashMap* last_element, HashMap* next_element){
    HashMap* current = malloc(sizeof(HashMap));
    current->Key = (char*)malloc(sizeof(char) * strlen(key));
    current->Value = (char*)malloc(sizeof(char) * strlen(value));
    current->last = last_element;
    if(last_element != NULL)
        last_element->next = current;
    current->next = next_element;
    if(next_element != NULL)
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

HashMap* extract_key_value(char* str, HashMap* last_element){
    char* key;
    char* value;
    char* temp = strtok(str, "=");
    key = (char*)malloc(sizeof(char) * strlen(temp));
    strcpy(key, temp);
    temp = strtok(NULL, "=");
    value = (char*)malloc(sizeof(char) * strlen(temp));
    strcpy(value, temp);
    if(value == NULL)
        value = "";
    return memory_alloc_Hash_Map(key, value,last_element, NULL);
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

void print_map(Map* map){
    HashMap* current = map->start;
    while (current != NULL)
    {
        printf("Key: %s \t Value: %s\n", current->Key, current->Value);
        current = current->next;
    }
}