#include<iostream>
#include<vector>
#include<climits>

using namespace std;

bool can_reach = false;
int length;
vector<bool> reachable;
int min_step = INT_MAX;

void traverse(vector<int>& nums, int index, int steps) {
	//cout << index << ", value = " << nums[index] << ", length = " << length <<  endl;

	if(index == (length - 1)){
		if(min_step > steps) {
			min_step = steps;
		}
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

	steps += 1; 	

	for(int i=nums[index];i>=1;i--) {
		if(index + i < length && (reachable[index+i])) {
			traverse(nums, index + i, steps);
			reachable[index+i] = can_reach;
		}		
	}
}

int jump(vector<int>& nums) {
        length = nums.size();
	reachable.resize(length);
	for(int i=0;i<length;i++) {
		reachable[i] = true;
	}

	traverse(nums, 0, 0);
	return min_step;       
}

int main(int argc, char** argv) {
	vector<int> nums1 = {2,3,1,1,4};

	cout << jump(nums1) << endl;

	return 0;
}
