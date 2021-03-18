#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(){
    char str[100];
    scanf("%s", str);   
    printf("String: %s\n", str); 
    char* x = strtok(str, "=");

    printf("String: %s\n", x); 
    x = strtok(NULL, "=");

    printf("String: %s\n", x); 

}