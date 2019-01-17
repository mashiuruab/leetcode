#include<iostream>
#include<vector>

using namespace std;

int max(int i, int j, vector<int>& nums) {
	return nums[i] > nums[j] ? i : j;
}

void max_heapify(vector<int>& nums) {
	vector<int> parent;
	parent.resize(nums.size());

	for(int i=0;i<nums.size();i++) {
		if(i == 0) {
			parent[i] = -1;
		}

		int left_idx = (2 * (i + 1)) - 1;
		int right_idx = left_idx + 1;

		if(right_idx < nums.size()) {
			parent[left_idx] = i;
			parent[right_idx] = i;
		} else if (left_idx < nums.size()) {
			parent[left_idx] = i;
		} else {
			break;
		}
	}

	/*
	for(int i=0;i<nums.size();i++) cout << parent[i] << " ";
	cout << endl;
	*/
	
	
	int parent_val = 0;
	int current_index = 0;

	for(int i=nums.size()-1;i >= 0;i--) {
		current_index = i;
		parent_val = parent[current_index];
		while(parent_val != -1) {
			if(nums[parent[current_index]] < nums[current_index]) {
				int temp = nums[current_index];
				nums[current_index] = nums[parent[current_index]];
				nums[parent[current_index]] = temp;
			}
			current_index = parent[current_index];
			parent_val = parent[current_index];
		}						
	}
}

int extract_max(vector<int>& nums) {
	int max = nums[0];
	nums[0] = nums[nums.size()-1];
	nums[nums.size() - 1] = max;
	nums.erase(nums.begin() + nums.size() - 1);
	max_heapify(nums);

	return max;
}

int findKthLargest(vector<int>& nums, int k) {
	max_heapify(nums);

	int  max = 0;
	for(int i=0;i<k;i++) {
		max  = extract_max(nums);
		//cout << max << endl;
	}

	return  max;
}

int main(int argc, char** argv) {
	vector<int> nums1 = {3,2,1,5,6,4};
	vector<int> nums2 = {3,2,3,1,2,4,5,5,6};

	cout << findKthLargest(nums1, 2) << endl;
	cout << "#########################" << endl;
	cout << findKthLargest(nums2, 4) << endl;
	
	return  0;
}
