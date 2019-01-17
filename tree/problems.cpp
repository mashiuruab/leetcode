#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// finding max depth of a tree

int max_depth = -1;

int depth(TreeNode* root, int count) {
	if(root == NULL) return count;

	count++;	

	int left = depth(root->left, count);

	if(max_depth < left) max_depth = left;

	int right = depth(root->right, count);

	if(max_depth < right) max_depth = right;

	return max_depth;
}

int maxDepth(TreeNode* root) {
	depth(root, 0);

	return max_depth == -1 ? 0 : max_depth;	
}

// find  whether is a valid  BST
void is_max(TreeNode* root, int parent);
void is_min(TreeNode* root, int parent);

int get_max(TreeNode* root, int& max) {
	if(root == NULL) return max;
	if(root->val >= max) max = root->val;
	get_max(root->left, max);
	get_max(root->right, max);

	return max;
}

int get_min(TreeNode* root,  int& min) {
	if(root == NULL) return min;
	if(root->val <= min) min = root->val;
	get_min(root->left, min);
	get_min(root->right, min);
	
	return min;
}

bool valid_bst = true;

// we would find whether max is the highest value on that branch of tree
// we would call this using parameter root->left
void is_max(TreeNode* root, int parent) {
	if(root == NULL) return;

	if(root->val >= parent) {
		valid_bst &= false;
		return;
	}
	
	int A_MIN = -2147483648;
	int A_MAX = 2147483647;

	is_max(root->left, root->val);
	int left_max = get_max(root->left, A_MIN);
	if(left_max  != -2147483648) valid_bst &= (root->val > left_max);

	is_min(root->right, root->val);
	int right_min = get_min(root->right, A_MAX);
	if(right_min != 2147483647)  valid_bst &= (root->val < right_min);
}

void is_min(TreeNode* root, int parent) {
	if(root == NULL) return;

	if(root->val <= parent) {
		valid_bst &= false;
		return;
	}

	int A_MIN = -2147483648;
	int A_MAX = 2147483647;

	is_max(root->left, root->val);
	int left_max = get_max(root->left, A_MIN);
	if(left_max  != -2147483648) valid_bst &= (root->val > left_max);

	is_min(root->right, root->val);
	int right_min = get_min(root->right, A_MAX);
	if(right_min != 2147483647) valid_bst &= (root->val < right_min);
}

bool isValidBST(TreeNode* root) {
	if(root == NULL) return valid_bst;
	
	int A_MIN = -2147483648;
	int A_MAX = 2147483647;

	if (root->left != NULL) {
		is_max(root->left, root->val);
		int left_max = get_max(root->left, A_MIN);
		valid_bst &= (root->val > left_max);
	}

	if (root->right != NULL) {
		is_min(root->right, root->val);
		int right_min = get_min(root->right, A_MAX);
		valid_bst &= (root->val < right_min);
	}

	return valid_bst;
}

// find whether tree is a symmetric tree

bool is_symmetric = true;

void traverse(TreeNode* left, TreeNode* right) {
	if(left == NULL && right == NULL) return;

	if(left == NULL && right != NULL) {
		is_symmetric &= false;
		return;
	}

	if(left != NULL && right == NULL) {
		is_symmetric &= false;
		return;
	}

	is_symmetric &= (left->val == right->val);

	traverse(left->left, right->right);
	traverse(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
	if(root == NULL) return true;

	traverse(root->left, root->right);

	return is_symmetric;        
}

void compute_order(TreeNode* root, vector<vector<int>> &container, int count) {
	if(root == NULL) return;
	
	if(count ==  container.size()) {
		vector<int> inner_container;
		container.push_back(inner_container);	
	}
	
	container[count].push_back(root->val);

	count++;
	compute_order(root->left, container, count);
	compute_order(root->right, container, count);
}

vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> container;

	compute_order(root, container, 0);
	
	return container;
}

///  find  sortedArrayToBST

TreeNode* sortedArrayToBST(vector<int>& nums) {
	if(nums.size() == 0) return NULL;

	TreeNode* root = NULL;
	TreeNode* left = NULL;
	left = root;

	for(int i=0;i<nums.size() / 2;i++){
		TreeNode* newNode = new TreeNode(nums[i]);

		if(left != NULL && left->left != NULL && left->right  == NULL) {
			left->right = newNode;
			newNode->left = NULL;
			newNode->right = NULL;
			continue;
		}
		
		newNode->left = left;
		newNode->right = NULL;
		left = newNode;
	}

	int middle = nums.size() / 2;
	root = new TreeNode(nums[middle]);
	root->left = left;
	root->right = NULL;

	left = NULL;

	for(int j=middle + 1;j<nums.size();j++) {
		TreeNode* newNode = new TreeNode(nums[j]);

		if(left != NULL && left->left != NULL && left->right  == NULL) {
			left->right = newNode;
			newNode->left = NULL;
			newNode->right = NULL;
			continue;
		}

		newNode->left = left;
		newNode->right = NULL;
		left = newNode;
	}

	root->right = left;

	return root;
}

void print_sorted_bst(TreeNode* root) {
	if(root == NULL) return;

	cout<< root->val << " ";

	cout<< ",  left = ";
	print_sorted_bst(root->left);
	cout<< ", right  = ";
	print_sorted_bst(root->right);  
}

int main(int argc, char** argv) {
	/*
	TreeNode* root = new TreeNode(3);
	TreeNode* left = new TreeNode(9);
	TreeNode* right = new TreeNode(20);
	
	TreeNode* right_left = new TreeNode(15);
	TreeNode* right_right = new TreeNode(7);

	root->left = left;
	root->right = right;
	
	right->left = right_left;
	right->right = right_right;
	*/

	/*
	TreeNode* root = new TreeNode(-2147483648);
	TreeNode* right = new TreeNode(2147483647);
	root->right = right;
	*/

	/*
	vector<vector<int>> container = levelOrder(root);

	for(int i=0;i<container.size();i++){
		for(int j=0;j<container[i].size();j++){
			cout<< container[i][j]<< " ";
		}
		cout<<endl;
	}

	*/	
	
	vector<int> nums;
	/*
	nums.push_back(-10);
	nums.push_back(-3);
	nums.push_back(0);
	nums.push_back(5);
	nums.push_back(9);
	*/

	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(7);

	TreeNode* root = sortedArrayToBST(nums);
	print_sorted_bst(root);
	cout<< endl;

	return  0;
}
