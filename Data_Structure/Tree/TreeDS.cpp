#include<stdio.h>
#include<stdlib.h>
#include<queue>

using namespace std;

typedef struct BinTree
{
    int key;
    struct BinTree *leftChild;
    struct BinTree *rightChild;
}BT;

BT* getTNode(int key)
{
    BT *newNode = (BT*) malloc(sizeof(BT));
    newNode->key = key;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

void insertInToTree(BT **rootRef, int key)
{
    queue<BT*> q;
    BT *current = (*rootRef);
    q.push(current);
    while(!q.empty())
    {
        BT *frontNode = q.front();
        q.pop();
        if(frontNode->leftChild == NULL)
        {
            frontNode->leftChild = getTNode(key);
            break;
        }
        else
            q.push(frontNode->leftChild);
        if(frontNode->rightChild == NULL)
        {
            frontNode->rightChild = getTNode(key);
            break;
        }
        else
            q.push(frontNode->rightChild);
    }
}

void inOrderPrint(BT *rootRef)
{
    if(rootRef == NULL)
        return;
    inOrderPrint(rootRef->leftChild);
    printf("%d ",rootRef->key);
    inOrderPrint(rootRef->rightChild);
}

int main_TREEDS()
{
    BT *root = getTNode(1);
    insertInToTree(&root,2);
    insertInToTree(&root,3);
    insertInToTree(&root,4);
    insertInToTree(&root,5);
    insertInToTree(&root,6);
    printf("In-Order traversal:\n");
    inOrderPrint(root);
    return 0;
}
