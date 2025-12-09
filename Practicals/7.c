// 7 Program based on tries
// i. Create a text file containing keys{“and”, “bat”, “ball”, “book”,“cot”, “cotton”, “internet”, “interview”, “joy”, “job”, “King”, “Lion”, “man”,“mango”, “manage”} 
// separated by tab and then read those keys and insert them in trie and search the key which is accepted as input from user
// ii. Read the keys from char array which is already given and search the keys which are accepted as input from user
// iii. Read the keys from char array and search those keys which are given in text file
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h> // to lower()

#define ALPHABET 26

struct TrieNode{
    struct TrieNode *children[ALPHABET];
    int isEndOfWord; // flag: 1 means complete word ends, 0 means it's just a prefix, not a full word
};

struct TrieNode* getNode()
{
    struct TrieNode *node=(struct TrieNode*)malloc(sizeof(struct TrieNode));
    node->isEndOfWord=0;
    for(int i=0;i<ALPHABET;i++)
    {
        node->children[i]=NULL;
    }
    return node;
};

void insert(struct TrieNode *root, char *word)
{
    struct TrieNode *crwal = root; // temporary pointer used to move down the trie as we insert each character
    int index;
    for(int i=0;word[i]!='\0';i++)
    {
        char letter= tolower(word[i]);
        index= letter- 'a'; 
        // Example:
        // 'a' - 'a' → 0
        // 'c' - 'a' → 2
        // This maps characters 'a'-'z' to integer indices 0-25

        if(index<0 || index>=ALPHABET) continue; // check for non-alphabetic characters
        if(crwal->children[index]==NULL)
        {
            crwal->children[index]=getNode();
        }
        crwal=crwal->children[index];
    }
    crwal->isEndOfWord=1;
}   

int search(struct TrieNode *root, char *word)
{
    struct TrieNode *crawl= root;
    int index;
    for(int i=0;word[i]!='\0';i++)
    {
        char letter=tolower(word[i]);
        index=letter-'a';
        if(index<0 || index>=ALPHABET) continue; // check for non-alphabetic characters
        if(crawl->children[index]==NULL)
        {
            return 0;
        }
        crawl=crawl->children[index];
    }
    return crawl->isEndOfWord;
}