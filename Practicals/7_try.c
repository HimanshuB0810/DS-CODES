#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Added for tolower()

#define ALPHABET 26

// Trie Node structure
struct TrieNode {
    struct TrieNode *children[ALPHABET];
    int isEndOfWord;
};

// Create new Trie node
struct TrieNode* getNode() {
    struct TrieNode *node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    node->isEndOfWord = 0;
    for (int i = 0; i < ALPHABET; i++)
        node->children[i] = NULL;
    return node;
}

// Insert a word into Trie (CORRECTED)
void insert(struct TrieNode *root, char *word) {
    struct TrieNode *crawl = root;
    int index;

    for (int i = 0; word[i] != '\0'; i++) {
        // Convert to lowercase to handle "King" and "Lion"
        char letter = tolower(word[i]); 
        index = letter - 'a';
        
        // Safety check for non-alphabetic characters
        if (index < 0 || index >= ALPHABET) continue;

        if (crawl->children[index] == NULL)
            crawl->children[index] = getNode();
        crawl = crawl->children[index];
    }
    crawl->isEndOfWord = 1;
}

// Search a word in Trie (CORRECTED)
int search(struct TrieNode *root, char *word) {
    struct TrieNode *crawl = root;
    int index;

    for (int i = 0; word[i] != '\0'; i++) {
        char letter = tolower(word[i]);
        index = letter - 'a';
        
        if (index < 0 || index >= ALPHABET) return 0;
        if (crawl->children[index] == NULL)
            return 0;
        crawl = crawl->children[index];
    }
    return crawl->isEndOfWord;
}

void part1(struct TrieNode *root) {
    FILE *fp = fopen("textfile.txt", "r");
    char word[50];

    if (!fp) {
        printf("File not found! Please create textfile.txt first.\n");
        return;
    }

    // fscanf with %s automatically handles spaces, tabs, and newlines
    while (fscanf(fp, "%s", word) != EOF) {
        insert(root, word);
    }
    fclose(fp);

    char key[50];
    printf("\n--- Part 1: File to Trie ---\n");
    printf("Enter word to search: ");
    scanf("%s", key);

    if (search(root, key))
        printf("'%s' FOUND in Trie\n", key);
    else
        printf("'%s' NOT FOUND\n", key);
}

void part2(struct TrieNode *root) {
    // Note: I updated the array to match the assignment exactly (added caps)
    char *keys[] = {"and","bat","ball","book","cot","cotton",
                    "internet","interview","joy","job","King",
                    "Lion","man","mango","manage"};
    int n = 15;

    for (int i = 0; i < n; i++)
        insert(root, keys[i]);

    char key[50];
    printf("\n--- Part 2: Array to Trie ---\n");
    printf("Enter word to search: ");
    scanf("%s", key);

    if (search(root, key))
        printf("'%s' FOUND in Trie\n", key);
    else
        printf("'%s' NOT FOUND\n", key);
}

void part3(struct TrieNode *root) {
    char *keys[] = {"and","bat","ball","book","cot","cotton",
                    "internet","interview","joy","job","King",
                    "Lion","man","mango","manage"};
    int n = 15;

    // Insert array keys
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);

    // Read keys from file and search them
    FILE *fp = fopen("textfile.txt", "r");
    char word[50];

    if (!fp) {
        printf("File not found!\n");
        return;
    }

    printf("\n--- Part 3: Search File words in Array-Trie ---\n");
    while (fscanf(fp, "%s", word) != EOF) {
        if (search(root, word))
            printf("%-10s -> FOUND\n", word); // %-10s for formatting
        else
            printf("%-10s -> NOT FOUND\n", word);
    }
    fclose(fp);
}

int main() {
    // Note: In a real scenario, you should clear the Trie between choices
    // But for this lab logic, this is fine.
    struct TrieNode *root = getNode();
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