#include<iostream>
#include<vector>
#include<cmath>
#include<climits>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void insert_last(TreeNode* left, TreeNode* right) {
	TreeNode* head = left;
	TreeNode* prev = NULL;

	while(head != NULL){
		prev  = head;
		head = head->right;
	}

	prev->right = right;
}

void traverse(TreeNode* root){
	if(root == NULL) {
		return;
	}

	//cout<< root->val << " ";
	
	traverse(root->left);
	traverse(root->right);

	if(root->left != NULL && root->right != NULL) {
		TreeNode* right = root->right;
		insert_last(root->left, right);
		root->right = root->left;
		root->left = NULL;
	} else if(root->left != NULL && root->right == NULL) {
		root->right = root->left;
		root->left = NULL;
	}
}

void flatten(TreeNode* root) {
	traverse(root);
	//cout<<endl;
}

void print_LL(TreeNode* root) {
	if(root == NULL) {
		return;
	}

	cout<< "root = " << root->val << " Left = ";
	print_LL(root->left);
	cout<< "root = " << root->val << " Right = ";
	print_LL(root->right);
}

int main(int argc, char** argv) {
	TreeNode* root = new TreeNode(1);
	TreeNode* two = new TreeNode(2);
	TreeNode* three = new TreeNode(3);
	TreeNode* four = new TreeNode(4);
	TreeNode* five = new TreeNode(5);
	TreeNode* six = new TreeNode(6);

	two->left = three;
	two->right = four;
	five->right = six;
	root->left = two;
	root->right = five;

	flatten(root);

	print_LL(root);
	cout<< endl;
	
	return 0;
}
