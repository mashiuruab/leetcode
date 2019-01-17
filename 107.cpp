#include<iostream>
#include<vector>
#include<queue>
#include<math.h>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
vector<vector<int>> levelOrderBottom(TreeNode* root) {
	map<int, int> l_map;
        queue<TreeNode*> queue;
	vector<vector<int>> result;

	queue.push(root);
	int level = 0;
	l_map[level] = 1;

	while(!queue.empty()) {
		vector<int> temp;
		int push_count = 0;

		for(int i = 0; i < l_map[level]; i++) {
			TreeNode* node = queue.front();
			queue.pop();
			if(node ==  NULL) continue;
			
			if(node->left != NULL) {
				queue.push(node->left);
				push_count++;
			}
		
			if(node->right != NULL) {
				queue.push(node->right);
				push_count++;
			}
			
			temp.push_back(node->val);			
		}

		l_map[level] = push_count;

		if(temp.size() > 0) {
			result.push_back(temp);
		}
		
		level++;
	}

	return result;
}
*/

void traverse(TreeNode* root, vector<vector<int>> &result, int level){
	if(root == NULL) return;
	
	if(result.size() <= level) {
		vector<int> temp;
		result.push_back(temp);
	}

	result[level].push_back(root->val);
	level++;

	traverse(root->left, result, level);
	traverse(root->right, result, level);
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {
	vector<vector<int>> result;

	traverse(root, result, 0);

	for(int i = 0; i < result.size() / 2; i++) {
		vector<int> temp = result[i];
		result[i] = result[result.size() - i - 1];
		result[result.size() - i - 1] = temp;
	}

	return result;
}

int main(int argc, char** argv){

	return  0;
}
