/*
Date: 22/02/2018
Description: Implementation of Trie Delete
Author: Arup Kumar Sarker
url: https://www.geeksforgeeks.org/trie-delete/
*/


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
    return (0 != pCrawl) && (pCrawl->isLastNode) ;
}
 int isItFreeNode(tNode *pNode)
 {
    for(int i = 0; i<ALPHABET_MAX; i++)
    {
        if(pNode->children[i])
            return 0;
    }
    return 1;
 }

 int isLeafNode(tNode *pNode)
 {
    return (pNode->isLastNode != 0);
 }

bool deleteKeyHelper(tNode *root, char key[], int level, int len)
{
    if(root)
    {
        if(level == len)
        {
            if(root->isLastNode != 0)
            {
                root->isLastNode = 0;
                if(isItFreeNode(root))
                    return true;
                return false;
            }
        }
        else
        {
            int idx = IDX(key[level]);
            if(deleteKeyHelper(root->children[idx], key, level+1, len))
            {
                FREE(root->children[idx]);
                return (!isLeafNode(root)) && isItFreeNode(root);
            }
        }
    }
    return false;
}
void deleteKey(tlist *pNode, char key[])
{
    int len = sstrlen(key);
    if(len>0)
    {
            deleteKeyHelper(pNode->root, key, 0, len);
    }
}
int main()
{
    char keys[][8] = {"she", "sells", "sea", "shore", "the", "by", "sheer"};
    tlist pNode;
    intialize(&pNode);
    for(int i = 0;i<8;i++)
    {
        insertToTrie(&pNode, keys[i]);
    }
    deleteKey(&pNode, keys[0]);

    printf("%s %s\n", "she", searchIntoTrie(&pNode, "she") ? "Present in trie" : "Not present in trie");
    return 0;
}
