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

//find min fn is used to get the inorder successor
struct bstNode* findMin(struct bstNode *root){
    if (root == NULL){
        return NULL;
    }
    else if (root->left != NULL){
        return findMin(root->left);
    }
    else{
        return root;
    }
}

//delete fn
struct bstNode* deleteNode(struct bstNode *root, int data){
    if (root == NULL){
        return NULL;
    }
    if (data < root->val){
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->val){
        root->right = deleteNode(root->right, data);
    }
    else{
        if (root->left == NULL && root->right == NULL){ 	 // current root has no child
            free(root);
            return NULL;
        }
        else if (root->left == NULL || root->right == NULL){ //current root has only one child
            struct bstNode* temp;
            if(root->left == NULL){ 						 // only right child
                temp = root->right;
            }
            else if (root->right == NULL){					 // only left child
                temp = root->left;
            }
            free(root);
            return temp;
        }
        else {												 //current root has two children 
            struct bstNode *temp = findMin(root->right);	 //current root replaced by inorder successor
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }
    return root;
}

struct bstNode* searchNode(struct bstNode *root, int target){
    if (root == NULL || root->val == target){
        return root;
    }
    if(target > root->val){
        return searchNode(root->right, target);
    }
    return searchNode(root->left, target);
}

void postOrder(struct bstNode* root)
{
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ", root->val);
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

    postOrder(root);
    
    printf("\n");

     if (searchNode(root, 60) != NULL) {
        printf("60 found");
    }
    else {
        printf("60 not found");
    }
 
    printf("\n");
}#include <stdio.h> 
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

//find min fn is used to get the inorder successor
struct bstNode* findMin(struct bstNode *root){
    if (root == NULL){
        return NULL;
    }
    else if (root->left != NULL){
        return findMin(root->left);
    }
    else{
        return root;
    }
}

//delete fn
struct bstNode* deleteNode(struct bstNode *root, int data){
    if (root == NULL){
        return NULL;
    }
    if (data < root->val){
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->val){
        root->right = deleteNode(root->right, data);
    }
    else{
        if (root->left == NULL && root->right == NULL){ 	 //root has no child
            free(root);
            return NULL;
        }
        else if (root->left == NULL || root->right == NULL){ //root has only one child
            struct bstNode* temp;
            if(root->left == NULL){ 						 // only right child
                temp = root->right;
            }
            else if (root->right == NULL){					 // only left child
                temp = root->left;
            }
            free(root);
            return temp;
        }
        else {												 //root has two children 
            struct bstNode *temp = findMin(root->right);	 // root replaced by inorder successor
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }
    return root;
}

struct bstNode* searchNode(struct bstNode *root, int target){
    if (root == NULL || root->val == target){
        return root;
    }
    if(target > root->val){
        return searchNode(root->right, target);
    }
    return searchNode(root->left, target);
}

void postOrder(struct bstNode* root)
{
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ", root->val);
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

    postOrder(root);
    
    printf("\n");

     if (searchNode(root, 60) != NULL) {
        printf("60 found");
    }
    else {
        printf("60 not found");
    }
 
    printf("\n");
}
