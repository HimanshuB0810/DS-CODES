// 7 Program based on tries
// i. Create a text file containing keys{“and”, “bat”, “ball”, “book”,“cot”, “cotton”, “internet”, “interview”, “joy”, “job”, “King”, “Lion”, “man”,“mango”, “manage”} 
// separated by tab and then read those keys and insert them in trie and search the key which is accepted as input from user
// ii. Read the keys from char array which is already given and search the keys which are accepted as input from user
// iii. Read the keys from char array and search those keys which are given in text file
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h> 

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
    struct TrieNode *temp = root; 
    int index;
    for(int i=0;word[i]!='\0';i++)
    {
        char letter= tolower(word[i]);
        index= letter- 'a'; 
        

        if(index<0 || index>=ALPHABET) continue; 
        if(temp->children[index]==NULL)
        {
            temp->children[index]=getNode();
        }
        temp=temp->children[index];
    }
    temp->isEndOfWord=1;
}   

int search(struct TrieNode *root, char *word)
{
    struct TrieNode *temp= root;
    int index;
    for(int i=0;word[i]!='\0';i++)
    {
        char letter=tolower(word[i]);
        index=letter-'a';
        if(index<0 || index>=ALPHABET) continue; 
        if(temp->children[index]==NULL)
        {
            return 0;
        }
        temp=temp->children[index];
    }
    return temp->isEndOfWord;
}

void part1(struct TrieNode *root)
{
    FILE *fp=fopen("textfile.txt","r");
    char word[50];
    if(!fp)
    {
        printf("File not found!\n");
        return;
    }
    while(fscanf(fp,"%s",word)!=EOF)
    {
        insert(root,word);
    }
    fclose(fp);

    char key[50];
    printf("Enter word to search: ");
    scanf("%s",key);

    if(search(root,key))
    {
        printf("%s Found in Trie\n",key);
    }
    else
    {
        printf("%s Not Found\n");
    }
}

void part2(struct TrieNode *root) 
{
    char *keys[] = {"and","bat","ball","book","cot","cotton","internet","interview","joy","job","King","Lion","man","mango","manage"};
    int n = 15;

    for(int i=0; i<n; i++)
    {
        insert(root,keys[i]);
    }

    char key[50];
    printf("Enter word to search: ");
    scanf("%s",key);
    if(search(root,key))
    {
        printf("%s Found in Trie\n",key);
    }
    else
    {
        printf("%s Not Found\n");
    }
}

void part3(struct TrieNode *root) 
{
    char *keys[] = {"and","bat","ball","book","cot","cotton","internet","interview","joy","job","King","Lion","man","mango","manage"};
    int n = 15;

    for(int i=0; i<n; i++)
    {
        insert(root,keys[i]);
    }
    FILE *fp=fopen("textfile.txt","r");
    char word[50];
    if(!fp)
    {
        printf("File not found!\n");
        return;
    }

    while (fscanf(fp,"%s",word)!=EOF)
    {
        if(search(root,word))
        {
            printf("%s Found",word);
        }
        else
        {
            printf("%s Not Found",word);
        }
    }
}

int main()
{
    struct TrieNode* root=getNode();
    int choice;
    printf("1. File -> Trie -> Search User Input\n");
    printf("2. Array -> Trie -> Search User Input\n");
    printf("3. Array -> Trie -> Search File Input\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
        switch (choice) {
        case 1: part1(root); break;
        case 2: part2(root); break;
        case 3: part3(root); break;
        default: printf("Invalid choice\n");
    }
    return 0;
}

