#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int data;
	struct TreeNode *left, *right;
};

struct TreeNode* newTreeNode(int data)
{
	struct TreeNode* newTreeNode = new TreeNode;
	newTreeNode->data = data;
	newTreeNode->left = newTreeNode->right = NULL;
	return (newTreeNode);
}
int findMaxUtil(TreeNode* root, int& res)
{
	if (root == NULL)
		return 0;
	int l = findMaxUtil(root->left, res);
	int r = findMaxUtil(root->right, res);
	int max_single
		= max(max(l, r) + root->data, root->data);
	int max_top = max(max_single, l + r + root->data);

	res = max(res, max_top);

	return max_single;
}

int findMaxSum(TreeNode* root)
{
	int res = INT_MIN;
	findMaxUtil(root, res);
	return res;
}
int main(void)
{
	struct TreeNode* root = newTreeNode(10);
	root->left = newTreeNode(2);
	root->right = newTreeNode(10);
	root->left->left = newTreeNode(20);
	root->left->right = newTreeNode(1);
	root->right->right = newTreeNode(-25);
	root->right->right->left = newTreeNode(3);
	root->right->right->right = newTreeNode(4);
	cout << "Max path sum is " << findMaxSum(root);
	return 0;
}
