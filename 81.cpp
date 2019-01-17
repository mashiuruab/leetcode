#include<iostream>
#include<vector>

using namespace std;

int do_search(vector<int>& nums, int start, int end, int target) {
	if(start >= end) {
		return false;
	}

	int middle = (start + end) / 2;

	if(nums[middle] == target) {
		return true;
	}

	bool result1 = do_search(nums, start, middle, target);
	
	if(result1) return true;

	bool result2 = do_search(nums, middle+1, end, target);

	if(result2) return true;

	return false;
}

bool search(vector<int>& nums, int target) {
        return do_search(nums, 0, nums.size(), target);
}
int main(int argc, char** argv) {
	vector<int> nums = {4,5,6,7,0,1,2};
	int target = 0;

	cout << "search result = " << search(nums, target) << endl;
	
	return 0;
}
