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

char *split_tokens_by_space(char tokens[]){
    char *split_tokens = malloc(10 * sizeof(char));
    char *
    int i;

    for(i = 0; i < 10; i++)
        printf("split_tokens[%d]: %c\n", i, split_tokens[i]);
    return split_tokens;
}

char *file_to_list_of_tokens(FILE* file){
    char *list_of_tokens;
    int line_limit = 1000;
    char buffer[line_limit];
    while(!feof(file)){
        fgets(buffer, line_limit, file);
        char *split_tokens = split_tokens_by_space(buffer);
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
