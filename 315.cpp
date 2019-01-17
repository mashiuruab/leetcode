#include<iostream>
#include<vector>
#include<map>

using namespace std;

struct TreeNode {
	int val;
	int left_size;
	TreeNode* left;
	TreeNode* right;
	bool inherit;
	TreeNode(int value) : val(value), left_size(0), left(NULL), right(NULL), inherit(false) {}
};

TreeNode* build_tree(vector<int>& nums, map<int, int>  &result_map) {
	if(nums.size() == 0) {
		return  NULL;
	}

	TreeNode* root = new TreeNode(nums[0]);
	result_map[nums[0]] = 0;
	TreeNode* head = root;
	bool left = false;
	
	for(int i=1;i<nums.size();i++){
		root = head;
		TreeNode* prev;
		int inherit_parent = 0;

		bool prev_right  =  false;

		while(root != NULL) {
			prev = root;

			if(prev_right && root->left == NULL) {
				root->left_size = inherit_parent;
				root->inherit  = true;
				result_map[root->val] = root->left_size;
			}
			
			if(nums[i] < root->val) {
				if(root->inherit) {
					root->inherit = false;
					root->left_size = 0;
				}
				
				root->left_size += 1;
				result_map[root->val] = root->left_size;
				// update right
				TreeNode* temp = root;
				while(temp->right != NULL && temp->right->left == NULL) {
					temp->right->left_size = root->left_size;
					temp = temp->right;
				}
				root = root->left;
				prev_right = false;
			} else {
				inherit_parent = root->left_size;
				root = root->right;
				prev_right  =  true;
			}
		}

		if(nums[i] < prev->val) {
			TreeNode* newNode = new TreeNode(nums[i]);
			prev->left = newNode;
			result_map[newNode->val] = newNode->left_size;
			//prev->left_size += 1;
		} else {
			TreeNode* newNode = new TreeNode(nums[i]);
			prev->right =  newNode;
			prev->right->left_size = prev->left != NULL ? prev->left->left_size : inherit_parent;
			result_map[prev->right->val] = prev->right->left_size;
		}
	}

	return head;
}

void print_tree(TreeNode* root) {
	if(root == NULL) {
		return;
	}

	cout << "value  = " << root->val << ", left subtree size = " << root->left_size << endl;

	print_tree(root->left);
	print_tree(root->right);
}

void print_result(map<int, int> &result_map) {
	for(map<int, int>::iterator it = result_map.begin();it != result_map.end();it++) {
		cout<< "key = " << it->first << ", value = " << it->second << endl;
	}
}

void set_result(map<int, int> &result_map, vector<int> &result, vector<int> &nums) {
	for(int i=0;i<nums.size();i++) {
		result[i] = result_map.find(nums[i])->second;
	}
}

vector<int> countSmaller(vector<int>& nums) {
	vector<int>  result;
	result.resize(nums.size());

	map<int, int> result_map;
	TreeNode* root = build_tree(nums, result_map);

	set_result(result_map, result,  nums);

	return  result;
}

int main(int argc, char** argv) {
	vector<int> nums1 = {12, 1, 2, 3, 0, 11, 4};
	vector<int> nums2 = {5, 4, 3, 2, 1};
	vector<int> nums3 = {1, 2, 3, 4, 5};
	vector<int> nums4 = {5,2,6,1};
	vector<int> nums5 = {1,0,2};

	map<int, int>  result_map;
	TreeNode* root = build_tree(nums1, result_map);
	//print_tree(root);
	print_result(result_map);
	//countSmaller(nums1);

	cout << ".........................." << endl;

	result_map.clear();
	root = build_tree(nums2, result_map);
	//print_tree(root);
	print_result(result_map);
	//countSmaller(nums2);
	
	cout << ".........................." << endl;

	result_map.clear();
	root = build_tree(nums3, result_map);
	//print_tree(root);
	print_result(result_map);
	//countSmaller(nums3);

	cout << ".........................." << endl;

	result_map.clear();
	root = build_tree(nums4, result_map);
	//print_tree(root);
	print_result(result_map);
	//countSmaller(nums4);

	cout << ".........................." << endl;

	result_map.clear();
	root = build_tree(nums5, result_map);
	//print_tree(root);
	print_result(result_map);
	//countSmaller(nums4);

	return  0;
}
