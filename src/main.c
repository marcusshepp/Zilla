#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char *operators[4] = {"*", "+", "-", "/"};
const char *special_words[] = {
    "pr", // print
    "add",
    "sub",
    "not",
};

void print_a(char *arr[], int len){
    for(int i = 0; i < len; i++)
        printf("%s\n", arr[i]);
}


char *split_tokens_by_space(char line[]){
    char *split_tokens = malloc(10 * sizeof(char));
    char *char_ptr;
    char_ptr = strtok(line, " ");
    int i = 0;
    while(char_ptr != NULL){
        printf("%s\n", char_ptr);
        char_ptr = strtok(NULL, " ");
        split_tokens[i] = *(char*)malloc(sizeof(char));
        strcpy(split_tokens[i], char_ptr);
        ++i;
    }
    return split_tokens;
}

char *file_to_list_of_tokens(FILE* file){
    char *list_of_tokens;
    int line_limit = 1000;
    char line[line_limit];

    while(!feof(file)){

        fgets(line, line_limit, file);
        char *split_tokens = split_tokens_by_space(line);
        print_a(&split_tokens, 4); 
    }

    return list_of_tokens;
}

int main(int argc, char *argv[]){
    FILE* file = fopen(argv[1], "r");
    if(!file)
        return 1;
    char *list_of_tokens = file_to_list_of_tokens(file);
    return 0;
}
