#include<iostream>
#include<vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
	for(int i = 0; i < nums.size();i++) {
		if(i > 0 && i < nums.size() - 1) {
			if((nums[i] == nums[i-1]) && (nums[i] == nums[i + 1])) {
				nums.erase(nums.begin() + i);
				i--;
			}
		}
	}

	return nums.size();      
}

int main(int argc, char** argv) {
	vector<int> nums1 = {1,1,1,2,2,3};
	vector<int> nums2 = {0,0,1,1,1,1,2,3,3};

	cout << removeDuplicates(nums1) << endl;
	cout << removeDuplicates(nums2) << endl;

	
	return 0;	
}
