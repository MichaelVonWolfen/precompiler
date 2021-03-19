/// Returns -1 if nothing was done, 0 if something was found, 1 if something was found and i must increase
int parameters_check(int i, char** argv, Map* map, List* list, char* delimiter){
    char* temp_Str;
    int return_int = 0;
    char* str = argv[i];
    int ok = 1;
    if(!strcmp(str, delimiter)){
        i++;
        return_int = 1;
        if(map != NULL){
            Add_to_map(argv[i], map);
        } else{
            Add_to_list(argv[i], list);
        }
    }else if(str[0] == delimiter[0] && str[1] == delimiter[1]){
        temp_Str = (char*) malloc(sizeof (char) * strlen(str - 2));
        strncpy(temp_Str, str + 2, strlen(str) - 2);
        if(map != NULL){
            Add_to_map(temp_Str, map);
        } else{
            Add_to_list(temp_Str, list);
        }
    }
    return return_int;
}
void readCodeFromConsole(){
    return;
}