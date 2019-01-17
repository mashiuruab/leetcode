#include<iostream>
#include<vector>


using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traverse(TreeNode* root, int k, int distance, vector<int> &result) {
	if(root == NULL) return;

	if(k == distance) {
		result.push_back(root->val);
	}

	distance++;

	traverse(root->left, k, distance, result);
	traverse(root->right, k, distance, result);
}

string dist(TreeNode* root, TreeNode* target, int &distance, string path) {
	if(root == NULL) return "";

	if(root == target) return path;

	string pathL = dist(root->left, target, distance, path + "l");

	if(pathL != "") return pathL;

	if(pathL == "") {
		string pathR = dist(root->right, target, distance, path + "r");

		if(pathR != "") {
			return pathR;
		}
	}

	distance++;
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> result;

	traverse(root, K, 0, result);

	int distr = 0;
	string path = dist(root, target, distr, "");

	if(path[0] == 'l') {
		traverse(root->right, K - distr, 0, result);
	} else {
		traverse(root->left, K - distr, 0, result);
	}

	return result;
}

int main(int argc, char** argv) {
	return 0;
}
