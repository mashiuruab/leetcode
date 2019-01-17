#include<iostream>
#include<vector>

using namespace std;

bool can_reach = false;
int length;
vector<bool> reachable;

void traverse(vector<int>& nums, int index) {
	//cout << index << ", value = " << nums[index] << ", length = " << length <<  endl;

	if(index == (length - 1)){
		can_reach |= true;
		return;
	}

	if(nums[index] == 0) {
		can_reach |= false;
		return;
	}

	if(index > (length-1)) {
		can_reach |= false;
		return;
	} 	

	for(int i=1;i<=nums[index];i++) {
		if(index + i < length && (reachable[index+i])) {
			traverse(nums, index + i);
			reachable[index+i] = can_reach;
			if(can_reach) break;
		}		
	}
}

bool canJump(vector<int>& nums) {
        length = nums.size();
	reachable.resize(length);
	for(int i=0;i<length;i++) {
		reachable[i] = true;
	}

	traverse(nums, 0);
	return can_reach;
}

int main(int argc, char** argv) {
	vector<int> nums1 = {2,3,1,1,4};
	vector<int> nums2 = {3,2,1,0,4};

	cout << canJump(nums1) << endl;
	can_reach = false;
	cout << canJump(nums2) << endl;

	return 0;
}
