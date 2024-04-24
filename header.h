#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define NUMCHAR 26

#define VALID_WORDS "validWords.txt"
#define ANSWER_WORDS "worldleAnswers.txt"


// Typedef for a node in the tree
typedef struct trieNode {

    struct trieNode *children[NUMCHAR];
    int flag;

} trieNode;


/*
* Function Headers
*/

// Trie Functions
trieNode *newNode(void);
void insertWord(char * wordToInsert, trieNode ** root);
int searchTrie(char *wordToLookup, trieNode *root);
void freeTrie(trieNode **root);
