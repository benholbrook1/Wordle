#include "header.h"


int main(int argc, char** argv){

    FILE *fptr;

    fptr = fopen(VALID_WORDS, "r");
    if (fptr == NULL){
        fprintf(stderr, "Error, could not open file %s\n", VALID_WORDS);
        return -1;
    }



    trieNode *ValidWords_root = newNode();
    char* word;
    size_t len = 0;
    while(getline(&word, &len, fptr) != -1){
        // Remove the newline character
        word[5] = '\0';

        insertWord(word, &ValidWords_root);

        printf("*%s*\n", word);
    }




    fclose(fptr);
    if (word){
        free(word);
    }

    return 0;
}
