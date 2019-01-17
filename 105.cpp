#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int preIndex = 0;


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	if((preIndex ==  preorder.size()) || (inorder.size() == 0)) {
		return NULL;
	}

	int root = preorder[preIndex];

	TreeNode* rootNode  = new TreeNode(root);

	vector<int> leftio;
	vector<int> rightio;
	bool root_seen  = false;

	for(int i=0;i<inorder.size();i++){
		if(root == inorder[i]) {
			root_seen = true;
			continue;
		}

		if(root_seen) {
			//cout << "R = " << inorder[i] << " ";
			rightio.push_back(inorder[i]);
		} else {
			//cout << "L = " << inorder[i] << " ";
			leftio.push_back(inorder[i]);
		}
	}

	//cout<< endl;

	preIndex++;

	rootNode->left = buildTree(preorder, leftio);
	rootNode->right = buildTree(preorder, rightio);

	return rootNode;
}

void print_tree(TreeNode* root) {
	if(root == NULL) {
		cout << "NULL";
		return;
	}

	cout << "root = " << root->val <<  "-> left = ";
	print_tree(root->left);

	cout << "root = " << root->val <<  "-> right = ";
	print_tree(root->right);
}

int main(int argc, char** argv) {
	vector<int> preorder = {3,9,20,15,7};
	vector<int> inorder = {9,3,15,20,7};

	TreeNode* rootNode = buildTree(preorder, inorder);

	print_tree(rootNode);
	
	cout<< endl;
}
