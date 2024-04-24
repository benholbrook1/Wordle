#include "header.h"

/*
*   This Section of Code contains a Trie implementation which will be used to
*   create a structure to hold valid wordle words
*
*/


// Creates a new node
trieNode *newNode(void){

    trieNode *newNode = malloc(sizeof *newNode);

    // Start with the node not "flaged" i.e. it is not the last node representing a word in our dict
    newNode->flag = 0;

    // Set all children to null
    for(int i = 0; i < NUMCHAR; i++){
        newNode->children[i] = NULL;
    }

    return newNode;
}

void insertWord(char * wordToInsert, trieNode ** root){

    // in the case that the root is null
    if (*root == NULL){
        *root = newNode();
    }

    int wordLength = strlen(wordToInsert);
    trieNode *temp = *root;
    
    // for the length of the word, traverse down the tree, creating a new node if that letter doesn't exist
    for(int i = 0; i < wordLength; i++){

        // Get the index of where the next node should be
        char nextLetter = wordToInsert[i];
        int index = -1;
        // Handle if its a dash, otherwise convert to lowercase
        if (nextLetter == '-'){
            index = 26; // 26 is the first slot for an additional character
        } else if(nextLetter == '\''){
            index = 27; // 27 is the second slot for an additional character
        } else {
            if (isalpha(nextLetter)){
                index = tolower(nextLetter) - 97;
            }
        }
        if (index == -1){
            // We will disgard all dictionary words that contain non standard english letters along with ' and -
            //fprintf(stderr, "Error, Couldn't read %s from dictionary\n", wordToInsert);
            return;
        }

        // Traverse down the tree, creating new nodes if we need to
        if (temp->children[index] == NULL){
            temp->children[index] = newNode();
        }
        temp = temp->children[index];
    }

    // set the flag in our last node of the word to signify that that word exists
    temp->flag = 1;
}

int searchTrie(char *wordToLookup, trieNode *root){

    // get the length of the word we are looking up
    int length = strlen(wordToLookup);
    trieNode* temp = root;

    for (int i = 0; i < length; i++){

        // Get the index of where the next node should be
        char nextLetter = wordToLookup[i];
        int index = -1;
        // Handle if its a dash, otherwise convert to lowercase
        if (nextLetter == '-'){
            index = 26; // 26 is the last index
        } else {
            if (isalpha(nextLetter)){
                index = tolower(nextLetter) - 97;
            }
        }
        if (index == -1){
            return 0;
        }

        if (temp->children[index] == NULL){
            return 0;
        }
        temp = temp->children[index];
    }
    // returns a 1 if the flag has been set
    return temp->flag;
}

void freeTrie(trieNode **root) {
    // Check if the given root is NULL
    if (*root == NULL) {
        return;
    }

    // For each of the roots children, call this function recursively
    for (int i = 0; i < NUMCHAR; i++) {
        if ((*root)->children[i] != NULL) {
            freeTrie(&((*root)->children[i]));
        }
    }

    free(*root);
    *root = NULL; // Set the pointer to NULL after freeing to avoid dangling pointers
}


/*
* End of Trie code
*/
