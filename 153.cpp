#include<iostream>
#include<vector>
#include<climits>

using namespace std;

void traverse(vector<int>& nums, int start, int end, int &min) {
	if(start >= end) {
		return;
	}
	int middle  =  (start + end) / 2;
	cout<< middle << endl;

	if(nums[middle] < min) {
		min = nums[middle];
	}

	traverse(nums, start, middle, min);

	traverse(nums, middle+1, end, min);
}

int findMin(vector<int>& nums) {
	int min = INT_MAX;
	traverse(nums, 0, nums.size(), min);
	return min;
}

int main(int argc, char** argv) {
	vector<int> nums = {3,4,5,1,2};

	cout<< "result = " << findMin(nums) << endl;
	return 0;
}
