#include<bits/stdc++.h>

using namespace std;

struct TreeNode
{
int data;
struct TreeNode* left;
struct TreeNode* right;
};

bool printAncestors(struct TreeNode *root, int target)
{
if (root == NULL)
	return false;

if (root->data == target)
	return true;
if ( printAncestors(root->left, target) ||
	printAncestors(root->right, target) )
{
	cout << root->data << " ";
	return true;
}

return false;
}

struct TreeNode* newTreeNode(int data)
{
struct TreeNode* TreeNode = (struct TreeNode*)
					malloc(sizeof(struct TreeNode));
TreeNode->data = data;
TreeNode->left = NULL;
TreeNode->right = NULL;

return(TreeNode);
}

int main()
{
struct TreeNode *root = newTreeNode(1);
root->left	 = newTreeNode(2);
root->right	 = newTreeNode(3);
root->left->left = newTreeNode(4);
root->left->right = newTreeNode(5);
root->left->left->left = newTreeNode(7);

printAncestors(root, 7);

getchar();
return 0;
}
