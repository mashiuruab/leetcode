#include<iostream>
#include<vector>

using namespace std;

int singleNumber(vector<int>& nums) {
        int count = 0;
	int temp;
	int temp_sum;
	int result = 0;
	
	while(count < 32) {
		temp = 1<<count;
		temp_sum = 0;
		for(int i=0;i<nums.size();i++) {
			temp_sum += nums[i] & temp;
		}

		if((temp_sum % 3) != 0) {
			result  =  result | temp;
		}

		count++;
	}

	return result;
}


int main(int argc, char** argv) {
	vector<int> nums = {2,2,3,2};
	vector<int> nums1 = {0,1,0,1,0,1,99};

	cout<< singleNumber(nums) << endl;
	cout<< singleNumber(nums1) << endl;

	return 0;
}
