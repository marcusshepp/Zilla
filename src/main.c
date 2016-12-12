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
    /* IN: a single string line from the file
     * "foo + bar"
     * OUT: an array of each token from the line
     * split by spaces.
     * ["foo", "+", "bar"]
     * */
    // create an array to hold all of the strings from the line
    char* split_tokens = malloc(10 * sizeof(char));
    // `char_ptr` will be a pointer to the current token
    char *char_ptr;
    char_ptr = strtok(line, " ");
    int i = 0;

    while(char_ptr != NULL){

        printf("%s\n", char_ptr);
        // point the pointer at the next token
        char_ptr = strtok(NULL, " ");
        // allocate a space in mem for the current token
        // within the holder array
        split_tokens[i] = *(char*)malloc(sizeof(char));
        // copy the string over to the holder array
        strcpy(split_tokens[i], char_ptr);
        ++i;

    }
    // return the holder array
    return split_tokens;
}

char *file_to_list_of_tokens(FILE* file){
    /* IN: file pointer
     * OUT: list of tokens seperated by space
     * ["foo", "+", "bar"]
     * */
    char *list_of_tokens;
    int line_limit = 1000;
    char line[line_limit];

    while(!feof(file)){
        // for each line 
        // put line contents into buffer
        fgets(line, line_limit, file);
        // pass buffer into `split by tokens` function
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
