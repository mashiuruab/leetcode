#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<string> result;

void traverse(TreeNode* root, string &path) {
	if(root == NULL) {
		return;
	}

	path += to_string(root->val) + "->";

	string pathL = path;
	string pathR = path;

	traverse(root->left, pathL);
	traverse(root->right, pathR);

	if(root->left == NULL &&  root->right == NULL) {
		string temp = path;
		temp.erase(path.length() - 2, path.length());
		result.push_back(temp);
	}
}

vector<string> binaryTreePaths(TreeNode* root) {
	string path  = "";
        traverse(root, path);
	return result;
}

int main(int argc, char** argv) {
	return 0;
}
