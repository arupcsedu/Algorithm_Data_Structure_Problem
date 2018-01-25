/*
 * Basic_Trie.cpp
 *
 *  Created on: Jan 25, 2018
 *      Author: Arup Kumar Sarker
 *      url: https://www.geeksforgeeks.org/trie-insert-and-search/
 */

#include<stdio.h>
#include<malloc.h>

#define ALPHABET_MAX (26)
#define ARRAY_SIZE(s) sizeof(s)/sizeof(s[0])
#define TEXT_IDX(c) ((int)c - (int)'a')

struct TrieNode
{
	struct TrieNode *child[ALPHABET_MAX];
	bool isLastChild;
};

struct TrieNode* getNode()
{
	struct TrieNode *tNode = (struct TrieNode*)malloc(sizeof(struct TrieNode));
	tNode->isLastChild = false;
	for(int i = 0; i<ALPHABET_MAX;i++)
	{
		tNode->child[i] = NULL;
	}
	return tNode;
}
int sstrlen(char *str)
{
	int i = 0;
	while(*str != NULL)
	{
		str++;
		i++;
	}
	//printf("%d",i);

	return i;
}

void insertTrie(struct TrieNode *root, char *key)
{
	int len = sstrlen(key);
	struct TrieNode *pNode = root;;

	for(int i = 0; i<len;i++)
	{
		int index = TEXT_IDX(key[i]);
		if(pNode->child[index] == NULL)
		{
			pNode->child[index] = getNode();
		}
		pNode = pNode->child[index];
	}
	pNode->isLastChild = true;
}

bool searchTrie(struct TrieNode *root, char *key)
{
	int len = sstrlen(key);
	struct TrieNode *pNode = root;
	int i;
	for(i = 0; i < len;i++)
	{
		int index = TEXT_IDX(key[i]);
		if(!pNode->child[index])
			return false;
		pNode = pNode->child[index];
	}
	return ((pNode != NULL) && pNode->isLastChild);
}
int main()
{
	char keys[][8] = {"the","a","there","answer","any","by","bye","their"};
	char outputs[][32] = {"Not present in Trie", "Present in Trie"};

	//get root Node
	struct TrieNode *root = getNode();

	//Construct the tree
	for(int i = 0; i < ARRAY_SIZE(keys);i++)
	{
		insertTrie(root, keys[i]);
	}

	// Search the keys in Trie
	printf("%s is %s\n","this", outputs[searchTrie(root, "this")]);
	printf("%s is %s\n", "these",outputs[searchTrie(root,"these")]);
	printf("%s is %s\n","their", outputs[searchTrie(root,"their")]);
	printf("%s is %s\n","thaw",outputs[searchTrie(root, "thaw")]);
	return 0;
}

