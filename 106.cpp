#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int postIndex;
bool run_once = true;


TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	if(run_once) {
		run_once = false;
		postIndex = postorder.size() - 1;
	}

	if((postIndex < 0) || (inorder.size() == 0)) {
		return NULL;
	}

	int root = postorder[postIndex];

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

	postIndex--;

	rootNode->right = buildTree(rightio, postorder);
	rootNode->left = buildTree(leftio, postorder);

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
	vector<int> postorder = {8,4,5,2,6,7,3,1};
	vector<int> inorder = {4,8,2,5,1,6,3,7};

	TreeNode* rootNode = buildTree(inorder, postorder);

	print_tree(rootNode);
	
	cout<< endl;
}
