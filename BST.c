#include <stdio.h>
#include <stdlib.h>

struct bstNode
{
	int val;
	struct bstNode *left, *right;
};

//create new node fn
struct bstNode* newNodeCreate(int data)
{
	struct bstNode *temp = (struct bstNode*) malloc(sizeof(bstNode));
	temp->val = data;
	temp->left = temp->right = NULL;
	return temp;
}

//insert fn
struct bstNode* insertNode(struct bstNode* node, int data)
{
	if (node == NULL)
	{
		return newNodeCreate(data);
	}
	if (data < node->val)
	{
		node->left = insertNode(node->left, data);
	}
	else if (data > node->val)
	{
		node->right = insertNode(node->right, data);
	}
	
	return node;
}

//find min fn

struct bstNode* findMin(struct bstNode* root)
{
	if (root == NULL)
	{
		return NULL; 
	}
	else if (root->left != NULL)
	{
		return findMin(root->left);
	}
	return root;
}

//delete fn
struct bstNode* deleteNode(struct bstNode* root, data)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (data > root->val)
	{
		root->right = deleteNode(root->right, data); 
	}
	else if (data < root->val)
	{
		root->left = deleteNode(root->left, data);
	}
	else 
	{
		if (root->left == NULL && root->right == NULL)
			{
				 free(root);
				 return NULL;
			}
		}
        else if (root->left == NULL
                 || root->right == NULL) {
            struct bstNode* temp;
            if (root->left == NULL) {
                temp = root->right;
            }
            else {
                temp = root->left;
            }
            free(root);
            return temp;
        }
        else {
            struct bstNode* temp
                = findMin(root->right);
            root->val = temp->val;
            root->right = delete (root->right, temp->val);
        }
    }
    return root;
		
			
	
