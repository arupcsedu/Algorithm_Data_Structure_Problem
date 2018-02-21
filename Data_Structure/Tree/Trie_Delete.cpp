#include <stdio.h>
#include <malloc.h>

#define ALPHABET_MAX (26)
#define IDX(c) (int)c - (int)'a'
#define ARR_SIZE(a) sizeof(a)/sizeof(a[0])

#define FREE(p) \
    free(p); \
    p = NULL;

typedef struct trie_node tNode;

struct trie_node
{
    int isLastNode;
    tNode *children[ALPHABET_MAX];
};

typedef struct trie_list tlist;

struct trie_list
{
    int count;
    tNode *root;
};

int sstrlen(char *str)
{
    int len = 0;
    while(*str != NULL)
    {
        str++;
        len++;
    }
    return len;
}
tNode* getNode()
{
    tNode *newNode = (tNode*) malloc(sizeof(tNode));

    if(newNode)
    {
        newNode->isLastNode = 0;
        for(int i = 0;i<ALPHABET_MAX;i++)
        {
            newNode->children[i] = NULL;
        }
    }
    return newNode;
}
void intialize(tlist *pNode)
{
    pNode->root = getNode();
    pNode->count = 0;
}

void insertToTrie(tlist *pNode, char key[])
{
    tNode *pCrawl = pNode->root;
    pNode->count++;
    int len = sstrlen(key);
    for(int i = 0; i<len; i++)
    {
        int idx = IDX(key[i]);
        if(!pCrawl->children[idx])
            pCrawl->children[idx] = getNode();
        pCrawl = pCrawl->children[idx];
    }
    pCrawl->isLastNode = pNode->count;
}

int searchIntoTrie(tlist *pNode, char key[])
{
    tNode *pCrawl = pNode->root;
    int len = sstrlen(key);
    for(int i = 0; i<len; i++)
    {
        int idx = IDX(key[i]);
        if(!pCrawl->children[idx])
            return 0;
        pCrawl = pCrawl->children[idx];
    }
    return (!pCrawl) && pCrawl->isLastNode ;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
