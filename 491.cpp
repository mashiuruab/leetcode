#include<iostream>
#include<vector>
#include<map>

using namespace std;

map<string, int> k_map;
vector<vector<int>> result;

void traverse(vector<int> &nums, int index, string path, vector<int> temp) {
	if(index == nums.size()) return;

	if(index > 0 && (nums[index] < nums[index - 1])) {
		return;
	}

	temp.push_back(nums[index]);
	path += to_string(nums[index]);

	auto it = k_map.find(path);

	if(temp.size() >= 2 && (it == k_map.end())) {
		result.push_back(temp);
		k_map[path] = 1;
	}
	
	for(int i=index+1; i<nums.size();i++){
		traverse(nums, i, path, temp);
	}
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
	for(int i = 0; i < nums.size(); i++){
		vector<int> temp;
		traverse(nums, i, "", temp);
	}

	return result;
}

int main(int argc, char** argv) {
	vector<int> nums = {4,6,7,7};

	vector<vector<int>> result = findSubsequences(nums);

	for(int i=0;i<result.size();i++) {
		for(int j=0;j<result[i].size();j++) {
			cout<<result[i][j] << ", ";
		}
		cout<<endl;
	}

	return 0;
}
