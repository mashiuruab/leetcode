#include<iostream>
#include<vector>
#include<map>
#include<cmath>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

map<int, vector<int>> mp;
vector<vector<int>> result;

void traverse(TreeNode* root, int depth){
	if(root == NULL) {
		return;
	}

	//mq.push(root->val);

	int left = depth + 1;
	int right = depth + 1;
	
	if(root->left != NULL) {
		if(mp.find(left) != mp.end()) {
			mp[left].push_back(root->left->val);
		} else {
			vector<int> temp;
			temp.push_back(root->left->val);
			mp[left] = temp;
		}
	}

	if(root->right != NULL) {
		if(mp.find(right) != mp.end()) {
			mp[right].push_back(root->right->val);
		} else {
			vector<int> temp;
			temp.push_back(root->right->val);
			mp[right] = temp;
		}
	}

	traverse(root->left, left);
	traverse(root->right, right);
}

void do_reverse(vector<int> &tv) {
	for(int i=0;i<tv.size()/2;i++) {
		int temp = tv[i];
		tv[i] = tv[tv.size() - 1 - i];
		tv[tv.size() - 1 - i] = temp;
	}
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	if(root == NULL) {
		return result;
	}

	vector<int> temp;
	temp.push_back(root->val);
	mp[0] = temp;

	traverse(root, 0);

	bool toogle = true;
	for(map<int, vector<int>>::iterator it = mp.begin(); it != mp.end();++it) {
		if(!toogle) {// do reverse
			do_reverse(it->second);
		}

		result.push_back(it->second);
		toogle = !toogle;
	}

	return result;
}

int main(int argc, char** argv) {
	return 0;
}
