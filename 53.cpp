#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int maxSubArray(vector<int>& nums) {
        int max_so_far = nums[0];
	int current_max  =  nums[0];

	for(int i=1;i<nums.size();i++){
		if(current_max + nums[i] > nums[i]) {
			current_max = current_max + nums[i];
		} else {
			current_max = nums[i];
		}

		if(max_so_far < current_max) {
			max_so_far  = current_max;
		}
	}

	return max_so_far;
}

//// dividie and  conquer solution

int max(int a, int b) {
	return  a>b ? a : b;
}

int max(int a, int b, int c) {
	return  max(a,b) > c ? max(a,b) : c;
}

int crossing_sum(vector<int>& nums, int start, int end) {
	int current_sum = nums[start];
	int max_so_far = nums[start];

	for(int i=start+1;i<end;i++) {
		current_sum = max(current_sum+nums[i], nums[i]);
		max_so_far  = max(max_so_far, current_sum);
	}

	return max_so_far;
}

int dc(vector<int>& nums, int start, int end) {
	if(start == end) {
		return  nums[start];
	}

	int mid = (start + end) / 2;

	return max(dc(nums, start, mid),dc(nums,  mid+1, end), crossing_sum(nums, start, end));
}

int maxSubArray_dc(vector<int>& nums) {
	return dc(nums, 0, nums.size());	
}

int main(int argc, char** argv) {
	vector<int> nums = {0};
	cout << maxSubArray_dc(nums) << endl;
	return 0;	
}
