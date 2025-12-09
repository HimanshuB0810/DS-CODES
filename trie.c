#include<stdio.h>
#include<stdlib.h>
#define ALPHABET 25

struct trienode
{
    struct trienode* children[ALPHABET];
    int isEndOfWord;
};

struct trienode* CreateNode()
{
    struct trienode* newnode= (struct trienode*)malloc(sizeof(struct trienode));
    newnode->isEndOfWord=0;

    for(int i=0; i<ALPHABET;i++)
    {
        newnode->children[i]=NULL;
    }
    return newnode;
}

void insert(struct trienode* root, char* word)
{
    int index;
    struct trienode* temp=root;

    for(int i=0; word[i]!='\0';i++)
    {
        index=word[i]-'a';

        if(temp->children[index]==NULL)
        {
            temp->children[index]=CreateNode();
        }
        temp=temp->children[index];
    }
    temp->isEndOfWord=1;
}

void main()
{
    struct trienode*root= CreateNode();
    char word[50];

    printf("Enter word: ");
    scanf("%s",word);

    insert(root,word);
}