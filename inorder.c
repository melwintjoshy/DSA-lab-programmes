#include <stdio.h> 
#include <stdlib.h>

struct bstNode {
    int val;
    struct bstNode *right, *left;
};

//create new node fn
struct bstNode* createNewnode(int data){
    struct bstNode *temp = malloc(sizeof(struct bstNode));
    temp->val = data;
    temp->left = temp->right = NULL;
    return temp;
}

//insert fn
struct bstNode* insertNode(struct bstNode *root, int data){
    if (root == NULL){
        return createNewnode(data);
    }
    if (data < root->val){
        root->left = insertNode(root->left, data);
    }
    else if (data > root->val){
        root->right = insertNode(root->right, data);
    }
    return root;
}

void inOrder(struct bstNode* root)
{
    if (root != NULL) {
        inOrder(root->left);
        printf(" %d ", root->val);
        inOrder(root->right);
    }
}

int main()
{
    struct bstNode *root = NULL;

    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    inOrder(root);
    
    printf("\n");
}
