#include<iostream>
#include<map>
#include<vector>

using namespace std;

bool isPossible(vector<int>& nums) {
        map<int, int> k_map;

	for(int i = 0;i < nums.size();i++){ // O(n)
		auto it = k_map.find(nums[i]);
		if(it == k_map.end()) {
			k_map[nums[i]] = 1;
		} else {
			it->second++;
		}
	}

	int split = 0;
	int count = 0;

	while(true) {
		count  = 0;
		
		for(auto it = k_map.begin(); it != k_map.end(); it++){
			if(it->second > 0) {
				count++;
				cout << it->first << ", ";
				it->second--;
			}

			if(count == 3) break;		
		}
		cout << endl;

		if(count >= 3) {
			split++;
		} else if (count == 0) {
			break;
		}
	}

	return  split >= 2;
}

int main(int argc, char** argv){
	vector<int> nums1 = {1,2,3,3,4,5};
	vector<int> nums2 = {1,2,3,3,4,4,5,5};
	vector<int> nums3 = {1,2,3,4,4,5};

	cout << isPossible(nums1) << endl;
	cout << isPossible(nums2) << endl;
	cout << isPossible(nums3) << endl;

	return 0;
}
