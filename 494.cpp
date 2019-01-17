#include<iostream>
#include<vector>
#include<map>

using namespace std;

map<string, int> k_map;

void traverse(vector<int>& nums, int level, int S, int sum, string path) {
	if(sum == S) {
		auto it = k_map.find(path);
		if(it == k_map.end()) {
			k_map[path] = 1;
		}
	}

	if(sum > S) return;

	if(level == nums.size()) return;

	//if(nums[level] == 0) return;
	
	int left_sum = sum - nums[level];
	int right_sum = sum + nums[level];
	string left_path = path + "-" + to_string(nums[level]);
	string right_path = path + "+" + to_string(nums[level]);

	level++;

	traverse(nums, level, S, left_sum, left_path);
	if(nums[level-1] != 0) {
		traverse(nums, level, S, right_sum, right_path);
	}
}

int findTargetSumWays(vector<int>& nums, int S) {
	traverse(nums, 0, S, 0, "");

	/*
	for(auto it = k_map.begin(); it != k_map.end(); it++) {
		cout << "key = " << it->first << endl;
	}
	*/

	return k_map.size();
}

int main(int argc, char** argv) {
	vector<int> nums = {1, 1, 1, 1, 1};
	int S = 3;

	cout << findTargetSumWays(nums, S) << endl;

	return 0;
}
