#include<iostream>
#include<vector>

using namespace std;

/*
power set generation technique
2^n is  ok  with me to generate total number of possible sub set
suppose for n = 4, 2^4 = 16. 0000, 0001, 0010, 0011, 0100, 0101, 0110, 0111, ......
for n = 4, 00, 01, 10, 11. if we bitwise and  (&) this  2 sets of data we would all the sets possible
*/
vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> result;

	for(int i=0;i<(1<<nums.size());i++){
		vector<int> ps;
		for(int j=0;j<nums.size();j++) {
			if((i & (1<<j)) > 0) {
				//cout << "i = " << i << ", j = " << j << endl;
				ps.push_back(nums[j]);
			}
		}
		result.push_back(ps);
	}

	return result;
}

int main(int argc, char** argv) {
	vector<int> nums = {1,2,3};
	subsets(nums);
	return 0;
}
